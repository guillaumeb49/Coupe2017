/*
 * D_SysTick.c
 *
 *  Created on: 24 juil. 2016
 *      Author: Guillaume BITAUD
 */

#include "D_SysTick.h"

/**
 *	@brief Initialie SysTick to generate an interruption every second
 */
void Init_SysTick()
{
	// Program reload value.
	SysTick->LOAD = 600000;

	// Clear current value.
	SysTick->VAL = 0;

	// Program Control and Status register.
	SysTick->CTRL &= ~(SysTick_CTRL_COUNTFLAG_Msk | SysTick_CTRL_CLKSOURCE_Msk |
						SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk);
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;

	NVIC_SetPriority(SysTick_IRQn, 0);	// Maximum priority

	NVIC_EnableIRQ(SysTick_IRQn);		// Enable Interrupt



}

void F_Start_SysTick()
{
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

void F_Stop_SysTick()
{
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}


