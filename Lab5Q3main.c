#include "msp430G2553.h"
#define RedLED BIT6
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

 P1DIR |= BIT6;             // P1.6 to output
 TA0CTL = TASSEL_2 + MC_1 + ID_3;

 TA0CCR0 = 31250 - 1;
 TA0CCR1 = 6250;

 TA0CCTL0 |= CCIE;
 TA0CCTL1 |= CCIE;

 TA0CCTL0 &=~CCIFG;
 TA0CCTL1 &=~CCIFG;

 _enable_interrupts(); // Enter LPM0
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6;
    TA0CCTL0 &=~CCIFG;
    }

#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6;
    TA0CCTL1 &=~CCIFG;
    }
