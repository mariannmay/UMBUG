//////////////////////////////////////////
//	Magnetometer Header File			//
//	last edited by: Hossain-Al Masroor	//
//	date: February 1, 2012				//
//										//
//										//
//////////////////////////////////////////

#ifndef MAGNETOMETER_H
#define MAGNETOMETER_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"
#include "./msp430/SPIDevice.h"

///////structures//////////////////////////

typedef struct
{
	//TO DO
	SPI_Slave hardware;
	
}
Magnetometer;

typedef struct
{
	Magnetometer readspistatus;
	Magnetometer readspidata;
	Magnetometer spiwritecommand;
	Magnetometer spiwrite;
	Magnetometer addr;
	Magnetometer byte;


}SPIsetup;

typedef struct
{
	SPIsetup transmit_enable;
	SPIsetup receive;
	SPIsetup send_dummy_command;


}SPImessage;


/////////////methods////////////////////////////

void magnetometerspiInitialize();
void WriteByteSPI();
void ReadByteSPI();

#endif /*MAGNETOMETER_H*/
