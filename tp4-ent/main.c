#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "rgb.h"
#include "adc.h"

void RGB_setBrightness() {
	uint16_t adc_value = ADC_read(3); // Read ADC value from ADC3 (PC3)
	uint8_t brightness = adc_value / 4; // Scale ADC value (0-1023) to PWM value (0-255)

	RGB_setColor(brightness, brightness, brightness); // Set brightness for all colors
}


int main(void){
	
	RGB_init();
	sei();
	
	RGB_setColor(0,255,0);

	
	
	while(1){
		
		RGB_setBrightness();
		_delay_ms(5);


	}
}