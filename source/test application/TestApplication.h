//////////////////////////////////////////////////////////////////
//                                                              //
//    TestApplication header                                    //
//    last edited by: Kane Anderson                             //
//    date: November 22, 2011                                   //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef TESTAPPLICATION_H
#define TESTAPPLICATION_H

//////////////////////////////////

#include "../system/System.h"
#include "../application/ApplicationConfig.h"
#include "../drivers/devices/msp430/sdCardLibrary/MMC_lib/MMC.h"
#include <assert.h>
#include <stdio.h>

void test_SPI(void);
void test_SPI_framework(void);
void test_SPI_framework_2(void);
void test_realTimeClock(void);
void test_analogToDigital(void);
void test_digitalToAnalog(void);
void test_sdCard(void);
void test_sdCard_newlib(void);

//////////////////////////////////

void test_application_initialize(void);
void test_application_main(void);

#endif
