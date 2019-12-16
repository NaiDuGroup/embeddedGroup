
/*
 * tempHumiditySensor.S
 *
 * Created: 09/12/2019 12.41.51
 *  Author: DUNAI
 */ 

 #include "Header/tempHumiditySensor.h"
 
 
 
 //initialise the driver:
 void temperatureHumiditySensor_init()
 {
	 if ( HIH8120_OK == hih8120Create())
	 {
		 printf("INITIALIZATION\n");
	 }
	 
 }
 
 //float humidity = 0.0;
 //float temperature = 0.0;
 
 
 void temperatureHumidity_measure()
 {
	 if (HIH8120_OK != hih8120Wakeup())
	 {
		printf("ERROR Wakeup\n"); 
	 }
	 _delay_ms(50);
	 
	 if (HIH8120_OK != hih8120Meassure())
	 {
		 printf("ERROR meassure\n");
	 }
	 _delay_ms(50);
 }
 
uint16_t temperatureGetValue()
 {
	return hih8120GetTemperature_x10();
 }
 
uint16_t humidityGetValue()
 {
	 return hih8120GetHumidityPercent_x10();
 }
 
 
 
 
  
