/*
 * DIO.c
 *
 * Created: 18/11/2023 11:36:29 ص
 *  Author: Admin
 */ 


#include <avr/io.h>
#include "DIO.h"
#include "std_macros.h"

void DIO_Pin_Direction(char port_nam,char pin_num,char direc)
 {
	switch (port_nam)
	{
		// Set the direction of a pin in port A
		case 'A':
		case 'a':
		if(direc==1)
		{
			SET_BIT(DDRA,pin_num); // set the bin as an output pin "1"
		}
		else
		{
			CLR_BIT(DDRA,pin_num);// set the bin as an input pin "0"
		}
		break;
		
		// Set the direction of a pin in port B
		case 'B':
		case 'b':
		if(direc==1)
		{
			SET_BIT(DDRB,pin_num); // set the bin as an output pin "1"
		}
		else
		{
			CLR_BIT(DDRB,pin_num); // set the bin as an input pin "0"
		}
		break;
		
		// Set the direction of a pin in port C
		case 'C':
		case 'c':
		if(direc==1)
		{
			SET_BIT(DDRC,pin_num); // set the bin as an output pin "1"
		}
		else
		{
			CLR_BIT(DDRC,pin_num); // set the bin as an input pin "0"
		}
		break;
		
		// Set the direction of a pin in port D
		case 'D':
		case 'd':
		if(direc==1)
		{
			SET_BIT(DDRD,pin_num); // set the bin as an output pin "1"
		}
		else
		{
			CLR_BIT(DDRD,pin_num); // set the bin as an input pin "0"
		}
		break;
		
	}
	
}
void DIO_Pin_write(char port_nam, char pin_num, char output_val)
 {
	switch (port_nam)
	{
		// Set the value of the output of a pin in port A as high or low output
		case 'A':
		case'a':
		
		if(output_val==1)
		{
			SET_BIT(PORTA,pin_num); // set the output as high output
		}
		else
		{
			CLR_BIT(PORTA,pin_num);// // set the output as low output
		}
		break;
		
		
		// Set the value of the output of a pin in port B as high or low output 
		case 'B':
		case'b':
		
		if(output_val==1)
		{
			SET_BIT(PORTB,pin_num); // set the output as high output 
		}
		else
		{
			CLR_BIT(PORTB,pin_num);// // set the output as low output 
		}
		break;
		
		// Set the value of the output of a pin in port C as high or low output
		case 'C':
		case'c':
		
		if(output_val==1)
		{
			SET_BIT(PORTC,pin_num); // set the output as high output
		}
		else
		{
			CLR_BIT(PORTC,pin_num);// // set the output as low output
		}
		break;
		
		// Set the value of the output of a pin in port D as high or low output
		case 'D':
		case'd':
		
		if(output_val==1)
		{
			SET_BIT(PORTD,pin_num); // set the output as high output
		}
		else
		{
			CLR_BIT(PORTD,pin_num);// // set the output as low output
		}
		break;
				
	}
}
 
void DIO_Pin_Tog(char por_nam , char pin_num)
 {
	switch(por_nam)
	{
		// Toglle a given pin in port A
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pin_num);
		break;
		
		// Toglle a given pin in port B
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pin_num);
		break;
		
		// Toglle a given pin in port C
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pin_num);
		break;
		
		// Toglle a given pin in port D
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pin_num);
		break;
	}
}

unsigned char DIO_Pin_Read(char port_nam, char pin_num )
 {
	unsigned char  input_val;
	switch(port_nam)
	{
	
	// Read the input value of a pin in port A
	case 'A':
	case 'a':
    input_val = READ_BIT(PINA,pin_num); 
	break;
	// Read the input value of a pin in port B
	case 'B':
	case 'b':
	input_val = READ_BIT(PINB,pin_num);
	break;
	// Read the input value of a pin in port C
	case 'C':
	case 'c':
	input_val = READ_BIT(PINC,pin_num);
	break;
	// Read the input value of a pin in port D
	case 'D':
	case 'd':
	input_val = READ_BIT(PIND,pin_num);
	break;
	}	
	return input_val;
	
}

void DIO_Port_Direction(char port_nam,unsigned char direc)
 {
	switch(port_nam)
	{
	//set the direction of port A
	case 'A':
	case 'a':
	DDRA=direc;
	break;
	//set the direction of port B
	case 'B':
	case 'b':
	DDRB=direc;
	break;
	//set the direction of port C
	case 'C':
	case 'c':
	DDRC=direc;
	break;
	//set the direction of port D
	case 'D':
	case 'd':
	DDRD=direc;
	break;
	}	
}
void DIO_Potr_write(char port_num,unsigned char output_port_val)
 {
	switch(port_num)
	{
		
	// write the output value of port A
	case 'A':
	case 'a':
	PORTA=output_port_val;
	break;
	// write the output value of port B
	case 'B':
	case 'b':
	PORTB=output_port_val;
	break;
	// write the output value of port C
	case 'C':
	case 'c':
	PORTC=output_port_val;
	break;
	// write the output value of port D
	case 'D':
	case 'd':
	PORTD=output_port_val;
	break;
	}	
}
void DIO_Port_Tog(char port_nam)
 {
	switch(port_nam)
	{
		//toggle the output value of port A
		case 'A':
		case 'a':
		TOG_PORT(PORTA);
		 break;
		 //toggle the output value of port B
		 case 'B':
		 case 'b':
		 TOG_PORT(PORTB);
		 break;
		 //toggle the output value of port C
		 case 'C':
		 case 'c':
		 TOG_PORT(PORTC);
		 break;
		 //toggle the output value of port D
		 case 'D':
		 case 'd':
		 TOG_PORT(PORTD);
		 break;
	}
}
unsigned char DIO_Port_Read(char port_nam)
 {
	unsigned char port_val;
	switch(port_nam)
	{
		//read the value of port A
		case 'A':
		case 'a':
		port_val=PINA;
		break;
		//read the value of port B
		case 'B':
		case 'b':
		port_val=PINB;
		break;
		//read the value of port C
		case 'C':
		case 'c':
		port_val=PINC;
		break;
		//read the value of port D
		case 'D':
		case 'd':
		port_val=PIND;
		break;
	}
	return port_val;		
}
void DIO_connect_pullup(char port_nam, char pin_num, char connect_pullup)
 {
	switch(port_nam)
	{
		// active internal pullup in a given pin in port A
		case'A':
		case 'a':
		if (connect_pullup==1)
		{
			SET_BIT(PORTA,pin_num);
		}
		else
		{
			CLR_BIT(PORTA,pin_num);
		}
		break;
		// active internal pullup in a given pin in port B
		case'B':
		case 'b':
		if (connect_pullup==1)
		{
			SET_BIT(PORTB,pin_num);
		}
		else
		{
			CLR_BIT(PORTB,pin_num);
		}
		break;
		// active internal pullup in a given pin in port C
		case'C':
		case 'c':
		if (connect_pullup==1)
		{
			SET_BIT(PORTC,pin_num);
		}
		else
		{
			CLR_BIT(PORTC,pin_num);
		}
		break;
		// active internal pullup in a given pin in port D
		case'D':
		case 'd':
		if (connect_pullup==1)
		{
			SET_BIT(PORTD,pin_num);
		}
		else
		{
			CLR_BIT(PORTD,pin_num);
		}
		break;
	}	
}
void DIO_Low_nibble_Direction(char port_nam,unsigned char direc)
 {
		direc&=0x0f;
		switch(port_nam)
		{
			//set the direction of port A
			case 'A':
			case 'a':
			DDRA&=0xf0;
			DDRA|=direc;
			break;
			//set the direction of port B
			case 'B':
			case 'b':
			DDRB&=0xf0;
			DDRB|=direc;
			break;
			//set the direction of port C
			case 'C':
			case 'c':
		    DDRC&=0xf0;
		    DDRC|=direc;
			break;
			//set the direction of port D
			case 'D':
			case 'd':
			DDRD&=0xf0;
			DDRD|=direc;
			break;
		}
}

void DIO_High_nibble_Direction(char port_nam,unsigned char direc)
{
	direc&=0xf0;
	switch(port_nam)
	{
		//set the direction of port A
		case 'A':
		case 'a':
		DDRA&=0x0f;
		DDRA|=direc;
		break;
		//set the direction of port B
		case 'B':
		case 'b':
		DDRB&=0x0f;
		DDRB|=direc;
		break;
		//set the direction of port C
		case 'C':
		case 'c':
		DDRC&=0x0f;
		DDRC|=direc;
		break;
		//set the direction of port D
		case 'D':
		case 'd':
		DDRD&=0x0f;
		DDRD|=direc;
		break;
	}
}

void Low_nibble_write(unsigned char port_nam,unsigned char num)
 {
	num&=0x0f;
	switch(port_nam)
	{
		case'A':
		PORTA&=0xf0;
		PORTA|=num;
		break;
		
		case'B':
		PORTB&=0xf0;
		PORTB|=num;
		break;
		
		case'C':
		PORTC&=0xf0;
		PORTC|=num;
		break;
		
		case'D':
		PORTD&=0xf0;
		PORTD|=num;
		break;		
	}
}

void High_nibble_write(unsigned char port_nam,unsigned char num)
 {
	num<<=4;
	switch(port_nam)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=num;
		break;
		
		case 'B':
		PORTB&=0x0f;
		PORTB|=num;
		break;
		
		case 'C':
		PORTC&=0x0f;
		PORTC|=num;
		break;
		
		case 'D':
		PORTD&=0x0f;
		PORTD|=num;
		break;		
	}
}