/*
 * D_TIMER.c
 *
 *  Created on: 22 juil. 2016
 *      Author: guill
 */


#include "D_TIMER.h"


/**
 * @brief Initialize Timer 9
 * Timer 9 : Interruption on overflow every 5 ms
 */
void Init_Timer9()
{

	RCC->APB2ENR |= RCC_APB2ENR_TIM9EN;


	TIM9->CR1 |= TIM_CR1_ARPE;

	TIM9->PSC = 2400-1;	// Prescaler value 239+1 = 240 ====> 24MHz /  240 = 100 KHz

	TIM9->ARR = 100-1;

	TIM9->DIER |= TIM_DIER_UIE;	// Enable interrupt

	NVIC_EnableIRQ(TIM1_BRK_TIM9_IRQn);


	TIM9->CR1 |= TIM_CR1_CEN;

}
