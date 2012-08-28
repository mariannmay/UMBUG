//******************************************************************************
//  SD Card for MSP-FET430x169 Device Driver Header File
//
//  Description: This source file contains the interface for the SD driver
//
//  Chris Nichols
//  University of Manitoba
//  January 2008
//  Built with IAR Embedded Workbench Version: 4.01
//******************************************************************************

// prevent multiple instances of the same file
#ifndef __SD_CARD_H__     
#define __SD_CARD_H__

#include "../SPIDevice.h"

        #define CMD_LENGTH                              5

	/**
	 * DEBUG flag for the I2C driver
	 * Turning this on will cause printing of information regarding the operation 
	 * of the I2C driver to standard output regardless of the master DEBUG flag
	 **/
	#define SD_CARD_DEBUG				FALSE

	/**
	 * Include MSP430 pin definitions
	 **/
	#include <msp430fg4619.h>

	/**
	 * Include commonly used definitions
	 **/
	#include "./common.h"

	/**
	 * Include error codes
	 **/
	#include "./error_codes.h"

	/**
	 * Include crc generating routines
	 */
	#include "./crc.h"

	/**
	 * Include SPI driver interface
	 */
	#include "./spi.h"

	/**
	 * Include the I2C driver interface
	 **/
	//#include <i2c.h>

	/************************************************************ 
	 * Global Constants
	 ************************************************************/

	// SD status bits
	#define SD_PWR					BIT0	// 1 = power on, 0 = power off
	#define SD_INIT					BIT1	// 1 = initialization completed succesfully
	#define SD_RW					BIT2	// 1 = read, 0 = write
	#define SD_PEND					BIT3	// 1 = r/w pending, 0 = idle
	#define SD_VALID				BIT4	// 1 = last r/w is valid, 0 = if error occured
	#define SD_CHECK_CRC			        BIT5	// 1 = CRC checking is enabled
	#define SD_WRITE_LOCKUP			        BIT6	// 1 = Stuck in busy wait after write
        #define SD_OFF                                  0
      
        #define SD_START_ADDRESS                      0x0001
        #define SD_BLOCK_LENGTH         512
        
	/************************************************************ 
	 * Functions
	 ************************************************************/


        int sd_cmd(char cmd, long args, char resp, char* response);

	/**
	 * Initializes the SD card for use
	 * only needs to be called after a PUC
	 *
	 * IN: void
	 * OUT: int - error code (FALSE if no error)
	 **/
	int sd_init(void);

	/**
	 * Removes power from the SD card
	 *
	 * IN: void
	 * OUT: int - error code (FALSE if no error)
	 **/
	int sd_power_down(void);

	/**
	 * Reads a block of data from the SD card. Status of read can be
	 * checked through sd_check_status()
	 *
	 * IN: buff - receive buffer, must be at least numBytes in size
	 *     length - the number of bytes to be read (max 512)
	 *     block_addr - the address to read from (max depends on the card)
	 * OUT: int - error code (FALSE if no error)
	 **/
	int sd_read(char* buff, int length, long block_addr);

	/**
	 * Writes a block of data to the SD card.  Status of write can be
	 * checked through sd_check_status()
	 *
	 * IN: buff - transmit buffer, must be at least numBytes in size
	 *     length - the number of bytes to be written (max 512)
	 *     block_addr - the address to write to
	 * OUT: int - error code (FALSE if no error)
	 **/
	int sd_write(char* buff, int length, long block_addr);

	/**
	 * Checks the status of the SD card driver
	 *
	 * IN: void
	 * OUT: char - a status byte (see SD status bit descriptions)
	 *
	 **/
	char sd_check_status(void);
        
        #if SD_CARD_DEBUG
          int sd_get_csd();
        #endif
        

#endif // __SD_CARD_H__
