//******************************************************************************
//  SD Card for MSP-FET430x169 Device Driver Source File
//
//  Description: This source file contains the implementation for the SD driver
//
//  Chris Nichols
//  University of Manitoba
//  February 2008
//  Built with IAR Embedded Workbench Version: 4.01
//
//  Modified by Tianshao Ni
//  Univerisity of Manitoba
//  December 2011
//  Built with IAR Embedded Workbench Version; 5.31
//
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//  Note: This code is inteded for a SDHC card, not standard SD card.
//  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//******************************************************************************

//this driver is slow  you might wanna speed up the SPI speed

#include <sd_card.h>
#include <stdio.h>

// SD Card response sizes (in bytes)
#define R1				1
#define R2				2
#define R3				5
#define R7				5
#define MAX_R			5

// Meaning of R1
#define R1_ERR			0x7F	// R1 indicates an error if any bit is set
#define R1_IDLE			BIT0	// R1: card is initializing
#define R1_ERASE		BIT1	// R1: erase sequence reset
#define R1_ILLEGAL		BIT2	// R1: illegal command
#define R1_CRC			BIT3	// R1: comm CRC error
#define R1_ER_SEQ		BIT4	// R1: error in erase sequence
#define R1_ADD			BIT5	// R1: address error
#define R1_PARAM		BIT6	// R1: paramater error

// SD Card command set
#define CMD0			0		// GO_IDLE_STATE
#define CMD0_R			R1
#define CMD1                    1
#define CMD1_R                  R1
#define CMD2                    2
#define CMD2_R                  R2
#define CMD8			8		// SEND_IF_COND
#define CMD8_R			R7
#define CMD9			9		// SEND_IF_COND
#define CMD9_R			R1
#define CMD13			13		// SEND_STATUS
#define CMD13_R			R2
#define CMD16			16		// SET_BLOCKLEN
#define CMD16_R			R1
#define CMD17			17		// READ_SINGLE_BLOCK
#define CMD17_R			R1
#define CMD18                   18
#define CMD18_R                 R1
#define CMD24			24		// WRITE_BLOCK
#define CMD24_R			R1
#define CMD55			55		// APP_CMD
#define CMD55_R			R1
#define CMD58			58		// READ_OCR
#define CMD58_R			R3
#define CMD59			59		// CRC_ON_OFF
#define CMD59_R			R1
#define ACMD41			41		// SD_SEND_OP_COND
#define ACMD41_R		R1

// SD Card CRC Polynomials
#define CRC7_POLY		0x09	// The polynomial used for the CRC7
#define CRC16_POLY		0x1021	// The polynomial used for the CRC16

#define CMD_BITS		0x40	// Used to set the proper bit in a command for tx
#define CMD_MASK		0x3F	// Used to make sure commands are only 6 bits long

#define TOK_START		0xFE	// Data start token
#define TOK_ERR_MASK	0xF0	// Used to find an error token
#define TOK_ERR_ECC		0x04	// Bit indicating an ECC error in the card
#define TOK_ERR_RANGE	0x08	// Bit indicating out of valid range

#define SD_BLOCK_POW	0x09	// 2^9 bytes per physical block
#define SD_CHECK		0xAA	// Use the recommended check pattern of 10101010b
#define SD_VS			0x01	// Voltage supply of 2.7v-3.3v

#define SD_V1			1		// Indicates the SD card is version 1.x
#define SD_V2			2		// Indicates the SD card is version 2.x

#define ON_SD			BIT5	// -ON_SD pin

#define SD_TIMEOUT		TIMEOUT

#define SD_MAX_RESP_LENGTH      5

int sd_reset_bus(void);


/************************************************************
 * Private Functions
 ************************************************************/

/**
 * Sends a command to the SD card and checks the response
 *
 * IN: cmd - the command code
 *     args - the arguments
 *     resp - the response type
 *     response - a pointer to the response buffer
 *              - must be large enough to fit the response
 * OUT: char - error code
 **/
int sd_cmd(char cmd, long args, char resp, char* response)
{
	int error = NO_ERROR;
	int i;
	char crc;
        //char crc_check;
	char command[SD_MAX_RESP_LENGTH];

	// Set the transmission bit in the command byte
	command[0] = (cmd & CMD_MASK) | CMD_BITS;
	// Load the argument bytes into the array
	command[1] = args >> 24;
	command[2] = args >> 16;
	command[3] = args >> 8;
	command[4] = args;

	// Generate the CRC and set the end bit
        crc = (make_crc7(&command[0], CMD_LENGTH, CRC7_POLY) << 1) | BIT0;
      
	// Send the command and the first arguments and the CRC
	error = spi_tx(command[0]);
	error |= spi_tx(command[1]);
	error |= spi_tx(command[2]);
	error |= spi_tx(command[3]);
	error |= spi_tx(command[4]);
        //error |= spi_tx(0xff);
	error |= spi_tx(crc);

	// If there was an error here at all, return it
	if(error)
		return error;
         
	// Receive bytes until the first bit of an incoming byte is 0
	i = 0;
        //printf("\n%02d r: ", cmd);
	do
	{
		error |= rx_spi(response);
                i++;
                //printf("0x%02x ", response[0]);

	}while( ((*response & BIT7) == BIT7) && (i < SD_TIMEOUT));

	// If there was a time out, then just leave
	if(i >= SD_TIMEOUT)
		return MODULE_SD + ERR_TIMEOUT;
	else
	{
		// Otherwise receive the appropriate number of bytes for the response
		for(i = 1; i < resp; i++)
			error |= rx_spi(&response[i]);
	}   
        
	// Get the CRC byte
	error |= rx_spi(&crc);
        
	return error;
}

/************************************************************
 * Public Functions
 ************************************************************/

/**
 * Initializes the SD card for use
 * only needs to be called after a PUC
 *
 * IN: void
 * OUT: int - error code (FALSE if no error)
 **/
int sd_init(void)
{
	int i;
	char response[MAX_R];
        char dummy;
	int error;
        
        //!!!!!!!!!!!!HARDWARE AND BUS INITIALIZAITON!!!!
        
        //disable I2C
	error = i2c_disable();				
        //apply power to SD card
        P4DIR |= ON_SD;
	P4OUT &= ~ON_SD;	

        //enable SPI
	spi_enable();
        // CS must be held high during power up
	__spi_deassert_cs();					
	// Set the SPI speed to about 80KHz for initialization
	spi_set_speed(HFXTCLK/80000);
	// Send 80 clocks, SD card require at least 74 clock cycles
	for(i = 0; i < 10; i++)
		spi_tx(0xFF);
        // Assert CS before issuing any commands
	__spi_assert_cs();					
        
        
        //!!!!!!!!!!!!!SENDING SD CARD COMMAND NOW!!!!!!
        
	//CMD0 - Begin the initialization procedure
	error = sd_cmd(CMD0, 0, CMD0_R, &response[0]);
        if (error)
        {
            sd_reset_bus();			
	    return error;
        }
        if((response[0] & ~R1_IDLE) & R1_ERR)
	{
            sd_reset_bus();
            return error;
	}
        
                 
	//CMD8 - Send the interface conditions, mandatory for SDHC cards
	error = sd_cmd(CMD8,(SD_VS << 8) + SD_CHECK, CMD8_R, &response[0]);
	if (error)
        {
            sd_reset_bus();			
	    return error;
        }
        if((response[0] & ~R1_IDLE) & R1_ERR)
	{
            sd_reset_bus();
            return MODULE_SD + ERR_OTHER;
	}      
      
        
	//CMD59 to indicate that CRC is used for SD card
	error = sd_cmd(CMD59, 1, CMD59_R, &response[0]);
        if (error)
        {
            sd_reset_bus();			
	    return error;
        }
        if((response[0] & ~R1_IDLE) & R1_ERR)
	{
            sd_reset_bus();
            return MODULE_SD + ERR_OTHER;
	}  
        if(response[0] & R1_ILLEGAL)
	{
		response[0] &= ~R1_ILLEGAL;
	}
        
	//CMD55 indicate that the next command is an application specific command
        //ACMD41 starts the internal initialization routine for SD card, 
        //when its response is 0 then the init is done
	i = 0;
	do
	{
		error = sd_cmd(CMD55, 0, CMD55_R, &response[0]);
                if (error)
                {
                    sd_reset_bus();			
                    return error;
                }
           
		error = sd_cmd(ACMD41, 0x40000000, ACMD41_R, &response[0]);
                if (error)
                {
                    sd_reset_bus();			
                    return error;
                }
                
		i++;
                rx_spi(&dummy);
	}while( ((*response & R1_IDLE) == R1_IDLE) && (i < SD_TIMEOUT) ); 
	if(i >= SD_TIMEOUT)
		error = MODULE_SD + ERR_TIMEOUT;
               
        
        //CMD58 read OCR, is used to check SD card accepted voltage level and initialization status
        //use this CMD to verify that the specific SD card is okay to use
        #if SD_CARD_DEBUG
	error = sd_cmd(CMD58, 1, CMD58_R, &response[0]);
	if (error)
        {
            sd_reset_bus();			
	    return error;
        }
        if(response[0] & R1_ERR)
	{
            sd_reset_bus();				
	    return MODULE_SD + ERR_OTHER;
	}    
        #endif
                     
        
        sd_reset_bus();	
        
        //complete SD card operation for now
	return error;
}

int sd_reset_bus()
{
    __spi_deassert_cs();	
    spi_disable();
    i2c_enable();
    
    return NO_ERROR;
}

/**
 * Removes power from the SD card
 *
 * IN: void
 * OUT: int - error code (FALSE if no error)
 **/

int sd_power_down(void)
{
	int error = NO_ERROR;

        sd_reset_bus();
	
        // Hold SPI pins at logic 0 so SD card can't draw current from them
	P3DIR |= SPI_SIMO + SPI_SOMI + SPI_SCLK;	// Set SPI pins to output
	P3OUT &= ~(SPI_SIMO + SPI_SOMI+ SPI_SCLK);	// Clear SPI pins

	P4OUT |= ON_SD;					// Remove power from the SD card

	return error;
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
int sd_read(char* buff, int length, long block_addr)
{
	char response[SD_MAX_RESP_LENGTH];
	int i;
	int error = NO_ERROR;
        unsigned int crc = 0, crc_check = 0;
     
        //disable i2c, enable spi and assert cs
	 i2c_disable();
        spi_enable();		
	__spi_assert_cs();
        
        //CMD17, read a block
        error = sd_cmd(CMD17, block_addr,CMD17_R, &response[0]);
	if (error)
        {
            sd_reset_bus();			
	    return error;
        }
        if(response[0] & R1_ERR)
	{
            sd_reset_bus();				
	    return MODULE_SD + ERR_OTHER;
	} 

	// Wait for the start (or error) token
	i = 0;
	do
	{
		error |= rx_spi(&response[0]);
		i++;
	}while((response[0] == 0xFF) & (i < SD_TIMEOUT));
	if(i >= SD_TIMEOUT)
	{
		sd_reset_bus();
		return MODULE_SD + ERR_TIMEOUT;
	}        
        
	// Check the token received
        if(response[0] == TOK_START)
	{
                char temp_resp = 0;
                
            	for(i = 0; i < SD_BLOCK_LENGTH; i++)
                {	
                    char temp;
                    if (i < length)
                      rx_spi(&buff[i]);
                    else
                      rx_spi(&temp);
                }
                rx_spi(&temp_resp);
                crc = temp_resp << 8;
                rx_spi(&temp_resp);
                crc |= temp_resp;
                
                crc_check = make_crc16_sd(buff, length, CRC16_POLY);
                //printf("crc read: %d %d\n", crc_check, crc);
                
                if (crc != crc_check)
                {
                    sd_reset_bus();				
	            return MODULE_SD + ERR_CRC;
                }           
	}
	else if( (response[0] & TOK_ERR_MASK) == 0)
	{
		// Check for errors indicated in the token
		if(response[0] & TOK_ERR_ECC)
			error = MODULE_SD + ERR_ECC;
		else if(response[0] & TOK_ERR_RANGE)
			error = MODULE_SD + ERR_ADDR;
		else
			error = MODULE_SD + ERR_OTHER;

		sd_reset_bus();	
                return error;
	}
	else
	{
            sd_reset_bus();				
	    return MODULE_SD + ERR_OTHER;
	}      
        
        sd_reset_bus();
        
	return error;
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


int sd_write(char* buff,int length, long block_addr)
{
	char response[5];
        char crc = 0;
        unsigned int i = 0, crc_check = 0;;
	int error = NO_ERROR;

	// Disable the i2c module and assert CS
	i2c_disable();
        spi_enable();		
	__spi_assert_cs();

        
	// Send CMD24
	error = sd_cmd(CMD24, block_addr, CMD24_R, &response[0]);
	if (error)
        {
            sd_reset_bus();			
	    return error;
        }
	if(response[0] & R1_ERR)
	{
		sd_reset_bus();					// Resume operation as I2C slave

		if(response[0] & R1_CRC)
			return MODULE_SD + ERR_CRC;
		else if(response[0] & R1_ADD)
			return MODULE_SD + ERR_ADDR;
		else
			return MODULE_SD + ERR_OTHER;
	}
        
        spi_tx(0xfe);
        for(i = 0; i < SD_BLOCK_LENGTH; i++)
        {	
            if (i < length)
              spi_tx(buff[i]);
            else
              spi_tx(0x00);
        }
        
        crc_check = make_crc16_sd(buff, length, CRC16_POLY);
        crc = crc_check >> 8;
        spi_tx(crc);
        crc = crc_check;
        spi_tx(crc);
        
        rx_spi(&response[0]);
        if ((response[0] & 0x1F) != 0x05)
        {    sd_reset_bus();
            return MODULE_SD + ERR_CRC;	
        }

        //printf("data_r: %02x", response[0]);
        
        do
        {
              rx_spi(&response[0]);
              //printf("r: %02x", response[0]);
              i++;
        } while (response[0] != 0xff & i < SD_TIMEOUT);
        
        //error = sd_cmd(CMD13, 0, 5, &response[0]);    
        //printf("13 r: %02x %02x", response[0], response[1]);
        
        
        sd_reset_bus();
        
	return error;
}

