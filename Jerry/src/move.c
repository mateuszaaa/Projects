#include "move.h"

void moveRobot(){
    element move;


    if ( allMovesDone(&robot_queue) ){
        //stand still
        LED_ON;
        stopMotors();

    }else{
        move = getElement(&robot_queue);

        if ( move.type == FORWARD && goForward(GYRO)  ){
            nextMove();
        }


        if ( move.type == ROTATE && rotateInPoint() )
            nextMove();
    }
}

void nextMove(){
//    waitMs(2000);
    element move;
    switchToNextMove(&robot_queue);

    move = getElement(&robot_queue);
    if ( move.type == FORWARD ){
        robot.left_motor_pos=0;
        robot.right_motor_pos=0;
        robot.left_motor_target = move.value;
        robot.right_motor_target = move.value;
    }

    if (move.type == ROTATE){
        robot.rotation_target = move.value;
    }

}

uint8_t goForward(rotation_sensor_source rot_sensor){
    int left;
    int left_diff;
    int right;
    int right_diff;
    int correction; 

    left = getTranslation(LEFT_MOTOR); 
    right = getTranslation(RIGHT_MOTOR); 
    left_diff = robot.left_motor_target - robot.left_motor_pos;
    right_diff = robot.right_motor_target - robot.right_motor_pos;

    correction = getRotation(rot_sensor);

//    if( ( inRange(left,0 ,PWM_DELTA))   && \
//        ( inRange(right,0,PWM_DELTA))   && \
//        ( inRange(left_diff,0,POSITION_DELTA)) && \
//        ( inRange(right_diff,0,POSITION_DELTA)) ){

    if( ( inRange(left_diff,0,POSITION_DELTA)) && \
        ( inRange(right_diff,0,POSITION_DELTA)) ){
        stopMotors();
        return 1;

    }else{
        if (correction < 0 ){
            setRightMotorSigned( right-correction );
            setLeftMotorSigned ( left  );
        }else{
            setRightMotorSigned( right );
            setLeftMotorSigned ( left+correction  );
        }
        return 0;
    }
}


uint8_t rotateInPoint(){
    int rotation; 
    int rotation_diff;

    rotation = getRotationInPoint();
    rotation_diff = robot.rotation_target - robot.rotation;

    if( ( inRange(rotation,0 ,ANGLE_DELTA)) && ( inRange(rotation_diff,0,ANGLE_DELTA))){ 
        stopMotors();
            USART3_transmitString(itoa((int) rotation, buf,10));
            USART3_transmitString(" ");
            USART3_transmitString(itoa((int) rotation_diff, buf,10));
            USART3_transmitString("\n");
        return 0;
    }else{
        setLeftMotorSigned(rotation);
        setRightMotorSigned(-rotation);
        return 0;
    }
}
