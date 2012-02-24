//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice header                                        	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SPIDEVICE_H
#define SPIDEVICE_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"

///////////////////////////////////////////////

// structures /////////////////////////////////
typedef struct
{
	Byte data[8];
}
SPIMessage;

typedef struct
{
	SerialInput_4Pin input;
	
	SPIMessage transmitMessage;
	SPIMessage receivedMessage;
}
SPIDevice;

// functions //////////////////////////////////

void SPI_initialize(SPIDevice* device);
void SPI_transmit(SPIDevice* device);
void SPI_read(SPIDevice* device);

#endif
