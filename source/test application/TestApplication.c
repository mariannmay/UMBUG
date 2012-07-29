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

	//test_SPI_framework();
	//test_SPI_framework_2();
	//int i;
	//for (i = 0;i < 10000;i++)
	//{
	//	test_realTimeClock();
	//}
	//int i;
	//for (i = 0;i < 10000;i++)
	//{
		//test_sdCard();
	//}
	
	//test_thermocouple();
	
	//test_digitalToAnalog();
	test_radio();
	
	logLine("");
	logLine("All tests complete! --------------------");
	system_abort();
}

//////////////////////////////////////////////////////////////////

void test_SPI_framework(void)
{
	#if CDH_PROCESSOR_COMPILE
		logLine("testing CDH SPI with framework");
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
		
		SPI_transmit(&devices.test_SPI_device, '\r');
		SPI_transmit(&devices.test_SPI_device, '\n');
		
	#else
		logLine("testing COM SPI with framework");
		int i;
		for (i = 0; i < 28; i++)
		{
			SPI_receive(&devices.test_SPI_device);
			char received = devices.test_SPI_device.receiveMessage[0];
			if (received != DUMMY_CHAR)
			{
				printf("%c", received);
			}
		}
		printf("\r\nfinished receiving\r\n");
		fflush(stdout);
	#endif
}

// test 2

void test_SPI_framework_2(void)
{
		#if CDH_PROCESSOR_COMPILE
		logLine("testing CDH SPI with framework (2)");
		logLine("    transmitting: pwnage<-");
		logLine("    with one TX");
		Byte array[8] = {'p','w','n','a','g','e','<','-'};
		SPI_transmitStream(&devices.test_SPI_device, array, 8);
		
		SPI_transmit(&devices.test_SPI_device, '\r');
		SPI_transmit(&devices.test_SPI_device, '\n');
	
	#else
		logLine("testing COM SPI with framework (2)");
		int i;
		for (i = 0; i < 10; i++)
		{
			SPI_receive(&devices.test_SPI_device);
			char received = devices.test_SPI_device.receiveMessage[0];
			if (received != DUMMY_CHAR)
			{
				printf("%c", received);
			}
		}
		printf("\r\nfinished receiving\r\n");
		fflush(stdout);
	#endif
}

//////////////////////////////////////////////////////////////////

void test_SPI(void)
{
	logLine("testing SPI");
	
	P5DIR |= BIT1;                // P5.1 as output
  	P5OUT |= BIT1;                // P5.1 set high

	// testing SPI

	#if CDH_PROCESSOR_COMPILE
	
		// TODO uncomment and test
		/*
	
		P3OUT &= ~0x01;		// slave enable
		
		char nextCharToSend = '1';
		for(;;nextCharToSend++)
		{

			UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;
			if (nextCharToSend == ':') nextCharToSend = '1';
			
			P3OUT &= ~0x01;  // set STE low for slave enable
			char buff = spiSendByte(nextCharToSend);
			printf("recieved: %c\n", buff);
			
			P3OUT |= 0x01; // set STE high for slave disable
			
			// just a time killing loop
			int waitTimer;
			for (waitTimer = 10000; waitTimer > 0; waitTimer--){ ; }
	
		}
		*/
	#else		// SLAVE
		// TODO uncomment
		/*
		printf("    COM Slave Initialize\r\n");
		printf("Searching for: %c\n", 'C');
		fflush(stdout);
		
	  int x;
	  for(x =0;x<100;x++)
	  {

		UCB0CTL1 |= UCSWRST;
		UCB0CTL1 &= ~UCSWRST;
	  	UCB0TXBUF = 'C';
		while((P3IN & 0x01) == 0x01);	// wait for enable
		bool enabled = ((P3IN | 0xFE) == 0xFE);
		if (enabled)
		{
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			
		}
		
	  }
	  */
	#endif
	
}

///////////////////////////////////////////////////////////////////

void test_analogToDigital(void)
{
	// TODO
	logLine("testing A to D conversion");
}

void test_thermocouple(void)
{
	logLine("Testing thermocouple");
	Word raw;
	for (;;)
	{
		raw = thermocouple_read(&devices.testThermocouple);
		logCombo("raw voltage: ", raw);
	}
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
			#if COM_PROCESSOR_COMPILE
				devices.radio.microphone->value = i;
				
				startNewDigitalToAnalogConversion(devices.radio.microphone->value);
				
				// commented out to make it go faster
				// uncomment to print to file
				//logCombo("set digital out on pin 5", i);
				
				readAnalogInput(devices.test_AtoD);
				//logCombo("read analog in on pin 13", devices.test_AtoD->value);
			#endif
		}
	}
}

//////////////////////////////////////////////////////////////

void test_radio(void)
{
	#if COM_PROCESSOR_COMPILE
		logLine("testing output to radio");
		
		// 500 mV / 3.3 V = 620 / 4096
		#define radio_high 620
		#define radio_low 0
		
		bool toggle = low;
		
		for (;;)
		{
			toggle = toggle ? low : high;
			devices.radio.microphone->value = toggle ? radio_high : radio_low;
			startNewDigitalToAnalogConversion(devices.radio.microphone->value);
			int i;
			for (i = 0; i < 12000; i++) ; // wait
		}
		
		#undef radio_high
		#undef radio_low
	#endif
}

///////////////////////////////////////////////////////////////////

void test_realTimeClock(void)
{
	logLine("testing real time clock");
	
	// each transaction with the rtc must be a burst of at least
	// 2 bytes.  The first byte, you tell it what address to use
	// in the following byte.
	// On a read, the second byte will come to you from rtc.
	// On a write, the second byte must be sent to the rtc.
	
	// Poll the status register
	Byte toRTC[2];
	toRTC[0] = RTC_WRITE_CONTROL_REGISTER;
	toRTC[1] = RTC_DISABLE_WRITE_PROTECT;
	SPI_transmitStream(&devices.realTimeClock.SPI, toRTC, 2);
	printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[0]));
	printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[1]));
	
	toRTC[0] = RTC_READ_CONTROL_REGISTER;
	toRTC[1] = EMPTY_CHAR;
	SPI_transmitStream(&devices.realTimeClock.SPI, toRTC, 2);
	printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[0]));
	printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[1]));
	
	// should have read the byte you just wrote (RTC_DISABLE_WRITE_PROTECT)
	printf("read control register: %h\r\n\r\n", (devices.realTimeClock.SPI.receiveMessage[1]));
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////

void test_sdCard(void)
{
	logLine("Testing the SD card");
	
	// only defined on COM processor
	#if COM_PROCESSOR_COMPILE
	
		long i;
		for(i = 0; i < 10000; i++)
		{
			;	// wait
		}
	
		Byte toSD[32];
		
		toSD[0] = DUMMY_CHAR;
		toSD[1] = DUMMY_CHAR;
		toSD[2] = DUMMY_CHAR;
		toSD[3] = DUMMY_CHAR;
		toSD[4] = DUMMY_CHAR;
		toSD[5] = DUMMY_CHAR;
		toSD[6] = DUMMY_CHAR;
		toSD[7] = DUMMY_CHAR;
		SPI_transmitStream(&devices.sdCard.SPI, toSD, 8);

		toSD[0] = 0x40;
		toSD[1] = EMPTY_CHAR;
		toSD[2] = EMPTY_CHAR;
		toSD[3] = EMPTY_CHAR;
		toSD[4] = EMPTY_CHAR;
		toSD[5] = 0x95;
		toSD[6] = DUMMY_CHAR;
		toSD[7] = DUMMY_CHAR;
		toSD[8] = DUMMY_CHAR;
		SPI_transmitStream(&devices.sdCard.SPI, toSD, 9);
		
		toSD[0] = 0x40;
		toSD[1] = EMPTY_CHAR;
		toSD[2] = EMPTY_CHAR;
		toSD[3] = EMPTY_CHAR;
		toSD[4] = 0x0D;
		toSD[5] = DUMMY_CHAR;
		toSD[6] = DUMMY_CHAR;
		toSD[7] = DUMMY_CHAR;
		toSD[8] = DUMMY_CHAR;
		SPI_transmitStream(&devices.sdCard.SPI, toSD, 9);
		/*
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[0]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[1]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[2]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[3]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[4]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[5]);
		printf("transmitted: %x\r\n", devices.sdCard.SPI.transmitMessage[6]);
		fflush(stdout);
		*/
	#endif
}

///////////////////////////////////////////////////////////////////

// put other tests here

