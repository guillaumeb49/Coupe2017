/*
 * drv_HardConf.h
 *
 *  Created on: May 20, 2016
 *      Author: mario
 */

#ifndef D_GPIO_H_
#define D_GPIO_H_

#include "common.h"

void Init_GPIO(void);
void Set_led_blue(int);
void Set_led_green(int);
void Set_led_red(int);
void Set_led_orange(int);
int Get_led_blue(void);
int Get_led_green(void);
int Get_led_red(void);
int Get_led_orange(void);
int Get_btn(void);

#endif /* D_GPIO_H_ */
