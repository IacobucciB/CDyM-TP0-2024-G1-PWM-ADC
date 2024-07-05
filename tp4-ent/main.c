#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>

// PWM MACROS
#define PWM_PERIOD 20
#define PWM_DELTA 19
#define PWM_OFF PORTB &= ~(1<<PORTB5)
#define PWM_ON PORTB |= (1<<PORTB5)
#define PWM_START DDRB |= (1<<PORTB5)

// PWM SOFTWARE UPDATE
void PWM_soft_update(void){
	static uint8_t PWM_position = 0;
	if(++PWM_position>=PWM_PERIOD){
		PWM_position = 0;
	}
	if(PWM_position<PWM_DELTA){
		PWM_ON;
		} else {
		PWM_OFF;
	}
}

// INTERRUPTION
ISR(TIMER0_COMPA_vect){
	PWM_soft_update();
}

int main(void){
	
	DDRB |= (1<<PORTB5) | (1<<PORTB2) | (1<<PORTB1);
	
	TCCR0A |= (1<<COM0A1) | (1<<WGM01) | (1<<WGM00);
	TCCR0B |= (1<<CS01) | (1<<CS00);
	OCR0A = 249;
	
	TIMSK0 |= (1<<OCIE0A);
	sei();
	
	while(1){
	}
}

