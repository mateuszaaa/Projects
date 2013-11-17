#ifndef STEERING_H
#define STEERING_H
#include "defines.h"
#include "pid.h"
#include "motors.h"
typedef enum{
    GYRO,
    IR_SENSORS,
    ENCODERS
}rotation_sensor_source;


int limitRotation(int rotation);
int getRotationInPoint();
int getRotation(rotation_sensor_source );
int getRotationFromEncoders( );
int getRotationFromSensors();
int limitTranslation(int translation);
int getTranslation(motor_side side);
#endif
