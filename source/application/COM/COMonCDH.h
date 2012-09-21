//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCDH header                                           //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMonCDH_H
#define COMonCDH_H

// Includes //////////////////////////////////////////
#include "../ApplicationConfig.h"
#include "../../system/System.h"
#include "../../system/COMonCDHFlagChecking.h"
#include "../../system/Packet.h"

//Functions///////////////////////////////////////////

void checkForMessages(void);
void respondToMessage(void);
void addCommandToListOfTasks(void);

//connection control and maintenance
void connectionControl(void);

#endif
