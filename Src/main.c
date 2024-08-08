#include <stdio.h>
#include "adc.h"

uint32_t sensor_value;

int main(void){

	adc_init();
	start_conversion();

	while(1){

		sensor_value = adc_read();
		printf("Sensor value : %d\n\r",(int)sensor_value);
	}
}
