//////////////////////////////////////////////////////////////////
//                                                              //
//    COM header                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 16, 2012                                    //
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
	bool type;// info==true, command==false
	char *index;//contents
	//if info data
	//The first byte of the info array will contain the layout key for the array
	//This will differentiate the different types of info packets
	//if command data
	//TODO
	unsigned int size;//size
}
Data; //This is a chunk of information to be stuffed into, or taken out of, a packet



//Functions///////////////////////////////////////////

//sending packets/////////////////////////////////////
void packetize(Data *data, Packet *packet, char dest[]);
void generateFCS(Data *data, Packet *packet);
void bitStuffing(Packet *packet);
//recieving packets///////////////////////////////////
void depacketize(Data *data, Packet *packet);
void errorCorrection(Packet *packet);


#endif
