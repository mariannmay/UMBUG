//////////////////////////////////////////////////////////////////
//                                                              //
//    IO Types	                                                //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                   	//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "./IOTypes.h"


// TODO REMOVE
#include <stdio.h>

//////////////////////////////////////////////////////////////////

void initializeDigitalInput(DigitalInput* input, Word port, char pin)
{
	input->port = port;
	input->pin = pin;
	input->state = false;
}

//////////////////////////////////////////////////////////////////

void initializeSerialInput(SerialInput* input, Word port, char pin)
{
	input->port = port;
	input->pin = pin;
	input->state = false;
}

//////////////////////////////////////////////////////////////////

void initializeSerialOutput(SerialOutput* output, Word port, char pin)
{
	output->port = port;
	output->pin = pin;
	output->state = false;
}

///////////////////////////////////////////////

void initializeAnalogInput(AnalogInput* input, Word port, char pin)
{
	input->port = port;
	input->pin = pin;
	input->value = 0x00;
}

///////////////////////////////////////////////

void setDigitalOutput(DigitalOutput* output)
{
	// TODO REMOVE (debug)
	printf("    setDigitalOutput\r\n");
	fflush(stdout);
	
	
	Byte bitmask;
	switch(output->pin)
	{
		case 1	:	bitmask = 0x01; break;
		case 2	:	bitmask = 0x02; break;
		case 3	:	bitmask = 0x04; break;
		case 4	:	bitmask = 0x08; break;
		case 5	:	bitmask = 0x10; break;
		case 6	:	bitmask = 0x20; break;
		case 7	:	bitmask = 0x40; break;
		case 8	:	bitmask = 0x80; break;
		
		default	:	return;
	}
	
	output->port |= bitmask;
	output->state = high;
	
	// TODO REMOVE (debug)
	char temp = output->state;
	printf("    in setDigitalOutput, it's %x\r\n", temp);
	fflush(stdout);
}

void clearDigitalOutput(DigitalOutput* output)
{
	// TODO REMOVE (debug)
	printf("    clearDigitalOutput\r\n");
	fflush(stdout);
	
	
	Byte bitmask;
	switch(output->pin)
	{
		case 1	:	bitmask = 0xFE; break;
		case 2	:	bitmask = 0xFD; break;
		case 3	:	bitmask = 0xFB; break;
		case 4	:	bitmask = 0xF7; break;
		case 5	:	bitmask = 0xEF; break;
		case 6	:	bitmask = 0xDF; break;
		case 7	:	bitmask = 0xBF; break;
		case 8	:	bitmask = 0x7F; break;
		
		default	:	return;
	}
	
	output->port &= bitmask;
	output->state = low;
	
	
	// TODO REMOVE (debug)
	char temp = output->state;
	printf("    in clearDigitalOutput, it's %x\r\n", temp);
	fflush(stdout);
}

///////////////////////////////////////////////

// used on the COM processor
void setAnalogOutput(AnalogOutput* output)
{
	output->port = output->value;
}




