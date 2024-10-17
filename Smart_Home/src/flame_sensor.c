 /******************************************************************************
 *
 * Module: Flame Sensor
 *
 * File Name: flame_sensor.c
 *
 * Description: Source file for the flame_sensor driver
 *
 * Author: Bassam Ashraf
 *
 *******************************************************************************/
#include "gpio.h"
#include "flame_sensor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Function initializes the flame sensor pin direction.
 */
void FlameSensor_init(void)
{
	/* Configure pin of flame sensor as INPUT pin */
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID , PIN_INPUT);
}


/*
 * Description :
 * Function reads the value from the flame sensor and returns it.
 */
uint8 FlameSensor_getValue(void)
{
	uint8 sensor_value = LOGIC_LOW;

	/* If flame sensor detect the flame then sensor_value will be LOGIC_HIGH */
	sensor_value = GPIO_readPin(FLAME_SENSOR_PORT_ID , FLAME_SENSOR_PIN_ID);

	return sensor_value;
}


