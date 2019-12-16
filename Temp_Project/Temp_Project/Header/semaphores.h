
/*
 * semaphores.h
 *
 * Created: 11/12/2019 13.15.37
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"
#include <stdio.h>
#include <semphr.h>

SemaphoreHandle_t co2Semaphore;
SemaphoreHandle_t temperatureHumiditySemaphore;
SemaphoreHandle_t loraWANSemaphore;

void semaphores_init();