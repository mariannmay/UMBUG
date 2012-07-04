/*
 * TaskList - a list of tasks.
 * 
 * 
 * 
 * 
 * 
 * */

#include "./Task.h"
#include "../SimpleDefinitions.h"
#include "../drivers/devices/msp430/SPIDevice.h"
#include "TimeCounter.h"
#ifndef TASKLIST_H_
#define TASKLIST_H_



/*
 * If this is changed, the hash fucntion for fudge registers needs to be adjusted.
 * IE right now the algorithm wont support 128 tasks, without some slight changes./
 */
#define TASKLIST_MAX_NUM_TASKS 16 //this is just a guess right now.


extern int __TaskListIDs;
typedef struct
{
	/*
	 * always allocated TASKLIST_MAX_NUM_TASKS.  whether or not its filled is another matter.
	 */
	Task	tasks[TASKLIST_MAX_NUM_TASKS];
	/*
	 * numTasks keeps track of the number of _actual_ tasks in the list.
	 * This is done in case we want to be able to add tasks at runtime basically.
	 */
	int		numTasks;
	/*
	 * the current task's index into the tasks array
	 */
	int		currentTaskIndex;	
	
	/*
	 * the tasklist's ID. This is required for hashing to fudge registers.
	 * No, I don't expect you to understand the above sentence
	 */
	int ID;
	
} TaskList;
void performCurrentTask(TaskList*);
void initTaskList(TaskList*);
bool addToTaskList(TaskList*, int (*pt2Func)(), ShortDuration* duration, UI8 maxRetries);
#endif /*TASKLIST_H_*/
