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

void initialize_SPI(int not_used_yet)
{	
	// Use the library to setup SPI on port USCIB0
	halSPISetup();
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
 
