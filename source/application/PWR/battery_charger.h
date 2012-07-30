//******************************************************************************
//  Battery Charger for MSP-FET430x169 Device Driver Header File
//
//  Description: This header file contains the interface for the Battery Charger driver
//
//   Mohamed Temam Nasri
//		  31/05/2012 	
//******************************************************************************
 
// prevent multiple instances of the same file
#ifndef __BATTERYCHARGER_H__
#define __BATTERYCHARGER_H__
 
#include <msp430fg4619.h>

 
/**
 * DEBUG flag for the battery charger driver
 **/
#define BATTERYCHARGER_DEBUG		1
 
/************************************************************ 
 * Global Constants
 ************************************************************/
 
#define CHARGEDONE		STAT1
#define CHARGING		STAT2
#define CHARGEOFF		(STAT1+STAT2)
 

 
 
#endif // __BATTERYCHARGER_H__
 