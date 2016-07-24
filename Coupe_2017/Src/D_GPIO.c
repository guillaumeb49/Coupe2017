/*
 * drv_HardConf.c
 *
 *  Created on: May 20, 2016
 *      Author: mario
 */
#include "D_GPIO.h"

void init_GPIO(void){

	// ######### Configuring Clocks  #########
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN; // Port A : clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Port B : clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // Port C : clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN; // Port D : clock enable
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; // Port E : clock enable
	// ######### Configuring Pin direction #########
	// PORT A
	GPIOA->MODER &= ~(0<<0*2);	// PA0 : input  --> on bard BP
	GPIOA->MODER &= ~(0<<1*2);	// PA1 : input  --> Sensor motor D channel B
	GPIOA->MODER &= ~(0<<15*2);	// PA15: input  --> Sensor motor D channel A
	// PORT B
	GPIOB->MODER &= ~(0<<4*2);	// PB4 : input  --> Sensor motor G channel A
	GPIOB->MODER &= ~(0<<5*2);	// PB5 : input  --> Sensor motor G channel B

	// PORT C
	GPIOC->MODER |= (1<<6*2);	// PC6 : output --> led 5
	GPIOC->MODER |= (1<<8*2);	// PC8 : output --> led 6
	GPIOC->MODER |= (1<<9*2);	// PC9 : output --> led 7
	GPIOC->MODER |= (1<<11*2);	// PC11: output --> led 8
	// PORT D
	GPIOD->MODER |= (1<<15*2);	// PD15: output --> on board led
	GPIOD->MODER |= (1<<14*2);	// PD14: output --> on board led
	GPIOD->MODER |= (1<<13*2);	// PD13: output --> on board led
	GPIOD->MODER |= (1<<12*2);	// PD12: output --> on board led
	GPIOD->MODER &= ~(0<<7*2);	// PD7 : input  --> Jack
	// PORT E
	GPIOE->MODER |= (1<<6*2);	// PE6 : output --> Enable motor G
	GPIOE->MODER |= (1<<7*2);	// PE7 : output --> Enable motor D
	GPIOE->MODER &= ~(0<<8*2);	// PE8 : input  --> Sensor motor D channel Z
	GPIOE->MODER &= ~(0<<9*2);	// PE9 : input  --> Sensor motor G channel Z

	// ######### Configuring Speed  #########

	// ######### Configuring Alternate Function #########
	// PORT B
	// PORT A
	GPIOA->AFR[0] |= (0b0001<<4*1);	// AF1 on PA1 --> Timer 2 channel 2 --> QEI motor D channel B
	GPIOA->AFR[1] |= (0b0001<<4*7);	// AF1 on PA15--> Timer 2 channel 1 --> QEI motor D channel A
	// PORT B
	GPIOB->AFR[0] |= (0b0010<<4*4);	// AF2 on PB4 --> Timer 3 channel 1 --> QEI motor G channel A
	GPIOB->AFR[0] |= (0b0010<<4*5);	// AF2 on PB5 --> Timer 3 channel 2 --> QEI motor G channel B
}

void set_led_red(int state){
	(state) ? (GPIOD->ODR |= LED_RED_1) : (GPIOD->ODR &= ~LED_RED_1) ;
}

void set_led_orange(int state){
	(state) ? (GPIOD->ODR |= LED_ORANGE) : (GPIOD->ODR &= ~LED_ORANGE) ;
}

void set_led_green(int state){
	(state) ? (GPIOD->ODR |= LED_GREEN_1) : (GPIOD->ODR &= ~LED_GREEN_1) ;
}

void set_led_blue(int state){
	(state) ? (GPIOD->ODR |= LED_BLUE) : (GPIOD->ODR &= ~LED_BLUE) ;
}

int get_led_red(void){
	int boul;
	return boul;
}
int get_led_orange(void){
	int boul;

	return boul;
}
int get_led_green(void){
	int boul;

	return boul;
}
int get_led_blue(void){
	int boul;

	return boul;
}

int get_btn(void){
	int boul=0;
	(GPIOA->IDR & BP) ? (boul=1) : (boul=0) ;
	return boul;
}
