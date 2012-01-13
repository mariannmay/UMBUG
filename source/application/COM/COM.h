//////////////////////////////////////////////////////////////////
//                                                              //
//    COM header                                                //
//    last edited by: Craig Nemeth                              //
//    date: January 12, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef COM_H
#define COM_H

#include "../../system/System.h"

void packetize(char info[], char packet[], char dest[]);
void generateFCS(char *info, char *packet);
bool depacketize(char data[], char packet[]);
void errorCorrection(char packet[]);
void extractData(char data[], char packet[]);

#endif
