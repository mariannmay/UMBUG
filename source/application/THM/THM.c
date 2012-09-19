#include "THM.h"

#define THMBytes 2

bool currentlyApplyingHeat = false;
UI16 thmThresholdLOW = 0x23; //TODO: set as a proper value
UI16 thmThresholdHIGH = 0x50; //TODO: set as a proper value

UI16 getThermalSensorReading(void){
	UI16 sensorValue = 0x00;
	
	readAnalogInput(devices.thermister);
	sensorValue = devices.thermister->value;
  



	//thermocouple_read(&devices.tardigradeTemperatureSensor); // TODO: This is the way Kane was doing it (might be better?) 



	
	return(sensorValue);
}

void startHeating(void){
	//TODO:
}

void stopHeating(void){
	//TODO:
}

void sendTHMToPacketizer(UI16 value){
	Byte bytesToSend[THMBytes];
	
	bytesToSend[0] = (int)((value >> 8) & 0xFF);
	bytesToSend[1] = (int)(value & 0xFF);
	
	Packetize(PKT_THERMAL_READINGS, bytesToSend, THMBytes);
}

void thm_routine(void){
  UI16 currentTemp = 0x00;
  
  //TODO:
  if (1 /*enough time has passed since the last time we ran*/){
    currentTemp = getThermalSensorReading();
    if (!currentlyApplyingHeat){
      if (currentTemp <= thmThresholdLOW){
	    currentlyApplyingHeat = true;
	    startHeating();
      }
    }else{
      //continue doing what we were doing:
      if (currentTemp >= thmThresholdHIGH){
	    currentlyApplyingHeat = false;
	    stopHeating();
	    if (1 /*we are not over the groundstation*/){
	      sendTHMToPacketizer(currentTemp); //send the data to the packetizer to be timestamped
	    }else{
	      //make a big pile of things to send later? (probably just do abandon the data instead?
	    }
      }
    }
  }
}

