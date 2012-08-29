//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication source                                    //
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "TestApplication.h"

void test_application_initialize(void)
{
	#if DebugMode
		#if CDH_PROCESSOR_COMPILE
			logLine("running test on CDH processor");
			logLine("please check UMSATS_CDH_log.txt");
		#else
			logLine("running test on COM processor");
			logLine("please check UMSATS_COM_log.txt");
		#endif
	#endif
}

void test_application_main(void)
{
	#if DebugMode
		//test_SPI();
		//test_analogToDigital();
	
		//test_SPI_framework();
		//test_SPI_framework_2();
		//int i;
		//for (i = 0;i < 10000;i++)
		//{
			//test_sdCard();
		//}
		
	
		//test_COMmain();
	
		//test_thermocouple();
		
		//test_digitalToAnalog();
		//test_radio();
		//test_PSK();
		test_toneGenerator();
		
		// don't comment out the ones below, please
		// if need be, change the #define in user_config.h
		// KA
		
		//#if RTC_CONNECTED
		//	test_realTimeClock();
		//#endif
		//test_BinaryCodedDecimal();
		
		
		logLine("");
		logLine("All tests complete! --------------------");
		system_abort();
		
	#endif
}

#if DebugMode
	
	//////////////////////////////////////////////////////////////////
	
	void test_SPI_framework(void)
	{
		#if CDH_PROCESSOR_COMPILE
			logLine("testing CDH SPI with framework");
			logLine("    transmitting: Kane is awesome **********");
			SPI_transmit(&devices.test_SPI_device, 'K', true);
			SPI_transmit(&devices.test_SPI_device, 'a', true);
			SPI_transmit(&devices.test_SPI_device, 'n', true);
			SPI_transmit(&devices.test_SPI_device, 'e', true);
			SPI_transmit(&devices.test_SPI_device, ' ', true);
			SPI_transmit(&devices.test_SPI_device, 'i', true);
			SPI_transmit(&devices.test_SPI_device, 's', true);
			SPI_transmit(&devices.test_SPI_device, ' ', true);
			SPI_transmit(&devices.test_SPI_device, 'a', true);
			SPI_transmit(&devices.test_SPI_device, 'w', true);
			SPI_transmit(&devices.test_SPI_device, 'e', true);
			SPI_transmit(&devices.test_SPI_device, 's', true);
			SPI_transmit(&devices.test_SPI_device, 'o', true);
			SPI_transmit(&devices.test_SPI_device, 'm', true);
			SPI_transmit(&devices.test_SPI_device, 'e', true);
			SPI_transmit(&devices.test_SPI_device, ' ', true);
		
			int i;
			for (i = 0; i < 10; i++)
			{
				SPI_transmit(&devices.test_SPI_device, '*', true);
			}
			
			SPI_transmit(&devices.test_SPI_device, '\r', true);
			SPI_transmit(&devices.test_SPI_device, '\n', true);
			
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
			SPI_transmitStream(&devices.test_SPI_device, array, 8, true);
			
			SPI_transmit(&devices.test_SPI_device, '\r', true);
			SPI_transmit(&devices.test_SPI_device, '\n', true);
		
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
	
	// private
	extern void realTimeClock_unprotect(RealTimeClock* clock);
	
	void test_realTimeClock(void)
	{
		logLine("\r\ntesting real time clock");
		if (!initialize_SPI(&devices.realTimeClock.SPI))
		{
			logLine("    Could not initialize SPI\r\n");
			return;
		}
		
		// each transaction with the rtc must be a burst of at least
		// 2 bytes.  The first byte, you tell it what address to use
		// in the following byte.
		// On a read, the second byte will come to you from rtc.
		// On a write, the second byte must be sent to the rtc.
		
	
		// Poll the status register
		realTimeClock_unprotect(&devices.realTimeClock);
		//printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[0]));
		//printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[1]));
		
		Byte toRTC[2];
		toRTC[0] = RTC_READ_CONTROL_REGISTER;
		toRTC[1] = EMPTY_CHAR;
		SPI_transmitStream(&devices.realTimeClock.SPI, toRTC, 2, true);
		//printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[0]));
		//printf("transmission: %x\r\n", (devices.realTimeClock.SPI.transmitMessage[1]));
		
		// should have read the byte you just wrote (RTC_DISABLE_WRITE_PROTECT)
		//printf("read control register: %x\r\n", (devices.realTimeClock.SPI.receiveMessage[0]));
		//printf("read control register: %x\r\n\r\n", (devices.realTimeClock.SPI.receiveMessage[1]));
		assert(devices.realTimeClock.SPI.receiveMessage[1] == RTC_DISABLE_WRITE_PROTECT);
		logLine("    real time clock test write was successful");
		
		// test the time set function
		Time t;
		t.seconds	= 0x01;	// 
		t.minutes	= 0x37; // 
		t.hours		= 0x20; // 20:37:01
		t.day		= 0x05; // Friday
		t.date		= 0x03; // 3rd
		t.month		= 0x08; // August
		t.year		= 0x12; // 2012
		bool timeSetSuccessfully = realTimeClock_set(&devices.realTimeClock, &t);
		assert(timeSetSuccessfully);
		logLine("    real time clock successfully set to 8:37 August 3, 2012");
		
		fflush(stdout);
	
	}
	
	///////////////////////////////////////////////////////////////////
	
	void test_sdCard(void)
	{
		logLine("Testing the SD card");
		
		// only defined on COM processor
		#if COM_PROCESSOR_COMPILE
		/*
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
			toSD[8] = DUMMY_CHAR;
			toSD[9] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 10, true);
	
			toSD[0] = 0x40;
			toSD[1] = EMPTY_CHAR;
			toSD[2] = EMPTY_CHAR;
			toSD[3] = EMPTY_CHAR;
			toSD[4] = EMPTY_CHAR;
			toSD[5] = 0x95;
			toSD[6] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 7, true); //CMD0
			
			toSD[0] = DUMMY_CHAR;
			toSD[1] = DUMMY_CHAR;
			toSD[2] = DUMMY_CHAR;
			toSD[3] = DUMMY_CHAR;
			toSD[4] = DUMMY_CHAR;
			toSD[5] = DUMMY_CHAR;
			toSD[6] = DUMMY_CHAR;
			toSD[7] = DUMMY_CHAR;
			toSD[8] = DUMMY_CHAR;
			toSD[9] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 10, true);
			
			toSD[0] = 0x40;
			toSD[1] = EMPTY_CHAR;
			toSD[2] = EMPTY_CHAR;
			toSD[3] = EMPTY_CHAR;
			toSD[4] = 0x37; //0011 0111
			toSD[5] = DUMMY_CHAR;
			toSD[6] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 7, true); //CMD55
			
			toSD[0] = 0x40;
			toSD[1] = EMPTY_CHAR;
			toSD[2] = EMPTY_CHAR;
			toSD[3] = EMPTY_CHAR;
			toSD[4] = 0x29; //0010 1001
			toSD[5] = DUMMY_CHAR;
			toSD[6] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 7, true); //ACMD41
	
			toSD[0] = 0x40;
			toSD[1] = EMPTY_CHAR;
			toSD[2] = EMPTY_CHAR;
			toSD[3] = EMPTY_CHAR;
			toSD[4] = 0x11;
			toSD[5] = DUMMY_CHAR;
			toSD[6] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 7, true); //CMD17
			
			int count;
			int num;
			for(num=0;num<16;num++)
			{
				for(count=0;count<32;count++)
				{
					toSD[count] = DUMMY_CHAR;
				}
				SPI_transmitStream(&devices.sdCard.SPI, toSD, 32, true); //DUMMY x 512
			}		
			
			toSD[0] = 0x40;
			toSD[1] = EMPTY_CHAR;
			toSD[2] = EMPTY_CHAR;
			toSD[3] = EMPTY_CHAR;
			toSD[4] = 0x0D;
			toSD[5] = DUMMY_CHAR;
			toSD[6] = DUMMY_CHAR;
			SPI_transmitStream(&devices.sdCard.SPI, toSD, 7, true); //CMD13
		*/
		
		enableInterrupts();				// Enable Interrupts
	
	int error = NO_ERROR;
	
	
        error = sd_init();					// Power up the SD card
        
	if(error)
		printf("Error: init_sd()\n");
	
	printf("Init done\n");
	
	  int i = 0;
	  char tx[512] = {0};
	  char rx[512] = {0};

        //generate test data
        for (i = 0; i < 10; i++)
        {  tx[i] = i%0xff;
        }

        error = sd_write(tx,10, 1);       
        
        error = sd_read(rx, 10,1);
        
        
        //verify the data...
        for (i = 0; i < 10; i++)
          printf("0x%02x ", rx[i]);
      
	
	error = sd_power_down();			// Power down the SD card
	if(error)
		printf("Error: power_down_sd()\n");
	
		#endif
	}
	
	void test_COMmain(void)
	{
		#if COM_PROCESSOR_COMPILE
		
		//nvm im just gonna put this straight into  a real com main
		
		#endif
	}
	
	///////////////////////////////////////////////////////////////////
	
	void test_toneGenerator(void)
	{
		enableInterrupts();
		
		#if COM_PROCESSOR_COMPILE
			for (;;)
			{
				//startNewDigitalToAnalogConversion(devices.radio.microphone->value);
				
				//UI16 wait;
				//for (wait = 6000; wait --> 0;) { }
			}
		#endif
	}
	
	///////////////////////////////////////////////////////////////////
	
	void test_PSK(void)
	{
		logLine("Testing PSK");
		
		disableInterrupts();
	
		Byte data[8];
		data[0] = 0xFF;
		data[1] = 0xFF;
		data[2] = 0xA1;
		data[3] = 0x2C;
		data[4] = 0xB6;
		data[5] = 0x10;
		data[6] = 0x00;
		data[7] = 0x89;
		
		printf("data: ");
		int i;
		for(i = 0; i < 8; i++)
		{
			printf(" %x\t", data[i]);
		}
		fflush(stdout);
		
		convertBinaryToPSK(data,8);
		
		printf("\n\nPhase Shift History: ");
		for(i = 0; i < PhaseShiftHistoryLength; i++)
		{
			printf("%d, ", phaseShifts[i]);
		}
		printf("\n");
		
		enableInterrupts();
		
	}
	
	///////////////////////////////////////////////////////////////////
	
	void test_BinaryCodedDecimal(void)
	{
		logLine("\r\nTesting conversion of binary coded decimal (BCD) numbers");
		
		BCD_Value result;
		
		int i;
		for (i = 0; i < 10; i++)
		{
			result = convertDecimalToBinaryCodedDecimal(i);
			assert(result == i);
		}
		
		result = convertDecimalToBinaryCodedDecimal(10);
		assert(result == 0x10);
		
		result = convertDecimalToBinaryCodedDecimal(12);
		assert(result == 0x12);
		
		result = convertDecimalToBinaryCodedDecimal(23);
		assert(result == 0x23);
		
		result = convertDecimalToBinaryCodedDecimal(33);
		assert(result == 0x33);
		
		result = convertDecimalToBinaryCodedDecimal(50);
		assert(result == 0x50);
		
		result = convertDecimalToBinaryCodedDecimal(62);
		assert(result == 0x62);
		
		result = convertDecimalToBinaryCodedDecimal(87);
		assert(result == 0x87);
		
		result = convertDecimalToBinaryCodedDecimal(99);
		assert(result == 0x99);
		
		result = convertDecimalToBinaryCodedDecimal(100);
		assert(result == 0x00);
		
		result = convertDecimalToBinaryCodedDecimal(159);
		assert(result == 0x00);
		
		result = convertDecimalToBinaryCodedDecimal(255);
		assert(result == 0x00);
		
		logLine("    BCD is OK");
		
	}
	
	///////////////////////////////////////////////////////////////////
	
	// put other tests here


#endif
