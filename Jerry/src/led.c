
#include "led.h"
void initLED()
{
	//clock enable for port A
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	//orange - PD13
	GPIOA->MODER &= ~(GPIO_MODER_MODER15); //reset
	GPIOA->MODER |= GPIO_MODER_MODER15_0; //output
}
