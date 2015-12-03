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
	DDRD = 0xFF;
	
    while(1)
    {
		/*
		PORTD = 0x00;
		PORTB = 0xFF;
		PORTA = 0xFF;
		*/
		
		int8_t i;
		
		//int8_t outer;
		/*
		for(outer=0;outer<2000;outer++)
		{
			
			for(i=0;i<8;i++)
			{
				int8_t temp = ~(1<<i);
				
				PORTB = temp;
				PORTD = 0xFF;
				PORTA = 0xFF;
				
				_delay_ms(1);
			}
		}
		
		
		_delay_ms(1000);
		*/
		//for(outer=0;outer<2000;outer++)
		//{
			
			for(i=0;i<8;i++)
			{
				int8_t temp = ~(1<<i);
				
				PORTD = temp;
				PORTB = 0xFF;
				PORTA = 0xFF;
				
				_delay_ms(1);
			}
		//}
		
		//_delay_ms(1000);
		
    }
}