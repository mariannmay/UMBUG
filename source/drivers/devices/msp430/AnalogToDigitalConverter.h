//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of the processor's A2D                     //
//    last edited by: Kane Anderson                             //
//    date: March 8, 2012                                    	//
//																//
//////////////////////////////////////////////////////////////////

#ifndef ANALOGTODIGITALCONVERTER_H
#define ANALOGTODIGITALCONVERTER_H

//////////////////////////////////////////////////////////////////

#include <msp430fg4619.h>

//////////////////////////////////////////////////////////////////

void initialize_analogToDigitalConverter(void);
void startNewAnalogToDigitalConversion(void);

#endif
