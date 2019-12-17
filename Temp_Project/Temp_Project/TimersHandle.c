
/*
 * TimersHandle.c
 *
 * Created: 16/12/2019 12.25.16
 *  Author: DUNAI
 */ 

#include "TimersHandle.h"
#include "semaphores.h"

void timersHandle_init()
{
	co2Timer = xTimerCreate(
	"CO2 TIMER\n",
	(1000/portTICK_PERIOD_MS) * 60,
	pdFALSE,
	(void* ) 0,
	co2TimerRead
	);
}

void co2TimerRead(TimerHandle_t xTimer)
{
	printf("60sec CO2_TIMER_READ\n");
	
	xTimerStart (co2Timer,0);
}