
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


#include <task.h>
#include <time.h>

void tasks_init();

void getTemperature_Task(void *pvParameters);
void getCo2_Task(void *pvParameters);
void getHumidity_Task(void *pvParameters);
void lorawanSend_Task(void *pvParameters);




