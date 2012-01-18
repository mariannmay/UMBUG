//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
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
	StopMSP430WatchdogTimer;
	
	realTimeClock_initialize(&systemClock);
	watchdog_initialize(&systemWatchdog);
	
	application_initialize();
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
	
	application_main();
}


