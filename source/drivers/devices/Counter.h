//////////////////////////////////////////////////////////////////
//                                                              //
//    Counter header                                        	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COUNTER_H
#define COUNTER_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	DigitalInput enable;
	DigitalOutput count0;
	DigitalOutput count1;
	DigitalOutput count2;
	DigitalOutput count3;
}
Counter;

// functions //////////////////////////////////

void counter_initialize(void);
void startCount(Counter* counter);
void resetCount(Counter* counter);

#endif
