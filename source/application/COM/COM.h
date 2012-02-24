//////////////////////////////////////////////////////////////////
//                                                              //
//    COM header                                                //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COM_H
#define COM_H

// Includes //////////////////////////////////////////
#include "../../system/System.h"
#include "Encoder.h"
#include "Packet.h"

//Functions///////////////////////////////////////////

//connection control and maintenance
void connectionControl(void);

//sending packets/////////////////////////////////////
void packetize(Data *data, Packet *packet, char dest[]);
void generateFCS(Data *data, Packet *packet);
//recieving packets///////////////////////////////////
void depacketize(Data *data, Packet *packet);
void errorCorrection(Packet *packet);


#endif
