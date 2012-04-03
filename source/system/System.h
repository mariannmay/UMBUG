//////////////////////////////////////////////////////////////////
//                                                              //
//    System header                                             //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
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
void system_abort(void);
void toggleStatusLED(void);

extern void application_main(void);
extern void application_initialize(void);
extern void test_application_initialize(void);
extern void test_application_main(void);

#endif
