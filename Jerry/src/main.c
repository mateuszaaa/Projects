#include <stdio.h>
#include "defines.h"
#include "led.h"
#include "buttons.h"
#include "pwm.h"
#include "usart.h"
#include "spi.h"
#include "pwm.h"
#include "robot.h"
#include "pid.h"
#include "delay.h"
#include "i2c.h"
#include "timer.h"
#include "gyro.h"
#include "encoder.h"
#include "itoa.h"
#include "adc.h"
#include "ir_sensors.h"
#include "stack.h"

uint8_t usart_data;

uint8_t isBatteryWeak(){
    int battery;
   ADC1PrepareSingleMeasure(BATTERY);
   battery = ADC1SingleMeasure();
   return 0;
}

void blinkLed(){
    while(1){
        LED_ON;
        waitMs(50);
        LED_OFF;
        waitMs(50);
    }
}

int main(void)
{
    int pwm;
    int adc_on;
    int adc_off;
    uint16_t i;
    element elem;

    robot.rotation_target = 0;
    robot.right_motor_pos =0;
    robot.left_motor_pos =0;
    robot.right_motor_target =0;
    robot.left_motor_target =0;
	SysTick_Config(168000000/8/1000000); // interrupr 1000000 per secound

    
   initTimer3(1);
   initMotors();
   initEncoders();
   initUsart3();
//   enableUSART3RXNEInterrupt();
   initADC();
   initIRSensors();
   initLED();
   initSPI2();

   LED_OFF;
   waitMs(1000);
   LED_ON;

   initPIDStructures();
   stopMotors();
   resetEncoders();
   updateRobotState();
   robot.left_ir_sensor_target = measures.left_ir_sensor;
   robot.right_ir_sensor_target = measures.right_ir_sensor;

   initQueue(&robot_queue);
   //addMove(&robot_queue,FORWARD,2000);
   addMove(&robot_queue,ROTATE,20000);
//   addMove(&robot_queue,FORWARD,9000);
//   addMove(&robot_queue,ROTATE,0);
//   addMove(&robot_queue,ROTATE,6000);
//   addMove(&robot_queue,FORWARD,9000);
//   addMove(&robot_queue,ROTATE,6000);
//   addMove(&robot_queue,ROTATE,12000);
//   addMove(&robot_queue,FORWARD,9000);
//   addMove(&robot_queue,ROTATE,12000);
//   addMove(&robot_queue,ROTATE,3000);
//   nextMove();
   

   LED_ON;
    while(1)
    {
        if ( isBatteryWeak() ){
            stopMotors();
            blinkLed();
        }
        if (flags.update_robot == 1){
            moveRobot();
            updateRobotState(); 
            flags.update_robot =0;
        }

        if (flags.usart_custom == 1){


            USART3_transmitString(itoa((int) robot.rotation, buf,10));
            USART3_transmitString(" ");
            USART3_transmitString(itoa((int) robot.rotation_target, buf,10));
            USART3_transmitString("\n");


        }
    }
//        flags.usart_custom == 0;
//        USART3_transmitString("lewe_kolo_diff ");
//        USART3_transmitString(itoa((int) robot.left_motor_target - robot.left_motor_pos , buf,10));
//        USART3_transmitByte('\n');
//        USART3_transmitString("lewe kolo pwm ");
//        USART3_transmitString(itoa((int) getTranslation(LEFT_MOTOR) , buf,10));
//        USART3_transmitByte('\n');
//    
//        USART3_transmitString("prawe kolo diff ");
//        USART3_transmitString(itoa((int) robot.right_motor_target - robot.right_motor_pos , buf,10));
//        USART3_transmitByte('\n');
//        USART3_transmitString("prawe kolo pwm ");
//        USART3_transmitString(itoa((int) getTranslation(RIGHT_MOTOR) , buf,10));
//        USART3_transmitByte('\n');
//    }
//
//    if (flags.usart_graph == 1){
//        static uint8_t usart_start = 1;
//        if (usart_start ){
//            usart_start=0;
//            USART3_transmitString("\n");
//            USART3_transmitString("\n");
//            USART3_transmitString("\n");
//            USART3_transmitString("__start__\n");
//            USART3_transmitString("lewe_kolo_pozycja ");
//            USART3_transmitString("lewe_kolo_cel ");
//            USART3_transmitString("lewe_kolo_diff ");
//            USART3_transmitString("lewe_kolo_pwm_T ");
//            USART3_transmitString("prawe_kolo_pozycja ");
//            USART3_transmitString("prawe_kolo_cel ");
//            USART3_transmitString("prawe_kolo_diff ");
//            USART3_transmitString("prawe_kolo_pwm_T \n");
//            USART3_transmitString(" \n");
//        }
//
//        USART3_transmitString(itoa((int) robot.right_motor_pos , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) robot.right_motor_target , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) robot.right_motor_target - robot.right_motor_pos , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) getTranslation(RIGHT_MOTOR) , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) robot.left_motor_pos , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) robot.left_motor_target , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) robot.left_motor_target - robot.left_motor_pos , buf,10));
//        USART3_transmitString(" ");
//        USART3_transmitString(itoa((int) getTranslation(LEFT_MOTOR) , buf,10));
//        USART3_transmitByte('\n');
//        flags.usart_graph = 0;
//    }
//    }
//


return 0;
}

void TIM3_IRQHandler(){ TIM3->SR &= ~(TIM_SR_UIF);
    static int x=0;
    flags.update_robot = 1;
    if (x<300)
        x++;
    else{
        x=0;
        flags.usart_custom = 1;
    }
    flags.usart_graph = 0;
}

void USART3_IRQHandler(){
    static uint8_t flag=1;
    usart_data = USART3->DR;
    flags.usart_data_recived = 1;
    if (flag){
        LED_ON;
    }else{
        LED_OFF;
    }
    flag = !flag;
    
    
}

void TIM1_UP_TIM10_IRQHandler(){
    TIM1->SR &= ~(TIM_SR_UIF);
}

