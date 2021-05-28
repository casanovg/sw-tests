/*
 * Tiny85_App_01.c
 *
 * Created: 12/05/2021 10:53:04
 *  Author: casanovg
 *
 * NOTE: Please make sure the ATtiny85 fuses are configured as shown below:
 *       Low:      0x62
 *       High:     0xD5
 *       Extended: 0xFE
 *
 * This test is to verify that the chip is set properly.
 * If so, a LED on PB1 should blink at (DELAY * 2) intervals.
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB1
#define LED_DDR DDRB
#define LED_PORT PORTB

#define DELAY 500				/* Delay in milliseconds*/

int main(void) {
    LED_DDR |= (1 << LED_PIN);			/* Set led control pin Data Direction Register for output */
    LED_PORT &= ~(1 << LED_PIN);		/* Turn led off */
    for(;;) {
		LED_PORT ^= (1 << LED_PIN);	/* Toggle PB1 */
		_delay_ms(DELAY);
    }
}
