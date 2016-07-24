/*
 * event.c
 *
 *  Created on: 22 juil. 2016
 *      Author: guill
 */



#include <stm32f4xx.h>

/**
 * System Tick 1 second time base
 */
void SysTick_Handler(void)
{

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
		GPIOD->ODR ^= GPIO_ODR_ODR_15;
	}
}
