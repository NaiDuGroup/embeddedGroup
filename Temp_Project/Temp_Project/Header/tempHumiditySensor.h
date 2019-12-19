#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek\version 1.0.0
 *
 * \defgroup tempHumiditySensor
 * \brief This file contains functions responsible for manipulating with HIH8120 sensor
 *
 * This file contains functions responsible for initializing, waking up, getting measurments and getting the values of the sensor
 */


#include "ATMEGA_FreeRTOS.h"

#include <hih8120.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>


/**
 * \ingroup tempHumiditySensor
 * \brief Initializes the hih8120sensor
 * 
 */
void temperatureHumiditySensor_init();

/**
 * \ingroup tempHumiditySensor
 * \brief measures the humidity and temperature
 * Wakes up the sensor with a 50ms delay, takes the measuring
 */
void temperatureHumidity_measure();

/**
 * \ingroup tempHumiditySensor
 * \brief gets the temperature value
 * \param[out] temperature value of a measurement
 */
uint16_t temperatureGetValue();

/**
 * \ingroup tempHumiditySensor
 * \brief gets the humidity value
 * \param[out] Humidity value of a measurement
 */
uint16_t humidityGetValue();



