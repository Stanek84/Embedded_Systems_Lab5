#include <msp430.h> 
#define RedLED BIT6 //defines red LED
#define GreenLED BIT0 //defines green LED
#define ToggleLeds (P1OUT ^= RedLED|GreenLED) //enable is switched between red and green
#define Button BIT3 //defines button

/**
 * main.c
 */
int main(void)
{
    BCSCTL2 |= DIVS_3; //divides clock frequency by 8 and chooses the SMCLK
    WDTCTL = WDT_MDLY_32; //divides clock frequency by 32465
    IE1 |= WDTIE;
    P1DIR = 0x41; //set I/O terminals, which in this case is red and green LED
    P1OUT = 0x40; //sets output as red LED
    _enable_interrupts(); //enables interrupt

    LPM1; //Low power mode
}

#pragma vector = WDT_VECTOR
__interrupt void WDT(void) //interrupt service routine
{
    P1OUT = ToggleLeds; //outputs in between LEDs as defined above
}
