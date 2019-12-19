
/*
 * board_tasks.c
 *
 * Created: 17/12/2019 13.05.39
 *  Author: DUNAI
 */ 

#include "Header/board_tasks.h"
#include "Header/myQueues.h"



void tasks_init()
{
	
	
	
	xTaskCreate(
	getTemperature_Task,
	"getTemperature_Task_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 2,
	NULL);
	
	xTaskCreate(
	getCo2_Task,
	"getCo2_Task_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 3,
	NULL);
	
	xTaskCreate(
	getHumidity_Task,
	"getHumidity_Task_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 4,
	NULL);
	
	xTaskCreate(
	lorawanSend_Task,
	"lorawanSend_Task_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 1,
	NULL);

	

}

void getTemperature_Task(void *pvParameters)
{
	uint16_t temperature = 0;
    
	for( ;; )
	{
		if (xSemaphoreTake(temperatureSemaphore,1000 / portTICK_PERIOD_MS))
		{
			temperatureHumidity_measure();
			temperature = temperatureGetValue();
			printf("temperature = %d \n", temperature);
			
			xSemaphoreGive(temperatureSemaphore);
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &temperature,	//pointer to the temp
			0);
			
		}
		
		else
		{
			printf("temperature_task failed to get temperature\n");
		}
		vTaskDelay(60000 / portTICK_PERIOD_MS); // 5 second
		
	}
}

void getCo2_Task(void *pvParameters)
{
    uint16_t co2 = 0;
	
	for( ;; )
	{
		if (xSemaphoreTake(co2Semaphore,1000 / portTICK_PERIOD_MS))
		{
			co2Sensor_measure();
			printf("co2 = %d \n", co2Sensor_getValue());
			xSemaphoreGive(co2Semaphore);
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &co2,	//pointer to the temp
			0);
		}
		
		else
		{
			printf("co2_task failed to get co2Value\n");
		}
		vTaskDelay(60000 / portTICK_PERIOD_MS); // 5 seconds
	}
}

void getHumidity_Task(void *pvParameters)
{
	
	uint16_t humidity = 0;

	for( ;; )
	{
		if (xSemaphoreTake(humiditySemaphore,1000 / portTICK_PERIOD_MS))
		{
			temperatureHumidity_measure();
			printf("humidity = %d \n", humidityGetValue());
			xSemaphoreGive(humiditySemaphore);
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &humidity,	//pointer to the temp
			0);
		}
		
		else
		{
			printf("getHumidity_task failed to get temperature\n");
		}
		vTaskDelay(60000 / portTICK_PERIOD_MS); // 5 second
	}
}

void lorawanSend_Task(void *pvParameters)
{
	lorawanDevStart();
	
	for( ;; )
	{
		if (xSemaphoreTake(lorawanSemaphore,1000 / portTICK_PERIOD_MS))
		{
			lorawanDevSend_data();
			printf("Data sent to Loriot!\n");
			xSemaphoreGive(lorawanSemaphore);
		}
		
		else
		{
			printf("lorawanSend_task failed to send data\n");
		}
		vTaskDelay(60000 / portTICK_PERIOD_MS); // 60 second
	}
}


