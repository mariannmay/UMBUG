
#include "PacketGrabber.h"


int ptrBeenRead;
int ptrWritten;

//if a packet is found
//it returns 1 and places the packet in global array "retrievedPacket"
int findPacket(int* address)
{
/*	int foundPacket = 0;
	int pos = 0;

	for(pos = (lastEndFlag+1); pos<packetLength && foundPacket==0; pos++)//start at next pos after last packet
	{
		if(firstHalf[pos]==0xFF)//if found start flag
		{
			if(pos == 0)//the first half holds the packet
			{
				if(firstHalf[packetLength-1]==0xFF)//found end flag
				{
					foundPacket = 1;
					retrievedPacket = firstHalf;
					lastEndFlag = -1;
				}
			}else//the packet is split between the two halves
			{
				if(secondHalf[pos -1] == 0xFF)//found end flag
				{
					foundPacket = 1;
					int i;
					int x =0;
					for(i=pos;i<packetLength;i++)
					{
						retrievedPacket[x] = firstHalf[i];
						x++;
					}
					for(i=0;i<pos;i++)
					{
						retrievedPacket[x] = secondHalf[i];
						x++;
					}
					lastEndFlag = pos-1;
				}				
			}
			
		}
	}
	
	return foundPacket;*/
	return 1;
}

bool AcquiredNewData(void)
{
	return ((ptrBeenRead + MAX_RECIEVED_PACKET_SIZE)<= ptrWritten) || ((ptrBeenRead > ptrWritten) && (MASTER_BUFFER_SIZE - ptrBeenRead + ptrWritten >= MAX_RECIEVED_PACKET_SIZE));
}

int findAX25Flag(UI8 byte1, UI8 byte2, int startingPosition, int endPosition)
{
	//create 16bit holder for the data
	UI16 data = (byte1<<8) + byte2;
	//16 bit mask to be shifted
	UI16 mask = 0xFF00>>startingPosition;
	//16bit flag comparator
	UI16 flag = 0x7E00>>startingPosition;
	
	int i;
	for(i = startingPosition; i<endPosition; i++)//for all bits in byte1 up to the end position which is usually 8
	{
		if(data&mask == flag)//found a flag
		{
			return i;//return start position of the flag byte
		}
		mask = mask>>1;
		flag = flag>>1;
	}
	return -1;//return nothing found error
}
