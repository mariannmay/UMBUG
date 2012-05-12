//////////////////////////////////////////////////////////////////
//                                                              //
//    Application config header                                 //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef APPLICATIONCONFIG_H
#define APPLICATIONCONFIG_H

#include "../SimpleDefinitions.h"

//////////////////////////////////

// choose whether to compile code for the CDH redundant controllers
// or the COM encoding controller
// IMPORTANT: only one of these should be defined as 1.
// NOT BOTH OF THEM
#define CDH_PROCESSOR_COMPILE 1
#define COM_PROCESSOR_COMPILE 0

// some constant
extern const int StuffConstant;

#endif
