
#ifndef ADC_H_
#define ADC_H_

#include "stm32f4xx.h"
#include <stdint.h>

void adc_init(void);
void start_conversion(void);
uint32_t adc_read(void);

#endif /* ADC_H_ */
