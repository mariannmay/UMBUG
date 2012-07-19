//******************************************************************************
//  File UART.c
//
//  Description: This  file provides all the required functions to send
//               and receive data using UART module
// version1.0  
//Author: Mohamed Temam Nasri
//		  31/05/2012
//******************************************************************************* 	


#include <msp430fg4619.h> 
//#include "main.h"
#include "UART.h"
#include <stdio.h>
#define USAxCTL		         U1CTL		/* USART Control Register  */	
    #define USAxBR0     	 U1BR0			/* USART Baud Rate 0 */
    #define USAxBR1     	 U1BR1			/* USART Baud Rate 1 */
    #define USAxMCTL   	     U1MCTL		    /* USART modulation control register*/
    #define USAxRXCTL   	 U1RCTL 		/* USART Receive Control  Register */
    #define USAxTXCTL   	 U1TCTL   		/* USART Transmit Control Register */
    #define USAxRXBUF        U1RXBUF        /* USART Receive Register Buffer*/
    #define USAxTXBUF        U1TXBUF       /* USART Transmit Register Buffer*/
    #define USAxIE 		     IE2       		/* USART Interrupt Enable Register */
    #define USAxIFG		     IFG2      		/* USART Interrupt Flags Register */                        
    #define USAxME           ME2            /* USART Module Enable */
    #define USAxMCTL         U1MCTL          // Modulation control register
  
    #define USAxRXIE         BIT4
    #define USAxTXIE         BIT5
    #define USAxRXIFG        BIT4
    #define USAxTXIFG        BIT5
  
/**
* @brief Function Name:     InitUART.                                                 
* @brief  Description: This function initialized the USCI-UART.
* @param none                                                   
* @return none                                                    
*/     


void InitUART(void){ 

	
 // printf("start of UART initization");
  volatile unsigned int i;

  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  FLL_CTL0 |= XCAP14PF;                     // Configure load caps

  
  P4SEL |= 0x03;                            // P4.1,0 = USART1 TXD/RXD
  ME2 |= UTXE1 + URXE1;                     // Enable USART1 TXD/RXD
  U1CTL |= CHAR;                            // 8-bit character
  U1TCTL |= SSEL1;                          // UCLK = ACLK
  U1BR0 = 0x41;                             // 32k/9600 - 3.41
  U1BR1 = 0x03;                             //
  U1MCTL = 0x09;                            // Modulation
  U1CTL &= ~SWRST;                          // Initialize USART state machine
  IE2 |= URXIE1;                            // Enable USART1 RX interrupt

 for (;;){
  while (!(IFG2 & UTXIFG1));                // USART1 TX buffer ready?

  
 IFG2&=~UTXIFG1;
  TXBUF1 = 0x54;}                          // RXBUF1 to TXBUF1

                                             }
   
   

    
/* **************End of INITIALIZATION OF THE UART*****************************/


  


