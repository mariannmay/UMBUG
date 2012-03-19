//////////////////////////////////////////////////////////////////
//                                                              //
//    Watchdog source                                        	//
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012        								//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Watchdog.h"

// functions //////////////////////////////////

void watchdog_initialize(Watchdog* watchdog)
{
	//
}

void kickTheDog(Watchdog* watchdog)
{

	switch (watchdog->WDI->state)
	{
		 case low	:	watchdog->WDI->state = high;
						break;
		 
		 case high	:	watchdog->WDI->state = low;
						break;
		 
		 default	:	; // do nothing
						
	}
	
}


