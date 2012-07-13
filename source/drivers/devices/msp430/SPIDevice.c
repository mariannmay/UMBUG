//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice source                                        	//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

//I am using the 'B0' USCI module

#include "SPIDevice.h"
#include <stdio.h>

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
			UCB0CTL1   |= UCSWRST;                     // **Initialize USCI registers**
			
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
			UCB0CTL0	= 0xA9;
			//-------------------------------------------------------------------------
			//-------------------------------------------------------------------------
			//UCA0CTL1 -> Control Register 1
			//   6-7  |   5   |   4   |   3  |   2    |   1   |    0  |
			//---------------------------------------------------------
			//UCSSELx |                  Unused               |UCSWRST|
			//---------------------------------------------------------
			//UCSSELx (USCI clock source select)= 10b ->  SMCLK
			//UCSWRST (Software reset)          = 1b  ->  normally set by a PUC
			UCB0CTL1	= 0x80;                     
			//-------------------------------------------------------------------------
			// DATA RATE
			// Data rate = SMCLK/2 ~= 500kHz
			// UCA0BR1 = 0x00 & UCA0BR0 = 0x02
			//-------------------------------------------------------------------------
			UCB0BR0		= 0x08;                           
			UCB0BR1		= 0x00;
			
			//3) Configure ports
			P3SEL	   |= 0x0E;				// P3.1,P3.2,P3.3 option select
			P3DIR	   |= 0x01;				// P3.0 output direction
			P3SEL	   &= ~0x01;			// P3.0 is GPIO!!!!!!!!!!!
			
			P3DIR	   &= ~0x10;			// P3.4 input
			
			// 4)
			UCB0CTL1   &= ~UCSWRST;       	// **Initialize USCI state machine**
			break;
		
		case SPI_CHANNEL_2:

			UCA0CTL1   |= UCSWRST;      	// **Initialize USCI registers**
			UCA0CTL0	= 0xA9;
			UCA0CTL1	= 0x80;
			UCA0BR0		= 0x08;
			UCA0BR1		= 0x00;
			
			P7SEL	   |= 0x0E;
			P7DIR	   |= 0x01;
			P7SEL	   &= ~0x01;
			
			P7DIR	   &= ~0x10;
			
			UCA0CTL1   &= ~UCSWRST;
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
			UCB0CTL1   |= UCSWRST;                     // **Initialize USCI registers**
			
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
			UCB0CTL0	= 0xA1;
			//-------------------------------------------------------------------------
			//-------------------------------------------------------------------------
			//UCA0CTL1 -> Control Register 1
			//   6-7  |   5   |   4   |   3  |   2    |   1   |    0  |
			//---------------------------------------------------------
			//UCSSELx |                  Unused               |UCSWRST|
			//---------------------------------------------------------
			//UCSSELx (USCI clock source select)= 10b ->  SMCLK
			//UCSWRST (Software reset)          = 1b  ->  normally set by a PUC
			UCB0CTL1	= 0x80;                     
			//-------------------------------------------------------------------------
			// DATA RATE
			// Data rate = SMCLK/2 ~= 500kHz
			// UCA0BR1 = 0x00 & UCA0BR0 = 0x02
			//-------------------------------------------------------------------------
			UCB0BR0		= 0x08;                           
			UCB0BR1		= 0x00;
			
			//3) Configure ports <-BEGIN
			P3SEL	   |= 0x0E;				// P3.1,P3.2,P3.3 option select
			P3DIR	   &= ~0x01;			// P3.0 input direction
			P3DIR	   |= 0x10;				// P3.4 output	
			
			// 4)
			UCB0CTL1   &= ~UCSWRST;			// **Initialize USCI state machine**
			break;
			
		case SPI_CHANNEL_2:

			UCA0CTL1   |= UCSWRST;          // **Initialize USCI registers**
			
			UCA0CTL0	= 0xA1;
			UCA0CTL1	= 0x80;                     
			UCA0BR0		= 0x08;                           
			UCA0BR1		= 0x00;
			P7SEL	   |= 0x0E;				// P3.1,P3.2,P3.3 option select
			P7DIR	   &= ~0x01;			// P3.0 input direction
			P7DIR	   |= 0x10;				// P3.4 output	
			
			UCA0CTL1   &= ~UCSWRST;			// **Initialize USCI state machine**
			break;
			
		default:
			return false;
	}
	
	return true;
}

///////////////////////////////////////////////

// returns whether or not this was successful
bool initialize_SPI(SPI_Device* device)
{
	
	if (device->type == SPI_TYPE_Master)
	{
		return initialize_SPI_master(device->channel);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		return initialize_SPI_slave(device->channel);
	}
	
	return false;

}

///////////////////////////////////////////////

void SPI_transmit(SPI_Device* device, const Byte data)
{
	device->transmitMessage = data;
	
	if (device->type == SPI_TYPE_Master)
	{
		setDigitalOutput(device->chipSelect.out);
		int waitTimer;
		
		switch(device->channel)
		{
			case SPI_CHANNEL_1:
				UCB0CTL1	|= UCSWRST;
				UCB0CTL1	&= ~UCSWRST;								// software reset
				P3OUT		&= ~0x01;									// slave enable
				while ((UC0IFG & UCB0TXIFG) == 0);						// wait while not ready for TX
				IFG2		&= ~UCB0RXIFG;
				UCB0TXBUF	 = device->transmitMessage;					// write
				while ((UC0IFG & UCB0RXIFG) == 0);						// wait for RX buffer (full)
				device->receiveMessage = (UCB0RXBUF);
				for (waitTimer = 20000; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
				P3OUT		|= 0x01;									// set STE high for slave disable
				break;
				
			case SPI_CHANNEL_2:
				UCA0CTL1	|= UCSWRST;
				UCA0CTL1	&= ~UCSWRST;								// software reset
				P7OUT		&= ~0x01;									// slave enable
				while ((UC0IFG & UCA0TXIFG) == 0);						// wait while not ready for TX
				IFG2		&= ~UCA0RXIFG;
				UCA0TXBUF	 = device->transmitMessage;					// write
				while ((UC0IFG & UCA0RXIFG) == 0);						// wait for RX buffer (full)
				device->receiveMessage = (UCA0RXBUF);
				for (waitTimer = 20000; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
				P7OUT		|= 0x01;									// set STE high for slave disable
				break;
				
			default:
				device->receiveMessage = DUMMY_CHAR;
		}
	
		clearDigitalOutput(device->chipSelect.out);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		while(!device->chipSelect.in->state) {;}			// wait for enable

		switch(device->channel)
		{
			case SPI_CHANNEL_1:
				UCB0CTL1	|= UCSWRST;
				UCB0CTL1	&= ~UCSWRST;				// software reset
				IFG2		&= ~UCB0RXIFG;
				UCB0TXBUF	 = device->transmitMessage;	// write
				while ((UC0IFG & UCB0RXIFG) == 0);		// wait for RX buffer (full)
				device->receiveMessage = (UCB0RXBUF);
				break;
				
			case SPI_CHANNEL_2:
				UCA0CTL1	|= UCSWRST;
				UCA0CTL1	&= ~UCSWRST;				// software reset
				IFG2		&= ~UCA0RXIFG;
				UCA0TXBUF	 = device->transmitMessage;	// write
				while ((UC0IFG & UCA0RXIFG) == 0);		// wait for RX buffer (full)
				device->receiveMessage = (UCA0RXBUF);
				break;
				
			default:
				device->receiveMessage = DUMMY_CHAR;
		}
	}
	
}

///////////////////////////////////////////////

void SPI_receive(SPI_Device* device)
{
	
	device->receiveMessage = DUMMY_CHAR;
	
	if (device->type == SPI_TYPE_Master)
	{
		SPI_transmit(device, DUMMY_CHAR);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		int timeout = 0;
		
		if (device->channel == SPI_CHANNEL_1)
		{
			UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;
		  	UCB0TXBUF = DUMMY_CHAR;
		  	
		  	while(device->chipSelect.in->state == low)		// wait for chip select
		  	{
		  		readDigitalInput(device->chipSelect.in);
		  		timeout++;
		  		if (timeout > 10000) return;
		  	}
		  	
		  	while((P3IN & 0x01) == 0x01)					// wait for slave transmit enable
		  	{
		  		timeout++;
		  		if (timeout > 10000) return;
		  	}
		  	
		  	bool enabled = ((P3IN | 0xFE) == 0xFE);
			if (enabled)
			{
				
				while ((UC0IFG & UCB0RXIFG) == 0)			// wait for RX buffer (full)
				{
					timeout++;
		  			if (timeout > 10000) return;
				}
				char buff = UCB0RXBUF;
				device->receiveMessage = buff;
			}
		}
		else if (device->channel == SPI_CHANNEL_2)
		{
			UCA0CTL1 |= UCSWRST;
			UCA0CTL1 &= ~UCSWRST;
		  	UCA0TXBUF = DUMMY_CHAR;
		  	while(device->chipSelect.in->state == low);		// wait for chip select
		  	while((P7IN & 0x01) == 0x01);					// wait for slave transmit enable
		  	bool enabled = ((P7IN | 0xFE) == 0xFE);
			if (enabled)
			{
				while ((UC0IFG & UCA0RXIFG) == 0);			// wait for RX buffer (full)
				char buff = UCA0RXBUF;
				device->receiveMessage = buff;
			}
		}
	}
}



