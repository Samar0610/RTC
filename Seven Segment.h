/*
 * Seven_Segment.h
 *
 * Created: 02/12/2023 11:51:32 م
 *  Author: Admin
 */ 


#ifndef SEVEN SEGMENT_H_
#define SEVEN SEGMENT_H_

void seven_segment_Init(unsigned char port_nam);

void seven_segment_write(unsigned char port_nam,unsigned char num);

#endif /* SEVEN SEGMENT_H_ */