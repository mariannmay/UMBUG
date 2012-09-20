#ifndef HEATER_H_
#define HEATER_H_

// includes ///////////////////////////////////

#include "../DriversConfig.h"

// structure //////////////////////////////////
typedef struct
{
	DigitalOutput* voltageOutput;
}
Heater;

UI16 setHeater(Heater* heater);

#endif /*HEATER_H_*/
