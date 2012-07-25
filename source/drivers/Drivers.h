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
	DigitalOutput*	systemStatusLED;
	//Battery			mainBattery;
	Thermocouple	testThermocouple;
	
	
	AnalogInput*	test_AtoD;
	SPI_Device		test_SPI_device;
}
AllDevices;
#else
typedef struct
{
	Watchdog		systemWatchdog;
	RealTimeClock	realTimeClock;
	DigitalOutput*	systemStatusLED;
	//Battery			mainBattery;
	Thermocouple	testThermocouple;
	Radio			radio;
	SDCard			sdCard;
	
	
	AnalogInput*	test_AtoD;
	AnalogOutput*	testPSK;
	SPI_Device		test_SPI_device;
}
AllDevices;
#endif

extern AllDevices devices;

//////////////////////////////////////////////////////////////////

void drivers_initialize(void);

#endif
