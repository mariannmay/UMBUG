//////////////////////////////////////////////////////////////////
//                                                              //
//    Input Types                                               //
//    last edited by: Kane Anderson                             //
//    date: November 23, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef INPUTTYPES_H
#define INPUTTYPES_H

#include "SimpleDefinitions.h"

///////////////////////////////////////////////

typedef struct
{
	bool state;
}
DigitalInput;

typedef struct
{
	Millivolts value;
}
AnalogInput;

// typedef union
//{
//	Timestamp timestamp;
//  byte ID;
//  byte data[8];
//}
//IncomingPacket;

#endif
