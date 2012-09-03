//////////////////////////////////////////////////////////////////
//                                                              //
//    SDCard header                                        		//
//    last edited by: Kane Anderson                             //
//    date: April 06, 2012                                      //
//																//
//	  This file is a modified version of mmc.h from the SPI		//
//	  library													//
//                                                              //
//////////////////////////////////////////////////////////////////

// ***********************************************************
// Description: Library to access a MultiMediaCard 
//              functions: init, read, write ...
//  C. Speck / S. Schauer
//  Texas Instruments, Inc
//  June 2005
//
// Version 1.1
//   corrected comments about connection the MMC to the MSP430
//   increased timeout in mmcGetXXResponse
//
// ***********************************************************
// MMC Lib
// ***********************************************************


/* ***********************************************************
* THIS PROGRAM IS PROVIDED "AS IS". TI MAKES NO WARRANTIES OR
* REPRESENTATIONS, EITHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS 
* FOR A PARTICULAR PURPOSE, LACK OF VIRUSES, ACCURACY OR 
* COMPLETENESS OF RESPONSES, RESULTS AND LACK OF NEGLIGENCE. 
* TI DISCLAIMS ANY WARRANTY OF TITLE, QUIET ENJOYMENT, QUIET 
* POSSESSION, AND NON-INFRINGEMENT OF ANY THIRD PARTY 
* INTELLECTUAL PROPERTY RIGHTS WITH REGARD TO THE PROGRAM OR 
* YOUR USE OF THE PROGRAM.
*
* IN NO EVENT SHALL TI BE LIABLE FOR ANY SPECIAL, INCIDENTAL, 
* CONSEQUENTIAL OR INDIRECT DAMAGES, HOWEVER CAUSED, ON ANY 
* THEORY OF LIABILITY AND WHETHER OR NOT TI HAS BEEN ADVISED 
* OF THE POSSIBILITY OF SUCH DAMAGES, ARISING IN ANY WAY OUT 
* OF THIS AGREEMENT, THE PROGRAM, OR YOUR USE OF THE PROGRAM. 
* EXCLUDED DAMAGES INCLUDE, BUT ARE NOT LIMITED TO, COST OF 
* REMOVAL OR REINSTALLATION, COMPUTER TIME, LABOR COSTS, LOSS 
* OF GOODWILL, LOSS OF PROFITS, LOSS OF SAVINGS, OR LOSS OF 
* USE OR INTERRUPTION OF BUSINESS. IN NO EVENT WILL TI'S 
* AGGREGATE LIABILITY UNDER THIS AGREEMENT OR ARISING OUT OF 
* YOUR USE OF THE PROGRAM EXCEED FIVE HUNDRED DOLLARS 
* (U.S.$500).
*
* Unless otherwise stated, the Program written and copyrighted 
* by Texas Instruments is distributed as "freeware".  You may, 
* only under TI's copyright in the Program, use and modify the 
* Program without any charge or restriction.  You may 
* distribute to third parties, provided that you transfer a 
* copy of this license to the third party and the third party 
* agrees to these terms by its first use of the Program. You 
* must reproduce the copyright notice and any other legend of 
* ownership on each copy or partial copy, of the Program.
*
* You acknowledge and agree that the Program contains 
* copyrighted material, trade secrets and other TI proprietary 
* information and is protected by copyright laws, 
* international copyright treaties, and trade secret laws, as 
* well as other intellectual property laws.  To protect TI's 
* rights in the Program, you agree not to decompile, reverse 
* engineer, disassemble or otherwise translate any object code 
* versions of the Program to a human-readable form.  You agree 
* that in no event will you alter, remove or destroy any 
* copyright notice included in the Program.  TI reserves all 
* rights not specifically granted under this license. Except 
* as specifically provided herein, nothing in this agreement 
* shall be construed as conferring by implication, estoppel, 
* or otherwise, upon you, any license or other right under any 
* TI patents, copyrights or trade secrets.
*
* You may not use the Program in non-TI devices.
* ********************************************************* */

#ifndef SDCARD_H
#define SDCARD_H

#include "../DriversConfig.h"
#include "../devices/msp430/NickTianSPI/common.h"
#include "../devices/msp430/NickTianSPI/error_codes.h"
#include "../devices/msp430/NickTianSPI/crc.h"

// TODO REMOVE
#include <stdio.h>

// definitions
#define SDCARD_UNINITIALIZED 1
#define SDCARD_INITIALIZED 0
#define SDCARD_BLOCK_SIZE 512

// SD Card response sizes (in bytes)
#define R1				1
#define R2				2
#define R3				5
#define R7				5
#define MAX_R			5

// Meaning of R1
#define R1_ERR			0x7F	// R1 indicates an error if any bit is set
#define R1_IDLE			BIT0	// R1: card is initializing
#define R1_ERASE		BIT1	// R1: erase sequence reset
#define R1_ILLEGAL		BIT2	// R1: illegal command
#define R1_CRC			BIT3	// R1: comm CRC error
#define R1_ER_SEQ		BIT4	// R1: error in erase sequence
#define R1_ADD			BIT5	// R1: address error
#define R1_PARAM		BIT6	// R1: paramater error

// SD Card command set
#define CMD_LENGTH    	5
#define CMD0			0		// GO_IDLE_STATE
#define CMD0_R			R1
#define CMD1            1
#define CMD1_R          R1
#define CMD2            2
#define CMD2_R          R2
#define CMD8			8		// SEND_IF_COND
#define CMD8_R			R7
#define CMD9			9		// SEND_IF_COND
#define CMD9_R			R1
#define CMD13			13		// SEND_STATUS
#define CMD13_R			R2
#define CMD16			16		// SET_BLOCKLEN
#define CMD16_R			R1
#define CMD17			17		// READ_SINGLE_BLOCK
#define CMD17_R			R1
#define CMD18           18
#define CMD18_R         R1
#define CMD24			24		// WRITE_BLOCK
#define CMD24_R			R1
#define CMD55			55		// APP_CMD
#define CMD55_R			R1
#define CMD58			58		// READ_OCR
#define CMD58_R			R3
#define CMD59			59		// CRC_ON_OFF
#define CMD59_R			R1
#define ACMD41			41		// SD_SEND_OP_COND
#define ACMD41_R		R1

// SD Card CRC Polynomials
#define CRC7_POLY		0x09	// The polynomial used for the CRC7
#define CRC16_POLY		0x1021	// The polynomial used for the CRC16

#define CMD_BITS		0x40	// Used to set the proper bit in a command for tx
#define CMD_MASK		0x3F	// Used to make sure commands are only 6 bits long

#define TOK_START		0xFE	// Data start token
#define TOK_ERR_MASK	0xF0	// Used to find an error token
#define TOK_ERR_ECC		0x04	// Bit indicating an ECC error in the card
#define TOK_ERR_RANGE	0x08	// Bit indicating out of valid range

#define SD_BLOCK_POW	0x09	// 2^9 bytes per physical block
#define SD_CHECK		0xAA	// Use the recommended check pattern of 10101010b
#define SD_VS			0x01	// Voltage supply of 2.7v-3.3v

#define SD_V1			1		// Indicates the SD card is version 1.x
#define SD_V2			2		// Indicates the SD card is version 2.x

#define ON_SD			BIT5	// -ON_SD pin

#define SD_TIMEOUT		TIMEOUT

#define SD_MAX_RESP_LENGTH      5

// struct //////////////////////////////////

typedef struct
{
	SPI_Device		SPI;
	DigitalInput*	cardPresence;
	unsigned long	cardSize;
	unsigned char	status;
	
	Byte			RX_blockBuffer[SDCARD_BLOCK_SIZE];
	Byte			TX_blockBuffer[SDCARD_BLOCK_SIZE];
	
}
SDCard;

// extended functionality
void sdCard_sendCommand(Byte cmd, long args, UI8 responseSize, SDCard* card);
void sdCard_initialize(SDCard* card);
void sdCard_read(long blockAddress, SDCard* card);
void sdCard_write(long blockAddress, SDCard* card);

#endif
