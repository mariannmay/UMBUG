//////////////////////////////////////////////////////////////////
//                                                              //
//    Thermocouple source                                       //
//    last edited by: Kane Anderson                             //
//    date: January 10, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Thermocouple.h"

// functions //////////////////////////////////

void thermocouple_initialize(void)
{
	// TODO
}

Word thermocouple_read(Thermocouple* thermocouple)
{
	readAnalogInput(thermocouple->voltageInput);
	return thermocouple->voltageInput->value;
}

