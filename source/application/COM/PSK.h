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
#include "../COM/Tone.h"


void convertBinaryToPSK(Byte data[], int size);
Word phaseChange(int digital[]);
 

#endif
