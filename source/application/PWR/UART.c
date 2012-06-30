//******************************************************************************
//  File UART.c
//
//  Description: This  file provides all the required functions to send
//               and receive data using UART module
// version1.0  
//Author: Mohamed Temam Nasri
//		  31/05/2012
//******************************************************************************* 	


#include "msp430.h"
//#include "../main.h"
#include "UART.h"

#include <stdio.h>

#include "UART.h"
#include "TI_USCI_UART_Regs.h"
  
/**
* @brief Function Name:     InitUART.                                                 
* @brief  Description: This function initialized the USCI-UART.
* @param none                                                   
* @return none                                                    
*/    
    #define USAxCTL		     U1CTL	    /* USART Control Register  */	
    #define USAxBR0     	 U1BR0			/* USART Baud Rate 0 */
    #define USAxBR1     	 U1BR1			/* USART Baud Rate 1 */
    #define USAxRXCTL   	 U1RCTL 		/* USART Receive Control  Register */
    #define USAxTXCTL   	 U1TCTL   		/* USART Transmit Control Register */
    #define USAxRXBUF        U1RXBUF        /* USART Receive Register Buffer*/
    #define USAxTXBUF        U1TXBUF        /* USART Transmit Register Buffer*/
    #define USAxIE 		     IE2      		/* USART Interrupt Enable Register */
    #define USAxIFG		     IFG2      		/* USART Interrupt Flags Register */                        
    #define USAxME           ME2            /* USART Module Enable */
    #define USAxMCTL         U1MCTL          // Modulation control register
 
    #define USAxRXIE         BIT6
    #define USAxTXIE         BIT7
    #define USAxRXIFG        BIT6
    #define USAxTXIFG        BIT7


void InitUART(void){ 


	printf("test2\n");

 USAxCTL |=UCSWRST;	           /* USART Software Reset; stops USART state machine */
  
  UART_PxSEL |=BIT0+BIT1; 
  USAxME|=BIT5+BIT4;                       // Enable Transmit and  Receive module 
  UART_PxDIR &= ~UART_RX_PAD;               // Configure Px.X as input
  UART_PxDIR |= UART_TX_PAD;                // Configure Px.X as output

  
  USAxCTL |=CHAR;                           // No parity, 8 bits data ,1 stop bit	          
  USAxTXCTL|=SSEL1;                         // UCLK = ACLK 
  USAxBR0=3;                       
  USAxBR1=0;			
  	  
  USAxMCTL = 0x4a;                         // Modulation
  
	printf("test1\n");
  

  USAxCTL &= ~UCSWRST;                       // **Initialize USART state machine**
                                             // No parity, Two stops bits,8 bits data, Idle line//                                  
  
  USAxIE|=BIT5+BIT4;                         //Enable USART Transmit and Receive interrupts
  
    while (!(USAxIFG & UTXIFG1));   // check this condition     
    USAxTXBUF=0xAA;                 // should transmit AA
    while (!(USAxIFG & UTXIFG1));   // check if the module is ready to send data     
    USAxTXBUF=0x11;                 // should transmit 11
}
/* **************End of INITIALIZATION OF THE UART*****************************/


