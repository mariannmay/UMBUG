//////////////////////////////////////////////////////////////////
//                                                              //
//    Watchdog source                                        	//
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012        								//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Watchdog.h"


// TODO REMOVE
#include <stdio.h>


// functions //////////////////////////////////

void watchdog_initialize(Watchdog* watchdog)
{
	//
}

void kickTheDog(Watchdog* watchdog)
{
	// toggle between high and low
	char oldState = watchdog->WDI->state;
	
	// TODO REMOVE (debug)
	printf("\r\n");
	printf("in kickTheDog's start, oldState is ");
	fflush(stdout);
	
	
	switch (oldState)
	{
		 case low	:	printf("0\r\n");
						fflush(stdout);
						setDigitalOutput(watchdog->WDI);
						break;
		 
		 case high	:	printf("1\r\n");
						fflush(stdout);
						clearDigitalOutput(watchdog->WDI);
						break;
		 
		 default	:	printf("WRONG!\r\n");
						fflush(stdout);
						clearDigitalOutput(watchdog->WDI);
	}
	
	// TODO REMOVE (debug)
	char newState = watchdog->WDI->state;
	printf("in kickTheDog's end, newState is %x\r\n", newState);
	fflush(stdout);
}


