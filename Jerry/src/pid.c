#include "pid.h"
int calculatePID (int actual ,int target, pid *pid_motor , pid_gains pid_params)
{
    float pid;
	float error = target - actual;
    (*pid_motor).P = error;
    (*pid_motor).I += error;
    (*pid_motor).D = error-(*pid_motor).last_error; 

    
    (*pid_motor).I = limitI( (*pid_motor).I );

	pid = (*pid_motor).P * pid_params.KP + (*pid_motor).I * pid_params.KI + (*pid_motor).D * pid_params.KD;

    (*pid_motor).last_error = error;

    return pid;
}


int limitPWM(int pid){
    //Upper Bound 
    int max = MOTOR_MAX;
	if(pid > max)
		pid = max;

    //Lower Bound 
	if(pid < -max)
		pid = -max;
    return pid;
}

float limitI(float pid){
    //Upper Bound 
	if(pid > MOTOR_MAX)
		pid = MOTOR_MAX;

    //Lower Bound 
	if(pid < -MOTOR_MAX)
		pid = -MOTOR_MAX;
    return pid;
}

void initPIDStructures(){
    gains_rot_gyro.KP = 0.5;   
    gains_rot_gyro.KI = 0.0;  
    gains_rot_gyro.KD = 0.0;  

    gains_rot_encoders.KP = 0.0;   
    gains_rot_encoders.KI = 0.0;  
    gains_rot_encoders.KD = 0.0;  

    gains_rot_ir.KP = 0.0;   
    gains_rot_ir.KI = 0.0;  
    gains_rot_ir.KD = 0.0;  

    gains_translation.KP = 9.36;   
    gains_translation.KI = 0.01;  
    gains_translation.KD = 10.66;  

    gains_rotation_in_point.KP = 0.5;
    gains_rotation_in_point.KI = 0.06;
    gains_rotation_in_point.KD = 1.5;

    measures.right_motor_last_pos = 0; 
    measures.right_motor_current_pos = 0; 
    measures.angle_speed = 0; 
}

