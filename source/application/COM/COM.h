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

//Structures///////////////////////////////////////////
typedef struct
{
	char *index;
	unsigned int size;
}
Packet; //This is an AX.25 packet

typedef struct
{
	unsigned int type;//type of information being sent. Defines layout of char[] index
	char *index;//info
	unsigned int size;//size
}
Info; //This is a chunk of information to be stuffed into a packet


//Functions///////////////////////////////////////////

//sending packets/////////////////////////////////////
void packetize(char *info, Packet *packet, char dest[]);
void generateFCS(char *info, Packet *packet);
void bitStuffing(Packet *packet);
//recieving packets///////////////////////////////////
bool depacketize(char data[], Packet *packet);
void errorCorrection(Packet *packet);


#endif
