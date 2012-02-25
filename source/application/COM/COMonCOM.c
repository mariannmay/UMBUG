//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCOM source                                           //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMonCOM.h"

/*
void COMonCOM_main(void)
{
	
	// How I believe the COMs app should function
	
	bool contact = false; //true if established contact with ground (it's the encoder enable signal)
						  //CDH controls this variable (I'll figure that out later)
	
	while(1)
	{
		
		while(contact==true)
		{
			if(new packet is recieved)
			{
				decodePacket(packet);
				send memory address of this packet into CDH memory buffer for dePacketizing
			}else if(there is a packet to be sent)
			{
				get memory address from CDH memory buffer
				encodePacket(packet);
				sendTransciever(packet);
			}
			
		}
	}
	
}

*/

