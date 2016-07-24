/*
 * D_I2C.h
 *
 *  Created on: 14 juil. 2016
 *      Author: Guillaume BITAUD
 */

#ifndef D_I2C_H_
#define D_I2C_H_

#include "stm32f4xx.h"

typedef enum E_I2C_Status
{
	E_I2C_Status_OK = 0,
	E_I2C_Status_NAK = 1,
	E_I2C_Status_ERROR = 2
}E_I2C_Status;



void Init_I2C1(void);
E_I2C_Status Write_I2C1(uint8_t *tab_to_send, uint8_t size);



#endif /* D_I2C_H_ */
