#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek
 * \version 1.0.0
 *
 * \defgroup semaphores
 * \brief creating the semaphores
 *
 * This file contains functions responsible for manipulating with Semaphores
 */

#include "ATMEGA_FreeRTOS.h"
#include <semphr.h>
#include <stdio.h>

/**
 * \ingroup semaphores
 * \brief 4 created semaphores
 * 
 */
SemaphoreHandle_t temperatureHumiditySemaphore;
SemaphoreHandle_t co2Semaphore;
SemaphoreHandle_t fillPayloadQueueSemaphore;
SemaphoreHandle_t lorawanSemaphore;

/**
 * \ingroup lorawanDev
 * \brief Initializes the semaphores
 * 
 */
void semaphore_init();

