/*
 * Boundary.c
 *
 * Created: 11/30/2015 9:18:11 PM
 *  Author: Black_Knight
 */ 

#define  F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>
#include<stdlib.h>

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

/************************************************************************/
/*	position[i][j]:
	-1 : Free
	1  : Player 1
	2  : Player 2 
*/
/************************************************************************/
int8_t position[4][4];

int8_t current_player;
int8_t current_x;
int8_t current_y;

void init_control()
{
	int8_t i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			position[i][j]=-1;
		}
	}
	
	current_player = 1;
	current_x = 2;
	current_y = 2;
}

/************************************************************************/
/* 1. Change current_player
   2. Assign a free current_position (current_x and current_y)                                                                  */
/************************************************************************/
void change_control()
{
	position[current_x][current_y]=current_player;
	
	if(current_player==1)
	{
		current_player = 2;
	}
	else
	{
		current_player = 1;
	}
	
	int8_t i,j;
	
	int8_t isFree = 0;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(position[i][j]==-1)
			{
				current_x = i;
				current_y = j;
				
				isFree = 1;
				break;
			}
		}
		
		if(isFree==1)
		{
			break;
		}
	}
}

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
	else if(x==2 && y==1)
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
	else if(x==3 && y==1)
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
	
	
	else if(x==1 && y==2)
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
	else if(x==3 && y==2)
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
	
	
	else if(x==1 && y==3)
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
	else if(x==2 && y==3)
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
			0x08,0x10,0x20,0x40
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
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x08,0x10,0x20,0x40
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==1 && y==3)
	{
		
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x08,0x10,0x20,0x40
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTB = 0x00;
			PORTA = port_a_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==2 && y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
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
	
	else if(x==2 && y==2)
	{
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
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
		
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
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
	
	else if(x==3 && y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_b_temp_pattern[]={
			0x02,0x04,0x08,0x10
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
			PORTA = 0x00;
			PORTB = port_b_temp_pattern[i];
			_delay_ms(0.25);
		}
	}
	else if(x==3 && y==2)
	{
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_b_temp_pattern[]={
			0x02,0x04,0x08,0x10
		};
		
		for(i=0;i<4;i++)
		{
			PORTD = temp_col[i];
			
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
			0x02,0x04,0x08,0x10
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

void draw_occupied_positions()
{
	int8_t i,j;
	
	/************************************************************************/
	/* TEST BLOCK                                                           */
	/************************************************************************/
	
	position[1][2]=1;
	position[2][3]=1;
	position[3][2]=2;
	position[3][1]=2;
	
	/************************************************************************/
	/* END OF TEST BLOCK                                                                     */
	/************************************************************************/
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(position[i][j]==-1)
			{
				//Do Nothing
			}
			else if(position[i][j]==1)
			{
				draw_p1_pattern(i,j);
			}
			else
			{
				draw_p2_pattern(i,j);
			}
		}
	}
}

void draw_blinking_pattern()
{
	int8_t temp_col[4];
	
	int8_t i;
	
	if(current_player==1 && current_x==1 && current_y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==1 && current_y==2)
	{
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==1 && current_y==3)
	{
		
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x30,0x30,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==2 && current_y==1)
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
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==2 && current_y==2)
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
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==2 && current_y==3)
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
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==3 && current_y==1)
	{
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==3 && current_y==2)
	{
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==1 && current_x==3 && current_y==3)
	{
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_b_temp_pattern[]={
			0x00,0x0C,0x0C,0x00
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	//PLAYER 2
	
	if(current_player==2 && current_x==1 && current_y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x08,0x10,0x20,0x40
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==1 && current_y==2)
	{
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x08,0x10,0x20,0x40
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==1 && current_y==3)
	{
		
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x08,0x10,0x20,0x40
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = port_a_temp_pattern[i];
					_delay_ms(0.20);
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==2 && current_y==1)
	{
		
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==2 && current_y==2)
	{
		
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==2 && current_y==3)
	{
		
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_a_temp_pattern[]={
			0x00,0x00,0x01,0x02
		};
		
		int8_t port_b_temp_pattern[]={
			0x40,0x80,0x00,0x00
		};
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
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
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==3 && current_y==1)
	{
		temp_col[0]=col_R[1];
		temp_col[1]=col_R[2];
		temp_col[2]=col_R[3];
		temp_col[3]=col_R[4];
		
		int8_t port_b_temp_pattern[]={
			0x02,0x04,0x08,0x10
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==3 && current_y==2)
	{
		temp_col[0]=col_R[6];
		temp_col[1]=col_R[7];
		temp_col[2]=col_R[8];
		temp_col[3]=col_R[9];
		
		int8_t port_b_temp_pattern[]={
			0x02,0x04,0x08,0x10
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
		}
	}
	
	else if(current_player==2 && current_x==3 && current_y==3)
	{
		temp_col[0]=col_R[11];
		temp_col[1]=col_R[12];
		temp_col[2]=col_R[13];
		temp_col[3]=col_R[14];
		
		int8_t port_b_temp_pattern[]={
			0x02,0x04,0x08,0x10
		};
		
		
		
		int8_t loop;
		for(loop=0;loop<10;loop++)
		{
			if(loop%2==0)
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTA = 0x00;
					PORTB = port_b_temp_pattern[i];
					_delay_ms(0.25);
					
				}
			}
			else
			{
				for(i=0;i<4;i++)
				{
					PORTD = temp_col[i];
					
					PORTB = 0x00;
					PORTA = 0x00;
					
					_delay_ms(0.20);
				}
				
				draw_boundary();
				draw_occupied_positions();
				_delay_ms(1);
			}
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
	
	init_control();
	
	int8_t PC;
	
	int8_t left_button;
	
	//int8_t up_button,down_button,left_button,right_button,confirm_button;
	
	left_button = 0x01;
	//down_button = 0xFD;
	//up_button = 0xFB;
	//right_button = 0xF7;
	//confirm_button = 0xEF;
	/************************************************************************/
	/* TEST BLOCK                                                           */
	/************************************************************************/
	current_player=2;
	current_x=2;
	current_y=2;
	
	/************************************************************************/
	/* END OF TEST BLOCK                                                    */
	/************************************************************************/
	
    while(1)
    {
		
		//Check Win
		//if win, show animation
		//else
		PC = PORTC;
		if( (PC & left_button) != 0x00)
		{
			current_x=1;
			current_y=1;
		}
		/*
		else if((PC | up_button) == up_button)
		{
			current_x--;
			if(current_x<1) current_x=1;
		}
		else if((PC | down_button) == down_button)
		{
			current_x++;
		}
		else if((PC | right_button) == right_button)
		{
			current_y++;
		}
		else if((PC|confirm_button) == confirm_button)
		{
			//change control
		}
		*/
		draw_boundary();
		draw_occupied_positions();
		draw_blinking_pattern();	
    }
}