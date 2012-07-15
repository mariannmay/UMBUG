//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "CDHApplication.h"

void CDH_application_main(void)
{
	// TODO: This will be where the scheduler is started, and before that, the timer to 
	
	// TODO: make a mock-up schedule along with its datastructure.
	//       - don't forget about function pointers. Those will be important.
	// TODO: start the hardware interrupt timer for the next thing that needs to run from scheduler
	//       - use CommandTimerFacade's setTimer() command.
	//       - also use LimitTimerFacade's setTimer() command to set the time limit for the current command (send ground an error if we go over the limit).
	
	logLine("CDH scheduler initialized");
	
	CDHMainScheduleLoop();
}

void CDHMainScheduleLoop(void)
{
	// TODO: write the always-running loop here which gathers and runs commands from the ground and gets interrupted by the schedule.
	//       - make a data structure which holds commands (Maybe function pointers and parameters somehow? Maybe just packets which will be parsed later?)
	
	//testing ADC stuff
	
	//int adcreading = 0;
		
	for(;;)
	{
		kickTheDog(&devices.systemWatchdog);
		
		// read the current time (second precision)
		realTimeClock_update(&devices.realTimeClock);
		
		bool oneSecondHasPassed = (devices.realTimeClock.currentTime.seconds > systemTime.seconds);
		bool oneMinuteHasPassed = (devices.realTimeClock.currentTime.minutes > systemTime.minutes);
		bool oneHourHasPassed	= (devices.realTimeClock.currentTime.hours   > systemTime.hours);
		bool oneDayHasPassed	= (devices.realTimeClock.currentTime.date    > systemTime.date);
		
		if (oneSecondHasPassed)
		{
			systemTime.seconds	= devices.realTimeClock.currentTime.seconds;
			
			toggleStatusLED();
		}
		if (oneMinuteHasPassed)
		{
			systemTime.minutes	= devices.realTimeClock.currentTime.minutes;
			
		}
		if (oneHourHasPassed)
		{
			systemTime.hours	= devices.realTimeClock.currentTime.hours;
			
		}
		if (oneDayHasPassed)
		{
			systemTime.date		= devices.realTimeClock.currentTime.date;
			systemTime.month	= devices.realTimeClock.currentTime.month;
			systemTime.year		= devices.realTimeClock.currentTime.year;
			
		}
		
	
		//Freeze, criminal! >:|
		
		//List of function pointers:
		//float (*pt3Func)(float, float); // TODO: something like this...http://www.newty.de/fpt/intro.html
		// TODO: List of time limits for those functions:
		// TODO: List of time between those functions:
		
		//TODO: set time-out timer (limittimerfacade)
		//TODO: start next process in the list (make a list first of function pointers)
		//pt2Func(a, b); // TODO: Something like this...http://www.newty.de/fpt/intro.html
		
	}
	
}
