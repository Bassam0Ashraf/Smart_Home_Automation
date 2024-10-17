 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Description: Source file for the PWM driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the Timer Registers */
#include "pwm.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the PWM driver.
 */
void PWM_Timer0_Init(uint8 duty_cycle)
{
	/* Configure PWM
	 * Set WGM00 & WGM01 by '1' to select fast PWM mode
	 * Set COM01 by '1' to make OC0 non-inverting
	 * Set CS00 & CS02 by '1' to select N(Prescaler)=1024 */
	TCCR0 = (1<< WGM00) | (1<< WGM01) | (1<< COM01) | (1<< CS02) | (1<< CS00);

	/* Configure PB3/OC0 Pin as OUTPUT pin */
	GPIO_setupPinDirection(PORTB , PINB3 , PIN_OUTPUT);

	/* Set initial value for Timer0 & Compare value */
	TCNT0 = 0;
	OCR0 = duty_cycle * (TIMER0_MAX_STEPS/100);		// To calculate PWM in percentage.
}
