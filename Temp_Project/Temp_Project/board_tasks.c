
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
	getTemperatureHumidity_Task,
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
	configMAX_PRIORITIES - 2,
	NULL);
	
	xTaskCreate(
	fillPayloadQueue_Task,
	"fillPayload_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 2,
	NULL);
	
	
	xTaskCreate(
	allTasks,
	"all_Tasks_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 2,
	NULL);
	
	xTaskCreate(
	lorawanSend_Task,
	"lorawanSend_Task_taskCreate\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 2,
	NULL);
	
	

}

void allTasks()
{
	lorawanDevStart();
	
	for (;;)
	{
		
		vTaskDelay(5000/ portTICK_PERIOD_MS);
		xSemaphoreGive(co2Semaphore);
		
		vTaskDelay(5000/ portTICK_PERIOD_MS);
		xSemaphoreGive(temperatureHumiditySemaphore);
		vTaskDelay(5000/ portTICK_PERIOD_MS);
		xSemaphoreGive(fillPayloadQueueSemaphore);
		vTaskDelay(5000/ portTICK_PERIOD_MS);
		xSemaphoreGive(lorawanSemaphore);
		vTaskDelay(40000 / portTICK_PERIOD_MS);
		
	}
}

void getTemperatureHumidity_Task(void *pvParameters)
{
    
	for( ;; )
	{
		if (xSemaphoreTake(temperatureHumiditySemaphore,portMAX_DELAY))
		{
			temperatureHumidity_measure();
			
			temperature.data_type = 0;
			temperature.value = temperatureGetValue();
			
			humidity.data_type = 1;
			humidity.value = humidityGetValue();
			
			printf("temperature = %d \n", temperature.value);
			printf("humidity = %d \n", humidity.value);
		}
		
		else
		{
			printf("temperatureHumidity_task failed to get temperature\n");
		}
	}
}

void getCo2_Task(void *pvParameters)
{

	
	for( ;; )
	{
		if (xSemaphoreTake(co2Semaphore,portMAX_DELAY))
		{
			co2Sensor_measure();
			co2.data_type = 2;
			co2.value = co2Sensor_getValue();

			printf("co2 = %d \n", co2.value);
		}
		
		else
		{
			printf("co2_task failed to get co2Value\n");
		}
	}
}

void fillPayloadQueue_Task(void *pvParameters)
{

	for( ;; )
	{
		if (xSemaphoreTake(fillPayloadQueueSemaphore,portMAX_DELAY))
		{
			
			
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &temperature,	//pointer to the temp
			portMAX_DELAY);
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &humidity,	//pointer to the temp
			portMAX_DELAY);
			
			xQueueSend(
			payloadQueue, //queue handle
			(void*) &co2,	//pointer to the temp
			portMAX_DELAY);
		}
		else
		{
			printf("fillPayloadQueue_task failed to get temperature\n");
		}
		
	}
}

void lorawanSend_Task(void *pvParameters)
{
	
	
	for( ;; )
	{
		if (xSemaphoreTake(lorawanSemaphore,portMAX_DELAY))
		{
			lorawanDevSend_data();
			printf("Data sent to Loriot!\n");
		}
		
		else
		{
			printf("lorawanSend_task failed to send data\n");
		}
	}
}


