
/*
 * myTimers.c
 *
 * Created: 17/12/2019 11.35.32
 *  Author: DUNAI
 */ 
/*
#include "Header/myTimers.h"
#include "Header/semaphores.h"

void timers_init()
{
	mainTimer = xTimerCreate( "main timer  \n",           // Just a text name, not used by the kernel.
	                        ( 3400),						// The timer period in ticks.
	                          pdFALSE,                    // The timer is a one-shot timer.
	                          0,                          // The id is not used by the callback so can take any value.
	                          mainTimerCallbackFunction    // The callback function that switches the LCD back-light off.
	                        );

}


void mainTimerCallbackFunction(TimerHandle_t xTimer)
{
	printf("mainTimer using the semaphore (50 seconds)\n");
	if (xSemaphoreTake(lorawanSemaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(lorawanSemaphore) != pdTRUE)
	{
		
	}
		
	vTaskDelay(5000/portTICK_PERIOD_MS);
	
	
	
	
	printf("temperatureHumidity using the semaphore (5seconds)\n");
	if (xSemaphoreTake(lorawanSemaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(temperatureHumidityCo2Semaphore) != pdTRUE)
	{
		
	}	
	
	vTaskDelay(5000/portTICK_PERIOD_MS);
	
	printf("co2 using the semaphore (5seconds)\n");
	if (xSemaphoreTake(temperatureHumidityCo2Semaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(temperatureHumidityCo2Semaphore) != pdTRUE)
	{
		
	}
	
	vTaskDelay(5000/portTICK_PERIOD_MS);
	
	printf("lorawan using the semaphore (5seconds)\n");
	if (xSemaphoreTake(temperatureHumidityCo2Semaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(lorawanSemaphore) != pdTRUE)
	{
		
	}
		
	xTimerStart(mainTimer,0);
	
	
	
}
*/