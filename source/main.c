//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                    	//
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include <msp430fg4619.h>
#include "application/PWR/UART.h"

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

void main(void)
{
	//volatile unsigned int i;
	 
	
	system_initialize();
	InitUART();
	for(;;)
	{
		while (!(IFG2 & UTXIFG1));                // USART1 TX buffer ready?
  		TXBUF1 = 0xAB;          
	}
	//for(;;)
	//{
	//	system_main();
	//}
	
}
