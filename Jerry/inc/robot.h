#ifndef ROBOT_H
#define ROBOT_H
#include "defines.h"
#include "encoder.h"
#include "spi.h"
#include "pid.h"
#include "usart.h"
#include "itoa.h"
#include "ir_sensors.h"
#include "steering.h"

void updateRobotState();
void updateRobotAnglePosition();
void updateMotorsPosition();
void updateRightMotorPosition();
void updateLeftMotorPosition();
void moveRobot();
void updateRobotState();
void updateRobotAnglePosition();
void updateMotorsPosition();
void updateRightMotorPosition();
void updateLeftMotorPosition();
void moveRobot();

uint8_t inRange(int ,int ,int );

int limitTranslationPWM(int );
int getMotorTranslationPWMValue(uint8_t );
int getRotateInPointPWMValue();
int limitRotation(int );
int getRotationFromEncoders( );
int getRotationFromGyro( );
int getRotationFromIRSensors( );
#endif
