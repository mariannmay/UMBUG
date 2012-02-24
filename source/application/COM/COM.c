//////////////////////////////////////////////////////////////////
//                                                              //
//    COM source                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COM.h"

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

///// packetize /////////////////////////////////////////////////////
//wraps information in AX25 protocol and stores it in a packet
//
//Parameters:
//
//Data *data should have index max length of 256 and should be
//information. unless we're sending commands to ground
//Packet *packet should should have length of *data->size + 20
//char dest[] should be the destination callsign of length 7
//
//////////////////////////////////////////////////////////////////////
void packetize(Data *data, Packet *packet, char dest[])
{
	//information packet, max size is 276 bytes with protocol and maximum info
	
	unsigned int i;//counter
	
	packet->index[0] = 0x7E;//start flag
	
	//destination insertion
	for(i =0; i<7; i++)
	{
		packet->index[i+1] = dest[i];
	}
	
	//source temporarily = VE4SCH1
	packet->index[8] = 0x56;
	packet->index[9] = 0x45;
	packet->index[10] = 0x34;
	packet->index[11] = 0x53;
	packet->index[12] = 0x43;
	packet->index[13] = 0x48;
	packet->index[14] = 0x31;
	
	//control
	packet->index[15] = 0x00;
	
	//PID protocol identifier
	packet->index[16] = 0xF0; //no L3 protocol
	
	//information insertion
	for(i = 0; i<data->size; i++)
	{
		packet->index[17+i] = data->index[i];
	}
	
	//FCS generation and insertion
	generateFCS(data, packet);  
	
	//end flag
	packet->index[19 + data->size] = 0x7E;
	 
	//packet is complete
	
}

/////generateFCS////////////////////////////////////////////////////////
//generates and inserts the FCS into the packet
////////////////////////////////////////////////////////////////////////
void generateFCS(Data *data, Packet *packet)
{
	//generate the fcs
	//temporarily 0x00

	//FCS insertion
	packet->index[17 + data->size] = 0x00; //1st half of fcs
	packet->index[18 + data->size] = 0x00; //2nd half of fcs	
}



/// depacketize //////////////////////////////////////////////////////////
//unpacks and checks packets recieved from the COMs subsystem
//
//parameters:
//
//Data *data is structure in which the recieved data will be stored
//			  data->index array should be size of packet->size-20
//Packet *packet is the structure holding the packet retrieved by COMs
//
////////////////////////////////////////////////////////////////////////
void depacketize(Data *data, Packet *packet)
{
	
	//check and correct errors with FCS
	errorCorrection(packet);
	
	//TODO
	//check info or command and set boolean variable data->type= true or false;
	
	int i;
	for(i=0; i<data->size; i++)
	{
		data->index[i] = packet->index[17+i];
	}
	
}

void errorCorrection(Packet *packet)
{
	//TODO
	//extract FCS, check and fix packet
}

