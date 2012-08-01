//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMAPPLICATION_H
#define COMAPPLICATION_H

#include "../ApplicationConfig.h"
#include "../../system/System.h"
#include "../../system/Log.h"
#include "../../drivers/devices/msp430/TimerA.h"

void COM_application_main(void);
void COMMainScheduleLoop(void);
void runRadio(void);

#endif
