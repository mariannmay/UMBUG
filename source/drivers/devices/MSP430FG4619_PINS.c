//////////////////////////////////////////////////////////////////
//                                                              //
//    representation of the processor                           //
//    last edited by: Kane Anderson                             //
//    date: March 7, 2012                                    	//
//																//
//	  Software representations of digital inputs and outputs	//
//	  and serial comms (or whatever other pins)					//
//                                                              //
//////////////////////////////////////////////////////////////////

#include "./MSP430FG4619_PINS.h"

// global variable ///////////////////////////////////////////////

MSP430FG4619 msp430;

// initialize function ///////////////////////////////////////////

void initialize_msp430_IO_ports(void)
{
	// PORT_1
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[0],		0,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[1],		1,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[2],		2,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[3],		3,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[4],		4,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[5],		5,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[6],		6,		P1IN	);
	initializeDigitalInput(	&msp430.PORT_1.digitalInput[7],		7,		P1IN	);
	
	// PORT_2
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[0],		0,		P2IN	);
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[1],		1,		P2IN	);
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[2],		2,		P2IN	);
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[3],		3,		P2IN	);
	initializeSerialOutput(	&msp430.PORT_2.serialOutput,		4,		P2OUT	);
	initializeSerialInput (	&msp430.PORT_2.serialInput,			5,		P2IN	);
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[4],		6,		P2IN	);
	initializeDigitalInput(	&msp430.PORT_2.digitalInput[5],		7,		P2IN	);
	
	// PORT_3
	initializeSerialOutput(	&msp430.PORT_3.serialOutput[0],		0,		P3OUT	);
	initializeSerialOutput(	&msp430.PORT_3.serialOutput[1],		1,		P3OUT	);
	initializeSerialInput (	&msp430.PORT_3.serialInput[0],		2,		P3IN	);
	initializeSerialInput (	&msp430.PORT_3.serialInput[1],		3,		P3IN	);
	initializeDigitalInput(	&msp430.PORT_3.digitalInput[0],		4,		P3IN	);
	initializeDigitalInput(	&msp430.PORT_3.digitalInput[1],		5,		P3IN	);
	initializeDigitalInput(	&msp430.PORT_3.digitalInput[2],		6,		P3IN	);
	initializeDigitalInput(	&msp430.PORT_3.digitalInput[3],		7,		P3IN	);
	
	// PORT_4
	initializeSerialOutput(	&msp430.PORT_4.serialOutput[0],		0,		P4OUT	);
	initializeSerialInput (	&msp430.PORT_4.serialInput[0],		1,		P4IN	);
	initializeSerialOutput(	&msp430.PORT_4.serialOutput[1],		2,		P4OUT	);
	initializeSerialOutput(	&msp430.PORT_4.serialOutput[2],		3,		P4OUT	);
	initializeSerialInput (	&msp430.PORT_4.serialInput[1],		4,		P4IN	);
	initializeSerialInput (	&msp430.PORT_4.serialInput[2],		5,		P4IN	);
	initializeSerialOutput(	&msp430.PORT_4.serialOutput[3],		6,		P4OUT	);
	initializeSerialInput (	&msp430.PORT_4.serialInput[3],		7,		P4IN	);
	
	// PORT_5
	initializeAnalogInput ( &msp430.PORT_5.analogInput[0],		0,		P5IN	);
	initializeAnalogInput ( &msp430.PORT_6.analogInput[1],		1,		P5IN	);
	// YOU ARE HERE
	
	// PORT_6
	
	
	// PORT_7
	
	
	// PORT_8
	
	
	// PORT_9
	
	
	// PORT_10
	 
}
