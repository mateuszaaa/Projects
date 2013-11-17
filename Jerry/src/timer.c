#include "timer.h"
void initTimer3(uint16_t arr)
{


	//clock enable for port D
	//PD13 - TIM4_CH2  AF2
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

//	TIM3->PSC = 42000; // 1 s equals 1000 ticks
	TIM3->PSC = 42000; // 1 s equals 1000 ticks
	TIM3->ARR = arr;
	TIM3->DIER |= TIM_DIER_UIE; //enable timer interrupt
	TIM3->CR1 |= TIM_CR1_CEN;
	NVIC_EnableIRQ(TIM3_IRQn);  //enable enable interrupt from TIM3
}

