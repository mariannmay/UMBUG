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

}

void test_application_main(void)
{
	//test_COM();
	test_analogToDigital();
	
	int D2A_tests;
	for (D2A_tests = 0; D2A_tests < 10; D2A_tests++)
	{ 
		test_digitalToAnalog();
	}
	
	printf("All tests complete! --------------------\r\n");
	fflush(stdout);
	system_abort();
}

//////////////////////////////////////////////////////////////////

void test_SPI(void)
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
			int waitTimer;
			for (waitTimer = 10000; waitTimer > 0; waitTimer--){ ; }
	
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
	
	//printf("    COM test complete\r\n");
	//fflush(stdout);
}

///////////////////////////////////////////////////////////////////

void test_analogToDigital(void)
{
	// TODO
}

///////////////////////////////////////////////////////////////////

void test_digitalToAnalog(void)
{
	int i;
	for (i = 0; i < 0xFFF; i++)
	{
		devices.radio.microphone->value = i;
		startNewDigitalToAnalogConversion(devices.radio.microphone->value, 0);
		//logCombo("set digital out on P6.6", i);
		
		readAnalogInput(devices.test_AtoD);
		//logCombo("read analog in on P6.5 ", devices.test_AtoD->value);
	}
}

///////////////////////////////////////////////////////////////////

// put other tests here
