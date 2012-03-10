//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice header                                        	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SPIDEVICE_H
#define SPIDEVICE_H

#include "../../DriversConfig.h"

///////////////////////////////////////////////

// structures /////////////////////////////////
typedef struct
{
	Byte data[8];
}
SPIMessage;

typedef struct
{
	SPIModule_4Pin SPI;
	
	SPIMessage transmitMessage;
	SPIMessage receivedMessage;
}
SPIDevice;

// functions //////////////////////////////////

void initialize_SPI(void);
void SPI_transmit(SPIDevice* device);
void SPI_read(SPIDevice* device);

#endif
