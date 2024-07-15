#include "pwm.h"

volatile uint8_t red_duty = 0;
volatile uint8_t green_duty = 0;
volatile uint8_t blue_duty = 0;

void PWM_init() {
	
	PWM_START(RED_PIN);
	PWM_START(GREEN_PIN);
	PWM_START(BLUE_PIN);
	
	TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);
	TCCR0B |= (1<<CS01);
	OCR0A = 59;
	
	TIMSK0 |= (1<<OCIE0A);
}

void PWM_setDutyCycle(uint8_t pin, uint8_t dutyCycle) {
	if (pin == RED_PIN) {
		red_duty = dutyCycle;
		} else if (pin == GREEN_PIN) {
		green_duty = dutyCycle;
		} else if (pin == BLUE_PIN) {
		blue_duty = dutyCycle;
	}
}

void PWM_soft_update() {
	static uint8_t PWM_position = 0;
	if (++PWM_position >= PWM_PERIOD) {
		PWM_position = 0;
	}

	// Update RED_PIN
	if (PWM_position < red_duty) {
		PWM_ON(RED_PIN);
		} else {
		PWM_OFF(RED_PIN);
	}

	// Update GREEN_PIN
	if (PWM_position < green_duty) {
		PWM_ON(GREEN_PIN);
		} else {
		PWM_OFF(GREEN_PIN);
	}

	// Update BLUE_PIN
	if (PWM_position < blue_duty) {
		PWM_ON(BLUE_PIN);
		} else {
		PWM_OFF(BLUE_PIN);
	}
}

// ISR for Timer0 compare match
ISR(TIMER0_COMPA_vect) {
	PWM_soft_update();
}