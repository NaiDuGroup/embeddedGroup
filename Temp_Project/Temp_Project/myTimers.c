
/*
 * myTimers.c
 *
 * Created: 17/12/2019 11.35.32
 *  Author: DUNAI
 */ 

#include "Header/myTimers.h"
#include "Header/semaphores.h"

void timers_init()
{
	mainTimer = xTimerCreate( "main timer  \n",           // Just a text name, not used by the kernel.
	                        ( 50000 / portTICK_PERIOD_MS), // The timer period in ticks.
	                          pdFALSE,                    // The timer is a one-shot timer.
	                          0,                          // The id is not used by the callback so can take any value.
	                          mainTimerCallbackFunction    // The callback function that switches the LCD back-light off.
	                        );
	

	temperatureHumidityTimer = xTimerCreate( "temp_hum_timer \n",           // Just a text name, not used by the kernel.
										   ( 5000 / portTICK_PERIOD_MS), // The timer period in ticks.
											pdFALSE,                    // The timer is a one-shot timer.
										    0,                          // The id is not used by the callback so can take any value.
										    temperatureHumidityCallbackFunction    // The callback function that switches the LCD back-light off.
											);


	co2Timer = xTimerCreate("co2_timer \n",           // Just a text name, not used by the kernel.
						   ( 5000 / portTICK_PERIOD_MS), // The timer period in ticks.
							pdFALSE,                    // The timer is a one-shot timer.
							0,                          // The id is not used by the callback so can take any value.
							co2CallbackFunction    // The callback function that switches the LCD back-light off.
							);

	lorawanTimer = xTimerCreate("lorawan timer \n",           // Just a text name, not used by the kernel.
				   ( 5000 / portTICK_PERIOD_MS), // The timer period in ticks.
					pdFALSE,                    // The timer is a one-shot timer.
					0,                          // The id is not used by the callback so can take any value.
					lorawanCallbackFunction    // The callback function that switches the LCD back-light off.
					);
}


void mainTimerCallbackFunction(TimerHandle_t xTimer)
{
	printf("mainTimer using the semaphore (50 seconds)\n");
	if (xSemaphoreTake(lorawanSemaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(allSemaphores) != pdTRUE)
	{
		
	}
		
	xTimerStart(temperatureHumidityTimer,0);
}

void temperatureHumidityCallbackFunction(TimerHandle_t xTimer)
{
	printf("temperatureHumidityCallbackFunction using the semaphore (5seconds)\n");
	if (xSemaphoreTake(allSemaphores,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(temperatureHumiditySemaphore) != pdTRUE)
	{
		
	}
	
	xTimerStart(co2Timer,0);
}

void co2CallbackFunction(TimerHandle_t xTimer)
{
	printf("co2CallbackFunction using the semaphore (5seconds)\n");
	if (xSemaphoreTake(temperatureHumiditySemaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(co2Semaphore) != pdTRUE)
	{
		
	}
	
	xTimerStart(lorawanTimer,0);
}

void lorawanCallbackFunction(TimerHandle_t xTimer)
{
	printf("lorawanCallbackFunction using the semaphore (5seconds)\n");
	if (xSemaphoreTake(co2Semaphore,portMAX_DELAY))
	{
		
	}
	
	if (xSemaphoreGive(lorawanSemaphore) != pdTRUE)
	{
		
	}
	
	xTimerStart(mainTimer,0);
}