//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication source                                    //
//    last edited by: Craig Nemeth                              //
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
	
//	int wait;
//	for(wait=0;wait<1000;wait++);
	
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
		
		#if COM_CONNECTED
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
		#endif
		
		#if EEPROM_CONNECTED
			
			for(;;)
			{
		  		UCB0CTL1 |= UCSWRST;
  				UCB0CTL1 &= ~UCSWRST;
  				P3OUT &= ~0x01;
				spiSendByte(0x5F);
				P3OUT |= 0x01;				
			}
			
			/*
			//opcodes
			#define WREN  6
			#define WRDI  4
			#define RDSR  5
			#define WRSR  1
			#define READ  3
			#define WRITE 2
			
		  	UCB0CTL1 |= UCSWRST;
  			UCB0CTL1 &= ~UCSWRST;
			
			// Select EEPROM
			P3OUT &= ~0x01;
			// Send WRITE ENABLE command
			spiSendByte(WREN); 
			// Deselect EEPROM
			P3OUT |= 0x01;
			// Wait for command to be processed
			long timeWaster;
			for(timeWaster=0;timeWaster<100000;timeWaster++);
			
		  	UCB0CTL1 |= UCSWRST;
  			UCB0CTL1 &= ~UCSWRST;
			
			// Select EEPROM
			P3OUT &= ~0x01;
			// Send WRITE command
			spiSendByte(WRITE);
			// Send ADDRESS where to start writing
			long address = 0;
		  	UCB0CTL1 |= UCSWRST;
  			UCB0CTL1 &= ~UCSWRST;
			spiSendByte((char)(address>>8));   //send MSByte address first
		  	UCB0CTL1 |= UCSWRST;
  			UCB0CTL1 &= ~UCSWRST;
			spiSendByte((char)(address));      //send LSByte address
			// Send data
			unsigned int i;
			for(i = 0; i < 512; i++) {
		  		UCB0CTL1 |= UCSWRST;
  				UCB0CTL1 &= ~UCSWRST;
				spiSendByte(i);
			}
			// Deselect EEPROM
			P3OUT |= 0x01; //release chip
			  
			//wait for eeprom to finish writing
			for(timeWaster=0;timeWaster<300000;timeWaster++)
			{
				int x = 1+4;
				x++;
			}
			
			//read the EEPROM back to confirm
			int data = 0;
			for(i = 0; i < 512; i++) {
		   		data = read_eeprom(i); 
				printf("read: %u\n", data);
			}
  			for(timeWaster=0;timeWaster<5000;timeWaster++);
			*/
		#endif
	#else
		
		#if CDH_CONNECTED
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
	  

	 	/* for(;;)
	  	{
			UCB0CTL1 |= UCSWRST;
			UCB0CTL1 &= ~UCSWRST;
			while (halSPIRXREADY ==0);   // wait for RX buffer (full)
			char buff = UCB0RXBUF;
			UCB0TXBUF = 'X'; 	
	  	}*/
	  	#endif
	  
	  	#if SDCARD_CONNECTED
	  		//init as master
	  		initialize_SPI(1);
	  	
	  		//set mode to SPI on SD card by pulling CS low during CMD0: 40 00 00 00 00 95 (hexadecimal) pg 83
	  		spiSendByte(0x40);
	  		spiSendByte(0x00);
	  		spiSendByte(0x00);
	  		P3OUT ~= 0x01;			//CS low
	  		spiSendByte(0x00);
	  		spiSendByte(0x00);
	  		spiSendByte(0x95);		//CRC
	  		
	  		//recieve R1 response from the SD card with no errors 00000000
	  		char response = spiSendByte(0xFF);
	  		printf("response: %c\n", response);
	  		fflush(stdout);
	  		if(response == 0x00)
	  		{
	  			P5OUT |= BIT1;
	  		}
	 		
	  	#endif
	  
	#endif
	
	printf("    COM test complete\r\n");
	fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
