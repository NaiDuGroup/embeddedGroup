
/*
 * myTimers.h
 *
 * Created: 11/12/2019 15.05.20
 *  Author: DUNAI
 */ 
#include "ATMEGA_FreeRTOS.h"

#include <stdio.h>
#include <stdint.h>

#include "timers.h"

TimerHandle_t mainTimer;


void timers_init();

void mainTimerCallbackFunction(TimerHandle_t xTimer);

