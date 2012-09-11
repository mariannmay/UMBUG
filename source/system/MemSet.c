
UI16 tableOfValues_UI16[NUM_PARAM_UI16];
int tableOfValues_int[NUM_PARAM_int];
void setMemoryAt_int(int* address,int value)
{
	int intOn =	__get_SR_Register()&&GIE > 0;
		
	disableInterrupts();
	*address = value;
	if(intOn)
	{
		enableInterrupts();	
	}
	
}
void setMemoryAt_UI16(UI16* address, UI16 value)
{
	int intOn =	__get_SR_Register()&&GIE > 0;
		
	disableInterrupts();
	*address = value;
	if(intOn)
	{
		enableInterrupts();	
	}
}
void setMemoryAt_UI32(UI32* address,UI32 value)
{
	int intOn =	__get_SR_Register()&&GIE > 0;
		
	disableInterrupts();
	*address = value;
	if(intOn)
	{
		enableInterrupts();	
	}
}
void setMemoryAt_UI8(UI8* address,UI8 value)
{
	int intOn =	__get_SR_Register()&&GIE > 0;
		
	disableInterrupts();
	*address = value;
	if(intOn)
	{
		enableInterrupts();	
	}
}