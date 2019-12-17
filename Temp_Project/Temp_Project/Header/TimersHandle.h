
/*
 * TimersHandle.h
 *
 * Created: 16/12/2019 12.20.17
 *  Author: DUNAI
 */ 

#include "ATMEGA_FreeRTOS.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <timers.h>

TimerHandle_t co2Timer;


void timersHandle_init();

void co2TimerRead(TimerHandle_t xTimer);