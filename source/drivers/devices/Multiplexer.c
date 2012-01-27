//////////////////////////////////////////////////////////////////
//                                                              //
//    Multiplexer source                                        //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Multiplexer.h"

///////////////////////////////////////////////

// functions //////////////////////////////////

void mux_initialize(void)
{
	// TODO
}

void mux_2_1_Setup(MUX_2_1* mux, bool S0)
{
	     if (!S0) mux->out.state = mux->in0.state;
	else if ( S0) mux->out.state = mux->in1.state;
}

void mux_4_1_Setup(MUX_4_1* mux, bool S0, bool S1)
{
	     if (!S0 && !S1) mux->out.state = mux->in0.state;
	else if (!S0 &&  S1) mux->out.state = mux->in1.state;
	else if ( S0 && !S1) mux->out.state = mux->in2.state;
	else if ( S0 &&  S1) mux->out.state = mux->in3.state;
}

void mux_8_1_Setup(MUX_8_1* mux, bool S0, bool S1, bool S2)
{
	     if (!S0 && !S1 && !S2) mux->out.state = mux->in0.state;
	else if (!S0 && !S1 &&  S2) mux->out.state = mux->in1.state;
	else if (!S0 &&  S1 && !S2) mux->out.state = mux->in2.state;
	else if (!S0 &&  S1 &&  S2) mux->out.state = mux->in3.state;
	else if ( S0 && !S1 && !S2) mux->out.state = mux->in4.state;
	else if ( S0 && !S1 &&  S2) mux->out.state = mux->in5.state;
	else if ( S0 &&  S1 && !S2) mux->out.state = mux->in6.state;
	else if ( S0 &&  S1 &&  S2) mux->out.state = mux->in7.state;
}

void mux_1_2_Setup(MUX_1_2* mux, bool S0)
{
	if (!S0)
	{
		mux->out0.state = mux->in.state;
		mux->out1.state = low;
	}
	if (S0)
	{
		mux->out0.state = low;
		mux->out1.state = mux->in.state;
	}
}

