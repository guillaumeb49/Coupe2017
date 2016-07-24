/*
 * D_PWM.c
 *
 *  Created on: 11 juil. 2016
 *      Author: Guillaume BITAUD
 *
 *
 */

#include "D_PWM.h"

/**
 * @brief Initialize the PWM connected to Motor D
 *
 * Wiring : PE11(TIM1 CH2)	: Command motor D channel B
 * 			PE13(TIM1 CH3)	: Command motor D channel A
 *
 */
void InitPWMMotorD(void)
{
	// Init GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN; // Port E : clock enable

	GPIOE->MODER &= ~(GPIO_MODER_MODER11);	// PE11: Alternate --> Command motor D channel B
	GPIOE->MODER |=  (0x02 << 22);
	GPIOE->MODER &= ~(GPIO_MODER_MODER13);	// PE13: Alternate --> Command motor D channel A
	GPIOE->MODER |=  (0x02 << 26);

	GPIOE->AFR[1] &= ~(0x0F << 12);	// AF1 on PE11--> Timer 1 channel 2 --> PWM motor D channel A
	GPIOE->AFR[1] |=  (1    << 12);
	GPIOE->AFR[1] &= ~(0x0F << 20);	// AF1 on PE13--> Timer 1 channel 3 --> PWM motor D channel B
	GPIOE->AFR[1] |=  (1    << 20);


	// Init Timer 1 CH2
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;	// Enable clock on timer 1
	TIM1->PSC = 3;	// Prescaler

	TIM1->ARR = 1000 - 1;	// Approximatlty 25 KHz (PWM Frequency)

	TIM1->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;	// PWM mode 1 upcounting
	TIM1->CCMR1 &= ~TIM_CCMR1_OC2M_0;

	TIM1->CCMR1 |= TIM_CCMR1_OC2PE;	// Preload Enable
	TIM1->CCMR1 &= ~TIM_CCMR1_CC2S;	// Output
	TIM1->CCER 	|= TIM_CCER_CC2E;	// Channel is ON
	TIM1->CR1 	|= TIM_CR1_ARPE;	// Auto reload
	TIM1->EGR 	|= TIM_EGR_UG;		// Reinitialize the counter
	TIM1->SR 	&= TIM_SR_UIF;		// Clear update interrupt flag
	TIM1->BDTR 	|= TIM_BDTR_MOE;	// Main output Enable


	TIM1->CCR2 = 0; 	// Set duty cycle to 0%

	// Init Timer 1 CH3
	TIM1->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;	// PWM mode 1 upcounting
	TIM1->CCMR2 &= ~TIM_CCMR2_OC3M_0;

	TIM1->CCMR2 |= TIM_CCMR2_OC3PE;	// Preload Enable
	TIM1->CCMR2 &= ~TIM_CCMR2_CC3S;	// Output
	TIM1->CCER 	|= TIM_CCER_CC3E;	// Channel is ON

	TIM1->CCR3 = 0; 	// Set duty cycle to 0%

	// Start Timer 1
	TIM1->CR1 |= TIM_CR1_CEN;
}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorD(int new_pwm_value)
{

}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorD_chA(float new_cha_value)
{
	TIM1->CCR2 = (int)new_cha_value*10; 	// Set duty cycle to 0%
}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorD_chB(float new_chb_value)
{
	TIM1->CCR3 = (int) new_chb_value*10; 	// Set duty cycle to 0%
}




/**
 * @brief Initialize the PWM connected to Motor G
 *
 * Wiring : PB7(TIM4 CH2)	: Command motor D channel A
 * 			PB8(TIM4 CH3)	: Command motor D channel B
 *
 */
void InitPWMMotorG(void)
{
	// Init GPIO
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; // Port B : clock enable

	GPIOB->MODER &= ~(GPIO_MODER_MODER7);	// PB7: Alternate --> Command motor G channel A
	GPIOB->MODER |=  (0x02 << 14);
	GPIOB->MODER &= ~(GPIO_MODER_MODER8);	// PB8: Alternate --> Command motor G channel B
	GPIOB->MODER |=  (0x02 << 16);

	GPIOB->AFR[0] &= ~(0x0F << 28);	// AF1 on PB7--> Timer 4 channel 2 --> PWM motor G channel A
	GPIOB->AFR[0] |=  (2    << 28);
	GPIOB->AFR[1] &= ~(0x0F << 0);	// AF1 on PB8--> Timer 4 channel 3 --> PWM motor G channel B
	GPIOB->AFR[1] |=  (2    << 0);


	// Init Timer 4 CH2
	RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;	// Enable clock on timer 1
	TIM4->PSC = 3;	// Prescaler

	TIM4->ARR = 1000 - 1;	// Approximatlty 25 KHz (PWM Frequency)

	TIM4->CCMR1 |= TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2;	// PWM mode 1 upcounting
	TIM4->CCMR1 &= ~TIM_CCMR1_OC2M_0;

	TIM4->CCMR1 |= TIM_CCMR1_OC2PE;	// Preload Enable
	TIM4->CCMR1 &= ~TIM_CCMR1_CC2S;	// Output
	TIM4->CCER 	|= TIM_CCER_CC2E;	// Channel is ON
	TIM4->CR1 	|= TIM_CR1_ARPE;	// Auto reload
	TIM4->EGR 	|= TIM_EGR_UG;		// Reinitialize the counter
	TIM4->SR 	&= TIM_SR_UIF;		// Clear update interrupt flag
	TIM4->BDTR 	|= TIM_BDTR_MOE;	// Main output Enable


	TIM4->CCR2 = 0; 	// Set duty cycle to 0%

	// Init Timer 4 CH3
	TIM4->CCMR2 |= TIM_CCMR2_OC3M_1 | TIM_CCMR2_OC3M_2;	// PWM mode 1 upcounting
	TIM4->CCMR2 &= ~TIM_CCMR2_OC3M_0;

	TIM4->CCMR2 |= TIM_CCMR2_OC3PE;	// Preload Enable
	TIM4->CCMR2 &= ~TIM_CCMR2_CC3S;	// Output
	TIM4->CCER 	|= TIM_CCER_CC3E;	// Channel is ON

	TIM4->CCR3 = 0; 	// Set duty cycle to 0%

	// Start Timer 1
	TIM4->CR1 |= TIM_CR1_CEN;
}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorG(int new_pwm_value)
{

}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorG_chA(float new_cha_value)
{
	TIM4->CCR2 = (int)new_cha_value*10; 	// Set duty cycle to 0%
}

/**
 *	@param[in] new_pwm_value new Duty cycle value in percentage %
 */
void F_SetPWMMotorG_chB(float new_chb_value)
{
	TIM4->CCR3 = (int)new_chb_value*10; 	// Set duty cycle to 0%
}
