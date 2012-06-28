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
#include "main.h"
#include "UART.h"


  
/**
* @brief Function Name:     InitUART.                                                 
* @brief  Description: This function initialized the USCI-UART.
* @param none                                                   
* @return none                                                    
*/     
void InitUART(void){ 

  USAxCTL |=UCSWRST;	           /* USART Software Reset; stops USART state machine */
  
  
  UART_PxDIR &= ~UART_RX_PAD;               // Configure Px.X as input
  UART_PxDIR |= UART_TX_PAD;                // Configure Px.X as output
  UART_PxSEL |= (UART_TX_PAD|UART_RX_PAD); // Px.x & Px.X = USCI_Ax TXD & RXD
  
  USAxCTL |=0x20;                           // No parity 	          
  USAxTXCTL|=0x00;
  USAxRXCTL|=0x0D;
  USAxBR0=3;                       
  USAxBR1=0;			
  	  
  
  UCAxMCTL =  (UCBRF_0|UCBRS_6);  // Modulation UCBRSx = 6
  
  UCAxIFG &= ~UCAxRXIFG;          //Clear RX IFG
  USAxCTL =0x30;             // **Initialize USART state machine**
                             // No parity, Two stops bits,8 bits data, Idle line//                                  
             
   USAxIE|= USAxTXIE+ USAxRXIE;          // Enable USART Transmit and Receive interrupt enable   
  
/* **************End of INITIALIZATION OF THE UART*****************************/

}  

/* StopUARTRx.: This function disables the USCI-UART interrupts in order
 *  to not acknowledge byte sent by the TX.*/
void StopUARTRx(void){

  USAxIE &= ~USAxRXIE;             // Disable USART RX interrupt 
  
}
/*************End of StopUARTx*************/

/* StartUARTRx.: This function enables the USCI-UART interrupts in order 
                 to be ready to receive USBID messages.*/
void StartUARTRx(void){
  
  USAxIFG &= ~USAxRXIFG;           // Clear RX IFG
  USAxIE |= USAxRXIE;              // Enable USART RX interrupt
}
