

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LCD.h"
#include "Seven Segment.h"
#include "keypad.h"
#include "std_macros.h"
#include "Timer.h"
#define NOTPRESSED 0xff

volatile unsigned char s_counter=0;
unsigned char m_counter=0, h_countere=0;
unsigned char value, f_digit, s_digit;

int main(void)
{
	keypad_Init();
	LCD_Init();
	seven_segment_Init('D');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_send_string("press 1 to set ");
	LCD_move_cursor(2,5);
	LCD_send_string("clock");
	Timer2_OVF_init_external();
    while(1)
    {	
        value= keypad_cheak_press();
		if (value!=NOTPRESSED)
		{
			if (value=='1')
			{
				// set hours
				LCD_clear_screen();
				LCD_send_string("Hours=");
				LCD_move_cursor(1,7);
				_delay_ms(500);
				
				do 
				{
					f_digit=keypad_cheak_press();
				} while (f_digit==NOTPRESSED);
				LCD_send_char(f_digit);
				_delay_ms(300);
				do
				{
					s_digit=keypad_cheak_press();
				} while (s_digit==NOTPRESSED);
				LCD_send_char(s_digit);
				_delay_ms(300);
				
				h_countere=(s_digit-48)+10*(f_digit-48);
				
				// check hours value (must be <= 24)
				while (h_countere>24)
				{
					LCD_clear_screen();
					LCD_send_string("Error");
					LCD_move_cursor(2,1);
					LCD_send_string("invalid value");
					_delay_ms(1000);
					LCD_clear_screen();
					LCD_send_string("Hours=");
					LCD_move_cursor(1,7);
					_delay_ms(500);
					
					do
					{
						f_digit=keypad_cheak_press();
					} while (f_digit==NOTPRESSED);
					LCD_send_char(f_digit);
					_delay_ms(300);
					do
					{
						s_digit=keypad_cheak_press();
					} while (s_digit==NOTPRESSED);
					LCD_send_char(s_digit);
					_delay_ms(300);
					
					h_countere=(s_digit-48)+10*(f_digit-48);
					
				}
				
				// set minutes 
				LCD_clear_screen();
				LCD_send_string("Minutes=");
				LCD_move_cursor(1,9);
				do
				{
					f_digit=keypad_cheak_press();
				} while (f_digit==NOTPRESSED);
				LCD_send_char(f_digit);
				_delay_ms(300);
				do
				{
					s_digit=keypad_cheak_press();
				} while (s_digit==NOTPRESSED);
				LCD_send_char(s_digit);
				_delay_ms(300);
				m_counter=(s_digit-48)+10*(f_digit-48);
				
				// check minutes value (must be <= 60) 
				while (m_counter>60)
				{
					LCD_clear_screen();
					LCD_send_string("Error");
					LCD_move_cursor(2,1);
					LCD_send_string("invalid value");
					_delay_ms(1000);
					LCD_clear_screen();
					LCD_send_string("Minutes=");
					LCD_move_cursor(1,9);
					_delay_ms(500);
					
					do
					{
						f_digit=keypad_cheak_press();
					} while (f_digit==NOTPRESSED);
					LCD_send_char(f_digit);
					_delay_ms(300);
					do
					{
						s_digit=keypad_cheak_press();
					} while (s_digit==NOTPRESSED);
					LCD_send_char(s_digit);
					_delay_ms(300);
					
					m_counter=(s_digit-48)+10*(f_digit-48);
					
				}
				
				// set seconds 
				LCD_clear_screen();
				LCD_send_string("Seconds=");
				LCD_move_cursor(1,9);
				do
				{
					f_digit=keypad_cheak_press();
				} while (f_digit==NOTPRESSED);
				LCD_send_char(f_digit);
				_delay_ms(300);
				do
				{
					s_digit=keypad_cheak_press();
				} while (s_digit==NOTPRESSED);
				LCD_send_char(s_digit);
				_delay_ms(300);
				s_counter=(s_digit-48)+10*(f_digit-48);
				
				//check second value (must be <= 60)
					while (s_counter>60)
					{
						LCD_clear_screen();
						LCD_send_string("Error");
						LCD_move_cursor(2,1);
						LCD_send_string("invalid value");
						_delay_ms(1000);
						LCD_clear_screen();
						LCD_send_string("Seconds=");
						LCD_move_cursor(1,9);
						_delay_ms(500);
						
						do
						{
							f_digit=keypad_cheak_press();
						} while (f_digit==NOTPRESSED);
						LCD_send_char(f_digit);
						_delay_ms(300);
						do
						{
							s_digit=keypad_cheak_press();
						} while (s_digit==NOTPRESSED);
						LCD_send_char(s_digit);
						_delay_ms(300);
						
						s_counter=(s_digit-48)+10*(f_digit-48);
					}
				
				LCD_clear_screen();
				LCD_send_string("press 1 to set ");
				LCD_move_cursor(2,5);
				LCD_send_string("clock");
			}
			else
			{
				LCD_clear_screen();
				LCD_send_string("Error");
				_delay_ms(1000);
				LCD_clear_screen();
				LCD_send_string("press 1 to set ");
				LCD_move_cursor(2,5);
				LCD_send_string("clock");
			}			
		}
			
	    SET_BIT(PORTC,1);
	    SET_BIT(PORTC,2);
	    SET_BIT(PORTC,3);
	    SET_BIT(PORTC,4);
	    SET_BIT(PORTC,5);
	    CLR_BIT(PORTC,0);
	    seven_segment_write('D',s_counter%10);
	    _delay_ms(5);
	    
	    SET_BIT(PORTC,0);
	    SET_BIT(PORTC,2);
	    SET_BIT(PORTC,3);
	    SET_BIT(PORTC,4);
	    SET_BIT(PORTC,5);
	    CLR_BIT(PORTC,1);
	    seven_segment_write('D',s_counter/10);
	    _delay_ms(5);
	    
	    SET_BIT(PORTC,0);
	    SET_BIT(PORTC,1);
	    SET_BIT(PORTC,3);
	    SET_BIT(PORTC,4);
	    SET_BIT(PORTC,5);
	    CLR_BIT(PORTC,2);
	    seven_segment_write('D',m_counter%10);
	    _delay_ms(5);
	    
	    SET_BIT(PORTC,0);
	    SET_BIT(PORTC,1);
	    SET_BIT(PORTC,2);
	    SET_BIT(PORTC,4);
	    SET_BIT(PORTC,5);
	    CLR_BIT(PORTC,3);
	    seven_segment_write('D',m_counter/10);
	    _delay_ms(5);
	    
	    SET_BIT(PORTC,0);
	    SET_BIT(PORTC,1);
	    SET_BIT(PORTC,2);
	    SET_BIT(PORTC,3);
	    SET_BIT(PORTC,5);
	    CLR_BIT(PORTC,4);
	    seven_segment_write('D',h_countere%10);
	    _delay_ms(5);
	    
	    SET_BIT(PORTC,0);
	    SET_BIT(PORTC,1);
	    SET_BIT(PORTC,2);
	    SET_BIT(PORTC,3);
	    SET_BIT(PORTC,4);
	    CLR_BIT(PORTC,5);
	    seven_segment_write('D',h_countere/10);
	    _delay_ms(5);
	    
	    if (s_counter==60)
	    {
		    s_counter=0;
		    m_counter++;
	    }
	    if (m_counter==60)
	    {
		    m_counter=0;
		    h_countere++;
	    }
	    if (h_countere==24)
	    {
		    h_countere=0;
	    }		
    }
}

ISR(TIMER2_OVF_vect)
{
	s_counter++;
}