//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef DRIVERS_H
#define DRIVERS_H

#include "./DriversConfig.h"

// here we should put all devices
#include "../drivers/devices/Counter.h"
#include "../drivers/devices/Multiplexer.h"
#include "../drivers/devices/RealTimeClock.h"
#include "../drivers/devices/SDCard.h"
#include "../drivers/devices/Thermocouple.h"
#include "../drivers/devices/Watchdog.h"


// a struct containing all of the system's devices ///////////////
typedef struct
{
	Watchdog								systemWatchdog;
	RealTimeClock							systemClock;
	DigitalOutput*							systemStatusLED;
	SPIModule_3Pin							spiBus;
	SDCard									sdCard;
	MultiplexerSelectLines					multiplexerSelectLines;
	DigitalMultiplexer_8_1_Inputs			digitalInputMUX0;
	DigitalMultiplexer_8_1_Inputs			digitalInputMUX1;
	DigitalMultiplexer_8_1_Inputs			digitalInputMUX2;
	AnalogMultiplexer_8_1_Inputs			analogInputMUX0;
	AnalogMultiplexer_8_1_Inputs			analogInputMUX1;
	AnalogMultiplexer_8_1_Inputs			analogInputMUX2;
	DigitalSoftwareMultiplexer_8_1_Outputs	digitalOutputMUX0;
	DigitalSoftwareMultiplexer_8_1_Outputs	digitalOutputMUX1;
	DigitalSoftwareMultiplexer_8_1_Outputs	digitalOutputMUX2;
	
	Thermocouple							testThermocouple;
}
AllDevices;

extern AllDevices devices;

//////////////////////////////////////////////////////////////////

void drivers_initialize(void);
void drivers_readInputs(void);
void drivers_setOutputs(void);

#endif
