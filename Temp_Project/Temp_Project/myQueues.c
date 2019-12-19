
/*
 * myQueues.c
 *
 * Created: 19/12/2019 05.10.19
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"
#include "Header/myQueues.h"


 void queue_create()
 {
	 payloadQueue = xQueueCreate(3, sizeof(data_t));
 }