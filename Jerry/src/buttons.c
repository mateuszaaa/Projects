#include "buttons.h"
void initButtons()
{
	// enables clock for A port
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA->PUPDR |= GPIO_PUPDR_PUPDR0_1; //pull up


}
