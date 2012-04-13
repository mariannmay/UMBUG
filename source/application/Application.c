//////////////////////////////////////////////////////////////////
//                                                              //
//    Application source                                        //
//    last edited by:  Kane Anderson                            //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Application.h"
#include "ApplicationConfig.c" //TODO: this should be changed to be a .h file, right?
#include "CDH/CDHApplication.h"
#include "COM/COMonCOM.h"
#include <stdio.h>

//////////////////////////////////

void application_initialize(void)
{
	// TODO
	printf("application_init(void)\n");
}

void application_main(void)
{
	// note:
	// CDH_PROCESSOR_COMPILE and COM_PROCESSOR_COMPILE
	// are #defined in ApplicationConfig.h
	
	if(CDH_PROCESSOR_COMPILE)
	{
		// the application which will run
		// on the CDH processor
		
		//FIX: The processor isn't getting here! CDH_PROCESSOR_COMPILE is set to 1, so it SHOULD be working...
		printf("__we are the CDH processor__\n");
		CDH_application_main();
	}

	if(COM_PROCESSOR_COMPILE)
	{
		// the application which will run
		// on the COM processor
		printf("__we are the COM processor__\n");
		//COM_application_main(); //TODO: make this function
	}
}

//////////////////////////////////
