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
#include <stdio.h>

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

void main(void)
{
	 InitUART();
	
	
	printf("successes for me/n");
	fflush(stdout);
	system_initialize();
	
	
	
	for(;;)
	{
		system_main();
	}
	
}
