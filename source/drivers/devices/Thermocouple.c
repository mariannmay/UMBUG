//////////////////////////////////////////////////////////////////
//                                                              //
//    Thermocouple source                                       //
//    last edited by: Kane Anderson                             //
//    date: 08/13/2012		                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Thermocouple.h"

// functions //////////////////////////////////

void thermocouple_initialize(Thermocouple* thermocouple)
{
	// TODO
}

Word thermocouple_read(Thermocouple* thermocouple)
{
	readAnalogInput(thermocouple->voltageInput);
	return thermocouple->voltageInput->value;
}

DegreesCelsius rawA2DToDegreesCelsius(Millivolts rawVoltage)
{
	// here I am timesing by 10 temporarily as a trick for keeping precision
	UI16 resistanceOnTheThermistor_times10 = (10 * rawVoltage * ThermocouplePullUpResistor) / (ThreePointThreeVolts - rawVoltage);
	
	//UI32 denominator_C_x1000000 = 
	
	return (DegreesCelsius) 0;
}
