#ifndef USART_H
#define USART_H

#include "defines.h"

//USART 2
// PD5 TX
// PD6 RX
void initUsart3();

void USART3_transmitByte(uint8_t data);
void USART3_transmitString(char* data);
uint8_t USART3_reciveByte();

#endif
