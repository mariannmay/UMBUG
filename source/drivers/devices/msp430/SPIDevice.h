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

#ifndef DUMMY_CHAR
#define DUMMY_CHAR 			0xFF
#endif

#define SPI_TX_READY		(UC0IFG & UCB0TXIFG)
#define SPI_TX_DONE			(UCB0STAT & UCBUSY)
#define SPI_RX_READY		(UC0IFG & UCB0RXIFG)

///////////////////////////////////////////////

// structures /////////////////////////////////

typedef struct
{
	Byte 					data;
}
SPIMessage;

typedef struct
{
	SerialOutput*			clock;
	SerialInput*			serialInput;
	SerialOutput*			serialOutput;
	SerialOutput*			slaveTransmitEnable;
	
	SPIMessage				transmitMessage;
	SPIMessage				receiveMessage;
}
SPIModule_4Pin_master;

typedef struct
{
	SerialInput*			clock;
	SerialInput*			serialInput;
	SerialOutput*			serialOutput;
	SerialInput*			transmitEnable;		// active low
	
	SPIMessage				transmitMessage;
	SPIMessage				receiveMessage;
}
SPIModule_4Pin_slave;

typedef struct
{
	SPIModule_4Pin_master*	bus;
	DigitalOutput*			enable;
}
SPI_Slave;

// functions //////////////////////////////////

void initialize_SPI(bool spiMaster);
Byte SPI_transmit(const Byte data);
void SPI_receive(Byte* data);

#endif


