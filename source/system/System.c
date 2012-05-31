//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: April 30, 2012                                   	//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "System.h"
#include <stdio.h>

Time_ms systemTimer;

//////////////////////////////////////////////////////////////////

void system_initialize(void)
{
	
	systemTimer = 0;
	
	drivers_initialize();
	
	StopMSP430WatchdogTimer;
	initializeLogFile();
	
	#if DebugMode
		test_application_initialize();
	#else
		application_initialize();
	#endif
	
}

//////////////////////////////////////////////////////////////////

// 	main has an infinite loop which calls this function every time
void system_main(void)
{
	// TODO REMOVE
	printf("System main\r\n");
	fflush(stdout);
	
	// run the program
	#if DebugMode
		printf("== DEBUG MODE ==\n");
		test_application_main();
	#else
		printf("== REGULAR OPERATION ==\n");
		application_main();
	#endif
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
		 case low	:	devices.systemStatusLED->state = high;
						setDigitalOutput(devices.systemStatusLED);
						break;
		 case high	:	devices.systemStatusLED->state = low;
						clearDigitalOutput(devices.systemStatusLED);
						break;
		 default	:	; // do nothing
						
	}
	
}



