//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMApplication.h"

///////////////////////////////////////////////////////////////////

UI16 currentToneIndex = 0;
bool toggle = high;

#if COM_PROCESSOR_COMPILE
	#pragma vector=TIMERA0_VECTOR
	__interrupt void timerA0int()
	{
	
		if(TAIV && TAIV_TACCR1)	//if capture compare reg 1 interrupt
		{
			runRadio();
		}
		else
		{
		}
	}
#endif

///////////////////////////////////////////////////////////////////

void COM_application_main(void)
{
	initializePSKBuffer();
	logLine("COM scheduler initialized");
	for(;;)
	{
		COMMainScheduleLoop();
	}
}

void COMMainScheduleLoop(void)
{
	//logLine("LOOPIN' COM\n");
}

void runRadio(void)
{
	bool timeToChangePhase = false;
	
	if (timeToChangePhase == true)
	{
		UI8 currentPhaseChangeOutOf32 = phaseShifts[currentPhaseShiftIndex];
		phaseShifts[currentPhaseShiftIndex] = 0;
		currentPhaseShiftIndex++;
		if (currentPhaseShiftIndex >= PhaseShiftHistoryLength)
		{
			currentPhaseShiftIndex = 0;
		}
		UI16 degreesChange = phaseAngles[currentPhaseChangeOutOf32];
		UI16 toneIndexChange = ToneIndexPositionsPerDegreePhase * degreesChange;
		currentToneIndex += toneIndexChange;
	}
	
	if (currentToneIndex >= SINE_LENGTH)
	{
		currentToneIndex = (currentToneIndex % SINE_LENGTH);
	}
	
	devices.radio.microphone->value = getToneValueAt(currentToneIndex);
	startNewDigitalToAnalogConversion(devices.radio.microphone->value);
	
	currentToneIndex += 100;
	
}






