//////////////////////////////////////////////////////////////////
//                                                              //
//    Input Types                                               //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef INPUTTYPES_H
#define INPUTTYPES_H

#include "../SimpleDefinitions.h"

///////////////////////////////////////////////

typedef struct
{
	Word pin;
	bool state;
}
DigitalInput;

typedef struct
{
	Word pin;
	Millivolts value;
}
AnalogInput;

typedef struct
{
	DigitalInput pin0;
}
SerialInput_1Pin;

typedef struct
{
	DigitalInput pin0;
	DigitalInput pin1;
	DigitalInput pin2;
	DigitalInput pin3;
}
SerialInput_4Pin;

// typedef union
//{
//	Timestamp timestamp;
//  byte ID;
//  byte data[8];
//}
//IncomingPacket;

#endif
