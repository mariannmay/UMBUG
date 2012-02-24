//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication source                                    //
//    last edited by: Craig Nemeth                              //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "TestApplication.h"

//////////////////////////////////

void test_application_initialize(void)
{
	// TODO
}

void test_application_main(void)
{
	test_COM();
}

//////////////////////////////////////////////////////////////////

void test_COM(void)
{
	Data D;
	//malloc required?
	D.size = 3;
	D.type = true;
	D.index[0] = 'a';
	D.index[1] = 'b';
	D.index[2] = 'c';

	Packet P;
	//malloc here?
	P.size = D.size+20;
	
	char dest[] = {'V','E','4','U','M','_','1'};
	packetize(&D, &P, dest); //stuffing info into an AX.25 packet for VE4UM_1
	
	//heres where I want to test each byte
	//assert(pack[17] == 'a');
}

///////////////////////////////////////////////////////////////////

// put other tests here
