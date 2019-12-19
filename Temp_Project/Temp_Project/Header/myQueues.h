#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek
 * \version 1.0.0
 *
 * \defgroup myQueues
 * \brief creating the Queue
 *
 * This file contains functions responsible for manipulating the Queue
 */

 #include "ATMEGA_FreeRTOS.h"
 #include <queue.h>
 #include <stdio.h>
 /**
 * \ingroup myQueues
 * \brief creates a queue
 * 
 */
 QueueHandle_t payloadQueue;
 /**
 * \ingroup myQueues
 * \brief creates a data structure with 2 values
 * 
 */
  typedef struct  
 {
	 uint8_t data_type;
	 uint16_t value;
 } data_t; 
 
 /**
 * \ingroup myQueues
 * \brief Creates a queue
 * creates the queue with the size of "data_t" struct created earlier 
 */
 void queue_create();
 
 