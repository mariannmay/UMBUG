//////////////////////////////////////////////////////////////////
//                                                              //
//    Real time clock source                                  	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "RealTimeClock.h"

// functions //////////////////////////////////

void realTimeClock_initialize(RealTimeClock* clock)
{
	// TODO
}

Time_ms realTimeClock_timeSinceLastCheck(RealTimeClock* clock)
{
	Time_ms returnValue = clock->timeSinceLastCheck;
	clock->timeSinceLastCheck = 0;
	
	// TODO TEMP UNTIL IT IS FIXED PROPERLY
	returnValue = 1;
	
	
	return returnValue;
}

void realTimeClock_update(RealTimeClock* clock)
{
	// TODO
}

void realTimeClock_reset(RealTimeClock* clock)
{
	// TODO
}


