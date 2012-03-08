//////////////////////////////////////////////////////////////////
//                                                              //
//    COMFlagChecking header                                    //
//    last edited by: Craig Nemeth                              //
//    date: February 24, 2012                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COMonCDHFlagChecking_H
#define COMonCDHFlagChecking_H

#include "Packet.h"
#include "../drivers/CDHPINS/CDHtoCOMInterruptSet.h"
#include "../drivers/CDHPINS/COMtoCDHFlagCheck.h"

void checkFlag();
void setInterrupt();

//sending packets/////////////////////////////////////
void packetize(Data *data, Packet *packet, char dest[]);
void generateFCS(Data *data, Packet *packet);

//recieving packets///////////////////////////////////
void depacketize(Data *data, Packet *packet);
void errorCorrection(Packet *packet);

#endif


