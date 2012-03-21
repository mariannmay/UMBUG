//////////////////////////////////////////////////////////////////
//                                                              //
//    Console access header                                     //
//    last edited by: Kane Anderson                             //
//    date: March 18, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#ifndef CONSOLE_H
#define CONSOLE_H

// includes //////////////////////

#include "./SystemConfig.h"
#include <stdio.h>
#include <string.h>

// for reference... //////////////

//		typedef struct {
// 	    	int fd;                    /* File descriptor */
// 	    	unsigned char* buf;        /* Pointer to start of buffer */
// 	    	unsigned char* pos;        /* Position in buffer */
//	    	unsigned char* bufend;     /* Pointer to end of buffer */
//	    	unsigned char* buff_stop;  /* Pointer to last read char in buffer */
//	    	unsigned int   flags;      /* File status flags (see below) */
//		} FILE;

// definitions ///////////////////

static const char null_char = '\0';
static const char backspace_char = 0x7F;
static const char return_char = '\r';

static char consoleInputBuffer[CONSOLE_BUFFER_SIZE];
static int consoleInputBufferIndex;

// functions /////////////////////

void initializeConsole(void);
void runConsole(void);

//////////////////////////////////

#endif

