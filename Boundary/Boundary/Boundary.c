/*
 * Boundary.c
 *
 * Created: 11/30/2015 9:18:11 PM
 *  Author: Black_Knight
 */ 

#define  F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

int8_t col_R[] = {
	0b01111110 , 0b01101110 , 0b01011110 , 0b01001110 , 0b00111110 , 0b00101110 , 0b00011110 , 0b00001110,
	0b01111101 , 0b01101101 , 0b01011101 , 0b01001101 , 0b00111101 , 0b00101101 , 0b00011101 , 0b00001101
};

int8_t boundary_port_a[] = {
	0xFF,0x84,0x84,0x84,0x84,0xFF,0x84,0x84,0x84,0x84,0xFF,0x84,0x84,0x84,0x84,0xFF
};

int8_t boundary_port_b[] = {
	0xFF,0x21,0x21,0x21,0x21,0xFF,0x21,0x21,0x21,0x21,0xFF,0x21,0x21,0x21,0x21,0xFF
};

void draw_boundary()
{
	int8_t i;
	for(i=0;i<16;i++)
	{
		PORTD = col_R[i];
		
		PORTB = 0x00;
		PORTA = boundary_port_a[i];
		_delay_ms(0.5);
		
		PORTA = 0x00;
		PORTB = boundary_port_b[i];
		_delay_ms(0.5);
	}
}

void draw_p1_pattern(int8_t x,int8_t y)
{
	int8_t temp_col[4];
	
	int8_t i;
	
	if(x==1 && y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==1 && y==2)
	{
		
temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x01,0x01,0x00
		};
		
		int8_t port_b_temp_pattern[]={
			0x00,0x80,0x80,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
	else if(x==1 && y==3)
	{
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
	
	
	else if(x==2 && y==1)
	{
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==2 && y==2)
	{
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x01,0x01,0x00
		};
		
		int8_t port_b_temp_pattern[]={
			0x00,0x80,0x80,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
	else if(x==2 && y==3)
	{
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
	
	
	else if(x==3 && y==1)
	{
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==3 && y==2)
	{
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x01,0x01,0x00
		};
		
		int8_t port_b_temp_pattern[]={
			0x00,0x80,0x80,0x00
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
	else if(x==3 && y==3)
	{
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
			
		}
	}
}

void draw_p2_pattern(int8_t x,int8_t y)
{
	int8_t temp_col[4];
	
	int8_t i;
	
	if(x==1 && y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x30,0x48,0x48,0x30
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
}

int main(void)
{
	
	MCUCSR = (1<<JTD);
	MCUCSR = (1<<JTD);
	
	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0xFF;
	
    while(1)
    {
        //TODO:: Please write your application code
		draw_boundary();
		/*
		draw_p1_pattern(1,1);
		draw_p1_pattern(1,2);
		draw_p1_pattern(1,3);
		draw_p1_pattern(2,1);
		draw_p1_pattern(2,2);
		draw_p1_pattern(2,3);
		*/
		int8_t test_loop_i;
		
		for(test_loop_i=1;test_loop_i<=3;test_loop_i++)
		{
			int8_t test_loop_j;
			for(test_loop_j=1;test_loop_j<=3;test_loop_j++)
			{
				if(test_loop_i==1 && test_loop_j==1)
					draw_p2_pattern(1,1);
				else
					draw_p1_pattern(test_loop_i,test_loop_j);
			}
		}
			
    }
}