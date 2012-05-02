//////////////////////////////////////////////////////////////////
//                                                              //
//    System config header                                      //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SYSTEMCONFIG_H
#define SYSTEMCONFIG_H

#include "../SimpleDefinitions.h"

//////////////////////////////////

#define DebugMode 1
#define COMPROCESSOR 0
#define CDHPROCESSOR 1

extern const Time_ms WatchdogKickTimeInterval;
extern const char* DataLogFileName;

#endif
