//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "drivers/Drivers.h"
#include "system/System.h"
#include "test application/TestApplication.h"

//////////////////////////////////////////////////////////////////

void main(void)
{
	drivers_initialize();
	system_initialize();
	
	// note: DebugMode is #defined in SystemConfig.h
	#if DebugMode
		test_application_initialize();
		while(true)
		{
			test_application_main();
		}
	#else
		system_initialize();
		while(true)
		{
			system_main();
		}
	#endif
}
