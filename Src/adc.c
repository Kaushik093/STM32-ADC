#include "adc.h"

#define GPIOAEN		(1U<<0)
#define ADC1EN 		(1U<<8)
#define ADC_CH1		(1U<<0)
#define ADC_ON		(1U<<0)

#define ADC_SEQ_LEN	(0x00)

#define CONV_START  (1U<<30)
#define CONV_COMPLETE  (1U<<1)
#define CONV_CONT	(1U<<1)

void adc_init(void){

	/**Configure ADC GPIO pin**/

	//Enable clock for GPIO A
	RCC->AHB1ENR |= GPIOAEN;

	//Set GPIOA (PA1) to analog mode
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);

	/**Configure ADC module**/

	//Enable clock access to ADC (APB2 bus)
	RCC->APB2ENR |= ADC1EN;

	//Conversion sequence start
	ADC1->SQR3 = ADC_CH1;

	//Conversion sequence length
	ADC1->SQR1 = ADC_SEQ_LEN;

	//Enable ADC
	ADC1->CR2 = ADC_ON;
}

void start_conversion(void){

	//Enable continuous conversion
	ADC1->CR2 |= CONV_CONT;

	//Start adc conversion
	ADC1->CR2 |= CONV_START;
}

uint32_t adc_read(void){

	//Wait for conversion to complete
	while(!(ADC1->SR & CONV_COMPLETE));

	//Read from data register
	return (ADC1->DR);
}
