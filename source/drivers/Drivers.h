//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Kane Anderson                             //
//    date: January 22, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef DRIVERS_H
#define DRIVERS_H

#include <msp430fg4619.h>

#include "DriversConfig.h"

// here we should put all devices
#include "../drivers/devices/Counter.h"
#include "../drivers/devices/Multiplexer.h"
#include "../drivers/devices/RealTimeClock.h"
#include "../drivers/devices/SDCard.h"
#include "../drivers/devices/SPIDevice.h"
#include "../drivers/devices/Thermocouple.h"
#include "../drivers/devices/Watchdog.h"


//////////////////////////////////////////////////////////////////
// toggle the main LED
#define ToggleStatusLED P5DIR |= BIT1; P5OUT ^= BIT1

//////////////////////////////////////////////////////////////////
void drivers_initialize(void);
void drivers_update(void);

#endif
