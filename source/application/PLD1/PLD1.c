#include "PLD1.h"

#define PLD1Bytes 2

void pld1_routine(void)
{
	//TODO:
	Byte bytesToSend[PLD1Bytes];
	
	if (getUARTState() == UART_CAMorSPEC)
	{	
		//we're in the middle of sending things.
		if (0 /*we've sent the whole image OR we have timed out*/)
		{
			setUARTState(UART_NOT_RESERVED); // unset the flag to say we are done with the UART
		}
	}
	else if (getUARTState() == UART_NOT_RESERVED && 0 /*enough time since last run*/)
	{
		setUARTState(UART_CAMorSPEC); //claim the UART
		Packetize(PKT_TARDIGRADEIMAGEMODE1, bytesToSend, PLD1Bytes); // start sending the data to the packetizer to be timestamped
	  
	}
}




