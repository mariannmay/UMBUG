//////////////////////////////////////////////////////////////////
//                                                              //
//    Watchdog header                                        	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef WATCHDOG_H
#define WATCHDOG_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	DigitalInput something;
	DigitalOutput something2;
}
Watchdog;

// functions //////////////////////////////////

void watchdog_initialize(void);
void kickTheDog(Watchdog* watchdog);

#endif
