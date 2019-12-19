
#include "ATMEGA_FreeRTOS.h"
#include "../src/semphr.h"
#include <avr/interrupt.h>

#include "../FreeRTOSTraceDriver/FreeRTOSTraceDriver.h"

#include <stdio.h>
#include <stdio_driver.h>


#include "Header/myTimers.h"
#include "Header/tempHumiditySensor.h"
#include "Header/semaphores.h"
#include "Header/board_tasks.h"
#include "Header/co2Sensor.h"
#include "Header/lorawanDev.h"
#include "Header/myQueues.h"
#include "task.h"

 data_t temperature;
 data_t humidity;
 data_t co2;

int main(void)
{
	trace_init();
	stdioCreate(0);
	sei();


	semaphore_init();
	queue_create();
	temperatureHumiditySensor_init();
    co2Sensor_init();
	co2Sensor_measure();
	lorawanDev_init();
	
	
	
	printf("Program start\n");
	
	
	tasks_init();
	
	
	vTaskStartScheduler();

	while(1)
	{
		
	}
}