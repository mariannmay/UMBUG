//////////////////////////////////////////////////////////////////
//                                                              //
//    Encoder header file	                                    //
//    last edited by: Craig Nemeth                              //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COM.h"//includes the Packet struct

#ifndef ENCODER_H
#define ENCODER_H

void encodePacket(Packet *packet);
void decodePacket(Packet *packet);
void bitStuffing(Packet *packet);
void removeStuffing(Packet *packet);

#endif
