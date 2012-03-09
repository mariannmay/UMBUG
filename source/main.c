//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                    	//
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "system/System.h"

//////////////////////////////////////////////////////////////////

void main(void)
{
	system_initialize();

	for(;;)
	{
		system_main();
	}
	
}
