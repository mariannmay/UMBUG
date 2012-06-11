#include "msp430fg4619.h"
#include "../../../system/System.h" //for toggle led fucntion
#ifndef TIMERA_H_
#define TIMERA_H_

//pointer to function to call for interrupt.  change this to change interrupt function.
extern void (*timerAInt_taccr1)(void);

/*Basic Init function
 */
void initTimerA();

/*Blink a LED!
 */
void blink();
#endif /*TIMERA_H_*/
