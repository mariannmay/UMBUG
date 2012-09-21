//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice source                                        	//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

//I am using the 'B0' USCI module

#include "SPIDevice.h"

// functions //////////////////////////////////


// the following 2 functions set up USCI_B0 to use for SPI.

//USCI_B0 control register 0			UCB0CTL0
//USCI_B0 control register 1			UCB0CTL1
//USCI_B0 Bit rate control register 0	UCB0BR0
//USCI_B0 Bit rate control register 1	UCB0BR1

bool initialize_SPI_master(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:
			// 1)
			UCB0CTL1 |= UCSWRST;                     // **Initialize USCI registers**
			
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
			UCB0CTL0 = 0x29;
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
			UCB0BR0 = 0x02;                           
			UCB0BR1 = 0x00;
			
			//3) Configure ports <-BEGIN
			P3SEL |= 0x0E; // P3.1,P3.2,P3.3 option select
			P3DIR |= 0x01; // P3.0 output direction
			P3DIR &= ~0x10; //P3.4 input
			
			// 4)
			UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
			break;
		
		case SPI_CHANNEL_2:
			// TODO
			;
			break;
			
		default:
			return false;
	}
	
	return true;
	
}

bool initialize_SPI_slave(SPI_CHANNEL channel)
{
	
	switch (channel)
	{
		case SPI_CHANNEL_1:
			// 1)
			UCB0CTL1 |= UCSWRST;                     // **Initialize USCI registers**
			
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
			UCB0CTL0 = 0x21;
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
			UCB0BR0 = 0x02;                           
			UCB0BR1 = 0x00;
			
			//3) Configure ports <-BEGIN
			P3SEL |= 0x0E; // P3.1,P3.2,P3.3 option select
			P3DIR &= ~0x01; // P3.0 input direction
			P3DIR |= 0x10; //P3.4 output	
			
			// 4)
			UCB0CTL1 &= ~UCSWRST;                     // **Initialize USCI state machine**
			break;
			
		case SPI_CHANNEL_2:
			// TODO
			;
			break;
			
		default:
			return false;
	}
	
	return true;
}

///////////////////////////////////////////////

// returns whether or not this was successful
bool initialize_SPI(SPI_CHANNEL channel, SPI_TYPE spiType)
{
	
	if (spiType == SPI_TYPE_Master)
	{
		return initialize_SPI_master(channel);
	}
	else if (spiType == SPI_TYPE_Slave)
	{
		return initialize_SPI_slave(channel);
	}
	
	return false;

}

///////////////////////////////////////////////

void SPI_transmit(SPI_Device* device, const Byte data)
{
	setDigitalOutput(&device->chipSelect);
	device->transmitMessage = data;
	
	switch(device->channel)
	{
		case SPI_CHANNEL_1:
			UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;					// software reset
			while ((UC0IFG&UCB0TXIFG) == 0);		// wait while not ready for TX
			IFG2 &= ~UCB0RXIFG;
			UCB0TXBUF = device->transmitMessage;	// write
			while ((UC0IFG&UCB0RXIFG) == 0);		// wait for RX buffer (full)
			device->receiveMessage = (UCB0RXBUF);
			break;
			
		case SPI_CHANNEL_2:
			// TODO
			device->receiveMessage = DUMMY_CHAR;
			break;
			
		default:
			device->receiveMessage = DUMMY_CHAR;
	}
}

///////////////////////////////////////////////

void SPI_receive(SPI_Device* device, Byte* data)
{   
    // TODO
}



