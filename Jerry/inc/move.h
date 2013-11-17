#ifndef MOVE_H
#define MOVE_H
#include "defines.h"
#include "stack.h"
#include "steering.h"
#include "robot.h"
#define POSITION_DELTA 15
#define ANGLE_DELTA 30
#define PWM_DELTA 40

void moveRobot();
void nextMove();
uint8_t goForward(rotation_sensor_source rot_sensor);
uint8_t rotateInPoint();
#endif
