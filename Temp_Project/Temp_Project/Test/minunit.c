/*
 * minunit.c
 *
 * Created: 12/19/2019 10:25:08
 *  Author: aleks
 */ 
#include <stdio.h>
#include "minunit.h"
#include "../Header/co2Sensor.h"
#include "../Header/tempHumiditySensor.h"
#include "../Header/board_tasks.h"

 tests_run = 0;

char* init_temp_test_get_data(){
	temperatureHumiditySensor_init(21,1020,false);
	MU_ASSERT("error: humidity!=1020", 1020 == temperatureGetValue());
	return 0;
}
char* init_hum_test_get_data2(){
	temperatureHumiditySensor_init(24,400,false);
	MU_ASSERT("error: temperature!=24", 24 == temperatureGetValue());
	return 0;
}


static char* test_get_co2_data_value() {
	uint16_t temp = 150;
	co2Sensor_init();
	co2Sensor_measure();
	MU_ASSERT("error, temp valut != co2Sensor_getValue()", temp == co2Sensor_getValue());
	return 0;
}




static char * all_tests() {
	MU_RUN_TEST(init_temp_test_get_data);
	MU_RUN_TEST(init_hum_test_get_data2);
	MU_RUN_TEST(test_get_co2_data_value);
	
	
	return 0;
}



int main(int argc, char **argv) {
	
	char *result = all_tests();
	if (result != 0) {
		printf("%s\n", result);
	}
	else {
		printf("ALL TESTS PASSED\n" );
	}
	printf("Tests run: %d\n", tests_run);
	
	return result != 0;
}