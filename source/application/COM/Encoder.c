//////////////////////////////////////////////////////////////////
//                                                              //
//    Encoder source file	                                    //
//    last edited by: Craig Nemeth                              //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Encoder.h"

//////////////////////////////////

void encodePacket(Packet *packet)
{
	//TODO	
}

void decodePacket(Packet *packet)
{
	//TODO
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
 void bitStuffing(Packet *packet)
 {
 	//TODO 
 }
 
 void removeStuffing(Packet *packet)
 {
 	//TODO
 }
