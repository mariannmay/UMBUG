
#ifndef TIMERA_H_
#define TIMERA_H_

// includes ////////////////////////////////////////////////////

#include "msp430fg4618.h"
#include "../../../application/COM/COMApplication.h"
#include "../../../application/CDH/CDHApplication.h"

////////////////////////////////////////////////////////////////

//pointer to function to call for interrupt.  change this to change interrupt function.
extern void (*timerAInt_taccr1)(void);

void initTimerA();

////////////////////////////////////////////////////////////////

#endif

