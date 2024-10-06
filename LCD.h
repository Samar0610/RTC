/*
 * LCD.h
 *
 * Created: 19/12/2023 11:16:58 ص
 *  Author: Admin
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "DIO.h"
#include "LCD configuration.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAN_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#ifdef four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0x28
#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif

void LCD_Init(void);

static void send_falling_edge(void);

void LCD_send_cmd(char cmd);

void LCD_send_char(char data);

void LCD_send_string(char*data);

void LCD_clear_screen(void);

void LCD_move_cursor(char row, char colomn);

#endif /* LCD_H_ */