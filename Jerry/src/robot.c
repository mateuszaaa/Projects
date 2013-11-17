#include "robot.h"
int pwm_left;
int pwm_right;

void updateRobotAnglePosition(){
    int16_t data;
    uint8_t data_h;
    uint8_t data_l;

    data_h = SPI2_read(L3GD20_OUT_Z_H) ; 
    data_h = SPI2_read(L3GD20_OUT_Z_H) ; 
    data_l = SPI2_read(L3GD20_OUT_Z_L) ; 
    data_l = SPI2_read(L3GD20_OUT_Z_L) ; 


    data = ((data_h << 8) | (data_l & 0b11000000)) +L3GD20_OFFSET;
    data = (data >> 6);

    measures.angle_speed = data;
    robot.rotation += measures.angle_speed;
}

void updateMotorsPosition(){
    updateRightMotorPosition();
    updateLeftMotorPosition();
}

void updateSensorsState(){
    measures.left_front_ir_sensor = 0;
    measures.right_front_ir_sensor = 0;
    measures.left_ir_sensor = getMeasureIR(4);
    measures.right_ir_sensor = 0;
}

void updateRightMotorPosition(){
    //update data
    int delta;
    measures.right_motor_last_pos = measures.right_motor_current_pos;
    measures.right_motor_current_pos = TIM8->CNT;
    //change pos
    delta = measures.right_motor_current_pos - measures.right_motor_last_pos;
    robot.right_motor_pos += delta;
}

void updateLeftMotorPosition(){
    //update data
    int delta;
    measures.left_motor_last_pos = measures.left_motor_current_pos;
    measures.left_motor_current_pos =  TIM1->CNT;
    //change pos
    delta = measures.left_motor_current_pos - measures.left_motor_last_pos;
    robot.left_motor_pos += delta;
}

void updateRobotState(){
    updateRobotAnglePosition();
    updateMotorsPosition();
    updateSensorsState();
    
}



uint8_t inRange(int current,int target,int delta){
    if ( current >= target - delta && current <= target+delta )
        return 1;
    else
        return 0;
}


