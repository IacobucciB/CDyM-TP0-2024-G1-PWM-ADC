#include "main.h"

// Function prototypes
uint8_t RGB_setBrightness(void);
void processCommand(char channel);

// Static variables
static char bienvenida[] = "Controlador RGB \n\r Ingrese R, G o B para cambiar la intensidad del color seleccionado \n\r ";
//static char novalido[] = "ERROR: Comando no valido\n\r";
static char str[4];

// Function to set brightness based on ADC reading
uint8_t RGB_setBrightness() {
	uint16_t adc_value = ADC_read(3); // Leer valor del potenciómetro conectado al ADC3 (PC3)
	uint8_t brightness = adc_value / 4; // Escalar el valor ADC (0-1023) a PWM (0-255)
	return brightness;
}

// Function to process UART command and set corresponding color
void processCommand(char channel) {
	uint8_t brightness = RGB_setBrightness();
	switch (channel) {
		case 'R':
		RGB_setRed();
		UART_sendString("R");
		break;
		case 'G':
		RGB_setGreen();
		UART_sendString("G");
		break;
		case 'B':
		RGB_setBlue();
		UART_sendString("B");
		break;
		default:
		// UART_sendString(novalido);
		return;
	}
	// Send brightness value as string
	
	sprintf(str, "%u", brightness);
	UART_sendString(str);
	UART_sendString("\n\r");
	
}

int main(void) {
	DDRC = 0x00; // Set PORTC as input
	UART_init();
	RGB_init();
	ADC_init();
	sei(); // Enable global interrupts

	// Initial RGB color setup
	RGB_setRed();
	_delay_ms(100);
	RGB_setGreen();
	_delay_ms(100);
	RGB_setBlue();
	_delay_ms(100);
	RGB_setColor(255, 255, 255);

	// Send welcome message
	UART_sendString(bienvenida);

	while(1) {
		if (UART_hayComando()) {
			char channel = UART_getComando();
			processCommand(channel);
			UART_setHayComando();
		}
	}

	return 0;
}
