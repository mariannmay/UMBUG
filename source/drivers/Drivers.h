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
#include "../drivers/devices/Battery.h"
#include "../drivers/devices/Counter.h"
#include "../drivers/devices/Multiplexer.h"
#include "../drivers/devices/RealTimeClock.h"
#include "../drivers/devices/SDCard.h"
#include "../drivers/devices/Thermocouple.h"
#include "../drivers/devices/Watchdog.h"
#include "../drivers/devices/Radio.h"


// a struct containing all of the system's devices ///////////////
#if CDH_PROCESSOR_COMPILE
	typedef struct
	{
		Watchdog		systemWatchdog;
		RealTimeClock	realTimeClock;
		SPI_Device		COM_Processor;	
		DigitalOutput*	systemStatusLED;
		Thermocouple	tardigradeTemperatureSensor;
	}
	AllDevices;
#else
	typedef struct
	{
		Watchdog		systemWatchdog;
		RealTimeClock	realTimeClock;
		SPI_Device		CDH_Processor;
		DigitalOutput*	systemStatusLED;
		Thermocouple	tardigradeTemperatureSensor;
		Radio			radio;
		SDCard			sdCard;
	}
	AllDevices;
#endif

extern AllDevices devices;


//////////////////////////////////////////////////////////////////

void drivers_initialize(void);

#endif
