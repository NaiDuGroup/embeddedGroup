#pragma once
/**
 * 
 * \file
 * \authors Alexandru, Anatolii, Zsolt, Jacek
 * \version 1.0.0
 *
 * \defgroup lorawanDev
 * \brief This file contains functions responsible for manipulating with LoraWan
 *
 * This file contains functions responsible for initializing, starting and sending data
 */

#include "ATMEGA_FreeRTOS.h"

#include <stdio.h>
#include <lora_driver.h>
#include <ihal.h>


/**
 * \ingroup lorawanDev
 * \brief Initializes LoraWan
 * 
 */
void lorawanDev_init();

/**
 * \ingroup lorawanDev
 * \brief starts LoraWan
 * This function resets the driver, sets the device's identity ( appeui, app_key, dev_eui) and 
 * connects to the server
 */
void lorawanDevStart();

/**
 * \ingroup lorawanDev
 * \brief sends data to the server
 * Takes out the 3 readings from the queue, creates a payload of 6 bytes and sends it to the server
 */
void lorawanDevSend_data();