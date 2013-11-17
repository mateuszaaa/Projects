#include "delay.h"
void waitUs(uint32_t val)
{
	delay_counter=val;
	while (delay_counter){;}
}

void waitMs(uint32_t val)
{
	delay_counter=val*1000;
	while (delay_counter){;}
}
void decrementDelayValue(){
	delay_counter--;
}
