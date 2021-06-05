/*
 * main.c
 *
 * Created: 5/22/2021 4:46:58 PM
 *  Author: gcasanova
 */ 

#define F_CPU 1000000UL

#include <xc.h>
#include <stdint.h>
#include <util/delay.h>

int main(void) {
	
	//DDRB |= (1 << PB1);
	//PORTB |= (1 << PB1);
	
	DDRB = 0xFF;
	PORTB = 0xFF;
		
    for(;;) {
        //TODO:: Please write your application code
		for (uint8_t i = 0; i < 8; i++) {
			PORTB &= ~(1 << i);
			_delay_ms(63);
		}
		for (uint8_t i = 0; i < 8; i++) {
			PORTB |= (1 << i);
			_delay_ms(63);
		}
		//_delay_ms(2000);
		for (uint8_t i = 8; i > 0; i--) {
			PORTB &= ~(1 << (i - 1));
			_delay_ms(63);
		}
		for (uint8_t i = 8; i > 0; i--) {
			PORTB |= (1 << (i - 1));
			_delay_ms(63);
		}
			
    }
	
}