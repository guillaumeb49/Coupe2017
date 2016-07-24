/*
 * event.h
 *
 *  Created on: 24 juil. 2016
 *      Author: guill
 */

#ifndef EVENT_H_
#define EVENT_H_

#include <stm32f4xx.h>

extern volatile uint32_t hundred_ms_from_start;

// SysTick delay (100 ms)
void F_Delay_Systick(uint32_t delay_hundred_ms);

#endif /* EVENT_H_ */
