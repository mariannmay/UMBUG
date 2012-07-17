//////////////////////////////////////////////////////////////////
//                                                              //
//    SPIDevice header                                        	//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SPIDEVICE_H
#define SPIDEVICE_H

// includes ///////////////////////////////////

#include "../../DriversConfig.h"
#include "./sdCardLibrary/MMC_lib/hal_SPI.h"

// definitions ////////////////////////////////

#ifndef DUMMY_CHAR
#define DUMMY_CHAR 				0xFF
#endif

typedef enum
{
	SPI_TYPE_Master				= 0,
	SPI_TYPE_Slave				= 1
}
SPI_TYPE;

typedef enum 
{
    SPI_CHANNEL_1				= 1,
    SPI_CHANNEL_2				= 2
}
SPI_CHANNEL;

#define SPI_TX_READY			(UC0IFG & UCB0TXIFG)
#define SPI_TX_DONE				(UCB0STAT & UCBUSY)
#define SPI_RX_READY			(UC0IFG & UCB0RXIFG)

#define SPI_RX_BUFFER_SIZE		8
#define SPI_TX_BUFFER_SIZE		8

// structures /////////////////////////////////

typedef struct
{
	SPI_TYPE					type;
	SPI_CHANNEL					channel;
		
	Byte						transmitMessage[SPI_TX_BUFFER_SIZE];
	Byte						receiveMessage[SPI_RX_BUFFER_SIZE];
	
	union
	{
		DigitalOutput*			out;
		DigitalInput*			in;
	}
	chipSelect;
}
SPI_Device;

// functions //////////////////////////////////

bool initialize_SPI(SPI_Device* device);		// returns true if OK
void SPI_transmit(SPI_Device* device, const Byte data);
void SPI_transmitStream(SPI_Device* device, const Byte* data, UI8 length);
void SPI_receive(SPI_Device* device);

#endif


