//////////////////////////////////////////////////////////////////
//                                                              //
//    System header                                             //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
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

#include "../drivers/Drivers.h"
#include "SystemConfig.h"

//////////////////////////////////

void system_initialize(void);
void system_main(void);

extern void application_main(void);
extern void application_initialize(void);

#endif
