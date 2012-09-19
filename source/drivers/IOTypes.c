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
	bool answer;
	
	switch(input->portNum)
	{
		case  1	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P1IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P1IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P1IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P1IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P1IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P1IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P1IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P1IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  2	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P2IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P2IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P2IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P2IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P2IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P2IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P2IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P2IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  3	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P3IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P3IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P3IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P3IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P3IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P3IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P3IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P3IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  4	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P4IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P4IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P4IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P4IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P4IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P4IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P4IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P4IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  5	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P5IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P5IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P5IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P5IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P5IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P5IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P5IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P5IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  6	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P6IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P6IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P6IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P6IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P6IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P6IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P6IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P6IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  7	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P7IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P7IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P7IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P7IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P7IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P7IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P7IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P7IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  8	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P8IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P8IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P8IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P8IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P8IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P8IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P8IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P8IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  9	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P9IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P9IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P9IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P9IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P9IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P9IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P9IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P9IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		case  10	:
	
			switch(input->pin)
			{
				case	0 :	answer = (bool)((P10IN & BIT0) >> 0); break;
				case	1 :	answer = (bool)((P10IN & BIT1) >> 1); break;
				case	2 : answer = (bool)((P10IN & BIT2) >> 2); break;
				case	3 : answer = (bool)((P10IN & BIT3) >> 3); break;
				case	4 : answer = (bool)((P10IN & BIT4) >> 4); break;
				case	5 : answer = (bool)((P10IN & BIT5) >> 5); break;
				case	6 : answer = (bool)((P10IN & BIT6) >> 6); break;
				case	7 : answer = (bool)((P10IN & BIT7) >> 7); break;
				
				default	  : answer = false;
							
			}
			break;
			
		default	: answer = false;
	}
	
	input->state = answer;
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
	output->state = high;
	
	switch(output->portNum)
	{
		case 1	:	
			switch(output->pin)
			{
				case 0	:	P1OUT |= BIT0; break;
				case 1	:	P1OUT |= BIT1; break;
				case 2	:	P1OUT |= BIT2; break;
				case 3	:	P1OUT |= BIT3; break;
				case 4	:	P1OUT |= BIT4; break;
				case 5	:	P1OUT |= BIT5; break;
				case 6	:	P1OUT |= BIT6; break;
				case 7	:	P1OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
			
		case 2	:	
			switch(output->pin)
			{
				case 0	:	P2OUT |= BIT0; break;
				case 1	:	P2OUT |= BIT1; break;
				case 2	:	P2OUT |= BIT2; break;
				case 3	:	P2OUT |= BIT3; break;
				case 4	:	P2OUT |= BIT4; break;
				case 5	:	P2OUT |= BIT5; break;
				case 6	:	P2OUT |= BIT6; break;
				case 7	:	P2OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		case 3	:	
			switch(output->pin)
			{
				case 0	:	P3OUT |= BIT0; break;
				case 1	:	P3OUT |= BIT1; break;
				case 2	:	P3OUT |= BIT2; break;
				case 3	:	P3OUT |= BIT3; break;
				case 4	:	P3OUT |= BIT4; break;
				case 5	:	P3OUT |= BIT5; break;
				case 6	:	P3OUT |= BIT6; break;
				case 7	:	P3OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 4	:	
			switch(output->pin)
			{
				case 0	:	P4OUT |= BIT0; break;
				case 1	:	P4OUT |= BIT1; break;
				case 2	:	P4OUT |= BIT2; break;
				case 3	:	P4OUT |= BIT3; break;
				case 4	:	P4OUT |= BIT4; break;
				case 5	:	P4OUT |= BIT5; break;
				case 6	:	P4OUT |= BIT6; break;
				case 7	:	P4OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 5	:	
			switch(output->pin)
			{
				case 0	:	P5OUT |= BIT0; break;
				case 1	:	P5OUT |= BIT1; break;
				case 2	:	P5OUT |= BIT2; break;
				case 3	:	P5OUT |= BIT3; break;
				case 4	:	P5OUT |= BIT4; break;
				case 5	:	P5OUT |= BIT5; break;
				case 6	:	P5OUT |= BIT6; break;
				case 7	:	P5OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 6	:	
			switch(output->pin)
			{
				case 0	:	P6OUT |= BIT0; break;
				case 1	:	P6OUT |= BIT1; break;
				case 2	:	P6OUT |= BIT2; break;
				case 3	:	P6OUT |= BIT3; break;
				case 4	:	P6OUT |= BIT4; break;
				case 5	:	P6OUT |= BIT5; break;
				case 6	:	P6OUT |= BIT6; break;
				case 7	:	P6OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 7	:	
			switch(output->pin)
			{
				case 0	:	P7OUT |= BIT0; break;
				case 1	:	P7OUT |= BIT1; break;
				case 2	:	P7OUT |= BIT2; break;
				case 3	:	P7OUT |= BIT3; break;
				case 4	:	P7OUT |= BIT4; break;
				case 5	:	P7OUT |= BIT5; break;
				case 6	:	P7OUT |= BIT6; break;
				case 7	:	P7OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 8	:	
			switch(output->pin)
			{
				case 0	:	P8OUT |= BIT0; break;
				case 1	:	P8OUT |= BIT1; break;
				case 2	:	P8OUT |= BIT2; break;
				case 3	:	P8OUT |= BIT3; break;
				case 4	:	P8OUT |= BIT4; break;
				case 5	:	P8OUT |= BIT5; break;
				case 6	:	P8OUT |= BIT6; break;
				case 7	:	P8OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 9	:	
			switch(output->pin)
			{
				case 0	:	P9OUT |= BIT0; break;
				case 1	:	P9OUT |= BIT1; break;
				case 2	:	P9OUT |= BIT2; break;
				case 3	:	P9OUT |= BIT3; break;
				case 4	:	P9OUT |= BIT4; break;
				case 5	:	P9OUT |= BIT5; break;
				case 6	:	P9OUT |= BIT6; break;
				case 7	:	P9OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 10	:	
			switch(output->pin)
			{
				case 0	:	P10OUT |= BIT0; break;
				case 1	:	P10OUT |= BIT1; break;
				case 2	:	P10OUT |= BIT2; break;
				case 3	:	P10OUT |= BIT3; break;
				case 4	:	P10OUT |= BIT4; break;
				case 5	:	P10OUT |= BIT5; break;
				case 6	:	P10OUT |= BIT6; break;
				case 7	:	P10OUT |= BIT7; break;
				
				default	:	return;
			}
			break;
		
		default	:	return;
	}
	
}

void clearDigitalOutput(DigitalOutput* output)
{
	output->state = low;
	
	switch(output->portNum)
	{
		case 1	:	
			switch(output->pin)
			{
				case 0	:	P1OUT &= ~BIT0; break;
				case 1	:	P1OUT &= ~BIT1; break;
				case 2	:	P1OUT &= ~BIT2; break;
				case 3	:	P1OUT &= ~BIT3; break;
				case 4	:	P1OUT &= ~BIT4; break;
				case 5	:	P1OUT &= ~BIT5; break;
				case 6	:	P1OUT &= ~BIT6; break;
				case 7	:	P1OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
			
		case 2	:	
			switch(output->pin)
			{
				case 0	:	P2OUT &= ~BIT0; break;
				case 1	:	P2OUT &= ~BIT1; break;
				case 2	:	P2OUT &= ~BIT2; break;
				case 3	:	P2OUT &= ~BIT3; break;
				case 4	:	P2OUT &= ~BIT4; break;
				case 5	:	P2OUT &= ~BIT5; break;
				case 6	:	P2OUT &= ~BIT6; break;
				case 7	:	P2OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		case 3	:	
			switch(output->pin)
			{
				case 0	:	P3OUT &= ~BIT0; break;
				case 1	:	P3OUT &= ~BIT1; break;
				case 2	:	P3OUT &= ~BIT2; break;
				case 3	:	P3OUT &= ~BIT3; break;
				case 4	:	P3OUT &= ~BIT4; break;
				case 5	:	P3OUT &= ~BIT5; break;
				case 6	:	P3OUT &= ~BIT6; break;
				case 7	:	P3OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 4	:	
			switch(output->pin)
			{
				case 0	:	P4OUT &= ~BIT0; break;
				case 1	:	P4OUT &= ~BIT1; break;
				case 2	:	P4OUT &= ~BIT2; break;
				case 3	:	P4OUT &= ~BIT3; break;
				case 4	:	P4OUT &= ~BIT4; break;
				case 5	:	P4OUT &= ~BIT5; break;
				case 6	:	P4OUT &= ~BIT6; break;
				case 7	:	P4OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 5	:	
			switch(output->pin)
			{
				case 0	:	P5OUT &= ~BIT0; break;
				case 1	:	P5OUT &= ~BIT1; break;
				case 2	:	P5OUT &= ~BIT2; break;
				case 3	:	P5OUT &= ~BIT3; break;
				case 4	:	P5OUT &= ~BIT4; break;
				case 5	:	P5OUT &= ~BIT5; break;
				case 6	:	P5OUT &= ~BIT6; break;
				case 7	:	P5OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 6	:	
			switch(output->pin)
			{
				case 0	:	P6OUT &= ~BIT0; break;
				case 1	:	P6OUT &= ~BIT1; break;
				case 2	:	P6OUT &= ~BIT2; break;
				case 3	:	P6OUT &= ~BIT3; break;
				case 4	:	P6OUT &= ~BIT4; break;
				case 5	:	P6OUT &= ~BIT5; break;
				case 6	:	P6OUT &= ~BIT6; break;
				case 7	:	P6OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 7	:	
			switch(output->pin)
			{
				case 0	:	P7OUT &= ~BIT0; break;
				case 1	:	P7OUT &= ~BIT1; break;
				case 2	:	P7OUT &= ~BIT2; break;
				case 3	:	P7OUT &= ~BIT3; break;
				case 4	:	P7OUT &= ~BIT4; break;
				case 5	:	P7OUT &= ~BIT5; break;
				case 6	:	P7OUT &= ~BIT6; break;
				case 7	:	P7OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 8	:	
			switch(output->pin)
			{
				case 0	:	P8OUT &= ~BIT0; break;
				case 1	:	P8OUT &= ~BIT1; break;
				case 2	:	P8OUT &= ~BIT2; break;
				case 3	:	P8OUT &= ~BIT3; break;
				case 4	:	P8OUT &= ~BIT4; break;
				case 5	:	P8OUT &= ~BIT5; break;
				case 6	:	P8OUT &= ~BIT6; break;
				case 7	:	P8OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 9	:	
			switch(output->pin)
			{
				case 0	:	P9OUT &= ~BIT0; break;
				case 1	:	P9OUT &= ~BIT1; break;
				case 2	:	P9OUT &= ~BIT2; break;
				case 3	:	P9OUT &= ~BIT3; break;
				case 4	:	P9OUT &= ~BIT4; break;
				case 5	:	P9OUT &= ~BIT5; break;
				case 6	:	P9OUT &= ~BIT6; break;
				case 7	:	P9OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		case 10	:	
			switch(output->pin)
			{
				case 0	:	P10OUT &= ~BIT0; break;
				case 1	:	P10OUT &= ~BIT1; break;
				case 2	:	P10OUT &= ~BIT2; break;
				case 3	:	P10OUT &= ~BIT3; break;
				case 4	:	P10OUT &= ~BIT4; break;
				case 5	:	P10OUT &= ~BIT5; break;
				case 6	:	P10OUT &= ~BIT6; break;
				case 7	:	P10OUT &= ~BIT7; break;
				
				default	:	return;
			}
			break;
		
		default	:	return;
	}
	
}

///////////////////////////////////////////////





