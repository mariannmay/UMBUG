//////////////////////////////////////////////////////////////////
//                                                              //
//    SDCard source                                        		//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "SDCard.h"

// TODO REMOVE (DEBUG ONLY)
#include <stdio.h>

// functions
void sdCard_initialize(SDCard* card)
{
	
	// if return is not NULL an error occured and the
    // SD-card will be initialized again 
    int timeout = 0;
	while (card->status != SDCARD_INITIALIZED)
  	{
    	//card->status = mmcInit();
    	timeout++;
    	if (timeout == 50)                      // Try 50 times until error
    	{
      		printf ("No SD card found!! %x\n", card->status);
      		break;
    	}
  	}
  	
}

void readSDCard(SDCard* card, UI8 address)
{
	// TODO
}

void writeByte(SDCard* card, UI8 byteAddress)
{
	// TODO
}
