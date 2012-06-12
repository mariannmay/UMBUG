//////////////////////////////////////////////////////////////////
//                                                              //
//    System source                                             //
//    last edited by: Kane Anderson                             //
//    date: April 30, 2012                                   	//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "System.h"
#include "../drivers/devices/msp430/TimerA.h"
#include <stdio.h>

Time_ms systemTimer;

//////////////////////////////////////////////////////////////////

void system_initialize(void)
{
	
	systemTimer = 0;
	
	drivers_initialize();
	
	StopMSP430WatchdogTimer;
	//initializeLogFile();
	initTimerA();
	//enableInterrupts();
	/*
	#if DebugMode
		test_application_initialize();
	#else
		application_initialize();
	#endif
	*/
	
}

//////////////////////////////////////////////////////////////////

// 	main has an infinite loop which calls this function every time
void system_main(void)
{	
	// run the program
	#if DebugMode
		logLine("== DEBUG MODE ==\r\n");
		test_application_main();
	#else
		logLine("== REGULAR OPERATION ==\r\n");
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

void enableInterrupts(void)
{

	__bis_SR_register(GIE);
	
}

void disableInterrupts(void)
{
	
	__bic_SR_register(GIE);
	
}
