//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of the processor's A2D                     //
//    last edited by: Kane Anderson                             //
//    date: May 30, 2012                                    	//
//																//
//////////////////////////////////////////////////////////////////

#ifndef ANALOGTODIGITALCONVERTER_H
#define ANALOGTODIGITALCONVERTER_H

//////////////////////////////////////////////////////////////////

#include <msp430fg4619.h>

//////////////////////////////////////////////////////////////////

#define AnalogToDigital_Port_5_0	ADC12MEM13
#define AnalogToDigital_Port_5_1	ADC12MEM12
#define AnalogToDigital_Port_6_0	ADC12MEM0
#define AnalogToDigital_Port_6_1	ADC12MEM1
#define AnalogToDigital_Port_6_2	ADC12MEM2
#define AnalogToDigital_Port_6_3	ADC12MEM3
#define AnalogToDigital_Port_6_4	ADC12MEM4
#define AnalogToDigital_Port_6_5	ADC12MEM5
#define AnalogToDigital_Port_6_6	ADC12MEM6
#define AnalogToDigital_Port_6_7	ADC12MEM7
#define AnalogToDigital_Port_10_6	ADC12MEM15
#define AnalogToDigital_Port_10_7	ADC12MEM14

//////////////////////////////////////////////////////////////////

void initialize_analogToDigitalConverter(void);
void startNewAnalogToDigitalConversion(void);

#endif
