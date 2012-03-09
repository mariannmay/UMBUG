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

///////////////////////////////////////////////

typedef struct
{
	volatile Byte port;
	char pin;
	bool state;
}
DigitalInput;

void initializeDigitalInput(DigitalInput* input, Byte port, char pin);
void readDigitalInput(DigitalInput* input);

///////////////////////////////////////////////

typedef struct
{
	volatile Word port;
	char pin;
	Millivolts value;
}
AnalogInput;

void initializeAnalogInput(AnalogInput* input, Word port, char pin);
void readAnalogInput(AnalogInput* input);

////////////////////////////////////////////////

typedef struct
{
	volatile Byte port;
	char pin;
	bool state;
}
SerialInput;

void initializeSerialInput(SerialInput* input, Byte port, char pin);
void readSerialInput(SerialInput* input);

/////////////////////////////////////////////////

typedef struct
{
	Byte port;
	char pin;
	bool state;
}
SerialOutput;

void initializeSerialOutput(SerialOutput* input, Byte port, char pin);

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
	Byte port;
	char pin;
	bool state;
}
DigitalOutput;

void initializeDigitalOutput(DigitalOutput* output, Byte port, char pin);
void setDigitalOutput(DigitalOutput* output);
void clearDigitalOutput(DigitalOutput* output);

///////////////////////////////////////////////

typedef struct
{
	Byte port;
	char pin;
	Millivolts value;
}
AnalogOutput;

void setAnalogOutput(AnalogOutput* output);

///////////////////////////////////////////////

#endif
