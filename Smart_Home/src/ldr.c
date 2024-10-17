 /******************************************************************************
 *
 * Module: LDR
 *
 * File Name: ldr.c
 *
 * Description: Source file for the LDR driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

#include "ldr.h"
#include "adc.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function reads the LDR sensor value and returns the light intensity.
 */
uint8 LDR_getLightIntensity(void)
{
	uint8 LDR_Intensity = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the LDR is connected */
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	/* Calculate the LDR intensity from the ADC value*/
	LDR_Intensity = (uint8) ( ((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE) );

	return LDR_Intensity;
}

