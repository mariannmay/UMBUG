//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of the processor                           //
//    last edited by: Kane Anderson                             //
//    date: March 8, 2012                                    	//
//																//
//	  Software representations of digital inputs and outputs	//
//	  and serial comms (or whatever other pins)					//
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef MSP430FG4619PINS_H
#define MSP430FG4619PINS_H

//////////////////////////////////////////////////////////////////

#include <msp430fg4619.h>
#include "../../../application/ApplicationConfig.h"
#include "../../IOTypes.h"
#include "./AnalogToDigitalConverter.h"
#include "./SPIDevice.h"

//////////////////////////////////////////////////////////////////

// struct to represent the mcu ///////////////////////////////////
typedef struct
{
	struct { DigitalInput		digitalInput[8]	;	} PORT_1;
	
	struct { DigitalInput		digitalInput[6]	;
			 SerialInput		serialInput		;
			 SerialOutput		serialOutput	;	} PORT_2;
			 
	struct { SerialInput		serialInput[2]	;
			 SerialOutput		serialOutput[2]	;
			 DigitalInput		digitalInput[4]	;	} PORT_3;
			 
	struct { SerialInput		serialInput[4]	;
			 SerialOutput		serialOutput[4]	;	} PORT_4;
	
	struct { AnalogInput		analogInput		;
			 DigitalOutput		digitalOutput	;
			 DigitalInput		digitalInput[6]	;	} PORT_5;
			 
	struct { AnalogInput		analogInput[8]	;	} PORT_6;
	
	struct { DigitalOutput		digitalOutput[4];
			 SerialInput		serialInput[2]	;
			 SerialOutput		serialOutput[2]	;	} PORT_7;
			 
	struct { DigitalOutput		digitalOutput[8];	} PORT_8;
	
	struct { DigitalOutput		digitalOutput[8];	} PORT_9;
	
	struct { DigitalOutput		digitalOutput[6];
			 AnalogInput		analogInput[2]	;	} PORT_10;
			 
	SerialInput										  TDI;
	SerialInput										  TCK;
	SerialInput										  TDO;
	
}
MSP430FG4619;

//////////////////////////////////////////////////////////////

extern MSP430FG4619 msp430;

//////////////////////////////////////////////////////////////

void initialize_msp430_IO_ports(void);

#endif
