//******************************************************************************
//  File test_vavle.c
//
//  Description: This  file will will light an LED when a valve has been openned. 
//                 the vavle is NC (normally closed)
// version1.0  
//Author: Mohamed Temam Nasri
//		  26/057/2012
//******************************************************************************* 	


#include <msp430fg4619.h> 

  #include "Test_valve.h"
#include <stdio.h>



void testvalve(void){ 

	P4SEL=0x00;        // set as I/O
	P4DIR=0x01;       //  set as input 
	
	P6SEL=0x00;
	P6SEL=0xFF;        // set as Output
	
	
	while (P4IN&BIT0){P6OUT=0x00;}
	
  
                                             }
   
   

    
/* **************End of INITIALIZATION OF THE UART*****************************/


  


