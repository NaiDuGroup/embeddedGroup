
/*
 * semaphores.c
 *
 * Created: 16/12/2019 11.56.00
 *  Author: DUNAI
 */ 

#include "semaphores.h"

void semaphore_init()
{
	mainSemaphore = xSemaphoreCreateMutex();
	if (mainSemaphore == NULL)
	{
		mainSemaphore = xSemaphoreCreateMutex();
	}
	
	temperatureHumiditySemaphore = xSemaphoreCreateMutex();
	if (temperatureHumiditySemaphore == NULL)
	{
		temperatureHumiditySemaphore = xSemaphoreCreateMutex();
	}
	
	co2Semaphore = xSemaphoreCreateMutex();
	if (co2Semaphore == NULL)
	{
		co2Semaphore = xSemaphoreCreateMutex();
	}
	
	lorawanSemaphore = xSemaphoreCreateMutex();
	if (lorawanSemaphore == NULL)
	{
		lorawanSemaphore = xSemaphoreCreateMutex();
	}
	
	
}