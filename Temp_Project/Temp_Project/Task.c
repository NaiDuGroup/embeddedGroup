
/*
 * Task.c
 *
 * Created: 16/12/2019 12.42.50
 *  Author: DUNAI
 */ 
#include "Tasks.h"

void crete_tasks(void)
{
	xTimerCreate(
	co2Sensor_measureTask,
	"co2 TASK",
	configMINIMAL_STACK_SIZE,
	(void*) 1,
	configMAX_PRIORITIES - 1,
	&co2Sensor_measureTask
	);
} 

void co2Sensor_measure_task(void *pvParameters)
{
	(void ) pvParameters;
	
	while(1)
	{
		if (xSemaphoreTake (co2Semaphore, portMAX_DELAY) == pdTRUE)
		{
			co2Sensor_measure();
			printf("co2 task");
			vTaskDelay(100);
			xSemaphoreGive(co2Semaphore);
			vTaskDelay(15000/portTICK_PERIOD_MS);
		}
	}
}