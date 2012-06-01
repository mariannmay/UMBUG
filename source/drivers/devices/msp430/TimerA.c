//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of timer A			                        //
//    last edited by: Kane Anderson                             //
//    date: May 30, 2012                                    	//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "./TimerA.h"

void initializeTimerA(void)
{
	CCR0 = 32768; 
	TACTL = TASSEL_2 + MC_1;                  // SMCLK, contmode
}

