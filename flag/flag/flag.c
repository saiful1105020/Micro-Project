/*
 * test_1.c
 *
 * Created: 11/26/2015 7:31:40 PM
 *  Author: Black_Knight
 */ 


#include <avr/io.h>
#define F_CPU 1000000
#include <util/delay.h>

int8_t red[]={
	0x00, 0x00, 0x18 , 0x18, 0x18 , 0x18 , 0x00, 0x00
};

int8_t green[]={
	0x3C , 0x3C , 0x24 , 0x24 , 0x24 , 0x24 , 0x3c , 0x3c
};

int main(void)
{
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	
    while(1)
    {
		int8_t i;
		
		for(i=0;i<8;i++)
		{
			int8_t temp = ~(1<<i);
			
			PORTB = temp;
			PORTD = 0xFF;
			PORTA = green[i];
			
			PORTD = temp;
			PORTB = 0xFF;
			PORTA = red[i];
			
			_delay_ms(1);
		}
		
		_delay_ms(1000);
		
		PORTB=0x00;
		PORTD=0xFF;
		PORTA=0xFF;
		
		_delay_ms(1000);
    }
}