/*
 * LCD_configuration.h
 *
 * Created: 19/12/2023 11:14:03 ص
 *  Author: Admin
 */ 


#ifndef LCD CONFIGURATION_H_
#define LCD CONFIGURATION_H_

//#define four_bit_mode
#define four_bit_mode

#define Init_PORT 'A'
#define cnt_PORT 'A'
#define nibble 'H'
#define EN 0
#define RS 1
#define RW 2

#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06

#define FOUR_BITS 0x28
#define EIGHT_BITS 0x38

#endif /* LCD CONFIGURATION_H_ */