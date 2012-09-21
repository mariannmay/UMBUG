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

#include "system/Task.h"
#include "system/TestFunctions.h"
#include "system/System.h"
#include "system/TaskList.h"
#include "system/TimeCounter.h"
#include "system/TaskListInit.h"

extern void system_initialize(void);
extern void system_main(void);

//////////////////////////////////////////////////////////////////

extern SPI_WRITE(SPI_CHANNEL,UI8);
ShortDuration duration_1S;
extern TimeCounter currentTime;

void main(void)
{
	//volatile unsigned int i;
	UI16 killtime = 0x00;
	UI8 test = 0;
	
	system_initialize();
	// InitUART(); // TODO: removed from merge. use for testing uart
	//for(;;) // TODO: removed from merge. use for testing uart
	//{ // TODO: removed from merge. use for testing uart
	//	while (!(IFG2 & UTXIFG1));                // USART1 TX buffer ready? // TODO: removed from merge. use for testing uart
	//		TXBUF1 = 0xAB;           // TODO: removed from merge. use for testing uart
	//} // TODO: removed from merge. use for testing uart
	
	
	init_SCHEEPROM();
	//printf("Fuck you code cumdumpster crude-io you are sharty as ballz!!!!!\n");
	for(;;)
	{
		writeByte_SCHEEPROM(0x0011,0x5A);
		test = readByte_SCHEEPROM(0x0011);
		//for(killtime = 0; killtime < 0x0500; killtime++);//kill some time
		//printf("Holy cocks, its %d",test);
		//SPI_WRITE(SPI_CHANNEL_2, 0x5A);
		//printf("Read in %d\n",test);
		//for(killtime = 0; killtime < 0xFFFF; killtime++);//kill some time
	}

	for(;;)
	{
		system_main();
	}
	
}
