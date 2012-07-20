/**
 * Example: Blink LED
 * Author:  Dario Schor
 * Date:    November 11, 2011
 */

#include  <msp430fg4619.h>
#include <stdio.h>
 
void main(void)
{
  unsigned long i;
 
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
  P5DIR |= BIT1;                            // P5.1 as output
  

 
  
  
  	printf("hello\n");                      // Print statement
  	fflush(stdout);                         // Flush buffer
    
    for(;;){
  
    for(i=0; i < 30; i++){                   // Delay
      P5OUT |= BIT1;
      printf("set\n");
    }
    
 
    for(i=0; i < 30; i++){                   // Delay
       P5OUT &= ~BIT1;                          // Toggle P5.1
      printf("rst\n");
    }}
}
