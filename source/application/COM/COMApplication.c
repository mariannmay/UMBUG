//////////////////////////////////////////////////////////////////
//                                                              //
//    CDHApplication header                                     //
//    last edited by: Craig Nemeth                              //
//    date: August 31, 2012                                     //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "COMApplication.h"
///////////////////////////////////////////////////////////////////

#define COMMAND_ADDRESS 23;
#define CMD_SEND_120_PACKETS 120;
#define CMD_HANDSHAKE_ONE 15;
#define CMD_HANDSHAKE_TWO 52;
#define PACKET_SIZE 64;

///////////////////////////////////////////////////////////////////

UI16 currentToneIndex = 0;
bool toggle = high;

///////////////////////////////////////////////////////////////////

UI16* AtoDReadingOne;
UI16* AtoDReadingTwo;
int bitPositionInPacket = 0;
bool gotAnother64BytesFromRadio = false;

///////////////////////////////////////////////////////////////////
bool linkEstablished = false;
UI8* nextPacketGroupToSend;
UI16 nextSDCardAddress;
bool transmitting = false;
bool gotAnother64BytesFromRadio = false;

const UI8 stageTwoHandShake[] = {0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, CMD_HANDSHAKE_TWO,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF};

///////////////////////////////////////////////////////////////////

void COM_timerA_ISR(void)
{
	runRadio();
}

///////////////////////////////////////////////////////////////////

void COM_application_main(void)
{
	initializePSKBuffer();
	//init the packet finder Alg buffers
	firstHalf = (UI8 *)malloc(PACKET_SIZE);
	secondHalf = (UI8 *)malloc(PACKET_SIZE);
	AtoDReadingOne = (UI16 *)malloc(2);
	AtoDReadingTwo = (UI16 *)malloc(2);
	logLine("COM scheduler initialized");
	for(;;)
	{
		COMMainScheduleLoop();
	}
}

void COMMainScheduleLoop(void)
{

	//enable interrupts to communicate with GND and listen
	enableInterrupts();

	//control Radio interface/////////////////////////////////////////////////////////////////////////////////////////////
	if(AcquiredNewData)//set from the listening interrupt
	{
		if(findPacket(0))
		{	
			UI8 groundCommandNumber = retrievedPacket[COMMAND_ADDRESS];
			switch(groundCommandNumber)
			{
				case: CMD_HANDSHAKE_ONE
				{
					nextPacketGroupToSend = &stageTwoHandShake;//TODO: hardcode this as phase changes
					//set the global var transmitting to true so the radio interrupt sends the next buffer of packets
					transmitting = true;
					while(transmitting);//wait for the interrupt to finish sending the packet. it will set transmitting false
				}break;
				case: CMD_SEND_120_PACKETS
				{
					
					//send 10 groups of 12 packets in phase shift form
					//SD card must be read from at 512 bytes at a time
					//the packets in phase shift from are 40 bytes (40*12 = 480)
					//the last 32 bytes from the SD card will be zero filled which will do nothing to the output signal
					int packetGroup;
					for(packetGroup =0; packetGroup<10; packetGroup++)
					{
						if(nextSDCardAddress<=lastStoredSDCardAddress)
						{
							spiSDCardGetPacketGroup(nextPacketGroupToSend, nextSDCardAddress*512);//get packet from SD
							
							//set the global var transmitting to true so the radio interrupt sends the next buffer of packets
							transmitting = true;
							while(transmitting);//wait for the interrupt to finish sending the packet. it will set transmitting false
							
							//increment to next SD memory location
							nextSDCardAddress++;
						}else
						{
							nextPacketGroupToSend = &outOfDataMessage;
							//set the global var transmitting to true so the radio interrupt sends the next buffer of packets
							transmitting = true;
							while(transmitting);//wait for the interrupt to finish sending the packet. it will set transmitting false
						}
					}
					
				}break;
				default:
				{
					
				}break;
			}
		}
	}
	//end control of radio interface/////////////////////////////////////////////////////////////////////////////////////////
	//note: radio interrupt is still running
	//control CDH interface//////////////////////////////////////////////////////////////////////////////////////////////////
	if(CDHRequestingSPI && !transmitting)
	{
		disableInterrupts();//no more radio interface
		//TODO reset the buffer for the radio listening interrupt so old data is discarded when listening resumes
		
		CDHSPISendHandshake();//tell CDH that COM is ready to recieve data
		SPICDHGetPacket(packetFromCDH);//recieve packet from CDH
		convertBinaryToPSK(packetFromCDH,64);//convert and add to phase shifts from CDH buffer
		if(PhaseBufferSize==512)//if you have filled the buffer
		{
			spiSDCardSendPacketGroup(packetsInPhaseFormToSDCard, (++lastStoredSDCardAddress)*512);//send phase shifts to SD
		}
		enableInterrupts();
	}
	//end control CDH interface//////////////////////////////////////////////////////////////////////////////////////////////
}

void runRadio(void)
{
	if(transmitting)
	{
		bool timeToChangePhase = false;
		
		/*if (timeToChangePhase == true)
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
		else
		{*/
			currentToneIndex += 100;	
		//}
		
		if (currentToneIndex >= SINE_LENGTH)
		{
			currentToneIndex = (currentToneIndex % SINE_LENGTH);
		}
		
		//devices.radio.microphone->value = getToneValueAt(currentToneIndex);
		startNewDigitalToAnalogConversion(devices.radio.microphone->value);
		
	}else //listening
	{
		//do AtoD stuff
		//fill small buffer of 1Byte
		//then add to master circular buffer
	}
}






