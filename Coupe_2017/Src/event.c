/*
 * event.c
 *
 *  Created on: 22 juil. 2016
 *      Author: guill
 */


#include "event.h"

volatile uint32_t hundred_ms_from_start;


/**
 * System Tick 100 msecond time base
 */
void SysTick_Handler(void)
{
	hundred_ms_from_start++;
	GPIOD->ODR ^= GPIO_ODR_ODR_15;
}

/**
 * Wait for delay_hundred_ms* 100 ms
 */
void F_Delay_Systick(uint32_t delay_hundred_ms)
{
	uint32_t current_time = hundred_ms_from_start;
	uint32_t timeout = current_time + delay_hundred_ms;

	while(current_time < (timeout))
	{
		current_time = hundred_ms_from_start;
	}
}

/**
 * TROUVER le nom de la fonction d'interruption :
 * Regarder dans startup / startup_stm32.s
 */
void TIM1_BRK_TIM9_IRQHandler(void)
{
	if(TIM9->SR & TIM_SR_UIF)
	{
		TIM9->SR &= ~TIM_SR_UIF;
		GPIOD->ODR ^= GPIO_ODR_ODR_13;
	}
}
