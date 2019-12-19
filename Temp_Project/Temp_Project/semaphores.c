
/*
 * semaphores.c
 *
 * Created: 17/12/2019 11.21.59
 *  Author: DUNAI
 */ 

#include "Header/semaphores.h"

void semaphore_init() 
{
	temperatureSemaphore = xSemaphoreCreateMutex();
	co2Semaphore = xSemaphoreCreateMutex();
	humiditySemaphore = xSemaphoreCreateMutex();
	lorawanSemaphore = xSemaphoreCreateMutex();

}


