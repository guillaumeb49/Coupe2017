/*
 * drv_HardConf.h
 *
 *  Created on: May 20, 2016
 *      Author: mario
 */

#ifndef D_GPIO_H_
#define D_GPIO_H_

#include "common.h"

void init_GPIO(void);
void set_led_blue(int);
void set_led_green(int);
void set_led_red(int);
void set_led_orange(int);
int get_led_blue(void);
int get_led_green(void);
int get_led_red(void);
int get_led_orange(void);
int get_btn(void);

#endif /* D_GPIO_H_ */
