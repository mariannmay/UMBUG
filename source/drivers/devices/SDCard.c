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
	initialize_SPI(&card->SPI);
}

void readSDCard(SDCard* card, UI8 address)
{
	// TODO
}

void writeByte(SDCard* card, UI8 byteAddress)
{
	// TODO
}
