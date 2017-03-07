#define F_CPU 1000000L
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <util/delay.h>

unsigned char i=5;

ISR(TIMER1_COMPA_vect){
	i--;
	if(i==0){
		sleep_disable();
		cli();
		PORTB = (1<<PB1);
	}
}
int main(){
	DDRB = (1<<DDB1);
	PORTB = (1<<PB1);
	
	i = USART_Receive();
	
	OCR1A = (F_CPU/1024)-1; //((Frequencia/Prescaler)*tempo)-1
	
	TCCR1B |= (1<<WGM12); //Compare to OCR1A
	TIMSK |= (1<< OCIE1A); //Interrup on Compare
	
	TCCR1B |= (1<<CS12)|(1<<CS10);//Prescaller 1024
	
	_delay_ms(2000);
	PORTB = (0<<PB1);
	
	sei(); //Enable Interruption
	set_sleep_mode(SLEEP_MODE_IDLE);
	sleep_enable();
	sleep_mode();
	
	while(1){
		
	}
}
