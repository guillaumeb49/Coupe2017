/*
 * D_SysTick.h
 *
 *  Created on: 24 juil. 2016
 *      Author: Guillaume BITAUD
 */

#ifndef D_SYSTICK_H_
#define D_SYSTICK_H_

#include "stm32f4xx.h"

void Init_SysTick();
void F_Start_SysTick();
void F_Stop_SysTick();

#endif /* D_SYSTICK_H_ */
