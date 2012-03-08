//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCOMPeripherals header                                //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMonCOMPeripherals_H
#define COMonCOMPeripherals_H

#include <msp430fg4619.h>
#include "DriversConfig.h"

void checkportInterupts();
void checkTNCbufferFull();
void checkRealTimeClock();

#endif


