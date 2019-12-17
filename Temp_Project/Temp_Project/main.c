/*
 * Temp_Project.c
 *
 * Created: 04/12/2019 13.59.05
 * Author : DUNAI
 */ 
/*
#include<avr/io.h>
#include<util/delay.h>
#include<avr/sfr_defs.h>
int main(void)
{
	DDRA|=_BV(DDA0)|_BV(DDA7);// Set PA0 and PA7 to output
	
	while(1)
	{
		PORTA^=_BV(PA0);// Toggle PA0 (LED1)
		_delay_ms(100);PORTA^=_BV(PA7);// Toggle PA7 (LED2)
		_delay_ms(200);
	}
}

*/


/*

//NEW PART

#include "ATMEGA_FreeRTOS.h"
#include "ihal.h"
#include "lora_driver.h"
#include "Header/LoRaWAN.h"
//#include <task.h>
// High priorities
#define LED_TASK_PRIORITY			( tskIDLE_PRIORITY + 3 )
// Medium priorities
#define LORAWAN_TASK_PRIORITY			( tskIDLE_PRIORITY + 2 )
// Low priorities
 Task stack sizes

#define TASK_MY_TASK_STACK				( configMINIMAL_STACK_SIZE )
int main(void)
{
	stdioCreate(ser_USART0);
	
	hal_create(LED_TASK_PRIORITY); // Must be called first!! LED_TASK_PRIORITY must be a high priority in your system
	lora_driver_create(ser_USART1); // The parameter is the USART port the RN2483 module is connected to - in this case USART1 (AKA COM PORT?)
	lora_handler_create(LORAWAN_TASK_PRIORITY);

	// Replace with your application code 
	while (1)
	{
	// Application code goes in here
	}
	 //Let the operating system take over ??
	vTaskStartScheduler();
}
*/



#include "ATMEGA_FreeRTOS.h"
#include "Header/tempHumiditySensor.h"
#include "Header/co2Sensor.h"
#include "Header/lorawanDev.h"
#include "display_7seg.h"
#include <stdio.h>
#include <stdio_driver.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main (void)
{
	 stdioCreate(0);
	 sei();
	 printf("PROGRAM");
	 uint16_t humidity = 0.0;
	 uint16_t temperature = 0.0;
	 uint16_t ppm = 0.0;
	 temperatureHumiditySensor_init();
	 co2Sensor_init();
	 display_7seg_init(NULL);
	 display_7seg_power_up();
	// lorawanDev_init();
	// lorawanDevStart();
	// lorawanDevSend_data();
	 
	

	
	while(1)
	{
		
		temperatureHumidity_measure();
		humidity = humidityGetValue();
		temperature = temperatureGetValue();
		float temp = temperatureGetValue();
		co2Sensor_measure();
		ppm = co2Sensor_getValue();	
		printf("humidity = %d \n", humidity);
		printf("temperature = %d \n", temperature );
		printf("co2 = %d \n", ppm);
		display_7seg_display(temp/10,1);
		_delay_ms(1000);
		
		
			 
	}
}

