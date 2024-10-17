 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void)
{
	/* ADMUX Register Bits Description:
	 * REFS1:1 & REFS0:1 = 11 to choose to reference voltage 2.56V.
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX = (1<< REFS1) | (1<< REFS0);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 & ADPS1:1 ADPS0:1 = 111 to choose ADC_Clock = F_CPU/128 = 16Mhz/128 = 125Khz
	 * ADC must operate in range 50-200Khz
	 */
	ADCSRA = (1<< ADEN) | (1<< ADPS2) | (1<< ADPS1) | (1<< ADPS0);
}


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num)
{
	/* Input channel number must be from 0 --> 7.
	 *  Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel.
	 *  Choose the correct channel by setting the channel number in MUX4:0 bits.*/
	ADMUX = (ADMUX & 0xE0) | (channel_num & 0x07);

	/* Start conversion write '1' to ADSC */
	SET_BIT(ADCSRA,ADSC);

	/* Wait for conversion to complete, ADC flag (ADIF) becomes '1' */
	while(BIT_IS_CLEAR(ADCSRA,ADIF));

	/* Clear ADC flag (ADIF) by write '1' to it :) */
	SET_BIT(ADCSRA,ADIF);

	/* Read the digital value from the data register */
	return ADC;
}
