#include "TaskList.h"

#include "../SimpleDefinitions.h"
#include "TimeCounter.h"
#include <stdio.h>

/*
 * If i ever catch you playing with this variable I will break your kneecaps -Troy
 */
int __TaskListIDs = 0;
/*
 * Perform the current task in the given list.
 * 
 */


/*
 * the global holding the current time
 */
TimeCounter currentTime;
TimeCounter idleTime;
void performCurrentTask(TaskList* tl)
{
	//setTimerB(tasks[taskIndex].timeout);
	
	//NEED TO WRITE TO THE EEPROM HERE (INCREMENT)
	/*
	 * Calculate Address of "Fudge Register" for the current Task
	 * total 13 bit address.
	 * bis 0-6 (inclusive) represent the index of the task.
	 * bits 7-12 (inclusive) represent the ID of the taskList
	 * 
	 * Therefore, need a 2 byte (16 bit) integer for this.
	 */
	UI16 fudgeRegister = (((tl->ID)<<7)&0x3F80)+(tl->currentTaskIndex&0x007F);
	printf("fudge register: %x\n",fudgeRegister);
	//read in fudge register - value A
	UI8 fudgeVal = 0;
	if (fudgeVal > tl->tasks[tl->currentTaskIndex].maxRetries)
	{
		//skip
		return;	
	}
	
	//increment this value - value B
	//write value B to fudge register
		
	
	//printf("Status register is: %d\n",EEPROM_RESULT);
	TimeCounter snapshot = copy(&currentTime);
	addShortDurationToTimeCounter(&snapshot,&(tl->tasks[tl->currentTaskIndex]).duration);
	int result = tl->tasks[tl->currentTaskIndex].func();		//postincrement,increment after accessing.
	
	
	
	tl->currentTaskIndex = (tl->currentTaskIndex + 1)%tl->numTasks;
	
	//now, write value A back to the fudge register
	
	//kill remaining time.
	
	while(compareTimeCounter(&currentTime,&snapshot) < 1)
	{
		incrementTimeCounter(&idleTime);
	}
	
}

/*
 * Initialize values for a new TaskList
 */
 
void initTaskList(TaskList* tl)
{
	tl->currentTaskIndex = 0;
	tl->numTasks = 0;
	tl->ID = __TaskListIDs++;
}

/*
 * Add a task to the TaskList
 * return true if success
 * false if ya fudged up
 * 
 * Give it the address of the task list and a pointer to the function, as well as a reference to the duration.
 */
bool addToTaskList(TaskList* tl, int (*f)(), ShortDuration* s, UI8 mR)
{
	if (tl->numTasks < TASKLIST_MAX_NUM_TASKS - 1)
	{
		tl->tasks[tl->numTasks].func = f;
		tl->tasks[tl->numTasks].duration = *s;
		tl->tasks[tl->numTasks].maxRetries = mR;
		tl->numTasks = tl->numTasks + 1;
		
		return true;
	} else
		return false;	
	
}
