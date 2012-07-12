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

Time_ms realTimeClock_timeSinceLastCheck(RealTimeClock* RTC)
{
	Time_ms returnValue = RTC->timeSinceLastCheck;
	RTC->timeSinceLastCheck = 0;
	
	// TODO TEMP UNTIL IT IS FIXED PROPERLY
	returnValue = 1;
	//returnValue = 0;	// actually use this one if you have an RTC
	
	SPI_transmit(&RTC->SPI, DUMMY_CHAR);
	
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


