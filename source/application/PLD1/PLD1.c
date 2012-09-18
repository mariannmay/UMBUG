#include "PLD1.h"

void pld1_routine(void){
  //TODO:
  if (1 /*we are NOT in the middle-of-something AND no one is using the UART*/){
	if (1 /*enough time has passed since the last time we ran*/){
	  setUARTState(UART_CAMorSPEC); // set the UART flag to say we are in the middle of something
	  // start UART collecting from the battery monitor thang 1-wire thang
	}
  }else{
	// continue doing what we were doing:
	if (1 /*we have received all of what we expect OR we have timed out*/){
	  if (1 /*we are not over the groundstation*/){
		// send the data to the packetizer to be timestamped
	  }
	  // unset the flag to say we are done with the UART (the middle-of-something flag)
	  setUARTState(UART_NOT_RESERVED);
	}
  }
}




