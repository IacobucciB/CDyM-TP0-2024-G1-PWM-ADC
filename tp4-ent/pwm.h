#ifndef PWM_H
#define PWM_H

#include <avr/io.h>
#include <avr/interrupt.h>

// PWM pins
#define RED_PIN PORTB2
#define GREEN_PIN PORTB1
#define BLUE_PIN PORTB5

// PWM MACROS
#define PWM_PERIOD 20
#define PWM_OFF(pin) PORTB &= ~(1<<(pin))
#define PWM_ON(pin) PORTB |= (1<<(pin))
#define PWM_START(pin) DDRB |= (1<<(pin))

void PWM_init();
void PWM_setDutyCycle(uint8_t pin, uint8_t dutyCycle);
void PWM_soft_update();

#endif // PWM_H
