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
	#if CDH_PROCESSOR_COMPILE
		logLine("running test on CDH processor");
		logLine("please check UMSATS_CDH_log.txt");
	#else
		logLine("running test on COM processor");
		logLine("please check UMSATS_COM_log.txt");
	#endif
}

void test_application_main(void)
{
	//test_SPI();
	//test_analogToDigital();
	//test_digitalToAnalog();
	test_SPI_framework();
	
	printf("All tests complete! --------------------\r\n");
	fflush(stdout);
	system_abort();
}

//////////////////////////////////////////////////////////////////

void test_SPI_framework(void)
{
	#if CDH_PROCESSOR_COMPILE
		logLine("testing SPI with framework");
		logLine("    transmitting: Kane is awesome **********");
		SPI_transmit(&devices.test_SPI_device, 'K');
		SPI_transmit(&devices.test_SPI_device, 'a');
		SPI_transmit(&devices.test_SPI_device, 'n');
		SPI_transmit(&devices.test_SPI_device, 'e');
		SPI_transmit(&devices.test_SPI_device, ' ');
		SPI_transmit(&devices.test_SPI_device, 'i');
		SPI_transmit(&devices.test_SPI_device, 's');
		SPI_transmit(&devices.test_SPI_device, ' ');
		SPI_transmit(&devices.test_SPI_device, 'a');
		SPI_transmit(&devices.test_SPI_device, 'w');
		SPI_transmit(&devices.test_SPI_device, 'e');
		SPI_transmit(&devices.test_SPI_device, 's');
		SPI_transmit(&devices.test_SPI_device, 'o');
		SPI_transmit(&devices.test_SPI_device, 'm');
		SPI_transmit(&devices.test_SPI_device, 'e');
		SPI_transmit(&devices.test_SPI_device, ' ');
	
		int i;
		for (i = 0; i < 10; i++)
		{
			SPI_transmit(&devices.test_SPI_device, '*');
		}
	#else
		logLine("testing SPI with framework");
		int i = 0;
		for (;;)
		{
			SPI_receive(&devices.test_SPI_device);
			char received = devices.test_SPI_device.receiveMessage;
			if (received != DUMMY_CHAR)
			{
				printf("%c", received);
			}
			else
			{
				i++;
				if (i > 1000)
				{
					fflush(stdout);
					i = 0;
				}
			}
		}
	#endif
}

//////////////////////////////////////////////////////////////////

void test_SPI(void)
{
	logLine("testing SPI");
	
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
	#else		// SLAVE
		
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
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			
		}
		
	  }
	  
	#endif
	
}

///////////////////////////////////////////////////////////////////

void test_analogToDigital(void)
{
	// TODO
	logLine("testing A to D conversion");
}

///////////////////////////////////////////////////////////////////

void test_digitalToAnalog(void)
{
	logLine("testing D to A conversion");
	
	int D2A_tests;
	for (D2A_tests = 0; D2A_tests < 10; D2A_tests++)
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
}

///////////////////////////////////////////////////////////////////

// put other tests here
