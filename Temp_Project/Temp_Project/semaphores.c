
/*
 * semaphores.c
 *
 * Created: 17/12/2019 11.21.59
 *  Author: DUNAI
 */ 

#include "Header/semaphores.h"

void semaphore_init() 
{
	if (temperatureHumiditySemaphore == NULL)
	{
		temperatureHumiditySemaphore = xSemaphoreCreateBinary();
	}
	
	if (co2Semaphore == NULL)
	{
		co2Semaphore = xSemaphoreCreateBinary();
	}
	
	if (fillPayloadQueueSemaphore == NULL)
	{
		fillPayloadQueueSemaphore = xSemaphoreCreateBinary();
	}
	
	if (lorawanSemaphore == NULL)
	{
		lorawanSemaphore = xSemaphoreCreateBinary();
	}
	

	
	
}


