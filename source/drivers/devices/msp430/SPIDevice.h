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
	Byte data;
}
SPIMessage;

typedef struct
{
	SerialOutput*	clock;
	SerialInput*	serialInput;
	SerialOutput*	serialOutput;
	SerialOutput*	slaveTransmitEnable;
	
	SPIMessage		transmitMessage;
	SPIMessage		receiveMessage;
}
SPIModule_4Pin_master;

typedef struct
{
	SerialInput*	clock;
	SerialInput*	serialInput;
	SerialOutput*	serialOutput;
	SerialInput*	transmitEnable;		// active low
	
	SPIMessage		transmitMessage;
	SPIMessage		receiveMessage;
}
SPIModule_4Pin_slave;

typedef struct
{
	SPIModule_4Pin_master*		bus;
	DigitalOutput*				enable;
}
SPI_Slave;

// functions ///// these come from the library 

void initialize_SPI(bool spiMaster);
void SPI_transmit(unsigned char* bufferedData, unsigned int size);
void SPI_receive(unsigned char* bufferedData, unsigned int size);

#endif


