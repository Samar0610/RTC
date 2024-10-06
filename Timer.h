


#ifndef TIMER_H_
#define TIMER_H_

void Timer0_CTC_init_interrupt(void);
void Timer0_wave_nonPWM(void);
void Timer0_Fast_PWM_inverting();
void Timer0_Fast_PWM_non_inverting();
void Timer0_PhaseCorrect_PWM_inverting();
void Timer0_PhaseCorrect_PWM_non_inverting();
void Timer2_OVF_init_external();

#endif /* TIMER_H_ */