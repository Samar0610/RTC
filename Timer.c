#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_macros.h"

void Timer0_CTC_init_interrupt(void)
{
	SET_BIT(TCCR0,WGM01);  // select ctc mode
	OCR0=80; // compare match value
	
	// set timer clock value
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// enable interrupt
	sei();
	SET_BIT(TIMSK,OCIE0);
}

void Timer0_wave_nonPWM(void)
{
	SET_BIT(DDRB,3);
	SET_BIT(TCCR0,WGM01);  // select ctc mode
	OCR0=80; // compare match value
	
	// set timer clock value
	
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	SET_BIT(TCCR0,COM00);
}

void Timer0_Fast_PWM_inverting()
{
	SET_BIT(DDRB,3);
	// select fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	// 
	OCR0=64;
	
	// select timer clock 
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// inverting
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
}
void Timer0_Fast_PWM_non_inverting()
{
	SET_BIT(DDRB,3);
	// select fast PWM mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	//
	OCR0=64;
	// select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	//non inverting
	
	SET_BIT(TCCR0,COM01);
	
}

void Timer0_PhaseCorrect_PWM_inverting()
{
	SET_BIT(DDRB,3);
	// select phase correct PWM mode
	SET_BIT(TCCR0,WGM00);
	
	
	OCR0=64;
	
	// select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// inverting
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
}
void Timer0_PhaseCorrect_PWM_non_inverting()
{
	SET_BIT(DDRB,3);
	// select phase correct PWM mode
	SET_BIT(TCCR0,WGM00);
	
	
	OCR0=64;
	
	// select timer clock
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	
	// inverting
	
	SET_BIT(TCCR0,COM01);
	
}

void Timer2_OVF_init_external()
{
	SET_BIT(ASSR,AS2);
	// select the clock
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	//enable interrupt
	sei();
	SET_BIT(TIMSK,TOIE2);
}