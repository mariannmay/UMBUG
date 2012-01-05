//////////////////////////////////////////////////////////////////
//                                                              //
//    COM source                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 2, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COM.h"

void doSomething(void)
{
	// TODO
}


/*
 * note: this stuff does not compile

//wraps information in AX25 protocol
//info char[] should be max length of 256
char[] packetize(char[] info)
{
	char packet[info.size + 20]; //information packet, max size is 276 bytes with protocol and maximum info
	
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
	for(uint i = 0; i<info.size; i++)
	{
		packet[17+i] = info[i];
	}
	//FCS generation
	char FCS = generateFCS(info);
	
	//FCS insertion
	packet[17 + info.size] = FCS[0]; //1st half of fcs
	packet[18 + info.size] = FCS[1]; //2nd half of fcs
	//end flag
	packet[19 + info.size] = 0x7E;
	//packet is complete
	
	return packet;
}

char[] generateFCS(char[] info)
{
	char FCS[2];
	
	FCS[0] = 0x00;//default until FCS formula written
	FCS[1] = 0x00;
	
	return FCS;
	
}

*/
