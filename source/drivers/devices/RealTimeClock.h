//////////////////////////////////////////////////////////////////
//                                                              //
//    Real time clock header                                  	//
//    last edited by: Kane Anderson                             //
//    date: January 10, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef REALTIMECLOCK_H
#define REALTIMECLOCK_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"
#include "SPIDevice.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	SPIDevice* SPI;
	
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
