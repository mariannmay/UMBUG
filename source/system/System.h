//////////////////////////////////////////////////////////////////
//                                                              //
//    System header                                             //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SYSTEM_H
#define SYSTEM_H

//////////////////////////////////

#if DebugMode
	#include "stdlib.h"
	#include "stdio.h"
	#include "assert.h"
#endif

#include "Drivers.h"
#include "SystemConfig.h"

//////////////////////////////////

void system_initialize(void);

#endif
