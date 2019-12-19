/*
 * minunit.c
 *
 * Created: 12/19/2019 10:25:08
 *  Author: aleks
 */ 
#include <stdio.h>
#include "Test/minunit.h"
#include "Header/co2Sensor.h"
#include "Header/tempHumiditySensor.h"

 temp_hum_test test_temp_hum = NULL;
 co2_test test_co2 = NULL;
 tests_run = 0;

char* init_temp_hum_test_get_data(){
	temp_hum_test = temperatureHumiditySensor_init(21,1020,false);
	MU_ASSERT("error: humidity!=1020", 1020 == temperatureGetValue(temp_hum_test));
	return 0;
}
char* init_temp_hum_test_get_data2(){
	temp_hum_test = temperatureHumiditySensor_init(24,400,false);
	MU_ASSERT("error: temperature!=24", 24 == temperatureGetValue(temp_hum_test));
	return 0;
}


static char* test_get_co2_data_value() {
	int temp = 150;
	test_co2 = co2Sensor_init(temp, false);
	MU_ASSERT("error, temp valut != co2Sensor_measure(test_co2)", temp == co2Sensor_measure(test_co2));
	return 0;
}

char* co2_null(){
	test_co2 = NULL;
	MU_ASSERT("error: temp value != NULL", NULL == co2_Data);
	return 0;
}


static char * all_tests() {
	MU_RUN_TEST(init_temp_hum_test_get_data);
	MU_RUN_TEST(init_temp_hum_test_get_data2);
	MU_RUN_TEST(test_get_co2_data_value);
	MU_RUN_TEST(co2_null);
	
	
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