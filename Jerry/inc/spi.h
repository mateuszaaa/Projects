#ifndef SPI_H
#define SPI_H
#include"defines.h"

//PA5 - SCK AF5
//PA6 - MISO AF5
//PA7 - MOSI AF5
//PE3 - SPI SS
void initSPI1();
uint8_t SPI1_read(uint8_t subaddress);
void SPI1_write(uint8_t subaddress,uint8_t data);
void waitForFreeBusSPI1();

void initSPI2();
uint8_t SPI2_read(uint8_t subaddress);
void SPI2_write(uint8_t subaddress,uint8_t data);
void waitForFreeBusSPI2();

#endif
