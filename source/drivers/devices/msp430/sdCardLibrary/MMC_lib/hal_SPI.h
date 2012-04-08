// *************************************************************************************
//
// Filename:  hal_SPI.h: 
// Declarations for Communication with the MMC (see mmc.c) in unprotected SPI mode.
//
// Version 1.1
//    added ul declaration in macros mmcWriteSector and mmcReadSector
// *************************************************************************************

#ifndef _SPILIB_H
#define _SPILIB_H

#include "hal_hardware_board.h"

//----------------------------------------------------------------------------
//  These constants are used to identify the chosen SPI and UART
//  interfaces.
//----------------------------------------------------------------------------
#define SER_INTF_NULL    0
#define SER_INTF_USART0  1
#define SER_INTF_USART1  2
#define SER_INTF_USCIA0  3
#define SER_INTF_USCIA1  4
#define SER_INTF_USCIB0  5
#define SER_INTF_USCIB1  6
#define SER_INTF_USI     7
#define SER_INTF_BITBANG 8

#define halSPIRXBUF  UCB0RXBUF
#define halSPI_SEND(x) UCB0TXBUF=x
#define halSPITXREADY  (UC0IFG&UCB0TXIFG)     /* Wait for TX to be ready */
#define halSPITXDONE  (UCB0STAT&UCBUSY)       /* Wait for TX to finish   */
#define halSPIRXREADY (UC0IFG&UCB0RXIFG)      /* Wait for RX to be ready */
#define halSPIRXFG_CLR UC0IFG &= ~UCB0RXIFG
#define halSPI_PxIN  SPI_USART0_PxIN
#define halSPI_SOMI  SPI_USART0_SOMI

// Function Prototypes
void halSPISetup (void);
unsigned char spiSendByte(const unsigned char data);
unsigned char spiReadFrame(unsigned char* pBuffer, unsigned int size);
unsigned char spiSendFrame(unsigned char* pBuffer, unsigned int size);


#endif /* _SPILIB_H */

