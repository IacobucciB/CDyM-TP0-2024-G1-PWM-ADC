#include "rgb.h"
#include "pwm.h"

void RGB_init() {
	PWM_init();
}

void RGB_setColor(uint8_t red, uint8_t green, uint8_t blue) {
	PWM_setDutyCycle(PORTB2, blue);
	PWM_setDutyCycle(PORTB1, green);
	PWM_setDutyCycle(PORTB5, red);
}

void RGB_setSingleColor(char color, uint8_t duty) {
	switch (color)
	{
		case 'R':
		PWM_setDutyCycle(PORTB5, duty);
		break;
		case 'G':
		PWM_setDutyCycle(PORTB1, duty);
		break;
		case 'B':
		PWM_setDutyCycle(PORTB2, duty);
		break;
		default:
		break;
	}
}

void RGB_setRed() {
	RGB_setColor(120, 0, 0);
}

void RGB_setGreen() {
	RGB_setColor(0, 120, 0);
}

void RGB_setBlue() {
	RGB_setColor(0, 0, 120);
}
