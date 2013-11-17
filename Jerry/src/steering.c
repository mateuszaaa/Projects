#include "steering.h"
int limitRotation(int rotation){

    if (rotation > MAX_ROTATION ){
        return MAX_ROTATION;
    }

    if (rotation < - MAX_ROTATION){
        return -MAX_ROTATION;
    }

    return rotation;
}

int getRotationInPoint(){
    int pwm;
    pwm = calculatePID(robot.rotation,robot.rotation_target,&rotation_in_point,gains_rotation_in_point);
    pwm = limitRotation(pwm);
    return pwm;
}


int getRotationFromEncoders( ){
    int pwm;
    int motors_diff = robot.left_motor_pos  - robot.right_motor_pos;
    int motors_diff_target = 0 ;
    pwm = calculatePID(motors_diff,motors_diff_target,&rotation_encoders,gains_rot_encoders);
    return pwm;
}

int getRotationFromGyro( ){
    int pwm;
    pwm = calculatePID(robot.rotation,robot.rotation_target,&rotation_gyro,gains_rot_gyro);
    return pwm; 
}

int getRotationFromSensors(){
    int pwm;
    int sensors_diff = 0;
    int left;
    int right;

    left = robot.left_ir_sensor_target - measures.left_ir_sensor;
    right = robot.right_ir_sensor_target - measures.right_ir_sensor;
    pwm = calculatePID(left+right,sensors_diff,&rotation_ir,gains_rot_ir );
    return pwm;
}

int getRotation(uint8_t source){
    int rotation;

    if (source == IR_SENSORS)
        rotation = getRotationFromSensors();

    if (source == GYRO)
        rotation = getRotationFromGyro();

    if (source == ENCODERS)
        rotation = getRotationFromEncoders();
    rotation = limitRotation(rotation);

}

int limitTranslation(int translation){

    if (translation > MAX_TRANSLATION ) 
    {
        return MAX_TRANSLATION;
    }

    if ( translation < -MAX_TRANSLATION )
    {
        return -MAX_TRANSLATION;
    }

    return translation;
    
}

int getTranslation(motor_side side){
    int pwm=0;

    if (side == LEFT_MOTOR) {
        pwm = calculatePID(robot.left_motor_pos,robot.left_motor_target,&left_translation,gains_translation);
    }else{
        pwm = calculatePID(robot.right_motor_pos,robot.right_motor_target,&right_translation,gains_translation);
    }
    pwm = limitTranslation(pwm);
    return pwm; 
}

