#ifndef TIMERB_H_
#define TIMERB_H_
#include "msp430fg4619.h"
#include "../../../system/System.h" //for toggle led fucntion

//pointer to function to call for interrupt.  change this to change interrupt function.
extern void (*timerBInt_taccr1)(void);

/*Basic Init function
 */
void initTimerB();
void setTimerB(UI16 t);
void cancelTimer();
#endif /*TIMERB_H_*/
