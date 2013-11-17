#include "ir_sensors.h"

void initIRSensors(){
    //init pins used to controle IR diode light
RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN;

//  PB6
GPIOB->MODER |= GPIO_MODER_MODER6_0;//output

//  PB4
GPIOB->MODER |= GPIO_MODER_MODER4_0;//output

//  PD2
GPIOD->MODER |= GPIO_MODER_MODER2_0;//output

//  PC12
GPIOC->MODER |= GPIO_MODER_MODER12_0;//output

}

int getMeasureIR(uint8_t sensor){
    int adc;

    ADC1PrepareSingleMeasure(sensor);
    SENSOR1_ENABLE;
    waitUs(IR_MEASURE_US_DELAY);
    adc = ADC1SingleMeasure();
    SENSOR1_DISABLE;
    waitUs(IR_MEASURE_US_DELAY);


    return adc;
}
