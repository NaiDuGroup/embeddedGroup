
/*
 * tempHumiditySensors.h
 *
 * Created: 09/12/2019 12.30.49
 *  Author: DUNAI
 */ 


#include "ATMEGA_FreeRTOS.h"

#include <hih8120.h>
#include <stdio.h>
#include <stdint.h>
#include <util/delay.h>

void temperatureHumiditySensor_init();
void temperatureHumidity_measure();
uint16_t temperatureGetValue();
uint16_t humidityGetValue();


