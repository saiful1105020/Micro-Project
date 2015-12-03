/*
 * Decoder_Test.c
 *
 * Created: 11/29/2015 9:07:19 PM
 *  Author: Black_Knight
 */ 

#define F_CPU 1000000

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	DDRA = 0xFF;
	DDRB = 0xFF;
	/**
	*PORTD = X(I2-)(I1-)(I0-) (DECODER4-)(DECODER3-)(DECODER2-)(DECODER1-)
	*/
	
	int8_t decoder[4] = {0b00001110,0b00001101,0b00001011,0b00000111};
	int8_t dec_input[8]={0b00000000,0b00010000,0b00100000,0b00110000,0b01000000,0b01010000,0b01100000,0b01110000};
    
	/*
		FIRST 16 FOR COLOR RED, NEXT 16 FOR COLOR YELLOW
	*/
	
	int8_t upper_pattern[32]={0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x84,0x84,0x84,0x84,0x00,0x84,0x84,0x84,0x84,0x00,0x84,0x84,0x84,0x84,0x00};
	int8_t lower_pattern[32]={0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x21,0x21,0x21,0x21,0x00,0x21,0x21,0x21,0x21,0x00,0x21,0x21,0x21,0x21,0x00};
	
	while(1)
    {
		//decoder1 -> O0 should be low, O1-O7 high, Other decoder's outputs are high
		//PORTD = 0b00001011;
		
		int8_t i,j;
		
		/*
			FIRST 2 FOR COLOR RED, SECOND 2 FOR COLOR YELLOW
		*/
		
		for(i=0;i<4;i++)
		{
			int8_t dec = decoder[i];
			
			for(j=0;j<8;j++)
			{
				int8_t col = dec_input[j];
				int8_t temp = dec || col;
				
				PORTD = temp;
				PORTA = upper_pattern[8*i+j];
				PORTB = lower_pattern[8*i+j];
				
				_delay_ms(1);
			}
		}
		
    }
}