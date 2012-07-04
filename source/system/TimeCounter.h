/*
 * TimeCounter.h
 * Troy Denton May 31 2012
 * 
 * TimeCounter class is a container for large unsigned integers - a uint32 wont hold the number of mS in one year.  a bare minimum of 35 bits is needed.
 * 
 * In case things stay in orbit a little longer (who knows?) 64 bits will suffice for a gigantic amount of time.
 * 
 * need to include methods for incrementing - need to handle the rollover of course.
 * 
 * */
#include "../SimpleDefinitions.h"
#ifndef TIMECOUNTER_H_
#define TIMECOUNTER_H_





#define END_OF_LIFE_MSW	7
#define END_OF_LIFE_LSW	1471228928
#define TIMECOUNTER_MILLISECOND 1

#define TIMECOUNTER_SECOND	1000*TIMECOUNTER_MILLISECOND
#define TIMECOUNTER_MINUTE	60*TIMECOUNTER_SECOND
#define TIMECOUNTER_HOUR	60*TIMECOUNTER_MINUTE
#define TIMECOUNTER_DAY		24*TIMECOUNTER_HOUR
//#define TIMECOUNTER_WEEK	7*TIMECOUNTER_DAY WEEKS ARE FOR THE WEAK.

//months are shittily defined and so not accomodated here.

//if youre scheduling something for a year in advance you're a dumbass	(EOL function already available)


/*
 * Structure that holds enough space for mS in a year.
 */
typedef struct {
	
	UL32 LSW;	//Least significant word 
	UL32 MSW;	//Most significant word
	
	
	
} TimeCounter;

/*
 * Structure that holds enough space for mS in a minute.
 * (used for durations of tasks)
 */
typedef struct {
	
	UL32 LSW;
	
} ShortDuration;

//typedef struct {
//	UL32 MSW;   // THIS WAS MADE JUST SO THAT THE CODE WOULD COMPILE. (Please only commit working code to the master branch :P ) TODO: fix.
//	UL32 LSW;
//} TimeCount;


/*
 * Tests the relationship between a and b.
 * 
 * if (a > b) return 1
 * if (a == b) return 0
 * if (a < b) return -1
 * 
 * */
int compareTimeCounter(TimeCounter *a, TimeCounter *b);

/*
 * use this to initialize a TimeCounter to 0.
 * */
void initTimeCounter(TimeCounter *a);

/*
 * Use this to increment the timecounter a by one millisecond.
 */
void incrementTimeCounter(TimeCounter *a);

/*
 *Use this to add an amount of time to a timecounter structure. 
 * orig = orig + more
 * */
void addToTimeCounter(TimeCounter *orig, TimeCounter *more);


/*
 * addToTimeCount for use with shortdurations.
 */
 
 void addShortDurationToTimeCounter(TimeCounter *orig, ShortDuration *more);
/*
 * initDuration - use this to initialize a duration of time.
 * this is necessary because some amounts of time will not fit in a unsigned 32 bit long.
 * so dont go wasting your time with other functions.  This makes life easy.
 * */

void initDuration(TimeCounter *t, int days, int hours, int minutes, int seconds, int milliseconds);

void initShortDuration(ShortDuration *s, int mS);
//NO DECREMENT TIME COUNT ALLOWED.  UNECESSARY OPERATION LEADS TO BAD DESIGN!!!


//DONT DO IT!!!

/*
 * copy - used to take a snapshot of a timecounter.  Good for use with the global currentTime
 */
TimeCounter copy(TimeCounter* tc);

//CALL 918-2687 for more info/tongue lashing
#endif /*TIMECOUNTER_H_*/

