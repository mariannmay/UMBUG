//////////////////////////////////////////////////////////////////
//                                                              //
//    SDCard source                                        		//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "SDCard.h"

#if DebugMode
	#include "Log.h"
#endif

// functions

void sdCard_sendCommand(Byte cmd, long args, UI8 responseSize, SDCard* card)
{
	#if DebugMode
		printf("            CMD: 0x%x\r\n", cmd);
		printf("            args: 0x%x\r\n", args);
		logCombo("            expected response size", responseSize);
	#endif
	
	int i = 0;
	char crc;
	Byte command[SD_MAX_RESP_LENGTH+1];
	Byte response[SD_MAX_RESP_LENGTH+1];

	// Set the transmission bit in the command byte
	command[0] = (cmd & CMD_MASK) | CMD_BITS;
	// Load the argument bytes into the array
	command[1] = args >> 24;
	command[2] = args >> 16;
	command[3] = args >> 8;
	command[4] = args;

	// Generate the CRC and set the end bit
    crc = (make_crc7(&command[0], CMD_LENGTH, CRC7_POLY) << 1) | BIT0;
    
	command[5] = crc;
    
    #if DebugMode
    	printf("            CRC: 0x%x\r\n", command[5]);
    #endif
      
	// Send the command and the first arguments and the CRC
	
	#if DebugMode
		logLine("            tx command...");
		printf("                0x%x\r\n", command[0]);
		printf("                0x%x\r\n", command[1]);
		printf("                0x%x\r\n", command[2]);
		printf("                0x%x\r\n", command[3]);
		printf("                0x%x\r\n", command[4]);
		printf("                0x%x\r\n", command[5]);
	#endif
	
	SPI_transmitStream(&card->SPI, command, SD_MAX_RESP_LENGTH+1, false);
    
    #if DebugMode
    	logLine("            tx done");
    #endif
    
    i = 0;
	// Receive bytes until the first bit of an incoming byte is 0
	do
	{
		SPI_receive(&card->SPI, false);
        i++;
	}
	while( ((card->SPI.receiveMessage[0] & BIT7) == BIT7) && (i < SD_TIMEOUT));

	// If there was a time out, then just leave
	if(i >= SD_TIMEOUT)
	{
		#if DebugMode
			logLine(" *** SD card had SPI timeout! ***");
		#endif
		return;
	}
	else
	{
		#if DebugMode
			logLine("            getting response...");
		#endif
		
		// copy first part of response
		response[0] = card->SPI.receiveMessage[0];
		
		if (responseSize > 1)
		{
			// receive the appropriate number of additional bytes for the response
			// starting at 1 because the first byte was already received above
			for (i = 1; i < responseSize; i++)
			{
				SPI_receive(&card->SPI, false);
				response[i] = card->SPI.receiveMessage[0];
			}
		}
		
		// receive the CRC in the last byte
		SPI_receive(&card->SPI, false);
		response[SD_MAX_RESP_LENGTH] = card->SPI.receiveMessage[0];
	
	}
	
	
	for (i = 0; i < responseSize+1; i++)
	{
		card->SPI.receiveMessage[i] = response[i];
	} 
		
	#if DebugMode
		for (i = 0; i < responseSize; i++)
		{
			printf("                0x%x\r\n", card->SPI.receiveMessage[i]);
		}
		printf("        done sending CMD%x\r\n", cmd);
	#endif
}

/////////////////////////////////////////////

void sdCard_initialize(SDCard* card)
{
	initialize_SPI(&card->SPI);

	setDigitalOutput(card->SPI.chipSelect.out);

	// Send 80 clocks, SD card require at least 74 clock cycles
	int i;
	for(i = 0; i < 10; i++)
	{
		SPI_transmit(&card->SPI, 0xFF, false);
	}
    // Assert CS before issuing any commands
	clearDigitalOutput(card->SPI.chipSelect.out);
	
	//CMD0 - Begin the initialization procedure
	sdCard_sendCommand(CMD0, SD_EMPTY_ARGS, CMD0_R, card);
	
	//CMD8 - Send the interface conditions, mandatory for SDHC cards
	sdCard_sendCommand(CMD8, (SD_VS << 8) + SD_CHECK, CMD8_R, card);
	
	//CMD59 to indicate that CRC is used for SD card
	sdCard_sendCommand(CMD59, 1, CMD59_R, card);
	// ignore illegal
	if(card->SPI.receiveMessage[0] & R1_ILLEGAL)
	{
		card->SPI.receiveMessage[0] &= ~R1_ILLEGAL;
	}
	
	//CMD55 indicate that the next command is an application specific command
	//ACMD41 starts the internal initialization routine for SD card, 
	//when its response is 0 then the init is done
	i = 0;
	do
	{
		sdCard_sendCommand(CMD55, SD_EMPTY_ARGS, CMD55_R, card);
		sdCard_sendCommand(ACMD41, 0x40000000, ACMD41_R, card);

		i++;
	    SPI_receive(&card->SPI, false);
	}
	while( ((card->SPI.receiveMessage[0] & R1_IDLE) == R1_IDLE) && (i < SD_TIMEOUT) );
	
	setDigitalOutput(card->SPI.chipSelect.out);

}


/**
 * Reads a block of data from the SD card. Status of read can be
 * checked through sd_check_status()
 *
 * IN: buff - receive buffer, must be at least numBytes in size
 *     length - the number of bytes to be read (max 512)
 *     block_addr - the address to read from (max depends on the card)
 * OUT: int - error code (FALSE if no error)
 **/
void sdCard_read(long blockAddress, SDCard* card)
{
	int i;
    unsigned int crc = 0, crc_check = 0;
     
    setDigitalOutput(card->SPI.chipSelect.out);
        
    //CMD17, read a block
    // block_addr goes 0x01, 0x02, 0x03 ...
    sdCard_sendCommand(CMD17, blockAddress, CMD17_R, card);

	// Wait for the start (or error) token
	i = 0;
	do
	{
		SPI_receive(&card->SPI, false);
		i++;
	}
	while((card->SPI.receiveMessage[0] == 0xFF) & (i < SD_TIMEOUT));
	
	if(i >= SD_TIMEOUT)
	{
		clearDigitalOutput(card->SPI.chipSelect.out);
		return;
	}        
        
	// Check the token received
    if(card->SPI.receiveMessage[0] == TOK_START)
	{
		for(i = 0; i < SDCARD_BLOCK_SIZE; i++)
		{
			SPI_receive(&card->SPI, false);
			card->RX_blockBuffer[i] = card->SPI.receiveMessage[0];
	    }
			
		// for commands the CRC is only one byte
		// but for data, the CRC is two bytes
		SPI_receive(&card->SPI, false);
		crc = card->SPI.receiveMessage[0] << 8;
		SPI_receive(&card->SPI, false);
		crc |= card->SPI.receiveMessage[0];
		
		crc_check = make_crc16_sd(card->RX_blockBuffer, SDCARD_BLOCK_SIZE, CRC16_POLY);
		//printf("crc read: %d %d\n", crc_check, crc);
		
		if (crc != crc_check)
		{
			// error
		}           
	}
	else if( (card->SPI.receiveMessage[0] & TOK_ERR_MASK) == 0)
	{
		clearDigitalOutput(card->SPI.chipSelect.out);
		return;
	}
	else
	{
        // did not receive anything we can interperet
	}      
        
	clearDigitalOutput(card->SPI.chipSelect.out);
}

/**
 * Writes a block of data to the SD card.  Status of write can be
 * checked through sd_check_status()
 *
 * IN: buff - transmit buffer, must be at least numBytes in size
 *     length - the number of bytes to be written (max 512)
 *     block_addr - the address to write to
 * OUT: int - error code (FALSE if no error)
 **/


void sdCard_write(long blockAddress, SDCard* card)
{
	char crc = 0;
	unsigned int i = 0;
	unsigned int crc_check = 0;

	setDigitalOutput(card->SPI.chipSelect.out);

	// Send CMD24
	sdCard_sendCommand(CMD24, blockAddress, CMD24_R, card);
	
	SPI_transmit(&card->SPI, TOK_START, false);	// this is the start token
	
    for(i = 0; i < SDCARD_BLOCK_SIZE; i++)
    {
    	SPI_transmit(&card->SPI, card->TX_blockBuffer[i], false);
    }
    
    // 2byte CRC
    crc_check = make_crc16_sd(card->TX_blockBuffer, SDCARD_BLOCK_SIZE, CRC16_POLY);
    crc = crc_check >> 8;
    SPI_transmit(&card->SPI, crc, false);
    crc = crc_check;
    SPI_transmit(&card->SPI, crc, false);
    
    
    SPI_receive(&card->SPI, false);
    
    if ((card->SPI.receiveMessage[0] & 0x1F) != 0x05)	// it worked!
    {
		// TODO REMOVE
		printf("write to sd card successful\r\n");
		fflush(stdout);
    }
    
    clearDigitalOutput(card->SPI.chipSelect.out);
    
}



