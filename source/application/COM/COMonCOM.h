//////////////////////////////////////////////////////////////////
//                                                              //
//    COMonCOM header                                           //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMonCOM_H
#define COMonCOM_H

#include "../ApplicationConfig.h"
#include "Encoder.h"//includes the encoder methods
#include "../../system/Packet.h"//includes the Packet struct


void newPacketFromGround(check,interpret,checkBitErrorRate);
void handshakeGround();
void addToSendQueue();
void receiveCDHPacket();
void indexPointerTable();
void pre-encodePSK();
void sendPacketFromQueue();
void useRadio();
void flagPayloadData(priorities);
void maintainCOMTemperature();
void communicateCDHprocessor();

#endif
