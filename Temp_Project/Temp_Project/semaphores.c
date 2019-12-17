
/*
 * semaphores.c
 *
 * Created: 17/12/2019 11.21.59
 *  Author: DUNAI
 */ 

#include "Header/semaphores.h"

void semaphore_init() 
{
	allSemaphores = xSemaphoreCreateMutex();
	if( allSemaphores != NULL )
	{
		printf("allSemaphores was created successfully\n");
	}

	temperatureHumiditySemaphore = xSemaphoreCreateMutex();
	if( temperatureHumiditySemaphore != NULL )
	{
		printf("temperatureHumiditySemaphore was created successfully\n");
	}

	co2Semaphore = xSemaphoreCreateMutex();
	if ( co2Semaphore != NULL)
	{
		printf("co2Semaphore was created successfully\n");
	}

	lorawanSemaphore = xSemaphoreCreateMutex();
	if ( lorawanSemaphore != NULL)
	{
		printf("Lorawan was created successfully\n");
	}

}


