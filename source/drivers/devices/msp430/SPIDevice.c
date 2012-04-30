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

//1 - for master
//0 - for slave
void initialize_SPI(int master)
{	
	// Use the library to setup SPI on port USCIB0
	halSPISetup(master);
}

// Use the library to send the data
void SPI_transmit(unsigned char* bufferedData, unsigned int size)
{	
	spiSendFrame(bufferedData, size);
}

// Use the library to receive the data
void SPI_receive(unsigned char* bufferedData, unsigned int size)
{
	spiReadFrame(bufferedData, size);
}
 
