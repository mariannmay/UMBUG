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
	realTimeClock_reset(clock);
	initialize_SPI(&clock->SPI);
	
}

void realTimeClock_update(RealTimeClock* clock)
{
	// TODO
}

void realTimeClock_reset(RealTimeClock* clock)
{
	clock->currentTime.seconds	= 0;
	clock->currentTime.minutes	= 0;
	clock->currentTime.hours	= 0;
	clock->currentTime.date		= 0;
	clock->currentTime.month	= 0;
	clock->currentTime.year		= 0;
	
	clock->alarm0 = clock->currentTime;
	clock->alarm1 = clock->currentTime;
	
}


