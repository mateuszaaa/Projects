#ifndef GYRO_HH
#define GYRO_HH
#include "defines.h"
#include "pwm.h"
#include "motors.h"
#include "spi.h"
void updateRobotRotation ();
int getCurrentAngleSpeed();
#endif
