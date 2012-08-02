//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMApplication.h"

unsigned int x=0;

void COM_application_main(void)
{

	logLine("COM scheduler initialized");
	for(;;)
	{
		COMMainScheduleLoop();
	}
}

void COMMainScheduleLoop(void)
{
	//logLine("LOOPIN' COM\n");
}

void runRadio(void)
{
	x++;
	printf("running radio %d\n", x);	
	fflush(stdout);
}
