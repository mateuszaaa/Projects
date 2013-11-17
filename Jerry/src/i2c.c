#include "i2c.h"

void initI2C1()
{
	//I2C1
	// SCL PB8
	// SDA PB9
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN;
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;// clock for usart

	//PB8 - SCL AF4
	GPIOB->MODER |= GPIO_MODER_MODER8_1; //alternate function
	GPIOB->OTYPER |= GPIO_OTYPER_OT_8; //open drain
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR8_1; // 50 Mhz
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR8_0;
	GPIOB->AFR[1]|= (4<<0); //AF4

	//PB9 - SDA AF4
	GPIOB->MODER |= GPIO_MODER_MODER9_1; //alternate function
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR9_1; // 50 Mhz
	GPIOB->OTYPER |= GPIO_OTYPER_OT_9; //open drain
	GPIOB->PUPDR |= GPIO_PUPDR_PUPDR9_0;
	GPIOB->AFR[1]|= (4<<4); //AF4


    // Q0 - PB6
	GPIOB->MODER |= GPIO_MODER_MODER6_0;//output

    // Q1 - PB4
	GPIOB->MODER |= GPIO_MODER_MODER4_0;//output

    // Q2 - PD2
	GPIOD->MODER |= GPIO_MODER_MODER2_0;//output

    // Q3 - PC12
	GPIOC->MODER |= GPIO_MODER_MODER12_0;//output

	I2C1->CR2 |= 42;
	I2C1->CCR=178;
	I2C1->TRISE=45;
	I2C1->CR1 = I2C_CR1_PE;

//	LSI302DL_I2C1_ENABLE;

}
void waitForFreeBusI2C1(){
	while((I2C1->SR2 & I2C_SR2_BUSY));   //WAIT FOR FREE BUS
}

uint8_t getRegisterByI2C1(uint8_t address,uint8_t subaddress)
{
	uint8_t read_address = (address << 1) | VCNL4020_READ_BIT;
	uint8_t write_address = (address << 1)| VCNL4020_WRITE_BIT ;
	uint8_t recive_data;

	I2C1->CR1|=I2C_CR1_START; 			//SEND START BIT
	while(!(I2C1->SR1 & I2C_SR1_SB));   //WAIT TILL START BIT APPEAR
	I2C1->DR=write_address;		    	//SEND WRITE ADDRESS
	while(!(I2C1->SR1 & I2C_SR1_ADDR)); //WAIT TILL ADDRESS APPER ON THE LINE
	while(!(I2C1->SR1));				//read SR1 and SR2 to clear ADDR
	while(!(I2C1->SR2));				//should be no errors
	while(!(I2C1->SR1 & I2C_SR1_TXE)); 	//WAIT FOR FREE LINE TO WRITE DATA
	I2C1->DR=subaddress;				//SEND REGISTER ADDRESS
	while( !( I2C1->SR1 & I2C_SR1_BTF ));//CHECK IF TRANSFER IS COMPLETED
	I2C1->CR1|=I2C_CR1_START; 			//REPEAT START BIT SEND AND APPEAR CHECK
    while(!(I2C1->SR1 & I2C_SR1_SB));   //WAIT TILL START BIT APPEAR
	I2C1->DR=read_address;		    	//SEND READ ADDRESS
	while(!(I2C1->SR1 & I2C_SR1_ADDR)); //WAIT TILL ADDRESS APPER ON THE LINE
	while(!(I2C1->SR1));				//read SR1 and SR2 to clear ADDR
	while(!(I2C1->SR2));				//should be no errors
	while(!(I2C1->SR1 & I2C_SR1_RXNE)); //WAIT FOR FREE LINEA TO RECIVE DATA;
	I2C1->CR1 &= ~I2C_CR1_ACK; //to close communication
	recive_data = I2C1->DR & 0xff;
	I2C1->CR1 |= I2C_CR1_STOP;  		//SEND STOP BIT


	return recive_data;
}

void setRegisterByI2C1(uint8_t address,uint8_t subaddress,uint8_t data)
{
	uint8_t write_address = (address << 1) | VCNL4020_WRITE_BIT ;

	I2C1->CR1|=I2C_CR1_START; 			//SEND START BIT
	while(!(I2C1->SR1 & I2C_SR1_SB));   //WAIT TILL START BIT APPEAR
	I2C1->DR=write_address;		    	//SEND WRITE ADDRESS
	while(!(I2C1->SR1 & I2C_SR1_ADDR)); //WAIT TILL ADDRESS APPER ON THE LINE
	while(!(I2C1->SR1));				//read SR1 and SR2 to clear ADDR
	while(!(I2C1->SR2));				//should be no errors
	while(!(I2C1->SR1 & I2C_SR1_TXE)); 	//WAIT FOR FREE LINE TO WRITE DATA
	I2C1->DR=subaddress;				//SEND REGISTER ADDRESS
	while( !(I2C1->SR1 & I2C_SR1_TXE) ); 	//WAIT FOR FREE LINE TO WRITE DATA
	I2C1->DR=data;						//SEND DATA TO REGISTER
	while( !(I2C1->SR1 & I2C_SR1_TXE) ); 	//WAIT FOR FREE LINE TO WRITE DATA
	while( !( I2C1->SR1 & I2C_SR1_BTF ));//CHECK IF TRANSFER IS COMPLETED
	I2C1->CR1 |= I2C_CR1_STOP;  		//SEND STOP BIT
}
