#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

unsigned char i;

// main program
int main (void)
{
//PWM Initialisation
TCCR1A = 0b10000001; // fast PWM mode 8-bit on OC1A
TCCR1B = 0b00001010; // prescaling by 8

//Initial value;
OCR1A = 0x00;

DDRB = 0xFF; // set port B for output

// infinite loop
while(1)
{ 

for(i=0;i<255;i++)
{
	OCR1A = i;
	_delay_ms(10); 
}

for(i=255;i>0;i--)
{
	OCR1A = i;
	_delay_ms(10); 
}

}

}