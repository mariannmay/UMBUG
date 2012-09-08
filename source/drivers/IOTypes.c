//////////////////////////////////////////////////////////////////
//                                                              //
//    IO Types	                                                //
//    last edited by: Kane Anderson                             //
//    date: June 26, 2012                                   	//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "./IOTypes.h"

//////////////////////////////////////////////////////////////////

void initializeAnalogOutput(AnalogOutput* output, char portNum, char pin)
{
	// nothing to do here
}

void sendAnalogOutput(AnalogOutput* output)
{
	if ((output->portNum == 6) && (output->pin == 6))
	{
		startNewDigitalToAnalogConversion(output->value);
	}
}

//////////////////////////////////////////////////////////////////

void initializeDigitalInput(DigitalInput* input, char portNum, char pin)
{
	input->portNum = portNum;
	input->pin = pin;
	input->state = false;
}

void readDigitalInput(DigitalInput* input)
{
	volatile unsigned char* port;
	if		(input->portNum == 1)  port = &P1OUT;
	else if (input->portNum == 2)  port = &P2OUT;
	else if (input->portNum == 3)  port = &P3OUT;
	else if (input->portNum == 4)  port = &P4OUT;
	else if (input->portNum == 5)  port = &P5OUT;
	else if (input->portNum == 6)  port = &P6OUT;
	else if (input->portNum == 7)  port = &P7OUT;
	else if (input->portNum == 8)  port = &P8OUT;
	else if (input->portNum == 9)  port = &P9OUT;
	else if (input->portNum == 10) port = &P10OUT;
	
	if		(input->pin == 0) input->state = (bool)((*port & BIT0) >> 0);
	else if (input->pin == 1) input->state = (bool)((*port & BIT1) >> 1);
	else if (input->pin == 2) input->state = (bool)((*port & BIT2) >> 2);
	else if (input->pin == 3) input->state = (bool)((*port & BIT3) >> 3);
	else if (input->pin == 4) input->state = (bool)((*port & BIT4) >> 4);
	else if (input->pin == 5) input->state = (bool)((*port & BIT5) >> 5);
	else if (input->pin == 6) input->state = (bool)((*port & BIT6) >> 6);
	else if (input->pin == 7) input->state = (bool)((*port & BIT7) >> 7);
	

}

//////////////////////////////////////////////////////////////////

void initializeSerialInput(SerialInput* input, char portNum, char pin)
{
	input->portNum = portNum;
	input->pin = pin;
	input->state = false;
}

//////////////////////////////////////////////////////////////////

void initializeSerialOutput(SerialOutput* output, char portNum, char pin)
{
	output->portNum = portNum;
	output->pin = pin;
	output->state = false;
}

//////////////////////////////////////////////////////////////////



///////////////////////////////////////////////

void initializeAnalogInput(AnalogInput* input, char portNum, char pin)
{
	input->portNum = portNum;
	input->pin = pin;
	input->value = 0x0000;
}

void readAnalogInput(AnalogInput* input)
{
	startNewAnalogToDigitalConversion();
	
	//////////////
	
	switch (input->portNum)
	{
		case 5:
			switch (input->pin)
			{
				case 0:		input->value = ADC12MEM9; break;
				case 1:		input->value = ADC12MEM8; break;
				default: return;
			}
			break;
		
		case 6:
			switch (input->pin)
			{
				case 0:		input->value = ADC12MEM0; break;
				case 1:		input->value = ADC12MEM1; break;
				case 2:		input->value = ADC12MEM2; break;
				case 3:		input->value = ADC12MEM3; break;
				case 4:		input->value = ADC12MEM4; break;
				case 5:		input->value = ADC12MEM5; break;
				case 7:		input->value = ADC12MEM7; break;
				default: return;
			}
			break;
		
		case 10:
			switch (input->pin)
			{
				case 6:		input->value = ADC12MEM11; break;
				case 7:		input->value = ADC12MEM10; break;
				default: return;
			}
			break;
			
		default:
			return;
	}
}

///////////////////////////////////////////////

void initializeDigitalOutput(DigitalOutput* output, char portNum, char pin)
{
	output->portNum = portNum;
	output->pin = pin;
	output->state = false;
}

void setDigitalOutput(DigitalOutput* output)
{
	volatile unsigned char* port;
	if		(output->portNum == 1)  port = &P1OUT;
	else if (output->portNum == 2)  port = &P2OUT;
	else if (output->portNum == 3)  port = &P3OUT;
	else if (output->portNum == 4)  port = &P4OUT;
	else if (output->portNum == 5)  port = &P5OUT;
	else if (output->portNum == 6)  port = &P6OUT;
	else if (output->portNum == 7)  port = &P7OUT;
	else if (output->portNum == 8)  port = &P8OUT;
	else if (output->portNum == 9)  port = &P9OUT;
	else if (output->portNum == 10) port = &P10OUT;
	
	if		(output->pin == 0) *port |= BIT0;
	else if (output->pin == 1) *port |= BIT1;
	else if (output->pin == 2) *port |= BIT2;
	else if (output->pin == 3) *port |= BIT3;
	else if (output->pin == 4) *port |= BIT4;
	else if (output->pin == 5) *port |= BIT5;
	else if (output->pin == 6) *port |= BIT6;
	else if (output->pin == 7) *port |= BIT7;
	
}

void clearDigitalOutput(DigitalOutput* output)
{
	volatile unsigned char* port;
	if		(output->portNum == 1)  port = &P1OUT;
	else if (output->portNum == 2)  port = &P2OUT;
	else if (output->portNum == 3)  port = &P3OUT;
	else if (output->portNum == 4)  port = &P4OUT;
	else if (output->portNum == 5)  port = &P5OUT;
	else if (output->portNum == 6)  port = &P6OUT;
	else if (output->portNum == 7)  port = &P7OUT;
	else if (output->portNum == 8)  port = &P8OUT;
	else if (output->portNum == 9)  port = &P9OUT;
	else if (output->portNum == 10) port = &P10OUT;
	
	if		(output->pin == 0) *port &= ~BIT0;
	else if (output->pin == 1) *port &= ~BIT1;
	else if (output->pin == 2) *port &= ~BIT2;
	else if (output->pin == 3) *port &= ~BIT3;
	else if (output->pin == 4) *port &= ~BIT4;
	else if (output->pin == 5) *port &= ~BIT5;
	else if (output->pin == 6) *port &= ~BIT6;
	else if (output->pin == 7) *port &= ~BIT7;
	
}

///////////////////////////////////////////////





