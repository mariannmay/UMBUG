//////////////////////////////////////////////////////////////////
//                                                              //
//    Console access source                                     //
//    last edited by: Kane Anderson                             //
//    date: March 18, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

// includes //////////////////////

#include "./Console.h"

// functions /////////////////////

void initializeConsole(void)
{
	consoleInputBuffer[0] = null_char;
	consoleInputBufferIndex = 0;	
}

void runConsole(void)
{
	if (stdin == NULL) { return; }
	
	consoleInputBuffer[consoleInputBufferIndex] = (*stdin->buff_stop);
	
	if ((consoleInputBufferIndex > 0) && (consoleInputBuffer[consoleInputBufferIndex] == null_char))
	{
		printf("\r\n> echo > %s", consoleInputBuffer);
		consoleInputBufferIndex = 0;
	}
	
	consoleInputBufferIndex++;
	
	if (consoleInputBufferIndex > CONSOLE_BUFFER_SIZE)
	{
		consoleInputBufferIndex = 0;
	}
	
}

//////////////////////////////////


