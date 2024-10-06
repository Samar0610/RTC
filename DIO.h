/*
 * DIO.h
 *
 * Created: 18/11/2023 11:37:03 ص
 *  Author: Admin
 */ 


#ifndef DIO_H_
#define DIO_H_

void DIO_Pin_Direction(char port_nam,char pin_num,char direc);
/* Function to set the direction of a given pin in a given  port(input or output)
   Function name :  DIO_Set_Pin_Direction 
   Function return : void 
*/

void DIO_Pin_write(char port_nam, char pin_num, char output_val);
/* Function to set the output of a given pin in a given  port (high or low)
   Function name :  DIO_Pin_write 
   Function return : void 
*/

void DIO_Pin_Tog(char por_nam , char pin_num);
/* Function to toggle the value of the output of a given pin in a given  port
   Function name :  DIO_Tog_Pin
   Function return : void 
*/

unsigned char DIO_Pin_Read(char port_nam, char pin_num );
/* Function to read the input value of a given pin in a given  port
   Function name :  DIO_Pin_Read
   Function return : unsigned char  
*/

void DIO_Port_Direction(char port_nam,unsigned char direc);
/* Function to set the direction of a given  port(input or output)
   Function name :  DIO_Port_Direction 
   Function return : void 
*/
void DIO_Potr_write(char port_num,unsigned char output_port_val);
/* Function to set the output value of a given  port(high or low)
   Function name :  DIO_Port_write 
   Function return : void 
*/

void DIO_Port_Tog(char port_nam);
/* Function to toggle the output value of a given  port
   Function name :  DIO_Tog_Port
   Function return : void 
*/

unsigned char DIO_Port_Read(char port_nam);
/* Function to read the value of a given  port
   Function name :  DIO_Port_Read
   Function return : unsigned char
*/

void DIO_connect_pullup(char port_nam, char pin_num, char connect_pullup);
/* Function to active the pullup of a given pin in a given port 
   Function name :  DIO_connect_pullup
   Function return : void
*/

void DIO_Low_nibble_Direction(char port_nam,unsigned char direc);
void DIO_High_nibble_Direction(char port_nam,unsigned char direc);

void Low_nibble_write(unsigned char port_nam,unsigned char num );
void High_nibble_write(unsigned char port_nam,unsigned char num );

#endif /* DIO_H_ */