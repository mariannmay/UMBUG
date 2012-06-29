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

			UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;
			if (nextCharToSend == ':') nextCharToSend = '1';
			
			P3OUT &= ~0x01; //set STE low for slave enable
			char buff = spiSendByte(nextCharToSend);
			printf("recieved: %c\n", buff);
			
			P3OUT |= 0x01; //set STE high for slave disable
			
			// just a time killing loop
			int waitTimer = 10000;
			for (waitTimer; waitTimer > 0; waitTimer--){ ; }
	
		}
	#else
		
		printf("    COM Slave Initialize\r\n");
		printf("Searching for: %c\n", 'C');
		fflush(stdout);
		
	  int x;
	  for(x =0;x<100;x++)
	  {

		UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
	  	UCB0TXBUF = 'C';
		while((P3IN & 0x01) == 0x01);	//wait for enable
		bool enabled = ((P3IN | 0xFE) == 0xFE);
		if (enabled)
		{
			//while (halSPITXREADY ==0);   // wait while not ready for TX
			//halSPI_SEND(0xFF);     // dummy write
			while (halSPIRXREADY ==0);   // wait for RX buffer (full)
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			
		}
		
	  }
	  
	#endif
	
	printf("    COM test complete\r\n");
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
