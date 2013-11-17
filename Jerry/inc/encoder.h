#ifndef ENCODER_H
#define ENCODER_H

#include "defines.h"
    //Left Encoder
	//PA8 - TIM1_CH1
	//PA9 - TIM1_CH2
    //Right Encoder
    //PA6 - TIM8_CH1
	//PA7 - TIM8_CH2
    
void initEncoders();
void initLeftEncoder();
void initRightEncoder();
void resetEncoders();
#endif
