//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of the processor's A2D                     //
//    last edited by: Kane Anderson                             //
//    date: March 8, 2012                                    	//
//																//
//////////////////////////////////////////////////////////////////

#include "./AnalogToDigitalConverter.h"

//////////////////////////////////////////////////////////////////

void initialize_analogToDigitalConverter(void)
{
	ADC12CTL0 = 0x0000;		// allows you to configure the analog to digital port
	ADC12CTL1 = 0x0622;		// see user guide page 28-23 for more details, but...
							// conversion mode is 'sequence of channels' (page 28-12)
							// uses the internal oscillator
							// the a2d clock is divided into 2
							// sample and hold not inverted
							// SAMPCON is in pulse mode
							// timer A controls the Sample and Hold
							// the first sample is ADC12MEM0
	ADC12MCTL0 = 0x00;		// makes A0 go to MEM0, with V+ = Vcc and V- = Vss
	ADC12MCTL1 = 0x01;		// makes A1 go to MEM1, with V+ = Vcc and V- = Vss
	ADC12MCTL2 = 0x02;		// makes A2 go to MEM2, with V+ = Vcc and V- = Vss
	ADC12MCTL3 = 0x03;		// makes A3 go to MEM3, with V+ = Vcc and V- = Vss
	ADC12MCTL4 = 0x04;		// makes A4 go to MEM4, with V+ = Vcc and V- = Vss
	ADC12MCTL5 = 0x05;		// makes A5 go to MEM5, with V+ = Vcc and V- = Vss
	ADC12MCTL6 = 0x06;		// makes A6 go to MEM6, with V+ = Vcc and V- = Vss
	ADC12MCTL7 = 0x07;		// makes A7 go to MEM7, with V+ = Vcc and V- = Vss
	ADC12MCTL8 = 0x08;		// makes VeRef+ go to MEM8, with V+ = Vcc and V- = Vss
	ADC12MCTL9 = 0x09;		// makes VRef-/VeRef- go to MEM9, with V+ = Vcc and V- = Vss
	ADC12MCTL10 = 0x0A;		// makes temperature sensor go to MEM10, with V+ = Vcc and V- = Vss
	ADC12MCTL11 = 0x0B;		// makes (Vcc - Vss)/2 go to MEM11, with V+ = Vcc and V- = Vss
	ADC12MCTL12 = 0x0C;		// makes A12 go to MEM12, with V+ = Vcc and V- = Vss
	ADC12MCTL13 = 0x0D;		// makes A13 go to MEM13, with V+ = Vcc and V- = Vss
	ADC12MCTL14 = 0x0E;		// makes A14 go to MEM14, with V+ = Vcc and V- = Vss
	ADC12MCTL15 = 0x0F;		// makes A15 go to MEM15, with V+ = Vcc and V- = Vss
	ADC12IE = 0x00;			// disable analog to digital interrupts... we'll get to them soon enough
	ADC12CTL0 = 0x00F3; 	// see the user guide page 28-22 for interpretation
	P6SEL = 0xFF; 			// sets port 6 to use all 8 A2D
}

//////////////////////////////////////////////////////////////////

void startNewAnalogToDigitalConversion(void)
{
	// this involves toggling the ENC bit of the ADC12CTL0 register
	// see msp430fg4619 user guide page 28-12
	ADC12CTL0 &= 0xFFFD; // 1111 1111 1111 1101
	ADC12CTL0 |= 0x0002; // 0000 0000 0000 0010
	
}


