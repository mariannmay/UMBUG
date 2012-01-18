//////////////////////////////////////////////////////////////////
//                                                              //
//    Real time clock source                                  	//
//    last edited by: Kane Anderson                             //
//    date: January 4, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "RealTimeClock.h"

// functions //////////////////////////////////

void realTimeClock_initialize(RealTimeClock* clock)
{
	// TODO
}

Time_ms realTimeClock_timeSinceLastCheck(RealTimeClock* clock)
{
	Time_ms returnValue = clock->timeSinceLastCheck;
	clock->timeSinceLastCheck = 0;
	return returnValue;
}

void realTimeClock_update(RealTimeClock* clock)
{
	SPIMessage received = clock->SPI.receivedMessage;
	// TODO
	// fix
	Byte timeHighByte = received.data[0];
	Byte timeMidHighByte = received.data[1];
	Byte timeMidLowByte = received.data[2];
	Byte timeLowByte = received.data[3];
	
	// do something to figure the time out from the message
	// TODO
	// fix
	Time_ms oldTime = clock->currentTime;
	clock->currentTime = MultiByte4(timeHighByte, timeMidHighByte, timeMidLowByte, timeLowByte);
	Time_ms amountAdded = clock->currentTime - oldTime;
	clock->timeSinceLastCheck += amountAdded;
}

void realTimeClock_reset(RealTimeClock* clock)
{
	// TODO
	// fix
	
	SPIMessage resetPlease;
	resetPlease.data[0] = 0xFF;
	resetPlease.data[1] = 0xFF;
	resetPlease.data[2] = 0xFF;
	resetPlease.data[3] = 0xFF;
	resetPlease.data[4] = 0xFF;
	resetPlease.data[5] = 0xFF;
	resetPlease.data[6] = 0xFF;
	resetPlease.data[7] = 0xFF;
	
	clock->SPI.transmitMessage = resetPlease; 
}


