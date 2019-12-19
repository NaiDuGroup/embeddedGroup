
/*
 * lorawanDev.c
 *
 * Created: 09/12/2019 15.50.58
 *  Author: DUNAI
 */ 


#include "Header/lorawanDev.h"
#include "Header/co2Sensor.h"
#include "Header/tempHumiditySensor.h"
#include "Header/myQueues.h"

#define LORA_appEUI "ba4b140f562bc777"
#define LORA_appKEY "8390d15cabd2baab4468e37d88c54efa"



#define LORA_INIT_TASK_PRIORITY 7
void lorawanDev_init()
{
	hal_create(LORA_INIT_TASK_PRIORITY+1);
	lora_driver_create(ser_USART1);
	_delay_ms(10000);
	
}

void lorawanDevStart()
{
	
	
	_delay_ms(10000);
	lora_driver_reset_rn2483(1);
	vTaskDelay(2);
	lora_driver_reset_rn2483(0);
	vTaskDelay(150);
	lora_driver_flush_buffers();
	
	if (lora_driver_rn2483_factory_reset() != LoRA_OK)
	{
		printf("FACTORY RESET ERROR\n");
	}
	
	if (lora_driver_configure_to_eu868() != LoRA_OK)
	{
		printf("lora_Configure error\n");
	}
	
	static char dev_eui[17];
	if (lora_driver_get_rn2483_hweui(dev_eui) != LoRA_OK)
	{
		printf("lora_driver_get_rn2483_hweui error");
	}
	
	if (lora_driver_set_otaa_identity(LORA_appEUI,LORA_appKEY,dev_eui) != LoRA_OK)
	{
		printf("lora_driver_set_otaa_identity error\n");
	}
	
	
	e_LoRa_return_code_t rc;
	
	while(rc != LoRa_ACCEPTED)
	{
		printf("LORAWAN device is not connected\n");
		rc = lora_driver_join(LoRa_OTAA);
		_delay_ms(1000);
	}
	
	printf("LORAWAN device is connected \n");
	
	
}

void lorawanDevSend_data()
{
	
	uint16_t tTemperature = xQueueReceive(payloadQueue, // queue handle
									  &tTemperature, // address of temperature placeholder
									  portMAX_DELAY);
	uint16_t tCO2 = xQueueReceive(payloadQueue, // queue handle
									  &tCO2, // address of temperature placeholder
									  portMAX_DELAY);
    uint16_t tHumidity = xQueueReceive(payloadQueue, // queue handle
									  &tHumidity, // address of temperature placeholder
								      portMAX_DELAY);
	
	lora_payload_t uplink_payload;
	
	uplink_payload.len = 6; // Length of the actual payload
	uplink_payload.port_no = 1; // The LoRaWAN port no to sent the message to
	uplink_payload.bytes[0] = tHumidity >> 8;
	uplink_payload.bytes[1] = tHumidity & 0xFF;
	uplink_payload.bytes[2] = tTemperature >> 8;
	uplink_payload.bytes[3] = tTemperature & 0xFF;
	uplink_payload.bytes[4] = tCO2 >> 8;
	uplink_payload.bytes[5] = tCO2 & 0xFF;
	
	e_LoRa_return_code_t rc;
	if ((rc = lora_driver_sent_upload_message(false, &uplink_payload)) == LoRa_MAC_TX_OK )
	{
		// The uplink message is sent and there is no downlink message received
		printf("The uplink message is sent and there is no downlink message received\n");
	}
	else if (rc == LoRa_MAC_RX_OK)
	{
		// The uplink message is sent and a downlink message is received
		printf("The uplink message is sent and a downlink message is received\n");
	}
	
	 
}