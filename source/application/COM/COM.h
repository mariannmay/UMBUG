//////////////////////////////////////////////////////////////////
//                                                              //
//    COM header                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 12, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COM_H
#define COM_H

#include "../../system/System.h"

//Structure///////////////////////////////////////////
typedef struct
{
	char *packet;
	unsigned int size;
}
Packet;


//Functions///////////////////////////////////////////

//sending packets/////////////////////////////////////
void packetize(char info[], char packet[], char dest[]);
void generateFCS(char *info, char *packet);
void bitStuffing(char *packet);
//recieving packets///////////////////////////////////
bool depacketize(char data[], char packet[]);
void errorCorrection(char packet[]);


#endif
