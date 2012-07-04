#include "TimeCounter.h"

void initShortDuration(ShortDuration *s, int mS)
{
	s->LSW = mS;	
}

int compareTimeCounter(TimeCounter *a, TimeCounter *b)
{
	//a is greater than b, return 1
	
	if ((a->MSW > b->MSW) || (a->MSW == b->MSW && (a->LSW > b->LSW)))
		return 1;
	//a is equal to be, return 0
	if (a->MSW == b->MSW && a->LSW == b->LSW)
		return 0;
	
	//a is less than b, return -1
	else	
		return -1;
}
void initTimeCounter(TimeCounter *a) //MODIFIED SO THAT CODE WOULD COMPILE. TODO: change it to what is actually desirable.
{
	a->LSW = 0;
	a->MSW = 0;
	
}
void incrementTimeCounter(TimeCounter *a){
	
	a->LSW = a->LSW + 1;
	if (a->LSW == 0)	//a rollover has occured.
	{
		a->MSW = a-> MSW + 1;		//so increment most significant word
		if (a->MSW == END_OF_LIFE_MSW && a->LSW == END_OF_LIFE_LSW)
			{
						//SATELLITE IS NOT SUPPOSED TO LIVE THIS LONG!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
						//send a final beacon 
			}
	}
	
	
}
void addToTimeCounter(TimeCounter *orig, TimeCounter *more)
{
	UL32 oldLSW= orig->LSW;
	
	orig->MSW += more->MSW;
	orig->LSW += more->LSW;
	
	if (orig->LSW < oldLSW)//rollover occured, add one to MSW
	{
		orig->MSW += 1;
	}	
	
}
void addShortDurationToTimeCounter(TimeCounter *orig, ShortDuration *more)
{
	UL32 oldLSW = orig->LSW;
	orig->LSW += more->LSW;
	if (orig->LSW < oldLSW)
	{
		orig->MSW += 1;	
	}	
	
}

//use initDuration to create a duration. dont use this function.
//if i ever catch you using this function i will break your kneecapS, note the emphasis on plural -Troy

void __UL32_to_TimeCounter_LSW__(TimeCounter *t, UL32 l)
{
	initTimeCounter(t);
	t->LSW = l;
	
}

void initDuration(TimeCounter *t, int days, int hours, int minutes, int seconds, int milliseconds)
{
	initTimeCounter(t);
	TimeCounter w;
	
	__UL32_to_TimeCounter_LSW__(&w,(UL32)days*(UL32)TIMECOUNTER_DAY);
	addToTimeCounter(t,&w);
	
	__UL32_to_TimeCounter_LSW__(&w,(UL32)hours*(UL32)TIMECOUNTER_HOUR);
	addToTimeCounter(t,&w);
	
	__UL32_to_TimeCounter_LSW__(&w,(UL32)minutes*(UL32)TIMECOUNTER_MINUTE);
	addToTimeCounter(t,&w);
	
	__UL32_to_TimeCounter_LSW__(&w,(UL32)seconds*(UL32)TIMECOUNTER_SECOND);
	addToTimeCounter(t,&w);
	
	__UL32_to_TimeCounter_LSW__(&w,(UL32)milliseconds*(UL32)TIMECOUNTER_MILLISECOND);
	addToTimeCounter(t,&w);
	
	
}

/*
 * Provide a copy of the current timecounter.  good for getting snapshots of the currentTime global.
 */
TimeCounter copy(TimeCounter* tc)
{
	TimeCounter t;
	t.LSW = tc->LSW;
	t.MSW = tc->MSW;
	return t;
}

//void destroyTimeCounter(TimeCounter *a)
//{
//	free(a);	//no dynamic structures (pointers) inside timecounter struct.	
//}
