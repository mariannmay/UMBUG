#include "THM.h"

bool currentlyApplyingHeat = false;
#define thmThresholdLOW 23; //TODO: set as a proper value
#define thmThresholdHIGH 120; //TODO: set as a proper value

UI16 getThermalSensorReading(void){
	//TODO:
}

void startHeating(void){
	//TODO:
}

void stopHeating(void){
	//TODO:
}

void thm_routine(void){
  UI16 currentTemp = 0x00;
  
  //TODO:
  //if (enough time has passed since the last time we ran){
    currentTemp = getThermalSensorReading();
    if (!currentlyApplyingHeat){
      if (currentTemp < thmThresholdLOW){
	    currentlyApplyingHeat = true;
	    startHeating();
	  }
    }else{
      //continue doing what we were doing:
	  if (currentTemp > thmThresholdHIGH){
	    currentlyApplyingHeat = false;
	    stopHeating();
	    //if (we are not over the groundstation){
	      //send the data to the packetizer to be timestamped
	    //}else{
	      //make a big pile of things to send later? (probably just do abandon the data instead?
	    //}
      }
    }
  //}
  
  return();
}