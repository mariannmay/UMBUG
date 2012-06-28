//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                    	//
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include <msp430fg4619.h>
#include <stdio.h>
#include "drivers/devices/msp430/TimerA.h"
#include "drivers/devices/msp430/TimerB.h"
#include "system/Task.h"
#include "system/TestFunctions.h"
#include "system/System.h"

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

void main(void)
{
	//system_initialize();
	WDTCTL = WDTPW | WDTHOLD;	
	printf("Start\n");	
	initTestTasks();
	
	
	initTimerA();
	initTimerB();
  	enableInterrupts();//__bis_SR_register(GIE);           // Enable interrupts
	//WDTCTL = WDTPW + WDTHOLD;	
	int x = 0;
	int y = x;
	
	//__bis_SR_register(GIE);
	for(;;)
	{
		
		x=y;
		y = x;
		//printf("Thunderlizards\n");
	}
	
}
