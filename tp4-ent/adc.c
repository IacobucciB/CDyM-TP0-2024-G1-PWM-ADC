#include "adc.h"

void ADC_init() {
	// AREF = AVcc
	ADMUX = (1 << REFS0);
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}


