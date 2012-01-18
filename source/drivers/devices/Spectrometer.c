//////////////////////////////////////////////////////////////////
//                                                              //
//    Spectrometer source                                      	//
//    last edited by: Kane Anderson                             //
//    date: January 12, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Spectrometer.h"

// functions //////////////////////////////////

void spectrometer_initialize(Spectrometer* spectrometer)
{
	// TODO
}

SpectrometryData readSpectrometer(Spectrometer* spectrometer)
{
	(*spectrometer).something.state = low;
	(*spectrometer).somethingElse.state = high;
	
	// TODO
	// finish this properly
	// replace the 0x00s with some read function
	// to read serial data from the spectrometer
	// or do whatever it is we need to do to read
	// the data
	
	(*spectrometer).data.byte[0] = 0x00;
	(*spectrometer).data.byte[1] = 0x00;
	(*spectrometer).data.byte[2] = 0x00;
	(*spectrometer).data.byte[3] = 0x00;
	(*spectrometer).data.byte[4] = 0x00;
	(*spectrometer).data.byte[5] = 0x00;
	(*spectrometer).data.byte[6] = 0x00;
	(*spectrometer).data.byte[7] = 0x00;
	
	return (*spectrometer).data;
}


