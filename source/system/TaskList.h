/*
 * TaskList - a circular buffer of task structures.
 * 
 * Ground commands get their own task list, as do routine operations.
 * 
 * 
 * 
 * */


#ifndef TASKLIST_H_
#define TASKLIST_H_

#endif /*TASKLIST_H_*/


#define TASKLIST_MAX_NUM_TASKS 128 //this is just a guess right now.


typedef struct 
{
	Task tasks[TASKLIST_MAX_NUM_TASKS];	//the circular buffer
	int start;							//the insert position
	int current;						//the current task position
	int num;							//the number of tasks in the system.
		
} TaskList;


/*
 * initialize a taskList structure.
 */
void initTaskList(TaskList *tl);

/*
 * Executes the next task in the list.  Removes the previous??????????????????????????
 * 
 * returns the return value of the executed function
 */
int executeNextTask();

/*
 * Add task to a tasklist - returns 1 for success or 0 for failure (full buffer).
 */
int addTask(TaskList *tl, Task *t); 



