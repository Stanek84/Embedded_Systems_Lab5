# Embedded_Systems_Lab5

This project contains three seperate code files,
with each file responding to a different question.

Question 1 Code
Lab5Q1main.c
For the first question of the lab, the red and green LEDs had to be toggled between each other. The interval for the toggling needed to be 256 milliseconds, so the timer needed to 
be configured to this condition. To find the frequency needed for 256 milliseconds of delay between toggles, the equation used was f = 1 / T. This would result in f = 1 / (256 * 
10^(-3)) = 3.9 hertz. The goal here is to have the frequency of the clock be the same as 3.9 hertz. If the SMCLK is used, the frequency would be equal to 1 * 10^6. Next, I used 
BSCSTL2 = DIVS_3, which means that the SMCLK frequency would be divided by 8, resulting in f = 125,000. Finally, I used WDTCTL = WDT_MDLY_32 so that the new frequency would be 
divided by 32768. The frequency at this point is equal to 3.81 hertz, which is approximately equal to 3.9 hertz.

Question 2 Code
Lab5Q2main.c
For the second part of the lab, we had to create a software pulse width modulation for an LED. The duty cycle for this PWM should be 10 percent and the period should be 500 
milliseconds. To configure the PWM for the 500 milliseconds, a somewhat different process that was used in the last part of the lab was used. The registers for TACCR0 and TACCR1 
need to be solved for in this case. The equation for TACCR0 is (f * T)/D -1, where f is the frequency of the clock that is being used, T is the period of the PWM, and D is the 
divider, which is chosen when the PWM is configured. In this case, TACCR0 would equal ((1 * 10^6 * 500 * 10^-3)/8) - 1) = 62500 - 1. D is set equal to 8 since TACTL has ID_3 in it 
and this is where the frequency divider is set. The frequency was also decided in TACTL with TASSEL_2, which decided that the SMCLK would be used. For the duty cycle to be 10%, 
TACCR1 has to be 10% of TACCR0, so 62500/10= 6250-1. Finally, TACCTL1 was set to OUTMOD_7 so that the system depends on TACCR0.

Question 3 Code
Lab5Q3main.c
For the final part of this lab, a LED’s brightness was controlled with a period 250 ms and a duty cycle of 20%. This question is different from the previous one, not only because 
of the values. This time an interrupt was used to toggle the LED. While the code was different, questions 2 and three of the lab were asking for the same thing, just with 
different values, so all the calculations done in part 2 are still valid.
