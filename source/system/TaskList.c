#include "TaskList.h"


/*
 * If i ever catch you playing with this variable I will break your kneecaps -Troy
 */
int __TaskListIDs = 0;
/*
 * Perform the current task in the given list.
 * 
 */

void performCurrentTask(TaskList tl*)
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
	UI16 fudgeRegister = (tl->ID<<2&0xFF00)+(tl->currentTaskIndex&0x00FF);
	
	//read in fudge register
	//increment this value
	//write this value to fudge register
	
	int result = tl->tasks[tl->currentTaskIndex++]();		//postincrement,increment after accessing.
	
	tl->currentTaskIndex = (tl->currentTaskIndex + 1)%tl->numTasks;
	
	
	/*Debug print for now*/
	printf("Result: %d\n",result);
	
	//NEED TO WRITE TO THE EEPROM HERE (DECREMENT)
	//decrement fudge value written, write again.
}

/*
 * Initialize values for a new TaskList
 */
void initTaskList(TaskList tl*)
{
	tl->currentTaskIndex = 0;
	tl->numTasks = 0;
	tl->ID = __TaskListIDs++;
}


/*
 * 
 * old linked list idea I was throwing around, have now thrown out  -Troy
 * 
 * void insertTask(BasicTaskList *btl,GroundCommandTask *gct)
{
	BasicTaskNode *newTask;
	newTask = (BasicTaskNode*)malloc(sizeof(BasicTaskNode));
	newTask->gct = gct;
	if (*btl->size == 0)
	{
		*btl->head = newTask;
		*btl->head->next = NULL;
		
	} else 
	{
		BasicTaskNode *prev;
		
		BasicTaskNode *btn = btl->head;
		int i;
		while(btn->next != NULL && compareTimeCount(gct->scheduledTime, btn->next->gct->scheduledTime) >= 0)
		{
			prev = btn;
			btn = btn->next;
		}
		if (btn->next == NULL)
		{
			btn->next = (BasicTaskNode*)malloc(sizeof(BasicTaskNode));
			btn->next->gct = gct;
			btn->next->next = NULL;	
		} else
		{
			newTask->next = btn->next;
			prev->next = newTask;
		}
		
	}
}

void initBasicTaskList(BasicTaskList *btl)
{
	*btl->size = 0;
	*btl->head = NULL;	
}




/*void initGroundCommandTaskList(GroundCommandTaskList *tl){
	tl->insert = 0;
	tl->current = 0;
	tl->num = 0;
	int i;
	for(i = 0; i < TASKLIST_MAX_NUM_TASKS)
	{
		
	}
}
void initRoutineTaskList(RoutineTaskList *tl){
	tl->insert = 0;
	tl->current = 0;
	tl->num = 0;
	int i;
	RoutineTask dummy;
	dummy.completed = TASK_COMPLETE;
	for(i = 0; i < TASKLIST_MAX_NUM_TASKS)
	{
		tl->tasks[i] = dummy;
	}
}



int addRoutineTask(RoutineTaskList *tl, RoutineTask *t)
{

	if(tl->tasks[tl->insert].completed == TASK_COMPLETED)
	{
		tl->tasks[tl->insert] = *t;
		tl->insert = (tl->insert + 1)%TASKLIST_MAX_NUM_TASKS;
		return 1;	//success
	} else {
		return 0;
	}
}
int addGroundCommandTask(GroundCommandTaskList *tl, GroundCommandTask *t)
{
	if(tl->tasks[tl->insert].completed == TASK_COMPLETED)
	{
		tl->tasks[tl->insert] = *t;
		tl->insert = (tl->insert + 1)%TASKLIST_MAX_NUM_TASKS;
		return 1;	//success
	} else {
		return 0;
	}
	
}
*/
