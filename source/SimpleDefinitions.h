//////////////////////////////////////////////////////////////////
//                                                              //
//    simple definitions                                        //
//    last edited by: Kane Anderson                             //
//    date: January 17, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef SIMPLEDEFINITIONS_H
#define SIMPLEDEFINITIONS_H

#include <stdbool.h>

// logic //////////////////////////////////////
#define high true
#define low false
///////////////////////////////////////////////

// data lengths ///////////////////////////////
typedef unsigned char UI8;
typedef signed char SI8;
typedef unsigned int UI16;
typedef signed int SI16;
typedef unsigned long UL32;
///////////////////////////////////////////////

// voltage and current ////////////////////////
typedef SI16 Millivolts;
typedef SI16 Milliamps;

// byte and word //////////////////////////////
typedef UI8 Byte;
typedef UI16 Word;
Word MultiByte2(Byte b1, Byte b2);
UL32 MultiByte4(Byte b1, Byte b2, Byte b3, Byte b4);

///////////////////////////////////////////////

// time ///////////////////////////////////////
typedef UL32 Time_ms;
#define OneSecond 1000

#endif
