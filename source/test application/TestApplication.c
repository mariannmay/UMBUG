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
	logLine("Test application start -----------------\r\n");
	
	#if CDH_PROCESSOR_COMPILE
		initialize_SPI(1);
	#else
		initialize_SPI(0);
	#endif
	
}

void test_application_main(void)
{
	johnsonsTest();
	johnsonsTest();
	johnsonsTest();
	
	//test_COM();
	
	logLine("All tests complete! --------------------\r\n");
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
	
	
	P5DIR |= BIT1;                // P5.1 as output
  	P5OUT |= BIT1;                // P5.1 set high

	//testing SPI

	#if CDH_PROCESSOR_COMPILE
		P3OUT = 0x01; //set STE high for slave enable
		
		for(;;)
		{
			//P5OUT ^= BIT1;              //always Toggle P5.1 if master
			spiSendByte(0xFF);
			//unsigned int x;
			//for(x=50000;x>0;x--);       // Delay
			//P3OUT ^= 0x08;
		}
	#else
	  for(;;)
	  {
		//while (halSPITXREADY ==0);   // wait while not ready for TX
		//halSPI_SEND(DUMMY_CHAR);     // dummy write
		//while (halSPIRXREADY ==0);   // wait for RX buffer (full)
		//char buff = halSPIRXBUF;
		//if(buff==0x55)
		//{
			if((P3IN & 0x01) == 0x01)//check STE high
			{
				P5OUT ^= BIT1; //if connected to master toggle LED
			}
			
			unsigned int x;
			for(x=50000;x>0;x--);
		//}
	  }
	  
		for(;;)
		{
			char buff = spiSendByte(0x55);
			if(buff==0x55)
			{
				P5OUT ^= BIT1; //if connected to master toggle LED
			}
		}
		
	#endif
	
	//fflush(stdout);
	
	//logLine("    COM test complete");
	//fflush(stdout);
	 
	 */
}

///////////////////////////////////////////////////////////////////

// johnson's test
void johnsonsTest(void)
{
	logLine("Johnson's Test --------\r\n");
	
	UI16 numberOfTests = 10000;
	UI16 index;
	
	// read the voltage on a fake thermocouple
	// the pin is port 6.6 (pin 5)
	for (index = 0; index < numberOfTests; index++)
	{
		readAnalogInput(devices.testThermocouple.voltageInput);
		logCombo("analog input on 6.6", devices.testThermocouple.voltageInput->value);
		logLine("");
	}
}

///////////////////////////////////////////////////////////////////


// put other tests here
