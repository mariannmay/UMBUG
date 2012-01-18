//////////////////////////////////////////////////////////////////
//                                                              //
//    Spectrometer header                                      	//
//    last edited by: Kane Anderson                             //
//    date: January 12, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SPECTROMETER_H
#define SPECTROMETER_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	// just guessing 8 bytes... not sure
	volatile Byte byte[8];
}
SpectrometryData;

typedef struct
{
	DigitalInput something;
	DigitalOutput somethingElse;
	
	SpectrometryData data;
}
Spectrometer;


// functions //////////////////////////////////

void spectrometer_initialize(Spectrometer* spectrometer);
SpectrometryData readSpectrometer(Spectrometer* spectrometer);

#endif
