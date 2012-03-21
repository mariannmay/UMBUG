//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "System.h"

Time_ms systemTimer;

//////////////////////////////////////////////////////////////////

void system_initialize(void)
{
	systemTimer = 0;
	drivers_initialize();
	StopMSP430WatchdogTimer;
	
	#if DebugMode
		test_application_initialize();
	#else
		application_initialize();
	#endif
	
	initializeConsole();

}

//////////////////////////////////////////////////////////////////

// 	main has an infinite loop which calls this function every time
void system_main(void)
{
	
	// upkeep items
	drivers_readInputs();
	
	systemTimer += realTimeClock_timeSinceLastCheck(&(devices.systemClock));
	if (systemTimer >= OneSecond)
	{
		toggleStatusLED();
		systemTimer = 0;
	}

	kickTheDog(&(devices.systemWatchdog));
	
	// run the program
	#if DebugMode
		test_application_main();
	#else
		application_main();
	#endif
	
	drivers_setOutputs();
	
	runConsole();
	
}

//////////////////////////////////////////////////////////////////

void system_abort(void)
{
	// infinite loop
	for(;;)	{ }
}

//////////////////////////////////////////////////////////////////

void toggleStatusLED(void)
{

	switch (devices.systemStatusLED->state)
	{
		 case low	:	devices.systemStatusLED->state = high; break;
		 case high	:	devices.systemStatusLED->state = low; break;
		 default	:	; // do nothing
						
	}
	
}



