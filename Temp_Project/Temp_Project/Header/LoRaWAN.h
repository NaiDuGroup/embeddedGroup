/*
 * LoRaWAN.h
 *
 * Created: 04/12/2019 14.33.45
 *  Author: DUNAI
 */ 

#pragma once
void lora_handler_create(UBaseType_t lora_handler_task_priority);
void lora_handler_task( void *pvParameters );