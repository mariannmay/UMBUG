//////////////////////////////////////////////////////////////////
//                                                              //
//    IO Types   	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 8, 2012 		                                //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef IOTYPES_H
#define IOTYPES_H

#include <msp430fg4619.h>
#include "../SimpleDefinitions.h"
#include "./devices/msp430/AnalogToDigitalConverter.h"

///////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	bool state;
}
DigitalInput;

void initializeDigitalInput(DigitalInput* input, char portNum, char pin);
void readDigitalInput(DigitalInput* input);

///////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	Millivolts value;
}
AnalogInput;

void initializeAnalogInput(AnalogInput* input, char portNum, char pin);
void readAnalogInput(AnalogInput* input);

////////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	bool state;
}
SerialInput;

void initializeSerialInput(SerialInput* input, char portNum, char pin);

/////////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	bool state;
}
SerialOutput;

void initializeSerialOutput(SerialOutput* input, char portNum, char pin);

/////////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	bool state;
}
DigitalOutput;

void initializeDigitalOutput(DigitalOutput* output, char portNum, char pin);
void setDigitalOutput(DigitalOutput* output);
void clearDigitalOutput(DigitalOutput* output);

///////////////////////////////////////////////

typedef struct
{
	char portNum;
	char pin;
	Millivolts value;
}
AnalogOutput;

///////////////////////////////////////////////

#endif
