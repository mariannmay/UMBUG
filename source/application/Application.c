//////////////////////////////////////////////////////////////////
//                                                              //
//    Application source                                        //
//    last edited by:  Craig Nemeth                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Application.h"

//////////////////////////////////

void application_initialize(void)
{
	// TODO
}

void application_main(void)
{
	// TODO
 unsigned int i;
 
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
  P5DIR |= BIT1;                            // P5.1 as output
  P5OUT |= BIT1;                            // P5.1 set high

  while(1)
  {
  	//printf("hello\n");                      // Print statement
  	//fflush(stdout);                         // Flush buffer
    P5OUT ^= BIT1;                          // Toggle P5.1
    for(i=10000;i>0;i--);                   // Delay
  }
  
  #if CDH_PROCESSOR_COMPILE
  	CDH_application_main(void);
  #endif
  
  #if COM_PROCESSOR_COMPILE
  	COM_application_main(void);
  #endif
}

//////////////////////////////////


