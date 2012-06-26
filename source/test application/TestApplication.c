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
	
	P5DIR |= BIT1;                // P5.1 as output
  	P5OUT |= BIT1;                // P5.1 set high

	//testing SPI

	#if CDH_PROCESSOR_COMPILE
		P3OUT &= ~0x01;		// slave enable
		
		char nextCharToSend = '1';
		for(;;nextCharToSend++)
		{
			initialize_SPI(1);
			if (nextCharToSend == ':') nextCharToSend = '1';
			
			P3OUT &= ~0x01; //set STE low for slave enable
			spiSendByte(nextCharToSend);
			
			P3OUT |= 0x01; //set STE high for slave disable
			
			// just a time killing loop
			int waitTimer = 10000;
			for (waitTimer; waitTimer > 0; waitTimer--){ ; }
			
		}
	#else
		
		printf("    COM Slave Initialize\r\n");
		printf("Searching for: %c\n", 'C');
		fflush(stdout);

		for(;;)
		{
		  	initialize_SPI(0);
		  	UCB0TXBUF = 0xFF;
			while((P3IN & 0x01) == 0x01);	//wait for enable
			bool enabled = ((P3IN | 0xFE) == 0xFE);
			if (enabled)
			{
				while (halSPIRXREADY ==0);   // wait for RX buffer (full)
				char buff = UCB0RXBUF;
				printf("recieved: %c\n", buff);
				fflush(stdout);
			}
		}
		
	#endif
	
	printf("    COM test complete\r\n");
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
