
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

TaskHandle_t mainTaskHandler;
TaskHandle_t tempHumTaskHandler;
TaskHandle_t co2TaskHandler;
TaskHandle_t lorawanTaskHandler;

void tasks_init();

void main_tasks(void *pvParameters);
void temp_humidity_task(void *pvParameters);
void co2_task(void *pvParameters);
void lorawan_task(void *pvParameters);



