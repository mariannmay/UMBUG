//////////////////////////////////////////////////////////////////
//                                                              //
//    Output Types                                              //
//    last edited by: Kane Anderson                             //
//    date: November 23, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef OUTPUTTYPES_H
#define OUTPUTTYPES_H

#include "../SimpleDefinitions.h"

///////////////////////////////////////////////

typedef struct
{
	bool state;
}
DigitalOutput;

typedef struct
{
	Millivolts value;
}
AnalogOutput;

// typedef union
//{
//	Timestamp timestamp;
//  byte ID;
//  byte data[8];
//}
//OutgoingPacket;

#endif
