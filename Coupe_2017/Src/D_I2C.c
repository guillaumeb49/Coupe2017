/*
 * D_I2C.c
 *
 *  Created on: 14 juil. 2016
 *      Author: Guillaume BITAUD
 */

#include "D_I2C.h"

/**
 * @brief Initialize the I2C1 peripheral Master mode
 * Wiring :
 * 	- PB6	: I2C1_SCL
 * 	- PB9	: I2C1_SDA
 *
 */
void Init_I2C1(void)
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;	// Init GPIO port B
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;		// Init I2C1 peripheral

	// Configure GPIO
	GPIOB->MODER &= ~(GPIO_MODER_MODER6 | GPIO_MODER_MODER9);
	GPIOB->MODER |= GPIO_MODER_MODER6_1 | GPIO_MODER_MODER9_1;
	GPIOB->AFR[0]&= ~(0xFF << 24);
	GPIOB->AFR[0]|=  (4 << 24);
	GPIOB->AFR[1]&= ~(0xFF << 4);
	GPIOB->AFR[1]|=  (4 << 4);

	// Configure I2C mode Master
	I2C1->CR2 &= ~I2C_CR2_FREQ;
	I2C1->CR2 |= 0x16;						//	16 MHz peripheral frequency
	I2C1->CCR |= I2C_CCR_FS | I2C_CCR_DUTY;	// Fast mode | Duty cycle tlow/thigh = 16/9
	I2C1->CCR &= ~I2C_CCR_CCR;
	I2C1->CCR |= 0x2;						// SCL clock = 320 KHz
	I2C1->CR1 |= I2C_CR1_PE;

}


/**
 * @brief
 *
 * @param[in]
 * @param[in]
 * @return
 *
 */
E_I2C_Status Write_I2C1(uint8_t *tab_to_send, uint8_t size)
{
	E_I2C_Status status = E_I2C_Status_ERROR;	// Init return value to error



	return status;
}


/**
 * @brief
 * @param[in] address of the slave
 * @param[in] dir	Direction (0 : read, 1 write)
 * @return
 *
 */
E_I2C_Status Send_addr_I2C1(uint8_t address, uint8_t dir)
{
	E_I2C_Status status = E_I2C_Status_ERROR;
	I2C1->DR = (address << 1) | (dir & 0x01);

	return status;
}
