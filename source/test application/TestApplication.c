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
		P3OUT &= ~0x01;		// slave enable
		//P3OUT |= 0x01; //start with slave disabled
		//spiSendByte('X');
		//unsigned int x =0;
		
		char nextCharToSend = '1';
		for(;;nextCharToSend++)
		{
			initialize_SPI(1);
			if (nextCharToSend == ':') nextCharToSend = '1';
			
			//P5OUT ^= BIT1;              //always Toggle P5.1 if master
			P3OUT &= ~0x01; //set STE low for slave enable
			spiSendByte(nextCharToSend);
			//Byte array[4] = {'k','a','n','e'};
			//spiSendFrame(array, 4);
			
			P3OUT |= 0x01; //set STE high for slave disable
			//spiSendByte('R');
			//spiSendByte('A');
			//spiSendByte('I');
			//spiSendByte('G');
			
			// just a time killing loop
			int waitTimer = 10000;
			for (waitTimer; waitTimer > 0; waitTimer--){ ; }
			
			///////////////////////////////////////////////////
			/*
			printf("wait for TX \n");
			fflush(stdout);			
			while (halSPITXREADY ==0);    // wait while not ready 
			IFG2 &= ~UCB0RXIFG;
			P3OUT &= ~0x01; //set STE low for slave enable
			printf("wait for enable \n");
			fflush(stdout);
			while(P3IN&0x10);//wait for MTE to be pulled low
			halSPI_SEND('C');            // write
			printf("wait for RX \n");
			fflush(stdout);
			while (halSPIRXREADY ==0);    // wait for RX buffer (full)
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			fflush(stdout);
			P3OUT |= 0x01; //set STE high for slave disable
			printf("wait for disable \n");
			fflush(stdout);
			while(~(P3IN&0x10));//wait for MTE to be pulled high	
			*/	
			  //return (halSPIRXBUF);
			///////////////////////////////////////////////////
			
			/*if(x == 10000)
			{
				P5OUT ^= BIT1;
				x=0;
			}      // Delay
			else
			{
				x++;
			}*/
			//P3OUT ^= 0x08;
		}
	#else
		
		//unsigned int x =0;
		//P3OUT |= 0x10; //disable MTE off the start
		printf("    COM Slave Initialize\r\n");
		printf("Searching for: %c\n", 'C');
		fflush(stdout);
		//for(;;)
		//{
			
			//P5OUT ^= BIT1;              //always Toggle P5.1 if master
			//while((P3IN & 0x01) == 0x01);	//wait for enable
			//char buff = spiSendByte(0xE1);		
			//while((P3IN & 0x01) == 0x00);	//wait for disable
			
			/////////////////////////////////////////////////////////////////// 
			/*
			printf("wait for enable %u\n", x);
			fflush(stdout);
			while((P3IN & 0x01) == 0x01);	//wait for enable
			printf("wait for TXBUFF %u\n", x);
			fflush(stdout);
			while (halSPITXREADY ==0);    // wait while not ready
			printf("wait for disable %u\n", x); 
			fflush(stdout);
			IFG2 &= ~UCB0RXIFG;
			halSPI_SEND('N');            // write
			P3OUT &= ~0x10;// pull MTE low
			while((P3IN & 0x01) == 0x00);	//wait for disable
			printf("wait for RXBUFF %u\n", x);
			fflush(stdout);
			while (halSPIRXREADY ==0);    // wait for RX buffer (full)
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			fflush(stdout);
			P3OUT |= 0x10;// pull MTE high
			*/
			///////////////////////////////////////////////////////////////////
			
			/*if(x == 10000)
			{
				P5OUT ^= BIT1;
				x=0;
			}      // Delay
			else
			{
				x++;
			}*/

			//if(buff=='C')
			//{
			//	P5OUT &= ~BIT1;
			//}

		//}
	  for(;;)
	  {
	  	initialize_SPI(0);
	  	UCB0TXBUF = 0xFF;
		while((P3IN & 0x01) == 0x01);	//wait for enable
		bool enabled = ((P3IN | 0xFE) == 0xFE);
		if (enabled)
		{
			//while (halSPITXREADY ==0);   // wait while not ready for TX
			//halSPI_SEND(0xFF);     // dummy write
			while (halSPIRXREADY ==0);   // wait for RX buffer (full)
			char buff = UCB0RXBUF;
			printf("recieved: %c\n", buff);
			fflush(stdout);
		}
		//while((P3IN & 0x01) == 0x00);	//wait for disable
	  }
		//if(buff==0xF5)
		//{
		//	P5OUT &= ~BIT1;
		//}
		//{
			//if((P3IN & 0x01) == 0x00)//check STE low
			//{
			//	P5OUT ^= BIT1; //if connected to master toggle LED
			//}
			
			//unsigned int x;
			//for(x=50000;x>0;x--);
		//}
	  //}
	  /*
		for(;;)
		{
			char buff = spiSendByte(0x55);
			if(buff==0x55)
			{
				P5OUT ^= BIT1; //if connected to master toggle LED
			}
		}
		*/
	#endif
	
	//fflush(stdout);
	
	//printf("    COM test complete\r\n");
	//fflush(stdout);
}

///////////////////////////////////////////////////////////////////

// put other tests here
