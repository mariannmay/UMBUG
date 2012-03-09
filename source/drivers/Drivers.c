//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers main file                                         //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Drivers.h"

// initialize devices ////////////////////////////////////////////
AllDevices devices;

//////////////////////////////////////////////////////////////////

void drivers_initialize(void)
{
	// system watchdog
		/*
		// sets 10.6 direction to 'output'
		P10DIR |= BIT6;
		devices.systemWatchdog.WDI->port = P10OUT;
		devices.systemWatchdog.WDI->pin = 5;
		devices.systemWatchdog.WDI->state = low;
		*/
		
	// system clock
	
	//Processor Specific
	#if COMPROCESSOR
		P10DIR 
	#elseif CDHPROCESSOR
	
	#endif
		
}

void drivers_update(void)
{
	// TODO
}
