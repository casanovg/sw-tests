/*
 * Tiny85-App-02.c
 *
 * Created: 28/05/2021 20:25:55
 * Author : casanovg
 *
 * NOTE: Please make sure the ATtiny85 fuses are configured as shown below:
 *       Low:      0x62
 *       High:     0xD5
 *       Extended: 0xFE
 *
 * This test is to verify that the chip is configured correctly and that the
 * Prescaler setting works. If so, a LED on PB1 should blink TIMES_SLOW times,
 * at (DELAY * 2) milliseconds intervals. Then the chip will speed up to
 * around 16 MHz and PB1 will flash TIMES_FAST times. After that, the chip
 * will be restored to the original settings and will continue to flash.
 */ 

#define F_CPU 1000000UL

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB1
#define LED_DDR DDRB
#define LED_PORT PORTB

#define DELAY 500				/* Delay in milliseconds*/
#define TIMES_SLOW 5            /* Times to blink slowly*/
#define TIMES_FAST 50           /* Times to blink fast */

#define OSC_FAST 0x4C           /* Oscillator offset */

// Prototypes
void SpeedUp(uint8_t offset);
void SlowDown(uint8_t initial_osccal);

// Main loop
int main(void) {

    LED_DDR |= (1 << LED_PIN);			/* Set led control pin Data Direction Register for output */
    LED_PORT &= ~(1 << LED_PIN);		/* Turn led off */

    uint8_t initial_osccal = OSCCAL;    /* Preserve user oscillator settings */
    
    // Slow
    for (uint8_t i = 0; i < TIMES_SLOW * 2; i++) {
		LED_PORT ^= (1 << LED_PIN);	/* Toggle PB1 */
		_delay_ms(DELAY);
    }

    // Speed up
    _delay_ms(DELAY);
    SpeedUp(OSC_FAST);

    // Fast
    for (uint8_t i = 0; i < TIMES_FAST * 2; i++) {
        LED_PORT ^= (1 << LED_PIN);	/* Toggle PB1 */
        _delay_ms(DELAY);
    }

    // Slow down
    _delay_ms(DELAY);
    SlowDown(initial_osccal);

    // Slow
    for (;;) {
        LED_PORT ^= (1 << LED_PIN);	/* Toggle PB1 */
        _delay_ms(DELAY);
    }
    
}

// Speed up the chip
void SpeedUp(uint8_t offset) {
    OSCCAL += offset;       // Oscillator speed up calibration
    CLKPR = (1 << CLKPCE);  // Prescaler enable
    CLKPR = 0x00;           // Clock division factor 1 (0000)
}

// Restore prescaler
void SlowDown(uint8_t initial_osccal) {
    OSCCAL = initial_osccal;                  // Oscillator slow down calibration
    CLKPR = (1 << CLKPCE);                    // Prescaler enable
    CLKPR = ((1 << CLKPS1) | (1 << CLKPS0));  // Clock division factor 8 (0011)
}
