#include "TimerB.h"
#include "../../../system/Task.h"
#include <stdio.h>
void (*timerBInt_tbccr0)(void);
void dumbFunc(void)
{
	printf("Dumb func default\n");	
}
void expire(void)
{
	printf("Task expired!\n");	
}
void initTimerB(void)
{
	/*
	 * TBSSEL_2 - smclk
	 * TBIE - interrupt enable
	 * CNTL_0 counter length 16 bits
	 * TBCLGRP_0 - group individual
	 * ID_0 - input clock division by 8 (2^3)
	 */
	TBCTL =  TBSSEL_2 | TBIE | CNTL_0 | TBCLGRP_0 | ID_3 /*| MC_1*/;	//MC_1 enables timer.  use setTimerB() function to enable
	
	
	/*Timer A Capture/Compare Control 0
	 * CM_0 = capture mode 0 (disabled, we want compare mode).
	 * CCLD_0 = load TBCL0 when count up to TBCL0
	 * CCIE = capture compare input enable
	 * CCIS_3 = reload TBCL0 on write to TBCCR0
	 */
	TBCCTL0 = CM_0 | CLLD_0 | CCIE | CCIS_3;
	
	TBCCR0 = 0xFFFF;
	timerBInt_tbccr0 = &expire;
	setTimerB(5000);
	
}

/*
 * may want to expand this so that it accepts a timecounter instead of U16 ?
 */
void setTimerB(UI16 t)
{
	
	TBCCR0 = t;
	TBCTL |= MC_1;
	
}

void cancelTimer()
{
	
	TBCTL &= ~(MC1 | MC0);	//stop timer operation
	TBR = 0;				//clear the counter as well for a fresh start whenever that happens
}

#pragma vector=TIMERB0_VECTOR
__interrupt void timerB0int(void){
	

	if(TBIV && TBIV_TBCCR1)
	{

		timerBInt_tbccr0();
		cancelTimer();
		
//		asm("pop r2\n\t");
//		asm("pop r2\n\t");
//		asm("pop r2\n\t");
//		asm("pop r2\n\t");		
		//_set_PC_register((unsigned short)previous_PC);		
		/*unsigned short derp = getPCofCallingFunction();
		_set_SP_register(derp);//put PC on the stack and call a return
		asm("ret");*/
		_set_SP_register((unsigned short)previous_SP+1);
		oldpc = getPCofCallingFunction();
		
		asm("ret");
	}
	
	
}






