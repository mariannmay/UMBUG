/*
 * 
 * Craig Nemeth SPI Library
 * 
 */


#ifndef _SPILIB_C
#define _SPILIB_C
//
//---------------------------------------------------------------
#include "hal_SPI.h"
#include "hal_hardware_board.h"

//#define withDMA

#ifndef DUMMY_CHAR
#define DUMMY_CHAR 0xFF
#endif

// SPI port functions
void halSPISetup(int master)
{
	// 1)
	UCB0CTL1 |= UCSWRST;                     // **Initialize USCI registers**
	
	if(master==1)
	{
		  //2) -> Initialize all USCI registers Set <- BEGIN
		  // CONTROL REGISTERS
		  //UCB0CTL0 -> Control Register 0
		  //  7   |  6  |  5  |  4   |  3  |  2-1   |  0   | 
		  //-------------------------------------------------------------------------
		  //UCCKPH|UCCKPL|UCMSB|UC7BIT|UCMST|UCMODEx|UCSYNC|
		  //UCCKPH (Clock phase)              = 0b  ->  Data is changed on the first UCLK edge and captured on the following edge.
		  //UCCKPL (Clock polarity)           = 0b  ->  The inactive state is low
		  //UCMSB (MSB first select)          = 1b  ->  MSB first
		  //UC7BIT (Character length)         = 0b  ->  8-bit data
		  //UCMST (Master mode)               = 1b  ->  Master mode
		  //UCMODEx (USCI mode)               = 00b ->  3-Pin SPI
		  //UCSYNC (Synchronous mode enable)  = 1b  ->  Synchronous mode
		  UCB0CTL0 = 0xA9;
		  //-------------------------------------------------------------------------
		  //-------------------------------------------------------------------------
		  //UCA0CTL1 -> Control Register 1
		  //   6-7  |   5   |   4   |   3  |   2    |   1   |    0  |
		  //---------------------------------------------------------
		  //UCSSELx |                  Unused               |UCSWRST|
		  //---------------------------------------------------------
		  //UCSSELx (USCI clock source select)= 10b ->  SMCLK
		  //UCSWRST (Software reset)          = 1b  ->  normally set by a PUC
		  UCB0CTL1 = 0x80;                     
		  //-------------------------------------------------------------------------
		  // DATA RATE
		  // Data rate = SMCLK/2 ~= 500kHz
		  // UCA0BR1 = 0x00 & UCA0BR0 = 0x02
		  //-------------------------------------------------------------------------
		  UCB0BR0 = 0x08;                           
		  UCB0BR1 = 0x00;
		  //3) Configure ports <-BEGIN
		  P3SEL |= 0x0E; // P3.1,P3.2,P3.3 option select
		  P3DIR |= 0x01; // P3.0 output direction
		  P3SEL &= ~0x01;// P3.0 is GPIO!!!!!!!!!!!
		  
		  P3DIR &= ~0x10; //P3.4 input
	}else
	{
		  //2) -> Initialize all USCI registers Set <- BEGIN
		  // CONTROL REGISTERS
		  //UCB0CTL0 -> Control Register 0
		  //  7   |  6  |  5  |  4   |  3  |  2-1   |  0   | 
		  //-------------------------------------------------------------------------
		  //UCCKPH|UCCKPL|UCMSB|UC7BIT|UCMST|UCMODEx|UCSYNC|
		  //UCCKPH (Clock phase)              = 0b  ->  Data is changed on the first UCLK edge and captured on the following edge.
		  //UCCKPL (Clock polarity)           = 0b  ->  The inactive state is low
		  //UCMSB (MSB first select)          = 1b  ->  MSB first
		  //UC7BIT (Character length)         = 0b  ->  8-bit data
		  //UCMST (Master mode)               = 0b  ->  Slave mode
		  //UCMODEx (USCI mode)               = 00b ->  3-Pin SPI
		  //UCSYNC (Synchronous mode enable)  = 1b  ->  Synchronous mode
		  UCB0CTL0 = 0xA1;
		  //-------------------------------------------------------------------------
		  //-------------------------------------------------------------------------
		  //UCA0CTL1 -> Control Register 1
		  //   6-7  |   5   |   4   |   3  |   2    |   1   |    0  |
		  //---------------------------------------------------------
		  //UCSSELx |                  Unused               |UCSWRST|
		  //---------------------------------------------------------
		  //UCSSELx (USCI clock source select)= 10b ->  SMCLK
		  //UCSWRST (Software reset)          = 1b  ->  normally set by a PUC
		  UCB0CTL1 = 0x80;                     
		  //-------------------------------------------------------------------------
		  // DATA RATE
		  // Data rate = SMCLK/2 ~= 500kHz
		  // UCA0BR1 = 0x00 & UCA0BR0 = 0x02
		  //-------------------------------------------------------------------------
		  UCB0BR0 = 0x08;                           
		  UCB0BR1 = 0x00;
		  //3) Configure ports <-BEGIN
		  P3SEL |= 0x0E; // P3.1,P3.2,P3.3 option select
		  P3DIR &= ~0x01; // P3.0 input direction
		  P3DIR |= 0x10; //P3.4 output	
	}
	
	// 4)
	UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
	
}

//Send one byte via SPI
unsigned char spiSendByte(const unsigned char data)
{
  while (halSPITXREADY ==0);    // wait while not ready for TX
  IFG2 &= ~UCB0RXIFG;
  halSPI_SEND(data);            // write
  while (halSPIRXREADY ==0);    // wait for RX buffer (full)
  return (halSPIRXBUF);
}

//returns size of data recieved in RXBuffer
/*unsigned int spiMasterCommunicate(unsigned char* TXBuffer, unsigned char* RXBuffer, unsigned int TXsize)
{
	int RXsize = 0;
	int i;
	for(i=0;i<TXsize;i++)
	{
		//software reset
		UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
		
		P3OUT &= ~0x01; //set STE low for slave enable
		while (halSPITXREADY ==0);    // wait while not ready for TX
		IFG2 &= ~UCB0RXIFG;
		halSPI_SEND(TXBuffer[i]);            // write
		while (halSPIRXREADY ==0);    // wait for RX buffer (full)
		char buff = halSPIRXBUF;
		if(buff!=0xFF)
		{
			RXBuffer[RXsize++] = buff;
		}	
		P3OUT |= 0x01; //set STE high for slave disable
	}
	return RXsize;
}*/ //MAKE A QUEUE FOR SPI SPLURGIN

//Read a frame of bytes via SPI
unsigned char spiReadFrame(unsigned char* pBuffer, unsigned int size)
{
#ifndef withDMA
  unsigned long i = 0;
  // clock the actual data transfer and receive the bytes; spi_read automatically finds the Data Block
  for (i = 0; i < size; i++){
    while (halSPITXREADY ==0);   // wait while not ready for TX
    halSPI_SEND(DUMMY_CHAR);     // dummy write
    while (halSPIRXREADY ==0);   // wait for RX buffer (full)
    pBuffer[i] = halSPIRXBUF;
  }
#else
        U1IFG &= ~(URXIFG1 + URXIFG1);      /* clear flags */
        /* Get the block */
        /* DMA trigger is UART1 receive for both DMA0 and DMA1 */
        DMACTL0 &= ~(DMA0TSEL_15 | DMA1TSEL_15);
        DMACTL0 |= (DMA0TSEL_9 | DMA1TSEL_9);
        /* Source DMA address: receive register.  */
        DMA0SA = U1RXBUF_;
        /* Destination DMA address: the user data buffer. */
        DMA0DA = (unsigned short)pBuffer;
        /* The size of the block to be transferred */
        DMA0SZ = size;
        /* Configure the DMA transfer*/
        DMA0CTL =
          DMAIE   |                         /* Enable interrupt */
          DMADT_0 |                         /* Single transfer mode */
          DMASBDB |                         /* Byte mode */
          DMAEN |                           /* Enable DMA */
          DMADSTINCR1 | DMADSTINCR0;        /* Increment the destination address */

        /* We depend on the DMA priorities here.  Both triggers occur at
           the same time, since the source is identical.  DMA0 is handled
           first, and retrieves the byte.  DMA1 is triggered next, and
           sends the next byte. */
        /* Source DMA address: constant 0xFF (don't increment)*/
        DMA1SA = U1TXBUF_;
        /* Destination DMA address: the transmit buffer. */
        DMA1DA = U1TXBUF_;
        /* Increment the destination address */
        /* The size of the block to be transferred */
        DMA1SZ = count-1;
        /* Configure the DMA transfer*/
        DMA1CTL =
          DMADT_0 |                         /* Single transfer mode */
          DMASBDB |                         /* Byte mode */
          DMAEN;                            /* Enable DMA */

        /* Kick off the transfer by sending the first byte */
        halMMC_SEND(0xFF);
        _EINT(); LPM0;  // wait till done
#endif
  return(0);
}


//Send a frame of bytes via SPI
unsigned char spiSendFrame(unsigned char* pBuffer, unsigned int size)
{
#ifndef withDMA
  unsigned long i = 0;
  // clock the actual data transfer and receive the bytes; spi_read automatically finds the Data Block
  for (i = 0; i < size; i++){
    while (halSPITXREADY ==0);   // wait while not ready for TX
    halSPI_SEND(pBuffer[i]);     // write
    while (halSPIRXREADY ==0);   // wait for RX buffer (full)
    pBuffer[i] = halSPIRXBUF;
  }
#else
      /* Get the block */
      /* DMA trigger is UART send */
      DMACTL0 &= ~(DMA0TSEL_15);
      DMACTL0 |= (DMA0TSEL_9);
      /* Source DMA address: the data buffer.  */
      DMA0SA = (unsigned short)pBuffer;
      /* Destination DMA address: the UART send register. */
      DMA0DA = U1TXBUF_;
      /* The size of the block to be transferred */
      DMA0SZ = count;
      /* Configure the DMA transfer*/
      DMA0CTL =
        DMAREQ  |                           /* start transfer */
        DMADT_0 |                           /* Single transfer mode */
        DMASBDB |                           /* Byte mode */
        DMAEN |                             /* Enable DMA */
        DMASRCINCR1 | DMASRCINCR0;          /* Increment the source address */
#endif
  return(0);
}

/***
 * read_eeprom()
 * Description: Read a byte from the specified address.
 **/
unsigned char* read_eeprom(int EEPROM_address, int size)
{
	//opcodes
	#define WREN  6
	#define WRDI  4
	#define RDSR  5
	#define WRSR  1
	#define READ  3
	#define WRITE 2
	
	unsigned char* data;	
	
	long address = 0;
	for(address = EEPROM_address; address <size; address+=32)
	{

	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST; 
	  	// Select device
	  	P8OUT &= ~0x01;
	  	// Send READ command
	  	spiSendByte(READ); //transmit read opcode
	  	// Send address of where to read from
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST; 
	  	spiSendByte((char)(address>>8));   //send MSByte address first
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;  
	  	spiSendByte((char)(address));      //send LSByte address
	  	// Send dummy write to sync clock
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST; 
		int y;
		int z=4;
		for(y=0;y<10;y++)
		{
			z++;
		}
		int i;
		for(i=0; i<32; i++)
		{
	  		data[i+address] = spiSendByte(0xFF); //get data byte
		}
	  	// Deselect device
	  	P8OUT |= 0x01; //release chip, signal end transfer
	}
  	// Return value
  	return data;
}

void write_eeprom(int EEPROM_address, int size, unsigned char* data)
{
	//opcodes
	#define WREN  6
	#define WRDI  4
	#define RDSR  5
	#define WRSR  1
	#define READ  3
	#define WRITE 2	

	int timeWaster;
	int retard;
	long address = 0;
	for(address = EEPROM_address; address <size; address+=32)
	{
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
		
		// Select EEPROM
		P8OUT &= ~0x01;
		// Send WRITE ENABLE command
		spiSendByte(WREN); 
		// Deselect EEPROM
		P8OUT |= 0x01;
		// Wait for command to be processed
		timeWaster=0;
		retard=67;
		for(timeWaster=0;timeWaster<10;timeWaster++)
		{
			retard += (9-8);
		};
		
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
		
		// Select EEPROM
		P8OUT &= ~0x01;
		// Send WRITE command
		spiSendByte(WRITE);
		// Send ADDRESS where to start writing
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
		spiSendByte((char)(address>>8));   //send MSByte address first
	  	UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
		spiSendByte((char)(address));      //send LSByte address
		// Send data
		unsigned int i;
		for(i = 0; i < 32; i++) {
	  		UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;
			P8OUT &= ~0x01;
			spiSendByte(data[address+i]);
			P8OUT &= ~0x01;
		}
		// Deselect EEPROM
		P8OUT |= 0x01; //release chip
		  
		//wait for eeprom to finish writing
		int x = 1+4;
		for(timeWaster=0;timeWaster<600;timeWaster++)
		{	
			x++;
		}
	}

}


#ifdef withDMA
#ifdef __IAR_SYSTEMS_ICC__
#if __VER__ < 200
interrupt[DACDMA_VECTOR] void DMA_isr(void)
#else
#pragma vector = DACDMA_VECTOR
__interrupt void DMA_isr(void)
#endif
#endif

#ifdef __CROSSWORKS__
void DMA_isr(void)   __interrupt[DACDMA_VECTOR]
#endif

#ifdef __TI_COMPILER_VERSION__
__interrupt void DMA_isr(void);
DMA_ISR(DMA_isr)
__interrupt void DMA_isr(void)
#endif
{
  DMA0CTL &= ~(DMAIFG);
  LPM3_EXIT;
}
#endif


//---------------------------------------------------------------------
#endif /* _SPILIB_C */
