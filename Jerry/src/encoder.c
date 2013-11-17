#include "encoder.h"
//TIM1
//TIM1_CH1 PA8
//TIM1_CH2 PA9
void initEncoders(){
    initRightEncoder();
    initLeftEncoder();
}

void initLeftEncoder()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // clock for port
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; // TIM1 enable

	//Alternate function
	//PA8 - TIM1_CH1
	//PA9 - TIM1_CH2

    GPIOA->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_1  | GPIO_OSPEEDER_OSPEEDR9_1;//50Mhz Fast Mode
	GPIOA->MODER   |= GPIO_MODER_MODER8_1       | GPIO_MODER_MODER9_1; //alternate function
	GPIOA->AFR[1]|= (1<<0) | (1<<4) ; //AF1 for PA8 and PA9

	TIM1->PSC = 1;
	TIM1->ARR = 0xffff; //max value

	//channel 1 is configured as input, IC1 is mapped on TI1
	//channel 2 is configured as input, IC1 is mapped on TI2
	TIM1->CCMR1|= TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0;
	TIM1->CCER|=  TIM_CCER_CC2P ; //
	//Counter counts up/down on both TI1FP1 and TI2FP2 edges
	//depending on the level of the other input.
	TIM1->SMCR |= TIM_SMCR_SMS_0|TIM_SMCR_SMS_1;
	TIM1->CR1 |= TIM_CR1_CEN;
    TIM1->CNT=10;
}

void initRightEncoder()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // clock for port
	RCC->APB2ENR |= RCC_APB2ENR_TIM8EN; // TIM8 enable

	//Alternate function
	//PA6 - TIM8_CH1
	//PA7 - TIM8_CH2

    GPIOC->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR6_1  | GPIO_OSPEEDER_OSPEEDR7_1;//50Mhz Fast Mode
	GPIOC->MODER   |= GPIO_MODER_MODER6_1       | GPIO_MODER_MODER7_1; //alternate function
	GPIOC->AFR[0]|= (3<<24) | (3<<28) ; //AF1 for PA8 and PA9

	TIM8->PSC = 1;
	TIM8->ARR = 0xffff; //max value

	//channel 1 is configured as input, IC1 is mapped on TI1
	//channel 2 is configured as input, IC1 is mapped on TI2
	TIM8->CCMR1|= TIM_CCMR1_CC2S_0 | TIM_CCMR1_CC1S_0;
	TIM8->CCER|=  TIM_CCER_CC2P ; //
	//Counter counts up/down on both TI1FP1 and TI2FP2 edges
	//depending on the level of the other input.
	TIM8->SMCR |= TIM_SMCR_SMS_0|TIM_SMCR_SMS_1;
	TIM8->CR1 |= TIM_CR1_CEN;
    TIM8->CNT=10;
}

void resetEncoders(){
    TIM8->CNT = 0;
    TIM1->CNT = 0;
}

