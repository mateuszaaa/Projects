#ifndef PWM_H
#define PWM_H

#include "stm32f4xx.h"
//PD13 timer 4 channel 2 AF2
void initPWM1();
void setPWM1Period(uint16_t );
void setPWM1Duty(uint16_t );

void initPWM2();
void setPWM2Period(uint16_t );
void setPWM2Duty(uint16_t );


#endif
