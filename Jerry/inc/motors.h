#ifndef MOTORS_HH
#define MOTORS_HH
#include "defines.h"
#include "pwm.h"

typedef enum {
    LEFT_MOTOR,
    RIGHT_MOTOR
}motor_side;

void initHBridgePins();
void initMotors();
void setRightMotor (int ,uint8_t );
void setLeftMotorSigned (int );
void setRightMotorSigned (int );
void setLeftMotor (int ,uint8_t );
void stopMotors();
void turnLeft (uint8_t );
void turnRight (uint8_t );
void rotateSigned(int );
#endif
