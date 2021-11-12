#include <msp430.h> 
#define RedLED BIT6 //defines red LED
#define Button BIT3 //defines green LED

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P1DIR |= 0x40; //defines I/O pins
	P1OUT |= 0x00; //sets pin 1.0 as the output
	P1SEL |= 0x40; //sets red LED to toggle

	TACCR0 = 62500 - 1; //maximum amount timer counts up to
	TACCR1 = 6250 - 1; //sets duty cycle; Ton; when timer is on
	TACTL = TASSEL_2 + ID_3 + MC_1;
	//TASSEL_2- chooses SMCLK
	//ID_3 - sets clock divider to 8
	//MC_1 - sets timer to up mode
	TACCTL1 = OUTMOD_7; //output reset when TACCR0 is reached
	
	while(1){
	    P1OUT ^= BIT6; //sets red LED to toggle
	}
}
