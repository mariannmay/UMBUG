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

void initialize_SPI_master(void)
{
	// TODO
}

void initialize_SPI_slave(void)
{
	// TODO
}


//1 - for master
//0 - for slave
void initialize_SPI(bool spiMaster)
{
	if (spiMaster)
	{
		initialize_SPI_master();
	}
	else
	{
		initialize_SPI_slave();
	}
}

// Use the library to send the data
void SPI_transmit(unsigned char* bufferedData, unsigned int size)
{	
	// TODO
}

// Use the library to receive the data
void SPI_receive(unsigned char* bufferedData, unsigned int size)
{
	// TODO
}
 
