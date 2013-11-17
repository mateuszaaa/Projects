#include "usart.h"

void initUsart3()
{
	//USART 3
	// PC10 TX
	// PC11 RX
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // clock for port d
	RCC->APB1ENR |= RCC_APB1ENR_USART3EN;// clock for usart

	//Alternate function
	//PC10 - TX
	GPIOC->MODER |= GPIO_MODER_MODER10_1; //alternate function
	GPIOC->AFR[1]|= (7<<8) ;
	//PC11 - RX
	GPIOC->MODER |= GPIO_MODER_MODER11_1; //alternate function
	GPIOC->AFR[1]|= (7<<12);

	USART3->BRR =  168000000/4/230400;

	//enables transmiter and reciver
	USART3->CR1 |= USART_CR1_TE | USART_CR1_RE;
	USART3->CR1 |= USART_CR1_UE;
}

void enableUSART3RXNEInterrupt(){
    USART3->CR1 |= USART_CR1_RXNEIE;
	NVIC_EnableIRQ(USART3_IRQn);  //enable enable interrupt from TIM3

}

void USART3_transmitByte(uint8_t data){

  while( !(USART3->SR & USART_SR_TXE) ){;} //check if transmission is completed
  USART3->DR=data;
}

void USART3_transmitString(char* data){
  uint8_t i =0;
  while ( data[i]!= '\0')
    USART3_transmitByte(data[i++]);

}

uint8_t USART3_reciveByte(){
  uint8_t data;
  while( !(USART3->SR & USART_SR_RXNE))
  data = USART3->DR ;
  return data;
}

