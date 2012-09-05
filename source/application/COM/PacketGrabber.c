
#include "PacketGrabber.h"

//if a packet is found
//it returns 1 and places the packet in global array "retrievedPacket"
int findPacket(int* address)
{
	UI8 possiblePacket[MIN_RECIEVED_PACKET_SIZE];
	int foundPacket = 0;
	printf("ptrRead = %d \n", ptrRead);
	printf("byte1[ptrRead] = %x \n", masterInputBuffer[ptrRead]);
	printf("byte2[ptrRead] = %x \n", masterInputBuffer[ptrRead+1]);
	printf("byte1[0] = %x \n", masterInputBuffer[0]);
	printf("byte2[1] = %x \n", masterInputBuffer[0+1]);
	int startingBitOfStartFlag = findAX25Flag(masterInputBuffer[ptrRead], masterInputBuffer[ptrRead+1], 0, 8);
	printf("startingBitOfStartFlag = %d \n", startingBitOfStartFlag);
	int startingBitOfEndFlag =0;
	if(startingBitOfStartFlag >= 0)//found a start flag
	{
		printf("found start flag");
		int i;
		for(i=MIN_RECIEVED_PACKET_SIZE+1; i<=MAX_RECIEVED_PACKET_SIZE+1; i++)//for each possible end flag location
		{
			if(i == MIN_RECIEVED_PACKET_SIZE+1)
			{//jump ahead and start
				startingBitOfEndFlag = findAX25Flag(masterInputBuffer[ptrRead+i], masterInputBuffer[ptrRead+i+1], startingBitOfStartFlag, 8);
			}else if (i == MAX_RECIEVED_PACKET_SIZE+1)
			{//stop early
				startingBitOfEndFlag = findAX25Flag(masterInputBuffer[ptrRead+i], masterInputBuffer[ptrRead+i+1], 0, startingBitOfStartFlag+1);
			}else
			{//checking bytes in middle, therefore check all bits
				startingBitOfEndFlag = findAX25Flag(masterInputBuffer[ptrRead+i], masterInputBuffer[ptrRead+i+1], 0, 8);
			}
			
			if(startingBitOfEndFlag >= 0)//found both flags
			{
				//remove bit stuffing from the contents between the flags
				printf("got it!");
			}
		}
	}else//didn't find a start flag
	{
		ptrRead++;
	}
	
	return foundPacket;
}

bool AcquiredNewData(void)
{
	return ((ptrRead + MAX_RECIEVED_PACKET_SIZE)<= ptrWrite) || ((ptrRead > ptrWrite) && (MASTER_BUFFER_SIZE - ptrRead + ptrWrite >= MAX_RECIEVED_PACKET_SIZE));
}

int findAX25Flag(UI8 byte1, UI8 byte2, int startingPosition, int endPosition)
{
	//create 16bit holder for the data
	UI16 data = (((UI16)byte1)<<8) + (UI16)byte2;
	//16 bit mask to be shifted
	UI16 mask = 0xFF00>>startingPosition;
	//16bit flag comparator
	UI16 flag = 0x7E00>>startingPosition;
	
	int i;
	for(i = startingPosition; i<endPosition; i++)//for all bits in byte1 up to the end position which is usually 8
	{
		
		if((UI16)(data&mask) == (UI16)flag)//found a flag
		{
			return i;//return start position of the flag byte
		}
		mask = mask>>1;
		flag = flag>>1;
	}
	return -1;//return nothing found error
}
