//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "System.h"

// GLOBAL VARIABLE ///////////////////////////////////////////////
static RealTimeClock systemClock;
static Time_ms systemTimer;
static Watchdog systemWatchdog;

//////////////////////////////////////////////////////////////////
void system_initialize(void)
{
	drivers_initialize();
	
	StopMSP430WatchdogTimer;
	
	realTimeClock_initialize(&systemClock);
	watchdog_initialize(&systemWatchdog);
	
	
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
	drivers_update();
	systemTimer += realTimeClock_timeSinceLastCheck(&systemClock);
	if (systemTimer >= WatchdogKickTimeInterval) kickTheDog(&systemWatchdog);
	if (systemTimer >= OneSecond)
	{
		realTimeClock_reset(&systemClock);
		ToggleStatusLED;
	}
	
	// run the program
	#if DebugMode
		test_application_main();
	#else
		application_main();
	#endif
}


