//////////////////////////////////////////////////////////////////
//                                                              //
//    Drivers main file                                         //
//    last edited by: Kane Anderson                             //
//    date: March 8, 2011                                   	//
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
	devices.systemWatchdog.WDI = &msp430.PORT_10.digitalOutput[5];
	watchdog_initialize(&devices.systemWatchdog);
		
	// system clock
	devices.systemStatusLED = &msp430.PORT_5.digitalOutput;
	
	// main battery
	devices.mainBattery.voltageLevel = &msp430.PORT_6.analogInput[2];
	
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
	
	// TODO read serial inputs
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
	
	// TODO send serial outputs
}
