//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "CDHApplication.h"
#include <stdio.h>

void CDH_application_main(void)
{
	// TODO: This will be where the scheduler is started, and before that, the timer to 
	
	// TODO: make a mock-up schedule along with its datastructure.
	//       - don't forget about function pointers. Those will be important.
	// TODO: start the hardware interrupt timer for the next thing that needs to run from scheduler
	//       - use CommandTimerFacade's setTimer() command.
	//       - also use LimitTimerFacade's setTimer() command to set the time limit for the current command (send ground an error if we go over the limit).
	CDHMainScheduleLoop();
}

void CDHMainScheduleLoop(void)
{
	// TODO: write the always-running loop here which gathers and runs commands from the ground and gets interrupted by the schedule.
	//       - make a data structure which holds commands (Maybe function pointers and parameters somehow? Maybe just packets which will be parsed later?)
	
	printf("CDH scheduler will now loop indefinitely.\n");
	for(;;)
	{
		//Freeze, criminal! >:|
	}
}
