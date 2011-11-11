/**
 * Example: Blink LED
 * Author:  Dario Schor
 * Date:    November 11, 2011
 */

#include  <msp430fg4619.h>
 
void main(void)
{
  unsigned int i;
 
  WDTCTL = WDTPW | WDTHOLD;                 // Stop WDT
  P5DIR |= BIT1;                            // P5.1 as output
  P1OUT |= BIT1;							// P5.1 set high

  while(1)
  {
    P5OUT ^= BIT1;							// Toggle P5.1
    for(i=50000;i>0;i--);                   // Delay
  }
}
