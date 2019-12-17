
/*
 * semaphores.h
 *
 * Created: 17/12/2019 10.56.39
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"
#include <semphr.h>
#include <stdio.h>

SemaphoreHandle_t display7segSemaphore;


void semaphore_init();

