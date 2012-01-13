//////////////////////////////////////////////////////////////////
//                                                              //
//    COM source                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 12, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COM.h"


///// packetize /////////////////////////////////////////////////////
//wraps information in AX25 protocol and stores it in a packet
//
//Parameters:
//
//char info[] should be max length of 256
//char packet[] should be length of info + 20
//char dest[] should be the destination callsign of length 7
//
//////////////////////////////////////////////////////////////////////
void packetize(char info[], char packet[], char dest[])
{
	//information packet, max size is 276 bytes with protocol and maximum info
	
	unsigned int i;//counter
	
	packet[0] = 0x7E;//start flag
	
	//destination insertion
	for(i =0; i<7; i++)
	{
		packet[i+1] = dest[i];
	}
	
	//source temporarily = VE4SCH1
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
	for(i = 0; i<sizeof(info); i++)
	{
		packet[17+i] = info[i];
	}
	
	//FCS generation and insertion
	generateFCS(info, packet);  
	
	//end flag
	packet[19 + sizeof(info)] = 0x7E;

	//do bit stuffing on assembled packet	
	bitStuffing(packet); 
	 
	//packet is complete
	
}

/////generateFCS////////////////////////////////////////////////////////
//generates and inserts the FCS into the packet
////////////////////////////////////////////////////////////////////////
void generateFCS(char *info, char *packet)
{
	//generate the fcs
	//temporarily 0x00

	//FCS insertion
	packet[17 + sizeof(info)] = 0x00; //1st half of fcs
	packet[18 + sizeof(info)] = 0x00; //2nd half of fcs	
}

/// bitStuffing //////////////////////////////////////////////////////////////////////
/*
 * BIT STUFFING IN AX.25
 * 
 * In order to assure that the flag bit sequence mentioned above doesn't appear 
 * accidentally anywhere else in a frame, the sending station shall monitor the
 * bit sequence for a group of five or more contiguous one bits. Any time five
 * contiguous one bits are sent the sending station shall insert a zero bit 
 * after the fifth one bit. During frame reception, any time five contiguous one 
 * bits are received, a zero bit immediately following five one bits shall be discarded
 */
 //
 //parameters: char *packet is the assembled AX.25 packet
 //
 //////////////////////////////////////////////////////////////////////////////////////
 void bitStuffing(char *packet)
 {
 	//TODO 
 	//also I found that this should probably be placed on the COMs seperate processor
 }

/// depacketize //////////////////////////////////////////////////////////
//unpacks and checks packets recieved from the COMs subsystem
//
//parameters:
//
//char data[] the array in which the recieved data will be stored
//			  data array should be size of packet-20
//char packet[] the packet retrieved by COMs
//
//returns true if info, false if a command
//
////////////////////////////////////////////////////////////////////////
bool depacketize(char data[], char packet[])
{
	bool type;//the type of packet. info or command. true or false.
	
	//check and correct errors with FCS
	errorCorrection(packet);
	
	//TODO
	//check and set variable type
	
	int i;
	for(i=0; i<sizeof(data); i++)
	{
		data[i] = packet[17+i];
	}
	
	return(type);
}

void errorCorrection(char packet[])
{
	//TODO
	//extract FCS, check and fix packet
}

