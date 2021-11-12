#include "msp430G2553.h"
#define RedLED BIT6 //defines red LED
void main(void)
{
 WDTCTL = WDTPW + WDTHOLD;  // Stop WDT

 P1DIR |= BIT6;             // P1.6 to output
 TA0CTL = TASSEL_2 + MC_1 + ID_3;
     //TASSEL_2- chooses SMCLK
     //ID_3 - sets clock divider to 8
     //MC_1 - sets timer to up mode

 TA0CCR0 = 31250 - 1; //maximum amount timer counts up to
 TA0CCR1 = 6250; //sets duty cycle; Ton; when timer is on

 TA0CCTL0 |= CCIE; //capture/compare interrupt enabled
 TA0CCTL1 |= CCIE; //capture/compare interrupt enabled

 TA0CCTL0 &=~CCIFG; //Capture/compare interrupt flag CCIFG = 1 when interrupt pending
 TA0CCTL1 &=~CCIFG; //Capture/compare interrupt flag CCIFG = 1 when interrupt pending

 _enable_interrupts(); // Enter LPM0
}
#pragma vector = TIMER0_A0_VECTOR       //define the interrupt service vector
__interrupt void TA0_ISR (void)    // interrupt service routine
    {
    P1OUT |=BIT6; //enables red LED
    TA0CCTL0 &=~CCIFG; //resets interrupt
    }

#pragma vector = TIMER0_A1_VECTOR       //define the interrupt service vector
__interrupt void TA1_ISR (void)    // interrupt service routine
    {
    P1OUT &=~BIT6; //disables red LED
    TA0CCTL1 &=~CCIFG; //resets interrupt
    }
