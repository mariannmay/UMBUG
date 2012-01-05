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

// structure //////////////////////////////////
typedef struct
{
	DigitalInput something;
	DigitalOutput something2;
}
SPIDevice;

// functions //////////////////////////////////

void SPI_initialize(SPIDevice* device);
void transmit(SPIDevice* recipient, char* message);

#endif
