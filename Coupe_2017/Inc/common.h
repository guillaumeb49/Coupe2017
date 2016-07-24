/*
 * common.h
 *
 *  Created on: May 20, 2016
 *      Author: mario
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <D_GPIO.h>
#include <stdio.h>

#include "stm32f4xx.h"
#include "D_QEI.h"
#include "D_PWM.h"
#include "D_UART.h"
#include "D_TIMER.h"

#define LED_RED_1   GPIO_ODR_ODR_14
#define LED_RED_2   GPIO_ODR_ODR_9
#define LED_RED_3   GPIO_ODR_ODR_11
#define LED_GREEN_1 GPIO_ODR_ODR_12
#define LED_GREEN_2 GPIO_ODR_ODR_6
#define LED_GREEN_3 GPIO_ODR_ODR_8
#define LED_BLUE    GPIO_ODR_ODR_15
#define LED_ORANGE  GPIO_ODR_ODR_13

#define BP	        GPIO_IDR_IDR_0

#define PWM_FREQ	200
#define HS_FREQ		180000000


#endif /* COMMON_H_ */
