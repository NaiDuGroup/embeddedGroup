#pragma once
/*
 * lorawanDev.h
 *
 * Created: 09/12/2019 15.47.45
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"

#include <stdio.h>
#include <lora_driver.h>
#include <ihal.h>



void lorawanDev_init();
void lorawanDevStart();
void lorawanDevSend_data();