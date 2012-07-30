//******************************************************************************
// source file for the Battery Charger and TestBattery Charger

//
// Description: this file contain the main operations executed by the power subsystem
//        Mohamed Temam Nasri
//******************************************************************************
 
#include "msp430fg4619.h"


#include "battery_charger.h"
 
//#define CHARGERENABLE	   TODO
#define STAT1		//TODO
#define STAT2		//TODO

/***********************************************************************************
 * FUNCTIONS
 * ********************************************************************************/
 
void bc_initialize(void) 
{ // this function should initilize the charging process of the battery
  //TODO
} 
 
void bc_disable(void)
{
    // this function should stop the charging process of the battery by sending a low signal to the enable 
    //TODO 
}
 
char bc_status(void) 
{ 
  //TODO 
} 
 
/* ISR for Battery Charger
 * this interrupt service routine should be used to detect any fault 
 * 
 * 
 */
