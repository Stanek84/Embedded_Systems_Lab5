#include <msp430.h> 
#define RedLED BIT6
#define Button BIT3

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x40;
	P1OUT |= 0x00;
	P1SEL |= 0x40;

	TACCR0 = 62500 - 1;
	TACCR1 = 6250 - 1;
	TACTL = TASSEL_2 + ID_3 + MC_1;
	TACCTL1 = OUTMOD_7;
	
	while(1){
	    P1OUT ^= BIT6;
	}
}
