#ifndef MEMSET_H_
#define MEMSET_H_


#include <msp430fg4619.h>
#include <stdio.h>
#include <intrinsics.h>
#include "../SimpleDefinitions.h"
#include "../system/TimeCounter.h"
/*
 * These functions set different variable sizes.
 * they return 1 on success or 0 on failure.
 * 
 */
void setMemoryAt_int(int*,int);
void setMemoryAt_UI8(UI8*, UI8);
void setMemoryAt_UI16(UI16*,UI16);
void setMemoryAt_TimeCounter(TimeCounter*, TimeCounter);//prob not necessary?


//set arbitrary data by using UI8's.
#endif