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
	initialize_msp430_IO_ports();
	
	// refer to the msp430 spreadsheet on google docs for
	// where to put your pins... when you use up a pin,
	// comment beside the pin to say what it is used for.
	
	// system watchdog ///////////////////////////////////////////
	
	devices.systemWatchdog.WDI					= &msp430.PORT_10.digitalOutput[5];
	watchdog_initialize(&devices.systemWatchdog);
		
	// system clock //////////////////////////////////////////////
	
	devices.realTimeClock.SPI.chipSelect.out	= &msp430.PORT_10.digitalOutput[4];
	devices.realTimeClock.SPI.channel			= SPI_CHANNEL_1;
	devices.realTimeClock.SPI.type				= SPI_TYPE_Master;
	devices.realTimeClock.SPI.activeHigh		= true;
	devices.realTimeClock.SPI.controlRegister0	= 0x29;
	devices.realTimeClock.SPI.controlRegister1	= 0x80;
	devices.realTimeClock.SPI.bitRateRegister0	= 0x20;
	devices.realTimeClock.SPI.bitRateRegister1	= 0x00;
	realTimeClock_initialize(&devices.realTimeClock);
	
	// SD card ///////////////////////////////////////////////////
	#if COM_PROCESSOR_COMPILE
		devices.sdCard.SPI.chipSelect.out		= &msp430.PORT_8.digitalOutput[0];
		devices.sdCard.SPI.channel				= SPI_CHANNEL_2;
		devices.sdCard.SPI.type					= SPI_TYPE_Master;
		devices.sdCard.SPI.activeHigh			= false;
		devices.sdCard.SPI.controlRegister0		= 0xA9;
		devices.sdCard.SPI.controlRegister1		= 0x80;
		devices.sdCard.SPI.bitRateRegister0		= 0x04;
		devices.sdCard.SPI.bitRateRegister1		= 0x00;
		sdCard_initialize(&devices.sdCard);
	#endif
	
	// TEST SPI FRAMEWORK ONLY ///////////////////////////////////
	
	/*
	#if CDH_PROCESSOR_COMPILE
		devices.test_SPI_device.chipSelect.out		= &msp430.PORT_10.digitalOutput[4];
		devices.test_SPI_device.channel				= SPI_CHANNEL_1;
		devices.test_SPI_device.type				= SPI_TYPE_Master;
		devices.test_SPI_device.activeHigh			= true;
		devices.test_SPI_device.controlRegister0	= 0xA9;
		devices.test_SPI_device.controlRegister1	= 0x80;
		devices.test_SPI_device.bitRateRegister0	= 0x04;
		devices.test_SPI_device.bitRateRegister1	= 0x00;
	#else
		devices.test_SPI_device.chipSelect.in		= &msp430.PORT_1.digitalInput[5];
		devices.test_SPI_device.channel				= SPI_CHANNEL_1;
		devices.test_SPI_device.type				= SPI_TYPE_Slave;
		devices.test_SPI_device.activeHigh			= true;
		devices.test_SPI_device.controlRegister0	= 0xA1;
		devices.test_SPI_device.controlRegister1	= 0x80;
		devices.test_SPI_device.bitRateRegister0	= 0x04;
		devices.test_SPI_device.bitRateRegister1	= 0x00;
	#endif
	
	initialize_SPI(&devices.test_SPI_device);
	*/
	
	// system status LED /////////////////////////////////////////
	
	devices.systemStatusLED					= &msp430.PORT_5.digitalOutput;
	
	// operating mode to fully active ////////////////////////////
	
	// correct me if I'm wrong but I think this enters low power mode 4
	//_bic_SR_register(LPM4_bits);
	
	// smclk clock setup /////////////////////////////////////////
	
	FLL_CTL0 |= DCOPLUS + XTS_FLL;
	FLL_CTL1 &= ~(SELS + SELM0 + SELM1 + SMCLKOFF + FLL_DIV0 + FLL_DIV1);
	FLL_CTL1 |= XT2OFF;
	
	// System Clock Frequency Integrator 0 ///////////////////////
	
	SCFI0 &= ~(FLLD0 + FLLD1);
	
	#if CDH_PROCESSOR_COMPILE
		SCFI0 |= FN_2; //FLL_DIV_1 |
	#endif
	
	#if COM_PROCESSOR_COMPILE
		SCFI0 |= FN_8; //FLL_DIV_1 |
	#endif
	 
	// System Clock Frequency Control ////////////////////////////
	
	SCFQCTL = SCFQ_2M;
	
	// Digital to analog conversion //////////////////////////////
	#if COM_PROCESSOR_COMPILE
		// TODO UNCOMMENT AFTER TEST OUTPUT DONE
		devices.radio.microphone				= &msp430.PORT_6.analogOutput;
		devices.test_AtoD						= &msp430.PORT_5.analogInput;
		//devices.testPSK							= &msp430.PORT_6.analogOutput;
		
	#endif
	
	// for debug purposes
	// TODO REMOVE
	devices.testThermocouple.voltageInput		= &msp430.PORT_6.analogInput[5]; // P6.5, pin #4
	
	
	
	// master multiplexer select lines... used for all multiplexed I/O
	//devices.multiplexerSelectLines.S0		= &msp430.PORT_8.digitalOutput[1];
	//devices.multiplexerSelectLines.S1		= &msp430.PORT_8.digitalOutput[2];
	//devices.multiplexerSelectLines.S2		= &msp430.PORT_8.digitalOutput[3];
	
	
}

//////////////////////////////////////////////////////////////////


