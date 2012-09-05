#ifndef PACKETGRABBER_H_
#define PACKETGRABBER_H_

/*
 * This method grabs packets out of two arrays that hold the incoming bits from the radio
 * and returns a pointer to the packet
 * 
 * It basically finds start and end flags and checks the source address to be from our ground station
 * returns a 1 if a packet was found, 0 if no packet found
 * 
 * 
 *	   AX25 Packet
 * 		^	   ^
 * 		|	   |
 *   masterInputBuffer <- 1Byte at a time from radio listening interrupt
 * 
 */
#include "../../drivers/IOTypes.h"//includes the IOType struct
#include <stdio.h>
#define MAX_RECIEVED_PACKET_SIZE 10//39//(32 + 7) = 120%
#define MIN_RECIEVED_PACKET_SIZE 8//32
#define MASTER_BUFFER_SIZE 128 //TODO change to 256

//input
static int ptrRead;
static int ptrWrite;
static UI8 masterInputBuffer[MASTER_BUFFER_SIZE];

//output
static UI8 retrievedPacket[MIN_RECIEVED_PACKET_SIZE];

//finds a packet in masterInputBuffer and puts it in retrievedPacket
int findPacket(int* address);
bool AcquiredNewData(void);
int findAX25Flag(UI8 byte1, UI8 byte2, int startingPosition, int endPosition);


#endif /*PACKETGRABBER_H_*/
