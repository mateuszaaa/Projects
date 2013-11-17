#ifndef PID_H
#define PID_H
#include "defines.h"
#include "motors.h"
int calculatePID (int ,int ,pid *,pid_gains );
int limitPWM(int );
float limitI(float );
#endif
