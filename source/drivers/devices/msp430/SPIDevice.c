//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice source                                        	//
//    last edited by: Craig Nemeth                              //
//    date: March 10, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

//I am using the 'B0' USCI module

#include "SPIDevice.h"

// functions //////////////////////////////////

void initialize_SPI(int master)
{
	if(master)
	{
		//initialize as master
		
		//set the UCSWRST pin in UCB0CTL1 register initializing all USCI registers
		UCB0CTL1 |= 0x01;
		
		//set bit rate control registers
		UCB0BR0 = 0xFF;
		UCB0BR1 = 0xFF;
		
		//set pin directions
		// port 3 = 1111 1011
		// P3.0 slave transmit enable is output (pin 71)
		// P3.1 slave in master out is output (pin 70)
		// P3.2 slave out master in input (pin 69)
		// P3.3 synchronizing master clock is output (pin 68)
		// the upper bits are GPIO that shouldnt be altered... will fix soon
 		P3DIR = 0xFB;
		
		//reset the UCSWRST pin in regoster UCB0CTL1 to enable SPI usage
		UCB0CTL1 = 0;
		
		//interrupt enables in IE2 register (optional)
		//UCB0RXIE pin = 1;
		//UCB0TXIE pin = 1;
		IE2 |= 0x0C; // 0000 1100
	}else
	{
		//initialize as slave
		
		//set the UCSWRST pin in UCB0CTL1 register initializing all USCI registers
		UCB0CTL1 |= 0x01;
		
		//set pin directions
		// port 3 = 1111 0100
		// P3.0 slave transmit enable is input (pin 71)
		// P3.1 slave in master out is input (pin 70)
		// P3.2 slave out master in output (pin 69)
		// P3.3 synchronizing master clock is input (pin 68)
		// the upper bits are GPIO that shouldnt be altered... will fix soon
 		P3DIR = 0xF4;
		
		//reset the UCSWRST pin in regoster UCB0CTL1 to enable SPI usage
		UCB0CTL1 = 0;
		
		//interrupt enables in IE2 register (optional)
		//UCB0RXIE pin = 1;
		//UCB0TXIE pin = 1;
		IE2 |= 0x0C; // 0000 1100
	}
}

//Transmition and reception occur simultaneoulsy so dummy reads and sends are used

void SPI_transmit(char data)
{	
	//load tx buffer with data and it will be transfered by hardware
	UCB0TXBUF = data;
	
	//dummy read
	data = UCB0RXBUF;
}

void SPI_receive(char* data)
{
	//dummy write
	UCB0TXBUF = 0xFF;
	
	//read from the recieve buffer
	*data = UCB0RXBUF;
}
