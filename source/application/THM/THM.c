//////////////////////////////////////////////////////////////////
//                                                              //
//    THMApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: 08/13/2012		                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "THM.h"

///////////////////////////////////////////////////////////////////

void THM_application_main(void)
{
	// read the temperature
	thermocouple_read(&devices.tardigradeTemperatureSensor);
	
	// decide what to do based on the temperature
}

