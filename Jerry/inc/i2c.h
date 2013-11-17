#ifndef I2C_H
#define I2C _H
#include"defines.h"
//I2C1
// SCL PB6
// SDA PB7
void initI2C1();
uint8_t getRegisterByI2C1(uint8_t address,uint8_t subaddress);
void setRegisterByI2C1(uint8_t address,uint8_t subaddress,uint8_t data);

void waitForFreeBusI2C1();
#endif
