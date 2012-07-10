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

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

void main(void)
{
	volatile unsigned int i;
	 
	

	system_initialize();
	
	for(;;)
	{
		system_main();
	}
	
}
