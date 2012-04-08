//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication source                                    //
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "TestApplication.h"

//////////////////////////////////

void test_application_initialize(void)
{
	printf("Test application start -----------------\r\n");
	fflush(stdout);
}

void test_application_main(void)
{
	
  	WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
	test_COM();
	
	printf("All tests complete! --------------------\r\n");
	fflush(stdout);
	system_abort();
}

//////////////////////////////////////////////////////////////////

void test_COM(void)
{
	/*
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
	*/
	
	P5DIR |= BIT1;                // P5.1 as output
  	P5OUT |= BIT1;                // P5.1 set high
	
	
	//testing SPI
	int i;
	for(i=0; i<10; i++)
	{
		P5OUT ^= BIT1;              // Toggle P5.1
		//printf("ON/OFF");
		fflush(stdout);
		//ToggleStatusLED;
		
		// Kane commented this out because it was giving compile warnings
		//char* data;

		//SPI_EEPROM_readbyte(data, i);
		//printf("byte ");
		//printf(data);
		unsigned int x;
		for(x=50000;x>0;x--);       // Delay
	}
	
	printf("    COM test complete\r\n");
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
