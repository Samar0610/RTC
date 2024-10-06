#include "DIO.h"
#include "keypad.h"
#define I_PORT 'B'
#define NOTPRESSED  0xff

void keypad_Init(void)
{
	DIO_Low_nibble_Direction(I_PORT,0x0f);
	
	DIO_High_nibble_Direction(I_PORT,0x00);
	
	DIO_connect_pullup(I_PORT,4,1);
	DIO_connect_pullup(I_PORT,5,1);
	DIO_connect_pullup(I_PORT,6,1);
	DIO_connect_pullup(I_PORT,7,1);
	
}

unsigned char keypad_cheak_press(void)
{
	char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	char row,colomn,x;
	char val=NOTPRESSED;
	for(row=0;row<4;row++)
	{
		Low_nibble_write(I_PORT,0x0f);
		DIO_Pin_write(I_PORT,row,0);
		for(colomn=0;colomn<4;colomn++)
		{
			x=DIO_Pin_Read(I_PORT,(colomn+4));
			if(x==0)
			{
				val=arr[row][colomn];
				break;
			}
		}		
		if(x==0)
		{
			break;
		}
	}
	return val;
}

