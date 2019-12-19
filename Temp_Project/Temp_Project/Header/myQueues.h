#pragma once
/*
 * myQueues.S
 *
 * Created: 19/12/2019 05.05.59
 *  Author: DUNAI
 */ 

 #include "ATMEGA_FreeRTOS.h"
 #include <queue.h>
 #include <stdio.h>
 
 QueueHandle_t payloadQueue;
 
  typedef struct  
 {
	 uint8_t data_type;
	 uint16_t value;
 } data_t; 
 
 void queue_create();
 
 