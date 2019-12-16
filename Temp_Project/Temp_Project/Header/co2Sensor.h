
/*
 * co2Sensor.h
 *
 * Created: 09/12/2019 12.42.58
 *  Author: DUNAI
 */ 
#include "ATMEGA_FreeRTOS.h"
#include <mh_z19.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

void co2Sensor_init();
void co2Sensor_measure();
void co2Sensor_callback(uint16_t ppm);
uint16_t co2Sensor_getValue();


