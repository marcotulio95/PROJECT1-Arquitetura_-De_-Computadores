/* ATmega8 with internal 4Mhz clock (6cycle + 64ms) */

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include "util/delay.h"

int main(void)
{
	DDRC = 0xFF;

   // infinite main loop
   while (1)
   {
	
	PORTC = 0x01; //  Liga Led na porta 01
	_delay_ms(2000); // Espera 2 segundo
	PORTC = 0X00; // Desliga o led na porta 01
	set_sleep_mode(SLEEP_MODE_PWR_SAVE);
	cli(); 	// desligar interrupções
	
	sleep_enable();	 // Ativa o Sleep Mode
	sei(); //Liga as interrupções
	sleep_cpu(); 
	cli();
	_delay_ms(5000);
	sleep_disable();
	sei();
	
   }
   
}