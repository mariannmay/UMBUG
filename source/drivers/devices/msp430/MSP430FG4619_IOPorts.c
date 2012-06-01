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
	// PORT_1																		CDH					COM
	P1DIR = 0x00; // 0000 0000
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[0],		1,	0	);	// 					/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[1],		1,	1	);	// 					/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[2],		1,	2	);	//  				/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[3],		1,	3	);	//  				/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[4],		1,	4	);	//  				/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[5],		1,	5	);	//  				/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[6],		1,	6	);	//  				/
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[7],		1,	7	);	//  				/

	// PORT_2																		CDH					COM
	P2DIR = 0x10; // 0001 0000
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[0],		2,	0	);	// digitalMUXIn0	/
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[1],		2,	1	);	// digitalMUXIn1	/
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[2],		2,	2	);	// digitalMUXIn2	/
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[3],		2,	3	);	//  				/
	initializeSerialOutput (	&msp430.PORT_2.serialOutput,		2,	4	);	//  				/
	initializeSerialInput  (	&msp430.PORT_2.serialInput,			2,	5	);	//  				/
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[4],		2,	6	);	//  				/
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[5],		2,	7	);	//  				/

	// PORT_3																		CDH					COM
	P3DIR = 0x03; // 0000 0011
	initializeSerialOutput (	&msp430.PORT_3.serialOutput[0],		3,	0	);	// SPI_1			/	SPI_1
	initializeSerialOutput (	&msp430.PORT_3.serialOutput[1],		3,	1	);	// SPI_1			/	SPI_1
	initializeSerialInput  (	&msp430.PORT_3.serialInput[0],		3,	2	);	// SPI_1			/	SPI_1
	initializeSerialInput  (	&msp430.PORT_3.serialInput[1],		3,	3	);	// SPI_1			/	SPI_1
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[0],		3,	4	);	//  				/
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[1],		3,	5	);	//  				/
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[2],		3,	6	);	//  				/
	initializeDigitalInput (	&msp430.PORT_3.digitalInput[3],		3,	7	);	//  				/

	// PORT_4																		CDH					COM
	P4DIR = 0x4D; // 0100 1101
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[0],		4,	0	);	//  				/
	initializeSerialInput  (	&msp430.PORT_4.serialInput[0],		4,	1	);	//  				/
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[1],		4,	2	);	//  				/
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[2],		4,	3	);	//  				/
	initializeSerialInput  (	&msp430.PORT_4.serialInput[1],		4,	4	);	//  				/
	initializeSerialInput  (	&msp430.PORT_4.serialInput[2],		4,	5	);	//  				/
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[3],		4,	6	);	//  				/
	initializeSerialInput  (	&msp430.PORT_4.serialInput[3],		4,	7	);	//  				/

	// PORT_5																		CDH					COM
	P5DIR = 0x02; // 0000 0010
	initializeAnalogInput  (	&msp430.PORT_5.analogInput,			5,	0	);	// Temperature1		/
	initializeDigitalOutput(	&msp430.PORT_5.digitalOutput,		5,	1	);	//  				/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[0],		5,	2	);	//  				/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[1],		5,	3	);	//  				/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[2],		5,	4	);	//  				/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[3],		5,	5	);	// sd card detect	/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[4],		5,	6	);	//  				/
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[5],		5,	7	);	//  				/

	// PORT_6																		CDH					COM
	P6DIR = 0X00; // 0000 0000
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[0],		6,	0	);	//  analogMUXIn0	/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[1],		6,	1	);	//  analogMUXIn1	/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[2],		6,	2	);	//  analogMUXIn2	/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[3],		6,	3	);	//  				/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[4],		6,	4	);	//  				/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[5],		6,	5	);	//  				/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[6],		6,	6	);	//  				/
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[7],		6,	7	);	//  				/

	// PORT_7																		CDH					COM
	P7DIR = 0xF3; // 1111 0011
	initializeSerialOutput (	&msp430.PORT_7.serialOutput[0],		7,	0	);	//  				/
	initializeSerialOutput (	&msp430.PORT_7.serialOutput[1],		7,	1	);	//  				/
	initializeSerialInput  (	&msp430.PORT_7.serialInput[0],		7,	2	);	//  				/
	initializeSerialInput  (	&msp430.PORT_7.serialInput[1],		7,	3	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[0],	7,	4	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[1],	7,	5	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[2],	7,	6	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[3],	7,	7	);	//  				/

	// PORT_8																		CDH					COM
	P8DIR = 0xFF; // 1111 1111
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[0],	8,	0	);	// 					/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[1],	8,	1	);	// MUX select 0		/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[2],	8,	2	);	// MUX select 1		/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[3],	8,	3	);	// MUX select 2		/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[4],	8,	4	);	// digitalMUXOut0	/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[5],	8,	5	);	// digitalMUXOut1	/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[6],	8,	6	);	// digitalMUXOut2	/
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[7],	8,	7	);	//  				/

	// PORT_9																		CDH					COM
	P9DIR = 0xFF; // 1111 1111
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[0],	9,	0	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[1],	9,	1	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[2],	9,	2	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[3],	9,	3	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[4],	9,	4	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[5],	9,	5	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[6],	9,	6	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[7],	9,	7	);	//  				/

	// PORT_10																		CDH					COM
	P10DIR = 0x3F; // 0011 1111
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[0],	10,	0	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[1],	10,	1	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[2],	10,	2	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[3],	10,	3	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[4],	10,	4	);	//  				/
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[5],	10,	5	);	// watchdog WDI		/
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[0],		10,	6	);	//  				/
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[1],		10,	7	);	//  				/

	// configuring Analog to Digital conversion -------------------------------------
	initialize_analogToDigitalConverter();

	if(CDH_PROCESSOR_COMPILE)
	{
		initialize_SPI(1);
	}
	else
	{
		if(COM_PROCESSOR_COMPILE)
		{
			initialize_SPI(0);
		}
	}
}
