#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "rgb.h"
#include "adc.h"

void RGB_setBrightness() {
	uint16_t adc_value = ADC_read(3); // Leer valor del potenciómetro conectado al ADC3 (PC3)
	uint8_t brightness = adc_value / 4; // Escalar el valor ADC (0-1023) a PWM (0-255)
	// if 62

	RGB_setColor(brightness, 255, 255); // Establecer brillo para todos los colores

	

	
}


int main(void){
	DDRC = 0x00;
	RGB_init();
	sei();
	
	ADC_init();
	RGB_setColor(255,100,255);
	// gbr
	
	
	while(1){
		//_delay_us(100);
		RGB_setBrightness();


	}
}