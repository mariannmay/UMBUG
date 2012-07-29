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

#include "system/Task.h"
#include "system/TestFunctions.h"
#include "system/System.h"
#include "system/TaskList.h"
#include "system/TimeCounter.h"


extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////
TaskList tl0;

/*
 * a simple duration value.
 */
ShortDuration duration_1S;
extern TimeCounter currentTime;
void main(void)
{
	//system_initialize();
	WDTCTL = WDTPW | WDTHOLD;	
	printf("Start\n");
	
	//initTimerA();
	//enableInterrupts();
	initTimeCounter(&currentTime);
	initTaskList(&tl0);
	initShortDuration(&duration_1S,1000);
	//initialize_SPI(1);//1 for master
	//initTestTasks();
	bool dumb = addToTaskList(&tl0,&testFunction2,&duration_1S,6);
	printf("test\n");
	int i;
	for(i=0;i<8;i++)
		{
		printf("Loading Function %d\n",tl0.numTasks);
		bool d = addToTaskList(&tl0,&testFunction1,&duration_1S,6);
		}
		
	
	initTimerA();
	//initTimerB();
  	enableInterrupts();//__bis_SR_register(GIE);           // Enable interrupts
	//WDTCTL = WDTPW + WDTHOLD;	

	
	//__bis_SR_register(GIE);
	for(;;)
	{
		
		performCurrentTask(&tl0);
		
		//printf("Thunderlizards\n");
	}
	
}
