#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>

void ADC_init();
uint16_t ADC_read(uint8_t channel);

#endif /* ADC_H_ */