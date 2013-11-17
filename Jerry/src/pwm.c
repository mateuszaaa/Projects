#include "pwm.h"

void initPWM1()
{
	//clock enable for port A
	//PA0 - TIM5_CH1  AF2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	GPIOA->MODER |= GPIO_MODER_MODER0_1; //alternate function
	GPIOA->AFR[0] |= (2<<0); //AF2

	TIM5->PSC = 1000;
	TIM5->CCR1 = 0; //trigger on channel 2
	TIM5->ARR = 1000;

	TIM5->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_2; //PWM mode on

	TIM5->CCER |= TIM_CCER_CC1E; //enable output on coresponding pin

	TIM5->CR1 |= TIM_CR1_ARPE;
	TIM5->CR1 |= TIM_CR1_CEN;
}

void setPWM1Period(uint16_t val)
{
	TIM5->ARR = val;
}

void setPWM1Duty(uint16_t val)
{
	TIM5->CCR1 = val;
}


void initPWM2()
{


	//clock enable for port A
	//P1 - TIM2_CH2  AF2
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;

	GPIOA->MODER |= GPIO_MODER_MODER1_1; //alternate function
	GPIOA->AFR[0] |= (2<<4); //AF2

	TIM5->PSC = 1000;
	TIM5->CCR2 = 0; //trigger on channel 2
	TIM5->ARR = 1000;

	TIM5->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2; //PWM mode on

	TIM5->CCER |= TIM_CCER_CC2E; //enable output on coresponding pin

	TIM5->CR1 |= TIM_CR1_ARPE;
	TIM5->CR1 |= TIM_CR1_CEN;
}

void setPWM2Period(uint16_t val)
{
	TIM5->ARR = val;
}

void setPWM2Duty(uint16_t val)
{
	TIM5->CCR2 = val;
}
