//////////////////////////////////////////////////////////////////
//                                                              //
//    Multiplexer header                                        //
//    last edited by: Kane Anderson                             //
//    date: November 23, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef MULTIPLEXER_H
#define MULTIPLEXER_H

#include <msp430fg4619.h>
#include "../DriversConfig.h"

///////////////////////////////////////////////

// structure //////////////////////////////////
typedef struct
{
	bool S0;
	DigitalInput in0;
	DigitalInput in1;
	DigitalOutput out;
}
MUX_2_1;

typedef struct
{
	bool S0;
	bool S1;
	DigitalInput in0;
	DigitalInput in1;
	DigitalInput in2;
	DigitalInput in3;
	DigitalOutput out;
}
MUX_4_1;

typedef struct
{
	bool S0;
	bool S1;
	bool S2;
	DigitalInput in0;
	DigitalInput in1;
	DigitalInput in2;
	DigitalInput in3;
	DigitalInput in4;
	DigitalInput in5;
	DigitalInput in6;
	DigitalInput in7;
	DigitalOutput out;
}
MUX_8_1;

typedef struct
{
	bool S0;
	DigitalInput in;
	DigitalOutput out0;
	DigitalOutput out1;
}
MUX_1_2;

// functions //////////////////////////////////

void mux_initialize(void);
void mux_2_1_Setup(MUX_2_1* mux, bool S0);
void mux_4_1_Setup(MUX_4_1* mux, bool S0, bool S1);
void mux_8_1_Setup(MUX_8_1* mux, bool S0, bool S1, bool S2);
void mux_1_2_Setup(MUX_1_2* mux, bool S0);

#endif
