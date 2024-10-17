 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.h
 *
 * Description: header file for Flame Sensor driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/
#ifndef SRC_FLAME_SENSOR_H_
#define SRC_FLAME_SENSOR_H_

#include "std_types.h"	// Standard data types.

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define FLAME_SENSOR_PORT_ID                 PORTD_ID
#define FLAME_SENSOR_PIN_ID                  PIN2_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function initializes the flame sensor pin direction.
 */
void FlameSensor_init(void);

/*
 * Description :
 * Function reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void);


#endif /* SRC_FLAME_SENSOR_H_ */
