//////////////////////////////////////////////////////////////////
//                                                              //
//    Log header      		                                  	//
//    last edited by: Kane Anderson                             //
//    date: April 30, 2012      	                            //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef LOG_H
#define LOG_H

#include "../drivers/DriversConfig.h"
#include "./SystemConfig.h"
#include <stdio.h>

// for printing a line to the file
void logLine(char* s);


void initializeLogFile(void);

#endif
