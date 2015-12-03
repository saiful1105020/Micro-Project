/*
 * Row_Test.c
 *
 * Created: 11/30/2015 10:08:54 AM
 *  Author: Black_Knight
 */ 

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

void test2()
{
	PORTA = 0xFF;
	_delay_ms(2000);
	PORTB = 0xFF;
	_delay_ms(2000);
	PORTA = 0x34;
	_delay_ms(20);
}

void test1()
{
	PORTB = 0x00;
	PORTA = 0xFF;
	_delay_ms(20);
	PORTA = 0X00;
	PORTB = 0xFF;
	_delay_ms(20);
	
	/*
	PORTB = 0x00;
	PORTB = 0x34;
	_delay_ms(20);
	*/
}
void test3()
{
	int8_t i;
	int temp1 = 0b00001110;
	int temp2= 0b00001101;
	int temp3 = 0b00000000;
	int inc = 0b00010000;
	PORTA = 0x01;
	for(i=0;i<8;i++)
	{
		PORTD = temp1 | temp3;
		temp3 = temp3 + inc;
	}
	_delay_ms(10);
	temp3 = 0b00000000;
	for(i=0;i<8;i++)
	{
		PORTD = temp2 | temp3;
		temp3 = temp3 + inc;
	}
	_delay_ms(10);
	
	
	 
}

int main(void)
{
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	DDRA = 0XFF;
	DDRB = 0XFF;
	DDRD = 0xFF;
	
    while(1)
    {
        //TODO:: Please write your application code
		//decoder1 -> O7 should be low, O1-O7 high, Other decoder's outputs are high 
		//PORTA = 0b01010101;
		PORTD = 0b01111101;
		test1();
		_delay_ms(100);
		
		PORTD = 0b01101101;
		test1();
		
    }
}