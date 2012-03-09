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
#include <assert.h>
#include <stdio.h>

//for testing the COMs application////////

#include "../application/COM/COMonCDH.h"
void test_COM(void);

//////////////////////////////////

void test_application_initialize(void);
void test_application_main(void);

#endif
