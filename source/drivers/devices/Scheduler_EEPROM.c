#include "../Drivers.h"
#include "Scheduler_EEPROM.h"
#include <stdio.h>
SPI_Device SchedulerEEPROM;

void writeByte_SCHEEPROM(UI16 address, UI8 data)
{
	//write enable before every write is mandator
	
	while(stillWriting_SCHEEPROM());
	Byte toSCHEEPROM[4] = {SCHEEPROM_WREN,0,0,0};
	//SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 1,true);
	SPI_transmit(&SchedulerEEPROM, toSCHEEPROM[0], true);
	
	//IMPORTANT - does chip select go high in this period?  It is mandatory!!! (after every WREN)
	//Yes it does.
	
	//now can actually write to eeprom
	toSCHEEPROM[0] = SCHEEPROM_WRITE;
	toSCHEEPROM[1] = (address>>8)&(0x00FF);
	toSCHEEPROM[2] = address&(0x00FF);
	toSCHEEPROM[3] = data;
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 4,true);

}

void writeStatus_SCHEEPROM(UI8 byte)
{

}
UI8 readByte_SCHEEPROM(UI16 address)
{
	while(stillWriting_SCHEEPROM());
	Byte toSCHEEPROM[3];
	toSCHEEPROM[0] = SCHEEPROM_READ;
	toSCHEEPROM[1] = (address>>8)&(0xFF);
	toSCHEEPROM[2] = address&0x00FF;
	//use my own pull CS low?
	
	clearDigitalOutput(SchedulerEEPROM.chipSelect.out);
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 3,false);
	SPI_receive(&SchedulerEEPROM,false);
	setDigitalOutput(SchedulerEEPROM.chipSelect.out);
	return (UI8)SchedulerEEPROM.receiveMessage[0];
}

/*
 * return 1 if still writing 0 else
 */
UI8 stillWriting_SCHEEPROM()
{
	clearDigitalOutput(SchedulerEEPROM.chipSelect.out);
	SPI_transmit(&SchedulerEEPROM,SCHEEPROM_RDSR,false);
	SPI_receive(&SchedulerEEPROM,false);
	setDigitalOutput(SchedulerEEPROM.chipSelect.out);
	return SchedulerEEPROM.receiveMessage[0]&0x01;
}

/*
This function has no arguments, because there is only one SPI_DEVICE struct for this.
*/



/* CONTROL REGISTERS
* =================
* UCB0CTL0 : Control Register 0
* ---------------------------------------------------------------
* | 7 | 6 | 5 | 4 | 3 | 2 1 | 0 |
* | UCCKPH | UCCKPL | UCMSB | UC7BIT | UCMST | UCMODEx | UCSYNC |
* ---------------------------------------------------------------
* UCCKPH (Clock phase) = 0b -> Data is changed on the first UCLK edge and captured on the following edge.
* UCCKPL (Clock polarity) = 0b -> The inactive state is low
* UCMSB (MSB first select) = 1b -> MSB first
* UC7BIT (Character length) = 0b -> 8-bit data
* UCMST (Master mode) = 1b -> Master mode
* UCMODEx (USCI mode) = 00b -> 3-Pin SPI
* UCSYNC (Synchronous mode enable) = 1b -> Synchronous mode
*
*
* UCA0CTL1 : Control Register 1
* ------------------------------------------------------------------
* | 7 6 | 5 4 3 2 | 0 |
* | UCSSELx | Unused | UCSWRST |
* ------------------------------------------------------------------
* UCSSELx (USCI clock source select)= 10b -> SMCLK
* UCSWRST (Software reset) = 1b -> normally set by a PUC
*
*
*
* UCB0BR0, UCB0BR1 : DATA RATE
* Data rate = SMCLK/2 ~= 500kHz
*
*
*/
void init_SCHEEPROM()
{
	SchedulerEEPROM.type = SPI_TYPE_Master;		//from perspective of processor
	SchedulerEEPROM.channel = SPI_CHANNEL_1/*TODO CHANGE BACK TO 2*/;	//dont know which to use yet - the one that RTC is _not_ on I assume.........

//Byte	transmitMessage[SPI_TX_BUFFER_SIZE];
//Byte	receiveMessage[SPI_RX_BUFFER_SIZE];

	//devices.realTimeClock.SPI.chipSelect.out	= &msp430.PORT_10.digitalOutput[4];
	SchedulerEEPROM.chipSelect.out	= &msp430.PORT_8.digitalOutput[2];    //8.2
	//SchedulerEEPROM.CLK.out			= &msp430.PORT_7.serialOutput[1]; //7.3
	//SchedulerEEPROM.MISO.in			= &msp430.PORT_7.serialInput[0];  //7.2
	//SchedulerEEPROM.MOSI.out		= &msp430.PORT_7.serialOutput[0]; 	  //7.1

		
	SchedulerEEPROM.activeHigh = false;
	/*
	SchedulerEEPROM.controlRegister0 = 1 << 7; //UCCKPH (Clock phase) = 0b -> Data is changed on the first UCLK edge and captured on the following edge.
	SchedulerEEPROM.controlRegister0 |= 0 << 6; //UCCKPL (Clock polarity) = 0b -> The inactive state is low
	SchedulerEEPROM.controlRegister0 |= 1 << 5; //UCMSB (MSB first select) = 1b -> MSB first
	SchedulerEEPROM.controlRegister0 |= 0 << 4; //UC7BIT (Character length) = 0b -> 8-bit data
	SchedulerEEPROM.controlRegister0 |= 1 << 3; //UCMST (Master mode) = 1b -> Master mode
	SchedulerEEPROM.controlRegister0 |= 0 << 2; //UCMODEx (USCI mode) = 00b -> 3-Pin SPI
	SchedulerEEPROM.controlRegister0 |= 0 << 1;
	SchedulerEEPROM.controlRegister0 |= 1 << 0; //UCSYNC (Synchronous mode enable) = 1b -> Synchronous mode
	//printf("\n\nconfig: %x\n\n",SchedulerEEPROM.controlRegister0);
	
	
	SchedulerEEPROM.controlRegister1 = 0 << 7; //UCSWRST (Software reset) = 1b -> normally set by a PUC
	SchedulerEEPROM.controlRegister1 |= 0 << 6; 
	SchedulerEEPROM.controlRegister1 |= 0 << 5; 
	SchedulerEEPROM.controlRegister1 |= 0 << 4; 
	SchedulerEEPROM.controlRegister1 |= 0 << 3; 
	SchedulerEEPROM.controlRegister1 |= 0 << 2; 
	SchedulerEEPROM.controlRegister1 |= 0 << 1; //UCSSELx (USCI clock source select)= 10b -> SMCLK
	SchedulerEEPROM.controlRegister1 |= 1 << 0; //UCSSELx (USCI clock source select)= 10b -> SMCLK
	*/
	SchedulerEEPROM.bitRateRegister0 = 0x20; // Copied this from RTC config....
	SchedulerEEPROM.bitRateRegister1 = 0x00; //  Copied this from RTC config....
	//P8.2
	
	SchedulerEEPROM.controlRegister0 = 0xA9;
	SchedulerEEPROM.controlRegister1 = 0x80;
	
	
	initialize_SPI(&SchedulerEEPROM);

	/*
	Status register
	Bit 7 - WPEN'
	Bits 6-4 - unused
	Bit 3 - BP1
	Bit 2 - BP0
	Bts 1-0 ready only (dont care)


	we want no write protection
	-BP1 = BP0 = 0

	we want no hardware write protection so set WPEN' = 1
	*/
	//TODO REENABLE THESE
	SPI_transmit(&SchedulerEEPROM,SCHEEPROM_WREN,true);
	Byte toSCHEEPROM[2] = {SCHEEPROM_WRSR,0x80};
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 2,true);
	
//TODO figure out what pin we can stick here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	
}
