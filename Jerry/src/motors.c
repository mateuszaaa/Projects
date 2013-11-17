#include "motors.h"
void initHBridgePins(){
    //AIN_1 - PC1
    //AIN_2 - PC2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; //clock enable for PORTC
    GPIOC->MODER |= GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0; //output mode
    //BIN_1 - PA3
    //BIN_2 - PA2
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;//clock enable for PORTA 
    GPIOA->MODER |= GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0;//output mode
}
void initMotors()
{
    initHBridgePins();
	initPWM1();
	initPWM2();
}

void setRightMotor (int speed,uint8_t dir)
{
   //dir == 1 -> FORNT 
   //dir == 0 -> BACK 
   if (dir == 1){
       AIN1_SET;
       AIN2_RESET;
   }else{
       AIN1_RESET;
       AIN2_SET;
   }
   setPWM1Duty(speed);
}

void setMotorSigned(int speed,motor_side side){
    if (side == LEFT_MOTOR){
        setLeftMotorSigned(speed);
    }else{
        setRightMotorSigned(speed);
    }
}

void setLeftMotorSigned (int speed){
   //dir == 1 -> FORNT 
   //dir == 0 -> BACK 
   uint8_t dir;
   if (speed > 0 ){
       dir = FRONT_DIR;
       speed = speed;
   }else{
       dir = BACK_DIR;
       speed = -speed;
   }
   setLeftMotor(speed,dir);
}

void setRightMotorSigned (int speed){
   //dir == 1 -> FORNT 
   //dir == 0 -> BACK 
   uint8_t dir;
   if (speed > 0 ){
       dir = FRONT_DIR;
       speed = speed;
   }else{
       dir = BACK_DIR;
       speed = -speed;
   }
   setRightMotor(speed,dir);
}
void setLeftMotor (int speed,uint8_t dir){
   //dir == 1 -> FORNT 
   //dir == 0 -> BACK 
   if (dir == 1){
       BIN1_RESET;
       BIN2_SET;
   }else{
       BIN1_SET;
       BIN2_RESET;
   }
   setPWM2Duty(speed);
}

void stopMotors(){
    setLeftMotorSigned(0);
    setRightMotorSigned(0);
    AIN1_RESET;
    AIN2_RESET;
    BIN1_RESET;
    BIN2_RESET;
}

void rotateSigned(int speed){
    if (speed > 0){
        turnRight(speed);
    }else{
        turnLeft(-speed);
    }

}

void turnRight (uint8_t speed)
{
   setLeftMotor(speed,FRONT_DIR);
   setRightMotor(speed,BACK_DIR);
}

void turnLeft (uint8_t speed)
{
   setLeftMotor(speed,BACK_DIR);
   setRightMotor(speed,FRONT_DIR);
}
