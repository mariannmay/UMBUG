//////////////////////////////////////////////////////////////////
//                                                              //
//    PSK header                                                //
//    last edited by: Tong Duan                                 //
//    date: July 10, 2012                                       //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef PSK_H
#define PSK_H

#include "../../system/Packet.h"//includes the Packet struct
#include "../../drivers/IOTypes.h"//includes the IOType struct



void convertBinaryToPSK(Byte data[], int size);
void testPSK(void);
Word phaseChange(int digital[]);
 

#endif
