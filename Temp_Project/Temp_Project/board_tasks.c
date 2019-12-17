
/*
 * board_tasks.c
 *
 * Created: 17/12/2019 13.05.39
 *  Author: DUNAI
 */ 

#include "Header/board_tasks.h"

TaskHandle_t xHandle = NULL;

void tasks_init()
{
	xTaskCreate(
	main_tasks,
	"start main tasks\n",
	configMINIMAL_STACK_SIZE,
	( void * ) 1,
	configMAX_PRIORITIES - 1,
	&xHandle);

	xTaskCreate(
	temp_humidity_task,
	"start temp_hum_task\n",
	configMINIMAL_STACK_SIZE,
	( void* ) 1,
	configMAX_PRIORITIES - 2,
	&xHandle);

	xTaskCreate(
	co2_task,
	"start co2_task\n",
	configMINIMAL_STACK_SIZE,
	( void* ) 1,
	configMAX_PRIORITIES - 2,
	&xHandle);

    xTaskCreate(
    lorawan_task,
    "start lorawan_task\n",
    configMINIMAL_STACK_SIZE,
    ( void* ) 1,
    configMAX_PRIORITIES - 2,
    &xHandle);

}

void main_tasks(void *pvParameters)
{

	for( ;; )
	{
		if (xSemaphoreTake( allSemaphores, portMAX_DELAY ) == pdTRUE)
		{
			if (xTimerReset(temperatureHumidityTimer,0) != pdTRUE)
				xTimerStart(temperatureHumidityTimer,0);

			xSemaphoreGive( allSemaphores);
			vTaskDelay(65000/ portTICK_PERIOD_MS); //  55 seconds
		}
	}
}

void temp_humidity_task(void *pvParameters)
{

	for( ;; )
	{
		if (xSemaphoreTake( temperatureHumiditySemaphore, portMAX_DELAY ) == pdTRUE)
		{
			temperatureHumidity_measure();
			printf("humidity = %d \n", humidityGetValue());
			printf("temperature = %d \n", temperatureGetValue());
			
			xSemaphoreGive(temperatureHumiditySemaphore);
		    vTaskDelay(65000/ portTICK_PERIOD_MS); //55 seconds
		}
	}
}

void co2_task(void *pvParameters)
{

	for( ;; )
	{
		if (xSemaphoreTake( co2Semaphore, portMAX_DELAY ) == pdTRUE)
		{
			co2Sensor_measure();
			printf("co2 = %d \n", co2Sensor_getValue());
			
			xSemaphoreGive(co2Semaphore);
			vTaskDelay(65000/ portTICK_PERIOD_MS); //55 seconds
		}
	}
}

void lorawan_task(void *pvParameters)
{
	lorawanDevStart();
	for( ;; )
	{
		if (xSemaphoreTake( lorawanSemaphore, portMAX_DELAY ) == pdTRUE)
		{
			lorawanDevSend_data();
			printf("data send\n");
			
			xSemaphoreGive(lorawanSemaphore);
			vTaskDelay(65000/ portTICK_PERIOD_MS); //55 seconds
		}
	}
}