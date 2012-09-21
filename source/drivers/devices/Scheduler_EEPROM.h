#define SCHEEPROM_READ 0x03		//0000 0011
#define SCHEEPROM_WRITE 0x02	//0000 0010
#define SCHEEPROM_WRDI 0x04		//0000 0100
#define SCHEEPROM_WREN 0x06		//0000 0110
#define SCHEEPROM_RDSR 0x05		//0000 0101
#define SCHEEPROM_WRSR 0x01		//0000 0001
#define SCHEEPROM_BYTES_PER_PAGE 32

extern SPI_Device SchedulerEEPROM;
UI8 readByte_SCHEEPROM(UI16 address);
void writeByte_SCHEEPROM(UI16 address, UI8 data);
void writeEnable_SCHEEPROM(void);
void writeStatus_SCHEEPROM(UI8 byte);
void init_SCHEEPROM();
UI8 stillWriting_SCHEEPROM();