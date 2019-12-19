#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek
 *\version 1.0.0
 *
 * \defgroup co2Sensor
 * \brief This file contains functions responsible for manipulating with MH_z19 sensor
 *
 * This file contains functions responsible for initializing, measuring and getting the values of the sensor
 */

#include "ATMEGA_FreeRTOS.h"
#include <mh_z19.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

uint16_t co2_test;

/**
 * \ingroup co2Sensor
 * \brief Initializes the MH_z19 sensor
 * 
 */
void co2Sensor_init();

/**
 * \ingroup co2Sensor
 * \brief performs the measuring
 * 
 */
void co2Sensor_measure();

/**
 * \ingroup co2Sensor
 * \brief Callback Function
 * The call back function will be called by the driver when a new CO2 value is returned by the sensor.
 */
void co2Sensor_callback(uint16_t ppm);

/**
 * \ingroup co2Sensor
 * \brief gets the co2 value
 * \param[out] co2 value of a measurement
 */
uint16_t co2Sensor_getValue();


