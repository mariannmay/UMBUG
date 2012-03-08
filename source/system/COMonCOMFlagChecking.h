//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCOMFlagChecking header                               //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMonCOMFlagChecking_H
#define COMonCOMFlagChecking_H

#include "Packet.h"
#include "../drivers/COMPINS/CDHtoCOMInterruptReceive.h"
#include "../drivers/COMPINS/COMtoCDHFlagSet.h"

void checkFlag();
void setInterrupt();

#endif

