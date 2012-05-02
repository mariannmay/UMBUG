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
	
	#if CDH_PROCESSOR_COMPILE
		initialize_SPI(1);
	#else
		initialize_SPI(0);
	#endif
	
}

void test_application_main(void)
{
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

	#if CDH_PROCESSOR_COMPILE
		int i;
		for(i=0; i<100; i++)
		{
			P5OUT ^= BIT1;              //always Toggle P5.1 if master
			spiSendByte(0x55);
			unsigned int x;
			for(x=50000;x>0;x--);       // Delay
		}
	#else
		for(;;)
		{
			printf("waiting for SPI\r\n");
			fflush(stdout);
			while(halSPIRXREADY==0)
			{
				printf(".");
				fflush(stdout);
			}
			printf("\r\n\n\n\n\nfinally got out of that damn loop!\r\n\n\n");
			fflush(stdout);
			char buff = halSPIRXBUF;
			if(buff==0x55)
			{
				P5OUT ^= BIT1; //if connected to master toggle LED
			}
		}
	#endif
	
	//fflush(stdout);
	
	//printf("    COM test complete\r\n");
	//fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
