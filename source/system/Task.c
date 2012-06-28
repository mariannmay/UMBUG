#include "Task.h"
#include "TimeCounter.h"
#include "TestFunctions.h"
#include "../drivers/devices/msp430/TimerB.h"
/*Array of tasks... this is jsut for test purposes as of now.  Might use a linked list structure for easier processing later on
 */
GroundCommandTask tasks[3];
int taskIndex = 0;

int* previous_SP;
unsigned short oldpc;
void initGroundCommandTask(GroundCommandTask *t, int (*pt2Func)(), int timeout/*, TimeCounter *schedTime, TimeCounter *duration*/)
{
	
	t->func = pt2Func;
	t->timeout = timeout;
	/*t->scheduledTime = *schedTime;
	t->duration = *duration;
	*/
}

int performGroundCommandTask(GroundCommandTask *t){
	
	return t->func();
	
}

	

/*
 * Deprecated, should be applying to a list of tasks.
 */
 /*
void performCurrentTask()
{
	//setTimerB(tasks[taskIndex].timeout);

	
	int result = performGroundCommandTask(&(tasks[taskIndex]));

	cancelTimer();
	taskIndex = (taskIndex + 1)%3;
	
	
	
	
	printf("Result: %d\n",result);
}

*/


