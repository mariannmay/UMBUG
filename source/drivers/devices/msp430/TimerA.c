#include "TimerA.h"
#include "../../../system/Task.h"
#include "../../../application/COM/COMApplication.h"
#include <stdio.h>
/*
 * Refer to this outside of the file with the extern keyword!!
 */
void (*timerAInt_taccr1)(void);
void dumbFunc(void){
	printf("Test\n");	
}
void initTimerA(){
	/*Timer A control register.
	 * TASSEL_2 = use SMCLK for clock source
	 * TAIE = timer a interrupt enable
	 * MC_1 is count-up mode
	 * ID_0 = divide frequency by 1 (2^0)
	 * 
	 */
	//enableInterrupts();
	TACTL = TASSEL_2 | TAIE | MC0 | ID_0;
	
	/*Timer A Capture/Compare Control 0
	 * CM_0 = capture mode 0 (disabled, we want compare mode).
	 * CCIS_0 = capture compare input (gnd, we not using an input signal.  Clock yes, input no.)
	 * CCIE = capture compare input enable
	 */
	TACCTL0 = CM_0 | CCIS_3 | CCIE;
	
	/*Timer A Capture/Compare 0
	 * period of count - counts up from 0 to TACCR0 and then registers an interrupt.
	 */
	//TACCR0 = 1024;
	//TACCR0 = 65535;

	/*
	 * interrupt call for basic task switching.
	 */
	#if CDH_PROCESSOR_COMPILE
		TACCR0 = 1024;
		timerAInt_taccr1 = &performCurrentTask;
	#endif
	#if COM_PROCESSOR_COMPILE
		logLine("timerACOMinit\n");
		TACCR0 = 1024;
		timerAInt_taccr1 = &runRadio;
	#endif	
	
	
}


/*
 * get this working at some point, maybe it already does?
void changeTimerAInterrupt((*pt2func)(void)){
	timerAInt_taccr1 = pt2func;	
}
*/

#pragma vector=TIMERA0_VECTOR
__interrupt void timerA0int(){
	
	//see which interrupt was actually fired:
	//toggleStatusLED();
	logLine("interrupt!!");
	
	//printf("TEst\n");
	if(TAIV && TAIV_TACCR1)	//if capture compare reg 1 interrupt
	{
		logLine("interrupt!!");
		timerAInt_taccr1();
		
	}
	
	
//	
//	if (TAIV && TAIV_TACCR2) //if capture compare reg 2 interrupt
//	{
//		
//	}
	return;
	
}
