#ifndef DEFINES_H
#define DEFINES_H

#include "stm32f4xx.h"

/*-----------------------------------------------------------------------------
 *  LEDS MACRO
 *-----------------------------------------------------------------------------*/
#define LED          (1<<15)
#define LED_ON       GPIOA-> ODR &= ~LED //RESET
#define LED_OFF      GPIOA-> ODR |= LED //Set

/*-----------------------------------------------------------------------------
 * TB6612  
 *-----------------------------------------------------------------------------*/
#define AIN1            (1<<2)
#define AIN2            (1<<1)
 
#define AIN1_SET        GPIOC-> ODR |= AIN1 //Set 
#define AIN1_RESET      GPIOC-> ODR &= ~AIN1
#define AIN2_SET        GPIOC-> ODR |= AIN2 //Set 
#define AIN2_RESET      GPIOC-> ODR &= ~AIN2

#define BIN1            (1<<3)
#define BIN2            (1<<2)

#define BIN1_SET        GPIOA-> ODR |= BIN1 //Set 
#define BIN1_RESET      GPIOA-> ODR &= ~BIN1
#define BIN2_SET        GPIOA-> ODR |= BIN2 //Set 
#define BIN2_RESET      GPIOA-> ODR &= ~BIN2

/*-----------------------------------------------------------------------------
 *  L3GD20 SPI
 *-----------------------------------------------------------------------------*/
#define L3GD20              (1<<12)
#define L3GD20_CS_HIGH  	GPIOB-> ODR |= L3GD20 //Set
#define L3GD20_CS_LOW	    GPIOB-> ODR &= ~L3GD20 //RESET
/*-----------------------------------------------------------------------------
 *  L3GD20 ADRESSESS
 *-----------------------------------------------------------------------------*/
#define L3GD20_OFFSET       64
#define L3GD20_WHOAMI		0x0f
#define L3GD20_READ			(1<<7)
#define L3GD20_WRITE		(0<<7)
#define L3GD20_CTRL1		0x20	
#define L3GD20_OUT_Z_H		0x2D	
#define L3GD20_OUT_Z_L		0x2C	
	
/*-----------------------------------------------------------------------------
 * MOTORS MACROS
 *-----------------------------------------------------------------------------*/
#define FRONT_DIR            1
#define BACK_DIR             0
#define MOTOR_MAX            1000
#define MAX_TRANSLATION      300
#define MAX_ROTATION         100


/*-----------------------------------------------------------------------------
 *  VCNL4020
 *-----------------------------------------------------------------------------*/


#define VCNL4020_ADDRESS        0x13
#define VCNL4020_READ_BIT       1
#define VCNL4020_WRITE_BIT      0
#define VCNL4020_WHOAMI         0x81

/*---------------------------------------------------------------------------
 *  IR SENSORS
 *---------------------------------------------------------------------------*/

#define SENSOR1             (1<<6) 
#define SENSOR1_ENABLE      GPIOB-> ODR |=  SENSOR1 //Set
#define SENSOR1_DISABLE     GPIOB-> ODR &= ~SENSOR1 //Reset

#define SENSOR2             (1<<4) 
#define SENSOR2_ENABLE      GPIOB-> ODR |=  SENSOR2 //Set
#define SENSOR2_DISABLE     GPIOB-> ODR &= ~SENSOR2 //Reset

#define SENSOR3             (1<<2) 
#define SENSOR3_ENABLE      GPIOD-> ODR |=  SENSOR3 //Set
#define SENSOR3_DISABLE     GPIOD-> ODR &= ~SENSOR3 //Reset

#define SENSOR4             (1<<12) 
#define SENSOR4_ENABLE      GPIOC-> ODR |=  SENSOR4 //Set
#define SENSOR4_DISABLE     GPIOC-> ODR &= ~SENSOR4 //Reset

#define IR_FRONT_LEFT           4 
#define IR_FRONT_RIGHT          0 
#define BATTERY                 8 

#define IR_MEASURE_US_DELAY     1

#define DELTA_TIME              1

static __IO uint32_t delay_counter;

typedef struct s_my_flags{
    uint8_t ir_sensors_read;
    uint8_t update_robot;
    uint8_t usart_graph;
    uint8_t usart_custom;
    uint8_t usart_data_recived; 
}my_flags;

typedef struct s_my_measures{
    int angle_speed;
    int angle_speed_last;
    int right_motor_last_pos;
    int16_t right_motor_current_pos;
    int left_motor_last_pos;
    int16_t left_motor_current_pos;
    int left_front_ir_sensor;
    int right_front_ir_sensor;
    int left_ir_sensor;
    int right_ir_sensor;
}my_measures;

typedef struct s_robot_state{
    int rotation;
    int rotation_target;

    int right_motor_target;
    int right_motor_pos;

    int left_motor_target;
    int left_motor_pos;

    int left_ir_sensor_target;
    int right_ir_sensor_target;
}robot_state;

typedef struct s_pid{
    float P;
    float I;
    float D;
    float error;
    float last_error;
}pid;

typedef struct s_pid_gains{
    float KP;
    float KI;
    float KD;
}pid_gains;

pid left_translation;
pid right_translation;
pid rotation_ir;
pid rotation_gyro;
pid rotation_encoders;
pid rotation_in_point;

pid_gains gains_translation;
pid_gains gains_rotation_in_point;
pid_gains gains_rot_ir;
pid_gains gains_rot_encoders;
pid_gains gains_rot_gyro;

volatile my_flags flags;
volatile my_measures measures;
volatile robot_state robot;

char buf[10];
#endif
