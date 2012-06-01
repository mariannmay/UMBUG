//////////////////////////////////////////////////////////////////
//                                                              //
//    Application source                                        //
//    last edited by:  Kane Anderson                            //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Application.h"
#include "CDH/CDHApplication.h"
#include "COM/COMonCOM.h"
#include <stdio.h>

//////////////////////////////////

void application_initialize(void)
{
	// TODO
}

void application_main(void)
{
	// note:
	// CDH_PROCESSOR_COMPILE and COM_PROCESSOR_COMPILE
	// are #defined in ApplicationConfig.h
	
#ifdef CDH_PROCESSOR_COMPILE
	
		// the application which will run
		// on the CDH processor
		
		//logLine("__we are the CDH processor__");		// we don't want this to print every loop
		CDH_application_main();
#endif

#ifdef COM_PROCESSOR_COMPILE
	
		// the application which will run
		// on the COM processor
		//logLine("__we are the COM processor__\n");		// we don't want this to print every loop
		//COM_application_main(); //TODO: make this function
#endif
}

//////////////////////////////////
