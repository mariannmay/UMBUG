//////////////////////////////////////////////////////////////////
//                                                              //
//    Thermocouple header                                     	//
//    last edited by: Kane Anderson                             //
//    date: January 10, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	AnalogInput voltageInput;
}
Thermocouple;

// functions //////////////////////////////////

void thermocouple_initialize(void);
Word thermocouple_read(Thermocouple* thermocouple);

#endif
