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

void initialize_SPI_master(void)
{
	
	UCB0CTL0  = 0x00;
	UCB0CTL0 |= UCMST;			// SPI master
	UCB0CTL0 |= UCMODE_1;		// 4-pin SPI with slave tx enable active low
	
	UCB0CTL1  = 0x00 | UCSWRST;	// not ready to work yet
	UCB0CTL1 |= UCSSEL_2;		// use SMCLK as the clock source
	
	UCB0BR0  = 0x02;			// bit rate is SMCLK / 2
	UCB0BR1  = 0x00;			// bit rate is SMCLK / 2
	
	IE2		|= 0x00;			// interrupts disabled... MSP polls them
	
	UCB0CTL1 &= ~UCSWRST;		// now it's ready.
	
}

void initialize_SPI_slave(void)
{
	
	UCB0CTL0  = 0x00;
	UCB0CTL0 |= UCMODE_1;		// 4-pin SPI with slave tx enable active low
	
	UCB0CTL1  = 0x00 | UCSWRST;	// not ready to work yet
	UCB0CTL1 |= UCSSEL_2;		// use SMCLK as the clock source
	
	UCB0BR0   = 0x02;			// bit rate is SMCLK / 2
	UCB0BR1   = 0x00;			// bit rate is SMCLK / 2
	
	IE2		 |= 0x00;			// interrupts disabled... MSP polls themm
	
	UCB0CTL1 &= ~UCSWRST;		// now it's ready.
}

///////////////////////////////////////////////

void initialize_SPI(bool spiMaster)
{
	spiMaster ? initialize_SPI_master() : initialize_SPI_slave();
}

///////////////////////////////////////////////

Byte SPI_transmit(const Byte data)
{
	while (!SPI_TX_READY) ;		// wait
	
	UCB0TXBUF = data;			// send it
	
	while (!SPI_RX_READY) ;		// wait
	
	return UCB0RXBUF;
}

///////////////////////////////////////////////

void SPI_receive(Byte* data)
{   
    *data = SPI_transmit(DUMMY_CHAR);
}



