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

//I tried including these so i could test my part of the application
//I couldn't properly reference COM to test my methods
//#include "../application/COM/COM.c"
//#include "../application/COM/COM.h"

//////////////////////////////////

void test_application_initialize(void);
void test_application_main(void);

#endif
