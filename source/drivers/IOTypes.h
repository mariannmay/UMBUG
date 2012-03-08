//////////////////////////////////////////////////////////////////
//                                                              //
//    IO Types   	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012 		                                //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef IOTYPES_H
#define IOTYPES_H

#include <msp430fg4619.h>
#include "../SimpleDefinitions.h"

///////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	bool state;
}
DigitalInput;

void initializeDigitalInput(DigitalInput* input, Word port, char pin);

///////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	Millivolts value;
}
AnalogInput;

void initializeAnalogInput(AnalogInput* input, Word port, char pin);

///////////////////////////////////////////////

typedef struct
{
	DigitalInput pin0;
}
SerialInput_1Pin;

////////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	bool state;
}
SerialInput;

void initializeSerialInput(SerialInput* input, Word port, char pin);

/////////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	bool state;
}
SerialOutput;

void initializeSerialOutput(SerialOutput* input, Word port, char pin);

/////////////////////////////////////////////////

typedef struct
{
	SerialInput clock;
	SerialInput slaveOutMasterIn;
	SerialOutput slaveInMasterOut;
	SerialOutput slaveTransmitEnable;
}
SerialInput_4Pin;

// typedef union
//{
//	Timestamp timestamp;
//  byte ID;
//  byte data[8];
//}
//IncomingPacket;





///////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	bool state;
}
DigitalOutput;

void setDigitalOutput(DigitalOutput* output);
void clearDigitalOutput(DigitalOutput* output);

///////////////////////////////////////////////

typedef struct
{
	Word port;
	char pin;
	Millivolts value;
}
AnalogOutput;

void setAnalogOutput(AnalogOutput* output);

///////////////////////////////////////////////

#endif
