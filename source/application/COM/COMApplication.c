//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Kane Anderson                             //
//    date: January 16, 2012                                    //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMApplication.h"

#if COM_PROCESSOR_COMPILE

	///////////////////////////////////////////////////////////////////
	
	UI16 currentToneIndex = 0;
	bool toggle = high;
	
	///////////////////////////////////////////////////////////////////
	
	void COM_timerA_ISR(void)
	{
		runRadio();
	}
	
	///////////////////////////////////////////////////////////////////
	
	void COM_application_main(void)
	{
		sdCard_initialize(&devices.sdCard);
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
		#if COM_PROCESSOR_COMPILE
		
			// TODO make this happen sometimes
			//bool timeToChangePhase = false;
			//static UI16 weirdTemp = 234;
			static UI16 phaseOffset = 150/4;
			static UI16 counter = 0;
			if (/*timeToChangePhase == true*/false)
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
			//else
			//{
				currentToneIndex += 150;
			//	currentToneIndex = currentToneIndex % SINE_LENGTH;
				//weirdTemp += 38;
			//}
			
			counter++;
			if(counter >= SINE_LENGTH/150)
			{
				counter = 0;
				phaseOffset = phaseOffset == 2400 ? 0:2400;
			}
			
			
			/*if (currentToneIndex%SINE_LENGTH < currentToneIndex)
			{
				phaseOffset += 150;	
			}
			*/
			currentToneIndex = currentToneIndex%SINE_LENGTH;
			phaseOffset = phaseOffset%SINE_LENGTH;
			
			
			/*
			if (currentToneIndex+phaseOffset >= SINE_LENGTH)
			{
				//currentToneIndex += weirdTemp;
				currentToneIndex = (currentToneIndex % (SINE_LENGTH - phaseOffset));
			}
			*/
			devices.radio.microphone->value = getToneValueAt((currentToneIndex + phaseOffset)%SINE_LENGTH);
			startNewDigitalToAnalogConversion(devices.radio.microphone->value);
		#endif
		
	}


#endif



