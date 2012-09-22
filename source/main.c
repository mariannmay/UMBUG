//////////////////////////////////////////////////////////////////
//                                                              //
//    main program	                                            //
//    last edited by: Kane Anderson                             //
//    date: March 3, 2012                                    	//
//																//
//	  This is where the magic starts							//
//                                                              //
//////////////////////////////////////////////////////////////////

#include <msp430fg4618.h>
#include "application/PWR/UART.h"
#include "application/COM/COMApplication.h"

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

//unsigned char asdfarray[12613];

void main(void)
{
	//volatile unsigned int i;
	 
	 //asdfarray[1] = 0x00;
	// asdfarray[2] = asdfarray[1];
	
	system_initialize();
	// InitUART(); // TODO: removed from merge. use for testing uart
	//for(;;) // TODO: removed from merge. use for testing uart
	//{ // TODO: removed from merge. use for testing uart
	//	while (!(IFG2 & UTXIFG1));                // USART1 TX buffer ready? // TODO: removed from merge. use for testing uart
	//		TXBUF1 = 0xAB;           // TODO: removed from merge. use for testing uart
	//} // TODO: removed from merge. use for testing uart
	
	int i = 0;
	
	while(!gotRateYet()){
		i = i + 1;
		InitUartToValue(i);
		// take a picture
		sendUARTData(0x0D); //'\r'
	}
	
	// ???
		sendUARTData(0x48); //'H'
		sendUARTData(0x44); //'D'
		sendUARTData(0x20); //' '
		sendUARTData(0x30); //'0'
		sendUARTData(0x0D); //'\r'
	
	// set Delay Mode
		sendUARTData(0x44); //'D'
		sendUARTData(0x4D); //'M'
		sendUARTData(0x20); //' '
		sendUARTData(0x35); //'5'
		sendUARTData(0x0D); //'\r'
		
	// send TC\r
	//	sendUARTData(0x54); //'T'
	//	sendUARTData(0x43); //'C'
	//	sendUARTData(0x0D); //'\r'
		
	
	// take a picture with only one channel
		sendUARTData(0x53); //'S'
		sendUARTData(0x46); //'F'
		//sendUARTData(0x20); //' '
		//sendUARTData(0x31); //'1'
		sendUARTData(0x0D); //'\r'
	
	for(;;)
	{
		system_main();
	}
	
}
