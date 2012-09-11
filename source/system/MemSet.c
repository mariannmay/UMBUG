#include "MemSet.h"
#include <intrinsics.h>
void setMemoryAt_int(int* address,int value)
{
	int intOn =	_get_SR_register()&&GIE > 0;
	_disable_interrupt();
	*address = value;
	if(intOn)
	{
		_enable_interrupt();	
	}
	
}
void setMemoryAt_UI16(UI16* address, UI16 value)
{
	int intOn =	_get_SR_register()&&GIE > 0;
		
	_disable_interrupt();
	*address = value;
	if(intOn)
	{
		_enable_interrupt();	
	}
}

void setMemoryAt_UI8(UI8* address,UI8 value)
{
	int intOn =	_get_SR_register()&&GIE > 0;
		
	_disable_interrupt();
	*address = value;
	if(intOn)
	{
		_enable_interrupt();	
	}
}
