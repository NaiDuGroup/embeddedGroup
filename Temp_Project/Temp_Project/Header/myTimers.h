
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
TimerHandle_t temperatureHumidityTimer;
TimerHandle_t co2Timer;
TimerHandle_t lorawanTimer;

void timers_init();

void mainTimerCallbackFunction(TimerHandle_t xTimer);
void temperatureHumidityCallbackFunction(TimerHandle_t xTimer);
void co2CallbackFunction(TimerHandle_t xTimer);
void lorawanCallbackFunction(TimerHandle_t xTimer);
