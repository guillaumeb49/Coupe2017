/*
 * D_PWM.h
 *
 *  Created on: 11 juil. 2016
 *      Author: guill
 */

#ifndef D_PWM_H_
#define D_PWM_H_

#include <stm32f4xx.h>

void InitPWMMotorD(void);
void F_SetPWMMotorD(int new_pwm_value);
void F_SetPWMMotorD_chA(float new_cha_value);
void F_SetPWMMotorD_chB(float new_chb_value);

void InitPWMMotorG(void);
void F_SetPWMMotorG(int new_pwm_value);
void F_SetPWMMotorG_chA(float new_cha_value);
void F_SetPWMMotorG_chB(float new_chb_value);

#endif /* D_PWM_H_ */
