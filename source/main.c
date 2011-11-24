//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Application.h"

//////////////////////////////////////////////////////////////////

void main(void)
{
	drivers_initialize();
	system_initialize();
	application_initialize();
	
	while(1)
	{
		application_main();
	}
}
