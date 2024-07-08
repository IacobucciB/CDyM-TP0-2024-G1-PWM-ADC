#include "adc.h"

void ADC_init() {
	// AREF = AVcc
	ADMUX = (1 << REFS0);
	// ADC Enable and prescaler of 128
	// 16000000/128 = 125000
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_read(uint8_t channel) {
	// Select ADC Channel. Channel must be 0-7. Channel will always be ADC3.
	ADMUX &= 0xF0;
	ADMUX |= channel;

	// Start Single conversion
	ADCSRA |= (1 << ADSC);
	
	// Wait for conversion to complete
	while((ADCSRA&(1<<ADIF))==0);

	// Clear the flag
	ADCSRA |= (1<<ADIF);
	
	return ADC;
	
	
}
