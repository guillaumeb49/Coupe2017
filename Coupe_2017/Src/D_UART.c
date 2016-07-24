/*
 * D_UART.c
 *
 *  Created on: 13 juil. 2016
 *      Author: Guillaume BITAUD
 *
 * USART Driver
 * Redefine GNU putchar and getchar to be used by the printf function
 */

#include "D_UART.h"

/**
 * @brief Initialize the USART2 peripheral
 *
 * Initializing USART2 at the specified baudrate
 * The main clock feeding peripheral is 50 MHz (so 50MHz / 8 for APB clock)
 * Wiring :
 *   - PA2 : Tx
 *   - PA3 : Rx
 */
void Init_UART2(long bauds)
{

	// Enable peripheral clocks
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;	// GPIOA
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;	// USART 2

	// Configure GPIO PA2(Tx) & PA3(Rx)
	GPIOA->MODER  &= ~(GPIO_MODER_MODER2 | GPIO_MODER_MODER3);
	GPIOA->MODER  |= (GPIO_MODER_MODER2_1| GPIO_MODER_MODER3_1);
	GPIOA->AFR[0] &= ~(0xFF << 8);
	GPIOA->AFR[0] |=  (0x77 << 8);	// Alternate function 7

	//USART1 initialization settings
	UART_HandleTypeDef uart;

	uart.Instance = USART2;
	uart.Init.BaudRate = bauds;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.Mode = UART_MODE_TX_RX;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	HAL_UART_Init(&uart);
	USART2->CR1 |= USART_CR1_UE | USART_CR1_TE | USART_CR1_RE;
}



/**
  * @brief  Retargets the C library printf function to the USART (GNU)
  * @param[in] character to send
  * @return character sent
  */
int __io_putchar(int ch)
{
	USART2->DR = ch;
	// Loop while character not sent
	while(!(USART2->SR & USART_SR_TXE));
	USART2->SR &= ~USART_SR_TXE;
	return(ch);
}

//******************************************************************************

/**
  * @brief  Retargets the C library scanf function to the USART (GNU)
  * @param  None
  * @return character received
  */
int __io_getchar(void)
{

  // Loop until the reception buffer is not empty
  while(!(USART2->SR & USART_SR_RXNE));

  return((int)USART2->DR);
}
