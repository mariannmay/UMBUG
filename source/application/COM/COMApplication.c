//////////////////////////////////////////////////////////////////
//                                                              //
//    COMApplication header                                     //
//    last edited by: Craig Nemeth                              //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMApplication.h"

void COM_application_main(void)
{
	//NOTE:  packets->size may exceed 276 in this application because of bitStuffing
	
	/* How I believe the COMs app should function
	while(1)
	{
		if(new packet is recieved)
		{
			decodePacket(packet);
			removeStuffing(packet);
			send memory address of this packet to CDH for dePacketizing
		}else if(there is a packet to be sent)
		{
			get memory address from CDH memory
			bitStuffing(packet);
			encodePacket(packet);
			send to transciever
		}
	}
	*/
}

