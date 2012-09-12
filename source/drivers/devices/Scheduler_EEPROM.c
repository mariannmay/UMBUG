#include "Drivers.h"
#include "Scheduler_EEPROM.h"

SPI_Device SchedulerEEPROM;

void writeByte_SCHEEPROM(UI16 address, UI8 data)
{
	//write enable before every write is mandator
	Byte toSCHEEPROM[3] = {SCHEEPROM_WREN,0,0};
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 1, true);
	
	//IMPORTANT - does chip select go high in this period?  It is mandatory!!! (after every WREN)
	//Yes it does.
	
	//now can actually write to eeprom
	toSCHEEPROM[0] = SCHEEPROM_WRITE;
	toSCHEEPROM[1] = address;
	toSCHEEPROM[2] = data;
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 3, true);

}

void writeStatus_SCHEEPROM(UI8 byte)
{

}
UI8 readByte_SCHEEPROM(UI16 address)
{
	Byte toSCHEEPROM[2] = {SCHEEPROM_RDSR, adress};
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 2, true);
	SPI_receive(&SchedulerEEPROM, true);
	return (UI8)SchedulerEEPROM.receiveMessage[0];
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
	SchedulerEEPROM.type = SPI_TYPE_MASTER;		//from perspective of processor
	SchedulerEEPROM.channel = SPI_CHANNEL_2;	//dont know which to use yet - the one that RTC is _not_ on I assume.........

//Byte	transmitMessage[SPI_TX_BUFFER_SIZE];
//Byte	receiveMessage[SPI_RX_BUFFER_SIZE];

	SchedulerEEPROM.activeHigh = false;

	SchedulerEEPROM.controlRegister0 = 1 << 0; //UCCKPH (Clock phase) = 0b -> Data is changed on the first UCLK edge and captured on the following edge.
	SchedulerEEPROM.controlRegister0 |= 0 << 1; //UCCKPL (Clock polarity) = 0b -> The inactive state is low
	SchedulerEEPROM.controlRegister0 |= 1 << 2; //UCMSB (MSB first select) = 1b -> MSB first
	SchedulerEEPROM.controlRegister0 |= 0 << 3; //UC7BIT (Character length) = 0b -> 8-bit data
	SchedulerEEPROM.controlRegister0 |= 1 << 4; //UCMST (Master mode) = 1b -> Master mode
	SchedulerEEPROM.controlRegister0 |= 0 << 5; //UCMODEx (USCI mode) = 00b -> 3-Pin SPI
	SchedulerEEPROM.controlRegister0 |= 0 << 6;
	SchedulerEEPROM.controlRegister0 |= 1 << 7; //UCSYNC (Synchronous mode enable) = 1b -> Synchronous mode
	
	
	
	SchedulerEEPROM.controlRegister1 = 0 << 0; //UCSWRST (Software reset) = 1b -> normally set by a PUC
	SchedulerEEPROM.controlRegister1 |= 0 << 1; 
	SchedulerEEPROM.controlRegister1 |= 0 << 2; 
	SchedulerEEPROM.controlRegister1 |= 0 << 3; 
	SchedulerEEPROM.controlRegister1 |= 0 << 4; 
	SchedulerEEPROM.controlRegister1 |= 0 << 5; 
	SchedulerEEPROM.controlRegister1 |= 0 << 6; //UCSSELx (USCI clock source select)= 10b -> SMCLK
	SchedulerEEPROM.controlRegister1 |= 1 << 7; //UCSSELx (USCI clock source select)= 10b -> SMCLK
	SchedulerEEPROM.bitRateRegister0 = 00x20; // Copied this from RTC config....
	SchedulerEEPROM.bitRateRegister1 = 0x00; //  Copied this from RTC config....
	
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
	
	Byte toSCHEEPROM[2] = {SCHEEPROM_WRSR,0x80};
	SPI_transmitStream(&SchedulerEEPROM, toSCHEEPROM, 1, true);
	
//TODO figure out what pin we can stick here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//P8.2
	SchedulerEEPROM.chipSelect = &msp430.PORT_8.digitalOutput[2];;
}