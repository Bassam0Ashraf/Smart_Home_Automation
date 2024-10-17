 /******************************************************************************
 *
 * Module: LDR
 *
 * File Name: ldr.h
 *
 * Description: header file for LDR driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/

#ifndef SRC_LDR_H_
#define SRC_LDR_H_

#include "std_types.h"	// Standard data types.

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LDR_SENSOR_CHANNEL_ID			0
#define LDR_SENSOR_MAX_VOLT_VALUE		2.56
#define LDR_SENSOR_MAX_LIGHT_INTENSITY	100

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function reads the LDR sensor value and returns the light intensity.
 */
uint8 LDR_getLightIntensity(void);


#endif /* SRC_LDR_H_ */
