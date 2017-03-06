 
 /**************************************************************************
 *      Fading Led
 *
 * Universidade Federal de Goiás
 * Microcontrolador Utilizado: AVR ATMega8
 * Grupo: Marco Túlio / Vitor do Vale Bernardo / Pablo Silva
 * Descrição: O codigo recebe os valores lido na entrada PWM atráves de um/
 *		   	  Potênciometro e irá ligar o LED proporcionalmente.
 * 
 ************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char i;

// Programa Principal
int main (void)
{
	
	DDRC = 0X00;
	
//PWM Inicialização
TCCR1A = 0b10000001; // fast PWM mode 8-bit on OC1A
TCCR1B = 0b00001010; // prescaling by 8

//Valores Iniciais;
OCR1A = 0x00;

DDRB = 0xFF; // Setando a PORTB como saída

// infinite loop
while(1)
{ 

	OCR1A = PINC0; // Recebendo o valor lido pelo PWM
	_delay_ms(10); 

}

}