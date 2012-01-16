//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication source                                    //
//    last edited by: Craig Nemeth                              //
//    date: January 10, 2012                                    //
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
	// TODO
	
	//testing COM////////////////////////////////////////////////
	char testInfo[] = {'a','b','c'};

	Packet P;
	//malloc here?
	P.size = 23;
	
	char dest[] = {'V','E','4','U','M','_','1'};
	packetize(testInfo, &P, dest); //stuffing info into an AX.25 packet for VE4UM_1
	
	//heres where I want to test each byte
	//assert(pack[17] == 'a');
	/////////////////////////////////////////////////////////////
}

