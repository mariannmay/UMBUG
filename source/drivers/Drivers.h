//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers header                                            //
//    last edited by: Craig Nemeth                              //
//    date: January 15, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef DRIVERS_H
#define DRIVERS_H

#include <msp430fg4619.h>

#include "DriversConfig.h"

// here we should put all devices
#include "../drivers/devices/DFlipFlop.h"
#include "../drivers/devices/Counter.h"
#include "../drivers/devices/Multiplexer.h"
#include "../drivers/devices/SDCard.h"
#include "../drivers/devices/Spectrometer.h"
#include "../drivers/devices/SPIDevice.h"
#include "../drivers/devices/Thermocouple.h"
#include "../drivers/devices/Watchdog.h"


//////////////////////////////////////////////////////////////////
void drivers_initialize(void);

#endif
