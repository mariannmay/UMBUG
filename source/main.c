//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Application.h"
#include "TestApplication.h"

//////////////////////////////////////////////////////////////////

void main(void)
{
	drivers_initialize();
	system_initialize();
	
	#if DebugMode
		test_application_initialize();
		while(true)
		{
			test_application_main();
		}
	#else
		application_initialize();
		while(true)
		{
			application_main();
		}
	#endif
}
