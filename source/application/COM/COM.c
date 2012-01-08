//////////////////////////////////////////////////////////////////
//                                                              //
//    COM source                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 8, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COM.h"

void doSomething(void)
{
	// TODO
}




//wraps information in AX25 protocol and stores it in a packet
//info char[] should be max length of 256
void packetize(char info[], char packet[])
{
	//static char packet[info.size + 20]; //information packet, max size is 276 bytes with protocol and maximum info
	
	packet[0] = 0x7E;//start flag
	//destination VE4UM_1
	packet[1] = 0x56;
	packet[2] = 0x45;
	packet[3] = 0x34;
	packet[4] = 0x55;
	packet[5] = 0x4D;
	packet[6] = 0x20;
	packet[7] = 0x31;
	//source VE4SCH1
	packet[8] = 0x56;
	packet[9] = 0x45;
	packet[10] = 0x34;
	packet[11] = 0x53;
	packet[12] = 0x43;
	packet[13] = 0x48;
	packet[14] = 0x31;
	//control
	packet[15] = 0x00;
	//PID protocol identifier
	packet[16] = 0xF0; //no L3 protocol
	//information insertion
	unsigned int i;
	for(i = 0; i<sizeof(info); i++)
	{
		packet[17+i] = info[i];
	}
	//FCS generation
	//generateFCS(info, packet);  i dont know why this method call gives an error so this method doesnt yet insert an FCS
	
	//end flag
	packet[19 + sizeof(info)] = 0x7E;
	//packet is complete
	
}

void generateFCS(char info[], char packet[])
{
	//generate the fcs
	//temporarily 0x00
	
	//FCS insertion
	packet[17 + sizeof(info)] = 0x00; //1st half of fcs
	packet[18 + sizeof(info)] = 0x00; //2nd half of fcs	
}


