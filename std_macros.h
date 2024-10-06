/*
 * bit_macros.h
 *
 * Created: 17/11/2023 11:43:36 م
 *  Author: Admin
 */ 


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit)      reg|=(1<<bit)
#define CLR_BIT(reg,bit)      reg&=(~(1<<bit))
#define TOG_BIT(reg,bit)      reg^=(1<<bit)
#define READ_BIT(reg,bit)     ((reg&(1<<bit))>>bit)
#define IS_BIT_SET(reg,bit)   (reg&(1<<bit))>>bit
#define IS_BIT_CLR(reg,bit)   !((reg&(1<<bit))>>bit)

#define TOG_PORT(reg)      reg=~reg


