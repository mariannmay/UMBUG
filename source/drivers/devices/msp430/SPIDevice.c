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
		if (device->activeHigh) clearDigitalOutput(device->chipSelect.out);
		else setDigitalOutput(device->chipSelect.out);
		return initialize_SPI_master(device->channel);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		return initialize_SPI_slave(device->channel);
	}
	
	return false;

}

///////////////////////////////////////////////

// Utility functions

void SPI_reset(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:	UCB0CTL1 |= UCSWRST; UCB0CTL1 &= ~UCSWRST; break;
		case SPI_CHANNEL_2:	UCA0CTL1 |= UCSWRST; UCA0CTL1 &= ~UCSWRST; break;
		default			  :	return;
	}
}

void SPI_slaveDisable(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:	P3OUT |= 0x01; break;					// set STE high for slave disable
		case SPI_CHANNEL_2:	P7OUT |= 0x01; break;					// set STE high for slave disable
		default			  :	return;
	}
}

void SPI_slaveEnable(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:	P3OUT &= ~0x01; break;					// set STE low for slave enable
		case SPI_CHANNEL_2:	P7OUT &= ~0x01; break;					// set STE low for slave enable
		default			  :	return;
	}
}

void SPI_clearInterruptFlag(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:	IFG2 &= ~UCB0RXIFG; break;
		case SPI_CHANNEL_2:	IFG2 &= ~UCA0RXIFG; break;
		default			  :	return;
	}
}

void SPI_WRITE(SPI_CHANNEL channel, Byte byte)
{
	switch (channel)
	{
		case SPI_CHANNEL_1:
			while ((UC0IFG & UCB0TXIFG) == 0);						// wait while not ready for TX
			SPI_clearInterruptFlag(channel);
			UCB0TXBUF	 = byte;									// write
			while ((UC0IFG & UCB0RXIFG) == 0);						// wait for RX buffer (full)
			break;
			
		case SPI_CHANNEL_2:
			while ((UC0IFG & UCA0TXIFG) == 0);						// wait while not ready for TX
			SPI_clearInterruptFlag(channel);
			UCA0TXBUF	 = byte;									// write
			while ((UC0IFG & UCA0RXIFG) == 0);						// wait for RX buffer (full)
			break;
		
		default:
			return;
	}
}

Byte SPI_READ(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1: return (UCB0RXBUF);
		case SPI_CHANNEL_2: return (UCA0RXBUF);
		default:			return DUMMY_CHAR;
	}
}

void SPI_setDummyOutput(SPI_CHANNEL channel)
{
	switch (channel)
	{
		case SPI_CHANNEL_1: UCB0TXBUF = DUMMY_CHAR;
		case SPI_CHANNEL_2: UCA0TXBUF = DUMMY_CHAR;
		default:			return;
	}
}

///////////////////////////////////////////////

void SPI_transmit(SPI_Device* device, const Byte data)
{
	device->transmitMessage[0] = data;
	
	if (device->type == SPI_TYPE_Master)
	{
		if (device->activeHigh == true) setDigitalOutput(device->chipSelect.out);
		else clearDigitalOutput(device->chipSelect.out);
		
		SPI_reset(device->channel);
		SPI_slaveEnable(device->channel);
		SPI_WRITE(device->channel, device->transmitMessage[0]);
		device->receiveMessage[0] = SPI_READ(device->channel);
		int waitTimer;
		for (waitTimer = 256; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
		SPI_slaveDisable(device->channel);
		
		if (device->activeHigh == true) clearDigitalOutput(device->chipSelect.out);
		else setDigitalOutput(device->chipSelect.out);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		int timeout = 0;
		while(!device->chipSelect.in->state)				// wait for enable
		{
			if (timeout++ > 10000) return;
		}
		SPI_reset(device->channel);
		SPI_clearInterruptFlag(device->channel);
		SPI_WRITE(device->channel, device->transmitMessage[0]);
		device->receiveMessage[0] = SPI_READ(device->channel);
		int waitTimer;
		for (waitTimer = 256; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
	}
}

///////////////////////////////////////////////

void SPI_receive(SPI_Device* device)
{
	device->receiveMessage[0] = DUMMY_CHAR;
	
	if (device->type == SPI_TYPE_Master)
	{
		SPI_transmit(device, DUMMY_CHAR);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		int timeout = 0;
		SPI_reset(device->channel);
		SPI_setDummyOutput(device->channel);
		while(device->chipSelect.in->state == low)		// wait for chip select
	  	{
	  		readDigitalInput(device->chipSelect.in);
	  		if (timeout++ > 10000) return;
	  	}
		
		if (device->channel == SPI_CHANNEL_1)
		{	
		  	while((P3IN & 0x01) == 0x01)					// wait for slave transmit enable
		  	{
		  		if (timeout++ > 10000) return;
		  	}
		  	bool enabled = ((P3IN | 0xFE) == 0xFE);
			if (enabled)
			{
				while ((UC0IFG & UCB0RXIFG) == 0)			// wait for RX buffer (full)
				{
		  			if (timeout++ > 10000) return;
				}
			}
		}
		else if (device->channel == SPI_CHANNEL_2)
		{
		  	while((P7IN & 0x01) == 0x01)					// wait for slave transmit enable
		  	{
		  		if (timeout++ > 10000) return;
		  	}
		  	bool enabled = ((P7IN | 0xFE) == 0xFE);
			if (enabled)
			{
				while ((UC0IFG & UCB0RXIFG) == 0)			// wait for RX buffer (full)
				{
		  			if (timeout++ > 10000) return;
				}
			}
		}
		device->receiveMessage[0] = SPI_READ(device->channel);
	}
}

void SPI_transmitStream(SPI_Device* device, const Byte* data, UI8 length)
{
	if (length > SPI_RX_BUFFER_SIZE || length > SPI_TX_BUFFER_SIZE) return;	// error
	
	if (device->type == SPI_TYPE_Master)
	{
		if (device->activeHigh == true) setDigitalOutput(device->chipSelect.out);
		else clearDigitalOutput(device->chipSelect.out);
		
		SPI_slaveEnable(device->channel);
		int index;
		for (index = 0; index < length; index++)
		{
			SPI_reset(device->channel);
			device->transmitMessage[index] = data[index];
			SPI_WRITE(device->channel, device->transmitMessage[index]);
			device->receiveMessage[index] = SPI_READ(device->channel);
			int waitTimer;
			for (waitTimer = 256; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
		}
		SPI_slaveDisable(device->channel);
		
		if (device->activeHigh == true) clearDigitalOutput(device->chipSelect.out);
		else setDigitalOutput(device->chipSelect.out);
	}
	else if (device->type == SPI_TYPE_Slave)
	{
		int timeout = 0;
		while(!device->chipSelect.in->state)					// slave must wait for enable
		{
			if (timeout++ > 10000) return;
		}
		int index;
		for (index = 0; index < length; index++)
		{
			SPI_reset(device->channel);
			SPI_clearInterruptFlag(device->channel);
			device->transmitMessage[index] = data[index];
			SPI_WRITE(device->channel, device->transmitMessage[index]);
			device->receiveMessage[index] = SPI_READ(device->channel);
			int waitTimer;
			for (waitTimer = 256; waitTimer > 0; waitTimer--){ ; }	// just a time killing loop
		}
	}
}



