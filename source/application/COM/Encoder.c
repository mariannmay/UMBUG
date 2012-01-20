//////////////////////////////////////////////////////////////////
//                                                              //
//    Encoder source file	                                    //
//    last edited by: Craig Nemeth                              //
//    date: January 20, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Encoder.h"

/*
 * Bit stuffing and prepending and appending of start and end flags will be done on the fly
 */

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
 *
 * This will be done on the fly as packets are encoded
 */
 //////////////////////////////////////////////////////////////////////////////////////

