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
	//char information[] = {0x01,0x0F,0x01};
	char pack[23];
	//COM.packetize(information, pack); //I'm trying to call my COM method
	//I tried including the COM folder into TestApplication.h so I could use the
	//method I wrote in the COMS folder
	int i;
	for(i =0; i<sizeof(pack); i++)
	{
		//heres where I want to test each byte but I forget how you said to do it
		//I'll ask next meeting about the syntax
	}
	/////////////////////////////////////////////////////////////
}

