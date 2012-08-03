//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef CDHAPPLICATION_H
#define CDHAPPLICATION_H

#include "../ApplicationConfig.h"
#include "../../system/System.h"
#include "../../system/Log.h"

void CDH_timerA_ISR(void);

void CDH_application_main(void);
void CDHMainScheduleLoop(void);

#endif
