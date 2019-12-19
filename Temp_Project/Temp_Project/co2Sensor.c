
/*
 * co2Sensor.c
 *
 * Created: 09/12/2019 14.37.45
 *  Author: DUNAI
 */ 

#include "Header/co2Sensor.h"

uint16_t co2PPM;
mh_z19_return_code_t rc;
uint16_t ppm;

void co2Sensor_init()
{
	mh_z19_create(ser_USART3, co2Sensor_callback);
}

void co2Sensor_measure()
{
	
	
	rc = mh_z19_take_meassuring();
	if (rc != MHZ19_OK)
	{
		
		printf("Something Wrong");
		vTaskDelay(1000 / portTICK_PERIOD_MS);		
	}

	
}

void co2Sensor_callback(uint16_t ppm)
{
	co2PPM = ppm;
}

uint16_t co2Sensor_getValue()
{
	return co2PPM;
}