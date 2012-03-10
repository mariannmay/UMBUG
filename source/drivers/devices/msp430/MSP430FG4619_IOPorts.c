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

#include "./MSP430FG4619_IOPorts.h"

// global variable ///////////////////////////////////////////////

MSP430FG4619 msp430;

// initialize function ///////////////////////////////////////////

void initialize_msp430_IO_ports(void)
{
	// PORT_1
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[0],		0,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[1],		1,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[2],		2,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[3],		3,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[4],		4,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[5],		5,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[6],		6,		P1IN		);
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[7],		7,		P1IN		);
	
	// PORT_2
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[0],		0,		P2IN		);
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[1],		1,		P2IN		);
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[2],		2,		P2IN		);
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[3],		3,		P2IN		);
	initializeSerialOutput (	&msp430.PORT_2.serialOutput,		4,		P2OUT		);
	initializeSerialInput  (	&msp430.PORT_2.serialInput,			5,		P2IN		);
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[4],		6,		P2IN		);
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[5],		7,		P2IN		);
	
	// PORT_3
	initializeSerialOutput (	&msp430.PORT_3.serialOutput[0],		0,		P3OUT		);
	initializeSerialOutput (	&msp430.PORT_3.serialOutput[1],		1,		P3OUT		);
	initializeSerialInput  (	&msp430.PORT_3.serialInput[0],		2,		P3IN		);
	initializeSerialInput  (	&msp430.PORT_3.serialInput[1],		3,		P3IN		);
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[0],		4,		P3IN		);
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[1],		5,		P3IN		);
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[2],		6,		P3IN		);
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[3],		7,		P3IN		);
	
	// PORT_4
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[0],		0,		P4OUT		);
	initializeSerialInput  (	&msp430.PORT_4.serialInput[0],		1,		P4IN		);
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[1],		2,		P4OUT		);
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[2],		3,		P4OUT		);
	initializeSerialInput  (	&msp430.PORT_4.serialInput[1],		4,		P4IN		);
	initializeSerialInput  (	&msp430.PORT_4.serialInput[2],		5,		P4IN		);
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[3],		6,		P4OUT		);
	initializeSerialInput  (	&msp430.PORT_4.serialInput[3],		7,		P4IN		);
	
	// PORT_5
	initializeAnalogInput  (	&msp430.PORT_5.analogInput[0],		0,		ADC12MEM13	);
	initializeAnalogInput  (	&msp430.PORT_5.analogInput[1],		1,		ADC12MEM12	);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[0],		2,		P5IN		);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[1],		3,		P5IN		);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[2],		4,		P5IN		);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[3],		5,		P5IN		);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[4],		6,		P5IN		);
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[5],		7,		P5IN		);
	
	// PORT_6
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[0],		0,		ADC12MEM0	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[1],		1,		ADC12MEM1	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[2],		2,		ADC12MEM2	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[3],		3,		ADC12MEM3	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[4],		4,		ADC12MEM4	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[5],		5,		ADC12MEM5	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[6],		6,		ADC12MEM6	);
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[7],		7,		ADC12MEM7	);
	
	// PORT_7
	initializeSerialOutput (	&msp430.PORT_7.serialOutput[0],		0,		P7OUT		);
	initializeSerialOutput (	&msp430.PORT_7.serialOutput[1],		1,		P7OUT		);
	initializeSerialInput  (	&msp430.PORT_7.serialInput[0],		2,		P7IN		);
	initializeSerialInput  (	&msp430.PORT_7.serialInput[1],		3,		P7IN		);
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[0],	4,		P7OUT		);
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[1],	5,		P7OUT		);
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[2],	6,		P7OUT		);
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[3],	7,		P7OUT		);
	
	// PORT_8
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[0],	0,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[1],	1,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[2],	2,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[3],	3,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[4],	4,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[5],	5,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[6],	6,		P8OUT		);
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[7],	7,		P8OUT		);
	
	// PORT_9
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[0],	0,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[1],	1,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[2],	2,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[3],	3,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[4],	4,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[5],	5,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[6],	6,		P9OUT		);
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[7],	7,		P9OUT		);
	
	// PORT_10
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[0],	0,		P10OUT		);
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[1],	1,		P10OUT		);
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[2],	2,		P10OUT		);
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[3],	3,		P10OUT		);
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[4],	4,		P10OUT		);
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[5],	5,		P10OUT		);
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[0],		6,		ADC12MEM15	);
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[1],		7,		ADC12MEM14	);
	
	// select all pins (for now... can be more choosey later)
	P1SEL = P2SEL = P3SEL = P4SEL = P5SEL = 
	P6SEL = P7SEL = P8SEL = P9SEL = P10SEL = 0xFF;
	
	// configuring Analog to Digital conversion -------------------------------------
	initialize_analogToDigitalConverter();
	
	initialize_SPI();
	
	
}
