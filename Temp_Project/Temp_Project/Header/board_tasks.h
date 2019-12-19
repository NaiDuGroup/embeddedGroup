#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek
 * \version 1.0.0
 *
 * \defgroup board_tasks
 * \brief creatie all the tasks
 *
 * This file contains functions responsible for manipulating the tasks
 */

#include "ATMEGA_FreeRTOS.h"

#include "co2Sensor.h"
#include "tempHumiditySensor.h"
#include "lorawanDev.h"
#include "semaphores.h"
#include "myQueues.h"


#include <task.h>
#include <time.h>

 /**
 * \ingroup board_tasks
 * \brief creates a data type
 * Create data type for the Humidity reading
 */
extern data_t temperature;
/**
 * \ingroup board_tasks
 * \brief creates a data type
 * Create data type for the Temperature reading
 */
extern data_t humidity;
/**
 * \ingroup board_tasks
 * \brief creates a data type
 * Create data type for CO2 readings
 */
extern data_t co2;


 /**
 * \ingroup board_tasks
 * \brief create the tasks
 * Create 5 tasks
 */
void tasks_init();

 /**
 * \ingroup board_tasks
 * \brief assign delays to semaphores
 * 
 */
void allTasks();

 /**
 * \ingroup board_tasks
 * \brief get the humidity and temp
 * tasks for getting the humidity and temperature readings and prepare for the payload
 */
 
void getTemperatureHumidity_Task(void *pvParameters);

 /**
 * \ingroup board_tasks
 * \brief get the co2
 * tasks for getting the co2 readings and prepare for the payload
 */
 
void getCo2_Task(void *pvParameters);

 /**
 * \ingroup board_tasks
 * \brief fill up the queue
 * tasks for putting the 3 readings inside the queue
 */
 
void fillPayloadQueue_Task(void *pvParameters);

 /**
 * \ingroup board_tasks
 * \brief send the data
 * tasks for sending all the readings to the server
 */
 
void lorawanSend_Task(void *pvParameters);





