/*
 * TaskList - a list of tasks.
 * 
 * 
 * 
 * 
 * 
 * */

#include "Task.h"
#include "../SimpleDefinitions.h"
#ifndef TASKLIST_H_
#define TASKLIST_H_




#define TASKLIST_MAX_NUM_TASKS 128 //this is just a guess right now.

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
	
	
} TaskList;
void performCurrentTask(TaskList*);
void initTaskList(TaskList*);
/*
typedef struct 
{
	RoutineTask tasks[TASKLIST_MAX_NUM_TASKS];	//the circular buffer
	int insert;							//the insert position
	int current;						//the current task position
	int num;							//the number of tasks in the system.
		
} RoutineTaskList;

typedef struct 
{
	GroundCommandTask tasks[TASKLIST_MAX_NUM_TASKS];	//the circular buffer
	int insert;							//the insert position
	int current;						//the current task position
	int num;							//the number of tasks in the system.
		
} GroundCommandTaskList;
*/
/*typedef struct
{
	GroundCommandTask	gct;
	BasicTaskNode* next;
	
}	BasicTaskNode;

typedef struct	//may not need this
{
	int size;
	BasicTaskNode* head;	//the first node
}	BasicTaskList;
*/
/*
typedef struct
{
	
	RoutineTaskNode *next;	
	RoutineTask task;
	
}	RoutineTaskNode;

typedef struct
{
	
	GroundCommandTaskNode *next;	
	GroundCommandTask task;
	
}	GroundCommandTaskNode;
*/

/*
 * initialize a taskList structure.
 */
 /*
void initGroundCommandTaskList(GroundCommandTaskList *tl);
void initRoutineTaskList(RoutineTaskList *tl);
*/

/*
 *	add a task to the list.  Tasks are removed upon completion. 
 */
/*
int addRoutineTask(RoutineTaskList *tl, RoutineTask *t); 
int addGroundCommandTask(GroundCommandTaskList *tl, GroundCommandTask *t);
*/
#endif /*TASKLIST_H_*/
