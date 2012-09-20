//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                    	//
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include <msp430fg4618.h>
#include <stdio.h>
#include "drivers/devices/msp430/TimerA.h"

#include "system/Task.h"
#include "system/TestFunctions.h"
#include "system/System.h"
#include "system/TaskList.h"
#include "system/TimeCounter.h"
#include "system/TaskListInit.h"

// TODO remove
#include <stdio.h>

extern void system_initialize(void);
extern void system_main(void);



/*
 * a simple duration value.
 */
extern SPI_WRITE(SPI_CHANNEL,UI8);
ShortDuration duration_1S;
extern TimeCounter currentTime;
void main(void)
{
	
	//disableInterrupts();
	
	printf("start of program\r\n");
	fflush(stdout);
	
	system_initialize();
	/*
	init_SCHEEPROM();
	//printf("Start\n");
	UI8 test;
	UI16 killtime = 0;
	for(;;)
	{
		writeByte_SCHEEPROM(0x0000,0x5A);
		test = readByte_SCHEEPROM(0x0000);
		SPI_WRITE(SPI_CHANNEL_2, 0x5A);
		//printf("Read in %d\n",test);
		for(killtime = 0; killtime < 0xFFFF; killtime++);//kill some time
	}
	//initTimerA();
	//enableInterrupts();
	initTimeCounter(&currentTime);
	initTaskList(&t0);
	initShortDuration(&duration_1S,1000);
	//initialize_SPI(1);//1 for master
	//initTestTasks();
	bool dumb = addToTaskList(&t0,&testFunction2,&duration_1S,6);
	printf("test\n");
	int i;
	for(i=0;i<8;i++)
		{
		printf("Loading Function %d\n",t0.numTasks);
		bool d = addToTaskList(&t0,&testFunction1,&duration_1S,6);
		}
		
	
	initTimerA();
	//initTimerB();
  	enableInterrupts();//__bis_SR_register(GIE);           // Enable interrupts
	//WDTCTL = WDTPW + WDTHOLD;	

	
	//__bis_SR_register(GIE);
	for(;;)
	{
		
		performCurrentTask(&t0);
		
		//printf("Thunderlizards\n");
	}
	*/
	
	printf("I am the god of your underpants\r\n");
	fflush(stdout);
	
}
