/*
 * main.c
 *
 * Created: 25/05/2021 22:05:41
 *  Author: casanovg
 */ 

#define F_CPU 1000000UL

#include <xc.h>
#include <util/delay.h>

#define LED_PIN PB1
#define LED_DDR DDRB
#define LED_PORT PORTB



int main(void) {
	
    for (;;) {
        //TODO:: Please write your application code 
		LED_DDR |= (1 << LED_PIN);		/* Set led control pin Data Direction Register for output */
		LED_PORT &= ~(1 << LED_PIN);	/* Turn led off */
		for(;;) {
		    LED_PORT ^= (1 << LED_PIN); /* Toggle PB1 */
			_delay_ms(250);
		}
		
    }
}

//#include <avr/io.h>
