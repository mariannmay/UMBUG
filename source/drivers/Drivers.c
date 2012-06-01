//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers main file                                         //
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//                                                              //
//////////////////////////////////////////////////////////////////

#include "Drivers.h"

// global variable ///////////////////////////////////////////////
AllDevices devices;

//////////////////////////////////////////////////////////////////

void drivers_initialize(void)
{
	
	// this initializes all of our named IO, allowing you to use
	// things like...
	// bool foo = msp430.PORT_1.digitalInput[0].state;
	// msp430.PORT_9.digitalOutput[4].state = true;
	initialize_msp430_IO_ports();
	
	
	// now go through devices...
	// refer to the msp430 spreadsheet on google docs for
	// where to put your pins... when you use up a pin,
	// comment beside the pin to say what it is used for.
	
	// system watchdog
	devices.systemWatchdog.WDI				= &msp430.PORT_10.digitalOutput[5];
	watchdog_initialize(&devices.systemWatchdog);
		
	// system clock
	devices.systemStatusLED					= &msp430.PORT_5.digitalOutput;
	
	//set operating mode to fully active using the status register
	_bic_SR_register(LPM4_bits);
	
	//smclk clock setup
	FLL_CTL0 |= DCOPLUS + XTS_FLL;
	FLL_CTL1 &= ~(SELS + SELM0 + SELM1 + SMCLKOFF + FLL_DIV0 + FLL_DIV0);
	FLL_CTL1 |= XT2OFF;
	
	/* System Clock Frequency Integrator 0 */
	SCFI0 &= ~(FLLD0 + FLLD1);
	SCFI0 |= FN_2; //FLL_DIV_1 | 
	/* System Clock Frequency Integrator 1 */
	//SCFI1 is auto set
	/* System Clock Frequency Control */
	SCFQCTL = SCFQ_1M;
	
	// this sets timer A up
	initializeTimerA();
	
	
	// SPI bus
	// note: this code is redundant.  The SPI library will take care
	//       of writing to these pins for us.  They are shown here
	//		 simply for clarification, and so nobody else uses the pins.
	// TODO verify and claim the proper pin numbers
	//devices.spiBus.clock					= &msp430.PORT_3.serialInput[1];	// P3.2
	//devices.spiBus.slaveInMasterOut			= &msp430.PORT_3.serialOutput[1];	// P3.0
	//devices.spiBus.slaveOutMasterIn			= &msp430.PORT_3.serialInput[0];	// P3.3
	//initialize_SPI(1);
	//initialize_SPI(2); //TODO: fix this ?? Should there be two?
						//... yes, COM needs 2
	
	// SD card
	devices.sdCard.SPI.bus					= &devices.spiBus;
	devices.sdCard.SPI.enable				= &msp430.PORT_8.digitalOutput[0];
	devices.sdCard.SPI.enable->state		= high;
	devices.sdCard.cardPresence				= &msp430.PORT_5.digitalInput[3];
	devices.sdCard.status					= SDCARD_UNINITIALIZED;
	sdCard_initialize(&devices.sdCard);
	
	// master multiplexer select lines... used for all multiplexed I/O
	devices.multiplexerSelectLines.S0		= &msp430.PORT_8.digitalOutput[1];
	devices.multiplexerSelectLines.S1		= &msp430.PORT_8.digitalOutput[2];
	devices.multiplexerSelectLines.S2		= &msp430.PORT_8.digitalOutput[3];
	
	// digital input multiplexer 0
	devices.digitalInputMUX0.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalInputMUX0.currentInput	= &msp430.PORT_2.digitalInput[0];
	
	// digital input multiplexer 1
	devices.digitalInputMUX1.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalInputMUX1.currentInput	= &msp430.PORT_2.digitalInput[1];
	
	// digital input multiplexer 2
	devices.digitalInputMUX2.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalInputMUX2.currentInput	= &msp430.PORT_2.digitalInput[2];
	
	// analog input multiplexer 0
	devices.analogInputMUX0.selectLines		= &devices.multiplexerSelectLines;
	devices.analogInputMUX0.currentInput	= &msp430.PORT_6.analogInput[0];
	
	// analog input multiplexer 1
	devices.analogInputMUX1.selectLines		= &devices.multiplexerSelectLines;
	devices.analogInputMUX1.currentInput	= &msp430.PORT_6.analogInput[1];
	
	// analog input multiplexer 2
	devices.analogInputMUX2.selectLines		= &devices.multiplexerSelectLines;
	devices.analogInputMUX2.currentInput	= &msp430.PORT_6.analogInput[2];
	
	// digital output multiplexer 0
	devices.digitalOutputMUX0.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalOutputMUX0.currentOutput	= &msp430.PORT_8.digitalOutput[4];
	
	// digital output multiplexer 1
	devices.digitalOutputMUX1.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalOutputMUX1.currentOutput	= &msp430.PORT_8.digitalOutput[5];
	
	// digital output multiplexer 2
	devices.digitalOutputMUX2.selectLines	= &devices.multiplexerSelectLines;
	devices.digitalOutputMUX2.currentOutput	= &msp430.PORT_8.digitalOutput[6];
	
	// johnsons test thermocouple
	devices.testThermocouple.voltageInput		= &msp430.PORT_6.analogInput[6];
}

//////////////////////////////////////////////////////////////////

void drivers_readInputs(void)
{
	
	int index;
	for (index = 0; index < 8; index++)
	{
		if (index < 1) { readAnalogInput (&msp430.PORT_5.analogInput);		   }
		if (index < 8) { readDigitalInput(&msp430.PORT_1.digitalInput[index]); }
		if (index < 6) { readDigitalInput(&msp430.PORT_2.digitalInput[index]); }
		if (index < 4) { readDigitalInput(&msp430.PORT_3.digitalInput[index]); }
		if (index < 6) { readDigitalInput(&msp430.PORT_5.digitalInput[index]); }
		if (index < 8) { readAnalogInput (&msp430.PORT_6.analogInput [index]); }
		if (index < 2) { readAnalogInput (&msp430.PORT_10.analogInput[index]); }
	}
	
	// that takes care of reading the digital and analog inputs... reset the
	// analog to digital converter so that it does another conversion
	// before next time
	startNewAnalogToDigitalConversion();
	
	// read serial inputs
	// note: for simplicity, we currently only have 8-Byte messages
	//		 this puts the data in the buffer that belongs to 
	//		 devices.SPIBus.receivedMessage
	SPI_receive(devices.spiBus.receivedMessage.data, STANDARD_SPI_MESSAGE_SIZE);
	
	// read multiplexed inputs...
	// there are 3 select lines, so each input is populated once
	// every 8 processor main loops
	readMultiplexedDigitalInput(&devices.digitalInputMUX0);
	readMultiplexedDigitalInput(&devices.digitalInputMUX1);
	readMultiplexedDigitalInput(&devices.digitalInputMUX2);
	readMultiplexedAnalogInput(&devices.analogInputMUX0);
	readMultiplexedAnalogInput(&devices.analogInputMUX1);
	readMultiplexedAnalogInput(&devices.analogInputMUX2);
}

void drivers_setOutputs(void)
{
	
	// drive the digital outputs
	int index;
	bool temp;
	
	for (index = 0; index < 8; index++)
	{
		
		if (index < 1)
		{
			if (msp430.PORT_5.digitalOutput.state == high) { setDigitalOutput(&msp430.PORT_5.digitalOutput); }
			else										   { clearDigitalOutput(&msp430.PORT_5.digitalOutput); }
		}
		if (index < 4)
		{
			temp = msp430.PORT_7.digitalOutput[index].state;
			temp ?	setDigitalOutput(&msp430.PORT_7.digitalOutput[index]) :
					clearDigitalOutput(&msp430.PORT_7.digitalOutput[index]);
		}
		if (index < 8)
		{
			temp = msp430.PORT_8.digitalOutput[index].state;
			temp ?	setDigitalOutput(&msp430.PORT_8.digitalOutput[index]) :
					clearDigitalOutput(&msp430.PORT_8.digitalOutput[index]);
			
			temp = msp430.PORT_9.digitalOutput[index].state;
			temp ?	setDigitalOutput(&msp430.PORT_9.digitalOutput[index]) :
					clearDigitalOutput(&msp430.PORT_9.digitalOutput[index]);

		}
		if (index < 6)
		{
			temp = msp430.PORT_10.digitalOutput[index].state;
			temp ?	setDigitalOutput(&msp430.PORT_10.digitalOutput[index]) :
					clearDigitalOutput(&msp430.PORT_10.digitalOutput[index]);
		}
		
	}
	
	// TODO setup digital to analog converter and set outputs here
	
	// send serial outputs
	// note: for simplicity, we currently only have 8-Byte messages
	//		 this sends the data in the buffer that belongs to 
	//		 devices.SPIBus.transmitMessage
	SPI_transmit(devices.spiBus.transmitMessage.data, STANDARD_SPI_MESSAGE_SIZE);
	
	// send multiplexed outputs
	// there are 3 select lines, so each output is actually sent once
	// every 8 processor main loops
	sendSoftwareMultiplexedDigitalOutput(&devices.digitalOutputMUX0);
	sendSoftwareMultiplexedDigitalOutput(&devices.digitalOutputMUX1);
	sendSoftwareMultiplexedDigitalOutput(&devices.digitalOutputMUX2);
}



