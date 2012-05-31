//////////////////////////////////////////////////////////////////
//                                                              //
//    Log source      		                                  	//
//    last edited by: Kane Anderson                             //
//    date: April 30, 2012      	                            //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "./Log.h"

void logLine(char* string)
{
	printf("\r\n%s\r\n", string);
	fflush(stdout);
}

void initializeLogFile(void)
{
	FILE* fp = fopen(DataLogFileName, "w");
	if (fp == NULL)
	{
		printf("Error in opening a file...");
		fflush(stdout);
	}
	else
	{
		fp = freopen(DataLogFileName, "w", stdout);
	}
}


