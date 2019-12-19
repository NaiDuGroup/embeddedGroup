#pragma once
/*
 * board_tasks.h
 *
 * Created: 17/12/2019 12.42.50
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"

#include "co2Sensor.h"
#include "tempHumiditySensor.h"
#include "lorawanDev.h"
#include "semaphores.h"
#include "myTimers.h"
#include "myQueues.h"


#include <task.h>
#include <time.h>


extern data_t temperature;
extern data_t humidity;
extern data_t co2;

void tasks_init();

void allTasks();
void getTemperatureHumidity_Task(void *pvParameters);
void getCo2_Task(void *pvParameters);
void fillPayloadQueue_Task(void *pvParameters);
void lorawanSend_Task(void *pvParameters);




