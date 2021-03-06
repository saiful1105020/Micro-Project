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
		int8_t row = 0b01111111;
		int8_t i;
		
		for(i=0;i<8;i++)
		{
			int8_t temp = row>>(i);
			
			PORTB = 0xFF;
			PORTC = temp;
			PORTA = 0xFF;
			
			_delay_ms(1000);
			
			PORTC = 0xFF;
			PORTB = temp;
			PORTA = 0xFF;
			
			_delay_ms(1000);
			
		}
    }
}