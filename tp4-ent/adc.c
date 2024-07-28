#include "adc.h"

void ADC_init() 
{
	// Habilitar el ADC y configurar el preescalador a 64 (125 kHz a 8 MHz de frecuencia de reloj).
	ADCSRA |= (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (0 << ADPS0);
	// Configurar la referencia de voltaje del ADC a AVCC con ajuste a la derecha.
	ADMUX |=  (0 << REFS1) | (1 << REFS0);
	ADMUX &= ~(1 << ADLAR);
}

uint16_t ADC_read(uint8_t channel) 
{
	// Seleccionar el canal 3 del ADC (PIN A3).
	ADMUX &= 0xF0; // Limpiar los bits MUX4:0 para configurarlos en 0.
	ADMUX |= 0x03; // Establecer los bits MUX4:0 en 011 para seleccionar el canal 3 (PIN A3).

	// Iniciar una conversion ADC.
	ADCSRA |= (1 << ADSC);

	// Esperar hasta que se complete la conversion.
	while ((ADCSRA & (1 << ADIF))==0);
	
	//Limpia el flag ADIF
	ADCSRA |= (1<<ADIF);

	// Leer y retornar el resultado de la conversion.
	uint8_t lowByte = ADCL;
	uint8_t highByte = ADCH;
	uint16_t valorADC = (highByte << 8) | lowByte;
	return valorADC;
}
