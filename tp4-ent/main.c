#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/delay.h>
#include <avr/interrupt.h>

#include "rgb.h"




int main(void){
	
	RGB_init();
	sei();
	
	RGB_setColor(255,0,255);

	
	
	while(1){
		


	}
}