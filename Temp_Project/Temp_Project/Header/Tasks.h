
/*
 * Tasks.h
 *
 * Created: 16/12/2019 12.38.47
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "co2Sensor.h"
#include "semaphores.h"
#include "TimersHandle.h"

#include <task.h>
#include <timers.h>

TaskHandle_t co2Sensor_measureTask;

void crete_tasks(void);

void co2Sensor_measure_task(void *pvParameters);
