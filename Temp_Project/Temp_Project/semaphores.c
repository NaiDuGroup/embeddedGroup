
/*
 * semaphores.c
 *
 * Created: 11/12/2019 13.21.11
 *  Author: DUNAI
 */ 
#include "Header/semaphores.h"

co2Semaphore = xSemaphoreCreateMutex();
if (co2Semaphore == NULL)
{
	co2Semaphore = xSemaphoreCreateMutex;
}

temperatureHumiditySemaphore = xSemaphoreCreateMutex();
if (temperatureHumiditySemaphore == NULL)
{
	temperatureHumiditySemaphore = xSemaphoreCreateMutex;
}

loraWANSemaphore = xSemaphoreCreateMutex();
if (loraWANSemaphore  == NULL)
{
	loraWANSemaphore  = xSemaphoreCreateMutex;
}