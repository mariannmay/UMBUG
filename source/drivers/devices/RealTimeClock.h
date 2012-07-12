//////////////////////////////////////////////////////////////////
//                                                              //
//    Real time clock header                                  	//
//    last edited by: Kane Anderson                             //
//    date: January 10, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef REALTIMECLOCK_H
#define REALTIMECLOCK_H

#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	SPI_Device SPI;
	
	Time_ms currentTime;
	Time_ms timeSinceLastCheck;
}
RealTimeClock;

// functions //////////////////////////////////

void realTimeClock_initialize(RealTimeClock* clock);
Time_ms realTimeClock_timeSinceLastCheck(RealTimeClock* clock);
void realTimeClock_update(RealTimeClock* clock);
void realTimeClock_reset(RealTimeClock* clock);

#endif
