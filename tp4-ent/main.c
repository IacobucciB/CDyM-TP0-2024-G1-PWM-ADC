#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>

// PWM MACROS
#define PWM_PERIOD 20
#define PWM_DELTA 10
#define PWM_OFF PORTB &= ~(1<<PORTB0)
#define PWM_ON PORTB |= (1<<PORTB0)
#define PWM_START DDRB |= (1<<PORTB0)

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

static uint8_t R = 0;
static uint8_t G = 0;
static uint8_t B = 0; // GREEN

#define PWM_PERIOD 20

#define PWM_R_DELTA ((PWM_PERIOD * R) / 255)
#define PWM_G_DELTA ((PWM_PERIOD * G) / 255)
#define PWM_B_DELTA ((PWM_PERIOD * B) / 255)

// FIX THIS
// PORTB5 = BLUE
// PORTB2 = RED / VIOLET
// PORTB1 = GREEN

#define PWM_R_OFF PORTB &= ~(1<<PORTB5)
#define PWM_R_ON PORTB |= (1<<PORTB5)
#define PWM_G_OFF PORTB &= ~(1<<PORTB2)
#define PWM_G_ON PORTB |= (1<<PORTB2)
#define PWM_B_OFF PORTB &= ~(1<<PORTB1)
#define PWM_B_ON PORTB |= (1<<PORTB1)

void violet(void){
	static uint8_t R_pos = 0;
	static uint8_t G_pos = 0;
	static uint8_t B_pos = 0;
	
	if(++R_pos>=PWM_PERIOD){
		R_pos = 0;
	}
	if(++G_pos>=PWM_PERIOD){
		G_pos = 0;
	}
	if(++B_pos>=PWM_PERIOD){
		B_pos = 0;
	}
	
	if(R_pos<PWM_R_DELTA){
		PWM_R_ON;
		} else {
		PWM_R_OFF;
	}
	if(G_pos<PWM_G_DELTA){
		PWM_G_ON;
		} else {
		PWM_G_OFF;
	}
	if(B_pos<PWM_B_DELTA){
		PWM_B_ON;
		} else {
		PWM_B_OFF;
	}
}


// INTERRUPTION
ISR(TIMER0_COMPA_vect){
	PWM_soft_update();
	violet();
	
	_delay_ms(500);
	
	static uint8_t sw = 0;
	sw++;
	if(sw == 2){
		sw = 0;
	}

	if(sw == 0){ 
		B = 255;
		R = 0;
	}
	if(sw == 1){ 
		B = 0;
		R = 255;
	}
}




int main(void){
	
	PWM_START; // port Y as output
	DDRB |= (1<<PORTB5) | (1<<PORTB2) | (1<<PORTB1); // ports RGB as output
	
	TCCR0A |= (1<<COM0A1)| (1<<COM0A0) | (1<<WGM01) | (1<<WGM00); // fast PWM inverse
	TCCR0B |= (1<<CS01) | (1<<CS00); // scaler 64
	OCR0A = 10;
	
	TIMSK0 |= (1<<OCIE0A);
	sei();
	
	while(1){
	}
}

