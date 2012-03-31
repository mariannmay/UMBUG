//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice header                                        	//
//    last edited by: Craig Nemeth                              //
//    date: March 10, 2012                                      //
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

void initialize_SPI(int master);
void SPI_transmit(char data);
void SPI_receive(char* data);
void SPI_EEPROM_readbyte(char* data, int address);

#endif
