//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "System.h"

// TODO REMOVE
#include <stdio.h>

Time_ms systemTimer;

//////////////////////////////////////////////////////////////////
void system_initialize(void)
{
	
	drivers_initialize();
	StopMSP430WatchdogTimer;
	
	#if DebugMode
		test_application_initialize();
	#else
		application_initialize();
	#endif

}

// 	main has an infinite loop which calls this function every time
void system_main(void)
{
	// upkeep items
	systemTimer += realTimeClock_timeSinceLastCheck(&(devices.systemClock));
//	if (systemTimer >= WatchdogKickTimeInterval)
//	{
		kickTheDog(&(devices.systemWatchdog));
//	}
//	if (systemTimer >= OneSecond)
//	{
		realTimeClock_reset(&(devices.systemClock));
		ToggleStatusLED;
//	}
	
	// TODO REMOVE debug only
	//printf("WDI: %d\r\n", temp);
	//fflush(stdout);
	
	// run the program
	#if DebugMode
		test_application_main();
	#else
		application_main();
	#endif
}

void system_abort(void)
{
	for(;;)
	{
		; // do nothing
	}
}


