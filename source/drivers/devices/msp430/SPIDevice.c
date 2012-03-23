//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice source                                        	//
//    last edited by: Craig Nemeth                              //
//    date: March 10, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

//I am using the 'B0' USCI module

#include "SPIDevice.h"

//opcodes for EEPROM
#define WREN  6
#define WRDI  4
#define RDSR  5
#define WRSR  1
#define READ  3
#define WRITE 2

// functions //////////////////////////////////

void initialize_SPI(int master)
{
	
	//set the UCSWRST pin in UCB0CTL1 register initializing all USCI registers
	UCB0CTL1 |= 0x01;
	
	//set bit rate control registers
	UCB0BR0 = 0xFF;
	UCB0BR1 = 0xFF;
	
	if(master)
	{
		//initialize as master
		
		//set pin directions
		// port 3 = xxxx 1011
		// P3.0 slave transmit enable is output (pin 71)
		// P3.1 slave in master out is output (pin 70)
		// P3.2 slave out master in input (pin 69)
		// P3.3 synchronizing master clock is output (pin 68)
 		P3DIR |= 0x0B;
 		P3DIR &= 0xFB;
 		
 		//set slave select high for EEPROM
 		P3OUT |= 0x01;
	}else
	{
		//initialize as slave
		
		//set pin directions
		// port 3 = xxxx 0100
		// P3.0 slave transmit enable is input (pin 71)
		// P3.1 slave in master out is input (pin 70)
		// P3.2 slave out master in output (pin 69)
		// P3.3 synchronizing master clock is input (pin 68)
		// the upper bits are GPIO that shouldnt be altered... will fix soon
 		P3DIR |= 0x04;
 		P3DIR &= 0xFB;
	}
	
	//reset the UCSWRST pin in regoster UCB0CTL1 to enable SPI usage
	UCB0CTL1 &= 0xFE;
	
	//interrupt enables in IE2 register (optional)
	//UCB0RXIE pin = 1;
	//UCB0TXIE pin = 1;
	IE2 |= 0x0C; // 0000 1100
}

//Transmition and reception occur simultaneoulsy so dummy reads and sends are used

void SPI_transmit(char data)
{	
	//load tx buffer with data and it will be transfered by hardware
	UCB0TXBUF = data;
	
	while(!UCB0TXIFG)
	{
		//wait for the TX buffer to move to shift register
	}
	//printf("sent TX buffer to register");
	//fflush(stdout);
	
	//dummy read
	data = UCB0RXBUF;
	
	while(!UCB0RXIFG)
	{
		//wait for data transfer to finish
	}
	//UCB0RXIFG &= 0x00;
}

void SPI_receive(char* data)
{
	//dummy write
	UCB0TXBUF = 0xFF;
	
	while(!UCB0TXIFG)
	{
		//wait for the TX buffer to move to shift register
	}
	
	//read from the recieve buffer
	*data = UCB0RXBUF;
	
	while(!UCB0RXIFG)
	{
		//wait for data transfer to finish
	}
	//UCB0RXIFG &= 0x00;
}

//testing
/*
 * on EEPROM
 * pin 1 is select
 * pin 6 is clk
 * pin 2 is datain
 * pin 5 is data out
 */
 
 void SPI_EEPROM_readbyte(char* data, int address)
 {
 	//EEPROM read
	P3OUT &= 0xFE; //set slave select low (select device)
	
	SPI_transmit(0x06); //send read opcode
	
	SPI_transmit(address>>8); //send address
	SPI_transmit(address);
	
	SPI_receive(data);
	
	P3OUT |= 0x01;//set slave select high
 	
 }
 
