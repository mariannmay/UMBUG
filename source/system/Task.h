/*
Task.h - representation of a task within the scheduler framework

or something like that

Each structure needs:
-A function pointer (this is the function that will actually get executed)
	-So far it takes no arguments and returns an int.
-A time at which the function is to be executed (this is expressed in: (plain integer, num mS, num nS)?) a uint of highest order anyway.
	this brings up an issue of rollover as well.  We might need to make a custom giganto-int struct if this is the case.
	
-The total amount of time that the function is going to run (in the same units as above)

DEFINITIVE SMALLEST UNIT TO CARE ABOUT IS MILLISECOND.

THE RTC IS IN MILLISECONDS.  no sense doing this to any finer granularity!!!


No IPC required as far as I know as of may 31 2012.

Troy Denton
May 31 2012


Jun 27 2012
Following the KISS principle, decisions have been made to keep the scheduler relatively simple.
IE - no context switching.

Before a task is performed, a write to an EEPROM happens.  A register (one dedicated to each task) is incremented.
When the function returns, the register is decremented.

The key point being, if the function never returned, a residual "fudge up" is left in the non-volatile memory.

If the number of "fudge-ups" exceeds a predetermined value, that function does not get called any more.
*/


#include "../SimpleDefinitions.h"
#include "TimeCounter.h"
#ifndef TASK_H_
#define TASK_H_



#define TASK_INCOMPLETE	0
#define TASK_COMPLETE	1


extern UI16 _TASK_IDS;


typedef struct
{
	int (*func)();
	ShortDuration duration;
	UI8 maxRetries;
	/*
	 * Now using task ID to create fudge register.
	 */
	UI16 TaskID;
	 
} Task;
//extern int* previous_SP;
//extern unsigned short oldpc;
//typedef struct 
//{
//	int (*func)();
//	UI16 timeout;
//	/*TimeCounter scheduledTime;*/
//	/*TimeCunter duration;*/
//	
//}	GroundCommandTask;
//
//typedef struct 
//{
//	int (*func)();
//	/*TimeCounter scheduledTime;*/
//	/*TimeCounter	duration;*/
//	UI8 completed;
//	
//}	RoutineTask;
//
//
//
//void initGroundCommandTask(GroundCommandTask *t, int (*pt2Func)(), int timeout/*, TimeCounter *schedTime, TimeCounter *duration*/);//remove time stuff for now, just test basic functionality.
//void destroyGroundCommandTask(GroundCommandTask *t);
//int performGroundCommandTask(GroundCommandTask *t);

/*
void initRoutineTask(RoutineTask *t, int (*pt2Func)(), TimeCounter *schedTime, TimeCounter *duration);
void destroyRoutineTask(RoutineTask *t);
int performRoutineTask(RoutineTask *t);
*/

//if you want to reschedule a task, create a new task.
//if you want a task to perform a different function, make a new Task.  dont be sloppy.

#endif /*TASK_H_*/

