#include "rgb.h"
#include "pwm.h"

void RGB_init() {
	PWM_init();
}

void RGB_setColor(uint8_t red, uint8_t green, uint8_t blue) {
	PWM_setDutyCycle(PORTB2, red);
	PWM_setDutyCycle(PORTB1, green);
	PWM_setDutyCycle(PORTB5, blue);
}

void RGB_setRed() {
	RGB_setColor(255, 0, 0);
}

void RGB_setGreen() {
	RGB_setColor(0, 255, 0);
}

void RGB_setBlue() {
	RGB_setColor(0, 0, 255);
}
