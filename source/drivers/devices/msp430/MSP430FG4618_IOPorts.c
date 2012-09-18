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

#include "./MSP430FG4618_IOPorts.h"

// global variable ///////////////////////////////////////////////

MSP430FG4618 msp430;

// initialize function ///////////////////////////////////////////

void initialize_msp430_IO_ports(void)
{
	// PORT_1																		Pin#		CDH					COM
	P1DIR = 0x00; // 0000 0000
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[0],		1,	0	);	// 	87		|					| CS in from SPI_1
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[1],		1,	1	);	// 	86		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[2],		1,	2	);	//  85		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[3],		1,	3	);	//  84		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[4],		1,	4	);	//  83		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[5],		1,	5	);	//  82		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[6],		1,	6	);	//  81		|					|
	initializeDigitalInput (	&msp430.PORT_1.digitalInput[7],		1,	7	);	//  80		|					|
	
	// PORT_2																		Pin#		CDH					COM
	P2DIR = 0x10; // 0001 0000
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[0],		2,	0	);	// 	79		| digitalMUXIn0		|
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[1],		2,	1	);	// 	78		| digitalMUXIn1		|
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[2],		2,	2	);	// 	77		| digitalMUXIn2		|
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[3],		2,	3	);	// 	76		|					|
	initializeSerialOutput (	&msp430.PORT_2.serialOutput,		2,	4	);	// 	75		|					|
	initializeSerialInput  (	&msp430.PORT_2.serialInput,			2,	5	);	// 	74		|					|
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[4],		2,	6	);	// 	73		|					|
	initializeDigitalInput (	&msp430.PORT_2.digitalInput[5],		2,	7	);	// 	72		|					|
	
	// PORT_3																		Pin#		CDH					COM
	#if CDH_PROCESSOR_COMPILE
		P3DIR = 0x0A; // 0000 1010
		initializeSerialInput  (	&msp430.PORT_3.serialInput[0],		3,	0	);	// 	71		| 					| 
		initializeSerialOutput (	&msp430.PORT_3.serialOutput[0],		3,	1	);	// 	70		| SPI_1_MOSI		| SPI_1_MOSI
		initializeSerialInput  (	&msp430.PORT_3.serialInput[0],		3,	2	);	// 	69		| SPI_1_MISO		| SPI_1_MISO
		initializeSerialOutput (	&msp430.PORT_3.serialOutput[1],		3,	3	);	// 	68		| SPI_1_CLK			| SPI_1_CLK
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[0],		3,	4	);	// 	67		|					|
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[1],		3,	5	);	//  66		|					| testInput on radio
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[2],		3,	6	);	// 	65		|					|
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[3],		3,	7	);	// 	64		|					|
		
	#elif COM_PROCESSOR_COMPILE
		P3DIR = 0x05; // 0000 0101
		initializeSerialOutput (	&msp430.PORT_3.serialOutput[0],		3,	0	);	// 	71		| 					| 
		initializeSerialInput  (	&msp430.PORT_3.serialInput[0],		3,	1	);	// 	70		| SPI_1_MOSI		| SPI_1_MOSI
		initializeSerialOutput (	&msp430.PORT_3.serialOutput[1],		3,	2	);	// 	69		| SPI_1_MISO		| SPI_1_MISO
		initializeSerialInput  (	&msp430.PORT_3.serialInput[1],		3,	3	);	// 	68		| SPI_1_CLK			| SPI_1_CLK
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[0],		3,	4	);	// 	67		|					|
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[1],		3,	5	);	//  66		|					| testInput on radio
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[2],		3,	6	);	// 	65		|					|
		initializeDigitalInput (	&msp430.PORT_3.digitalInput[3],		3,	7	);	// 	64		|					|
	#endif
	
	// PORT_4																		Pin#		CDH					COM
	P4DIR = 0x4D; // 0100 1101
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[0],		4,	0	);	//  63		|					|
	initializeSerialInput  (	&msp430.PORT_4.serialInput[0],		4,	1	);	//  62		|					|
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[1],		4,	2	);	//  51		|					|
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[2],		4,	3	);	//  50		|					|
	initializeSerialInput  (	&msp430.PORT_4.serialInput[1],		4,	4	);	//  49		|					|
	initializeSerialInput  (	&msp430.PORT_4.serialInput[2],		4,	5	);	//  48		|					|
	initializeSerialOutput (	&msp430.PORT_4.serialOutput[3],		4,	6	);	//  47		|					|
	initializeSerialInput  (	&msp430.PORT_4.serialInput[3],		4,	7	);	//  46		|					|
	
	// PORT_5																		Pin#		CDH					COM
	P5DIR = 0x02; // 0000 0010
	initializeAnalogInput  (	&msp430.PORT_5.analogInput,			5,	0	);	// 	13		|					| in from radio
	initializeDigitalOutput(	&msp430.PORT_5.digitalOutput,		5,	1	);	// 	12		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[0],		5,	2	);	// 	53		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[1],		5,	3	);	// 	54		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[2],		5,	4	);	// 	55		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[3],		5,	5	);	// 	56		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[4],		5,	6	);	// 	57		|					| 
	initializeDigitalInput (	&msp430.PORT_5.digitalInput[5],		5,	7	);	// 	58		|					| 
	
	// PORT_6																		Pin#		CDH					COM
	P6DIR = 0X40; // 0100 0000
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[0],		6,	0	);	//  95		| analogMUXIn0		|
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[1],		6,	1	);	//  96		| analogMUXIn1		|
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[2],		6,	2	);	//  97		| analogMUXIn2		|
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[3],		6,	3	);	// 	2		|					| 
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[4],		6,	4	);	// 	3		|					| 
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[5],		6,	5	);	// 	4		|					| 
	initializeAnalogOutput (	&msp430.PORT_6.analogOutput,		6,	6	);	//  5		| unused			| out to radio
	initializeAnalogInput  (	&msp430.PORT_6.analogInput[6],		6,	7	);	// 	6		|					| 
	
	// PORT_7																		Pin#		CDH					COM
	// YOU ARE HERE
	#if CDH_PROCESSOR_COMPILE
		P7DIR = 0xF3; // 1111 0011
		initializeSerialOutput (	&msp430.PORT_7.serialOutput[0],		7,	0	);	// 	45		|					| 
		initializeSerialOutput (	&msp430.PORT_7.serialOutput[1],		7,	1	);	// 	44		|					| 
		initializeSerialInput  (	&msp430.PORT_7.serialInput[0],		7,	2	);	// 	43		|					| 
		initializeSerialInput  (	&msp430.PORT_7.serialInput[1],		7,	3	);	// 	42		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[0],	7,	4	);	// 	41		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[1],	7,	5	);	// 	40		|	COM_SPI_CS		| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[2],	7,	6	);	// 	39		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[3],	7,	7	);	// 	38		|					|
	
	#elif COM_PROCESSOR_COMPILE
		P7DIR = 0xF3; // 1111 0011
		initializeSerialInput  (	&msp430.PORT_7.serialInput[0],		7,	0	);	// 	45		|					| 
		initializeSerialOutput (	&msp430.PORT_7.serialOutput[0],		7,	1	);	// 	44		|					| SPI_2
		initializeSerialInput  (	&msp430.PORT_7.serialInput[1],		7,	2	);	// 	43		|					| SPI_2
		initializeSerialOutput (	&msp430.PORT_7.serialOutput[1],		7,	3	);	// 	42		|					| SPI_2
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[0],	7,	4	);	// 	41		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[1],	7,	5	);	// 	40		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[2],	7,	6	);	// 	39		|					| 
		initializeDigitalOutput(	&msp430.PORT_7.digitalOutput[3],	7,	7	);	// 	38		|					|
	#endif 
	
	// PORT_8																		Pin#		CDH					COM
	P8DIR = 0xFF; // 1111 1111
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[0],	8,	0	);	// 	37		|					| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[1],	8,	1	);	// 	36		| MUX select 0		| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[2],	8,	2	);	// 	35		| MUX select 1		| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[3],	8,	3	);	// 	34		| MUX select 2		| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[4],	8,	4	);	// 	33		| digitalMUXOut0	| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[5],	8,	5	);	// 	32		| digitalMUXOut1	| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[6],	8,	6	);	// 	31		| digitalMUXOut2	| 
	initializeDigitalOutput(	&msp430.PORT_8.digitalOutput[7],	8,	7	);	//  30		|					|
	
	// PORT_9																		Pin#		CDH					COM
	P9DIR = 0xFF; // 1111 1111
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[0],	9,	0	);	//  29		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[1],	9,	1	);	//  28		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[2],	9,	2	);	//  27		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[3],	9,	3	);	//  26		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[4],	9,	4	);	//  25		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[5],	9,	5	);	//  24		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[6],	9,	6	);	//  23		|					|
	initializeDigitalOutput(	&msp430.PORT_9.digitalOutput[7],	9,	7	);	//  22		|					|
	
	// PORT_10																		Pin#		CDH					COM
	P10DIR = 0x3F; // 0011 1111
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[0],	10,	0	);	//  21		| 					| 
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[1],	10,	1	);	//  20		| 					| 
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[2],	10,	2	);	//  19		| 					| 
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[3],	10,	3	);	//  18		|					| SD card enable
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[4],	10,	4	);	// 	17		| RTC chip enable	|
	initializeDigitalOutput(	&msp430.PORT_10.digitalOutput[5],	10,	5	);	// 	16		| watchdog WDI		|
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[0],		10,	6	);	//  15		| 					| 
	initializeAnalogInput  (	&msp430.PORT_10.analogInput[1],		10,	7	);	//  14		| 					| 
	
	// configuring Analog to Digital conversion -------------------------------------
	initialize_analogToDigitalConverter();
	
	// configuring Digital to Analog conversion -------------------------------------
	initialize_digitalToAnalogConverter();
	
}




