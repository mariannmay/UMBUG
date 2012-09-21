//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCDH source                                           //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMonCDH.h"

void checkForMessages(void)
{
	
}

void respondToMessage(void)
{
	
}

void addCommandToListOfTasks(void)
{
	
}

//monitors and controls the connection with a ground station
void connectionControl(void)
{
	/*
	 * handshake1 is spammed from ground station while they predict we are coming overhead
	 * handshake2 is our confirmation response to handshake1
	 * handshake3 is ground confirming contact and may contain the first command
	
	if(handshake1 recieved)
	{
		sendHandshake2();
	}else if(handshake3 recieved)
	{
		contact = true; //start sending data	
	}
	*/
	
	//TODO
	/* must decide when we should be expecting ground confirmation of info packets recieved
	
	if(it's time to expect confirmation of reception & !confirmation)
	{
		contact = false; // We'll stop sending info packets
	}
	
	*/	
}



