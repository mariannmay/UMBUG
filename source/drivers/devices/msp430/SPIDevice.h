//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice header                                        	//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SPIDEVICE_H
#define SPIDEVICE_H

#include "../../DriversConfig.h"
#include "./sdCardLibrary/MMC_lib/hal_SPI.h"

///////////////////////////////////////////////

// structures /////////////////////////////////

typedef struct
{
	Byte data[8];
}
SPIMessage;

typedef struct
{
	SerialInput*	clock;
	SerialInput*	slaveOutMasterIn;
	SerialOutput*	slaveInMasterOut;
	
	SPIMessage		transmitMessage;
	SPIMessage		receivedMessage;
}
SPIModule_3Pin;

typedef struct
{
	SPIModule_3Pin*		bus;
	DigitalOutput*		enable;
}
SPIDevice;

// functions ///// these come from the library 

void initialize_SPI(void);
void SPI_transmit(unsigned char* bufferedData, unsigned int size);
void SPI_receive(unsigned char* bufferedData, unsigned int size);

#endif


