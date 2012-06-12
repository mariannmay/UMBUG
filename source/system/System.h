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

#include "../userConfig.h"
#include "../drivers/Drivers.h"
#include "SystemConfig.h"
#include <stdlib.h>

#if DebugMode
	#include "stdlib.h"
	#include "stdio.h"
	#include "assert.h"
	#include "./Log.h"
#endif

//////////////////////////////////

extern Time_ms systemTimer;

//////////////////////////////////

void system_initialize(void);
void system_main(void);
void system_abort(void);
void toggleStatusLED(void);
void enableInterrupts(void);
void disableInterrupts(void);
//////////////////////////////////

extern void application_main(void);
extern void application_initialize(void);
extern void test_application_initialize(void);
extern void test_application_main(void);

#endif
