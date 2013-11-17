#include "spi.h"
void initSPI2()
{
    // SCK - PB13
    // MISO - PB14
    // MOSI - PB15
	// clock for port  d
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;// clock for spi2

	//PB13 - SCK AF5
	GPIOB->MODER |= GPIO_MODER_MODER13_1; //alternate function
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR13_1; // 50 Mhz
	GPIOB->AFR[1]|= (5<<20);

	//PB14 - MISO AF5
	GPIOB->MODER |= GPIO_MODER_MODER14_1; //alternate function
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14_1; // 50 Mhz
	GPIOB->AFR[1]|= (5<<24);

	//PB15 - MOSI AF5
	GPIOB->MODER |= GPIO_MODER_MODER15_1; //alternate function
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR15_1; // 50 Mhz
	GPIOB->AFR[1]|= (5<<28);

	//PB12 - SPI NSS
	GPIOB->MODER |= GPIO_MODER_MODER12_0; //output mode
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR12_1; // 50 Mhz

	SPI2 -> CR1 |= SPI_CR1_MSTR;		//Master mode
	SPI2 -> CR1 |= SPI_CR1_BR_0 | SPI_CR1_BR_1; // baud rate control
	SPI2 -> CR1 |= SPI_CR1_DFF; // 16bit 
	SPI2 -> CR1 |= SPI_CR1_CPOL;
	SPI2 -> CR1 |= SPI_CR1_CPHA;

	SPI2 -> CR1 |= SPI_CR1_SSM;
	SPI2 -> CR1 |= SPI_CR1_SSI;

	SPI2 -> CR1 |= SPI_CR1_SPE; //włączenie SPI

    SPI2_write(0x20,0b00001100); // enable only Z
    SPI2_write(0x20,0b00001100); // enable only Z 


    SPI2_write(0x23,0b00110000); // enable only Z
    SPI2_write(0x23,0b00110000); // enable only Z

}

uint8_t SPI2_read(uint8_t subaddress){
	// fitted value for spi (read bit itd)
	uint16_t spi_register;
	spi_register = ((subaddress | L3GD20_READ)<< 8); //
    
    L3GD20_CS_LOW;

    SPI2->DR = spi_register;
	while (!(SPI2->SR & SPI_SR_TXE));	//Wait if TXE cleared, Tx FIFO is full.
	while (!(SPI2->SR & SPI_SR_RXNE));	//Wait if RNE cleared, Rx FIFO is empty.
	spi_register = SPI2->DR;
waitForFreeBusSPI2();
    L3GD20_CS_HIGH;

	return spi_register & 0xff;
}


void SPI2_write(uint8_t subaddress,uint8_t data){
	// fitted value for spi (read bit itd)
	uint16_t spi_register;

    L3GD20_CS_LOW;

	spi_register = ((subaddress | L3GD20_WRITE)<< 8) | data; //
    SPI2->DR = spi_register;
	while (!(SPI2->SR & SPI_SR_TXE));	//Wait if TXE cleared, Tx FIFO is full.
	while (!(SPI2->SR & SPI_SR_BSY));
    waitForFreeBusSPI2();
    L3GD20_CS_HIGH;
}

void waitForFreeBusSPI2(){
	while(SPI2->SR & SPI_SR_BSY);   //WAIT FOR FREE BUS
}
