/*
 * test_1.c
 *
 * Created: 11/26/2015 7:31:40 PM
 *  Author: Black_Knight
 */ 


#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	
    while(1)
    {
        PORTB = 0xFF;
		PORTC = 0x7F;
		PORTA = 0x80;
		
		_delay_ms(1000);
    }
}