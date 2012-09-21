#include "PLD1.h"

#define PLD1Bytes 2

void pld1_routine(void)
{
	//TODO:
	Byte bytesToSend[PLD1Bytes];
	
	if (getUARTState() == UART_NOT_RESERVED && 1/*TODO: enough time since last run*/)
	{	
		// TODO: Take the whole picture
		
		Packetize(PKT_TARDIGRADEIMAGEMODE1, bytesToSend, PLD1Bytes); // send the data to the com processor (should be timestamped there)
	}
}




