/*
 * Seven_Segment.c
 *
 * Created: 02/12/2023 11:51:53 م
 *  Author: Admin
 */ 
#include "DIO.h"

void seven_segment_Init(unsigned char port_nam)
{
	DIO_Port_Direction(port_nam,0xff);
}

void seven_segment_write(unsigned char port_nam,unsigned char num)
{
	unsigned char ss_arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	DIO_Potr_write(port_nam,ss_arr[num]);
}
