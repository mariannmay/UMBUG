//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Kane Anderson                             //
//    date: March 6, 2012       	                            //
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
#include "../drivers/devices/Spectrometer.h"


// a struct containing all of the system's devices ///////////////
typedef struct
{
	Watchdog		systemWatchdog;
	RealTimeClock	systemClock;
	DigitalOutput*	systemStatusLED;
	Spectrometer	spectrometer1;
	Spectrometer	spectrometer2;
}
AllDevices;

extern AllDevices devices;

//////////////////////////////////////////////////////////////////

void drivers_initialize(void);
void drivers_readInputs(void);
void drivers_setOutputs(void);

#endif
