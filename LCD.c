
#include "LCD.h"
#include "DIO.h"
#include "LCD configuration.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_Init(void)
{
	_delay_ms(200);
	
	#ifdef eight_bit_mode
	 
	DIO_Port_Direction(Init_PORT,0xff);
	DIO_Pin_Direction(cnt_PORT,EN,1);
	DIO_Pin_Direction(cnt_PORT,RW,1);
	DIO_Pin_Direction(cnt_PORT,RS,1);
	DIO_Pin_write(cnt_PORT,RW,0);
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#else
	
	DIO_High_nibble_Direction(Init_PORT,0xf0);
	DIO_Pin_Direction(cnt_PORT,EN,1);
	DIO_Pin_Direction(cnt_PORT,RW,1);
	DIO_Pin_Direction(cnt_PORT,RS,1);
	DIO_Pin_write(cnt_PORT,RW,0);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTRY_MODE);
	_delay_ms(1);
	
	#endif
	
}

static void send_falling_edge(void)
{
	DIO_Pin_write(cnt_PORT,EN,1);
	_delay_ms(2);
	DIO_Pin_write(cnt_PORT,EN,0);
	_delay_ms(2);	
}
void LCD_send_cmd(char cmd)
{
	#ifdef eight_bit_mode
	DIO_Potr_write(Init_PORT,cmd);
	DIO_Pin_write(cnt_PORT,RS,0);
	send_falling_edge();

	#else 
	 High_nibble_write(Init_PORT,cmd>>4);
	 DIO_Pin_write(cnt_PORT,RS,0);
	 send_falling_edge();
	 High_nibble_write(Init_PORT,cmd);
	 DIO_Pin_write(cnt_PORT,RS,0);
	 send_falling_edge();
	 _delay_ms(1);
	 	
	#endif
	
}

void LCD_send_char(char data)
{
	#ifdef eight_bit_mode
	DIO_Potr_write(Init_PORT,data);
	DIO_Pin_write(cnt_PORT,RS,1);
	send_falling_edge();
	
	#else 
		
		High_nibble_write(Init_PORT,data>>4);
		DIO_Pin_write(cnt_PORT,RS,1);
		send_falling_edge();
		High_nibble_write(Init_PORT,data);
		DIO_Pin_write(cnt_PORT,RS,1);
		send_falling_edge();
		_delay_ms(1);
		
	#endif

}
void LCD_send_string(char*data)
{
	while((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
	}
}

void LCD_clear_screen(void)
{
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}
void LCD_move_cursor(char row, char colomn)
{
	char data;
	if(row>2||row<1||colomn>16||colomn<1)
	{
		data=0x80;
	}
	else if(row==1)
	{
		data=0x80+colomn-1;
	}
	else if(row==2)
	{
		data=0xc0+colomn-1;
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}