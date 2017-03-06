 /**************************************************************************
 *      Comununicação entre dois Microcontroladores Utilizando  SPI (Master)
 *
 * Universidade Federal de Goiás
 * Microcontrolador Utilizado: AVR ATMega8
 * Grupo: Marco Túlio / Vitor do Vale Bernardo / Pablo Silva
 * Descrição: Codigo Master irá enviar comandos pela comunicação SPI para o slave
 *            O comando ira dizer o estado do LED: ligado ou desligado.
 * 
 ************************************************************************/
    

#define F_CPU 4000000UL           // clock do microcontrolador
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
 
/////////////////////////////configuração dos pinos utilizados //////////////////////////////////////
 
#define MOSI         PB3
#define MISO         PB4
#define SCK          PB5
#define SS           PB2
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  void SPI_inicializa(void)
  {
      DDRD =0xFF;
      DDRB |= ((1<<MOSI)|(1<<SCK)|(1<<SS));    //MOSI, SCK and SS são saidas(se for usar dois mestres então deve-se o SS como entrada) 
      DDRB &= (~(1<<MISO));                    //MISO é entrada
      PORTB |= (1<<SS);                        //inicia com SS em nivel alto
      //SPE : habilita SPI
      //MSTR: modo  Master 
      //SPIE:  habilita interrupção de SPI
      //SPCR = ((1<<SPE)|(1<<MSTR)|(1<SPR1)|(1<SPR0));    //(1<SPR1)|(1<SPR0) : FOSC/128
      SPCR = ((1<<SPE)|(1<<MSTR)|(1<SPR0));    //(1<SPR0) : FOSC/16
  }
   
  void SPI_envia_byte(char dados)
  {
      PORTB &= (~(1<<SS));    //coloca SS em nivel baixo (0), para transferir dados
      SPDR = dados;        //inicializa transferencia
      while(!(SPSR & (1<<SPIF)));    //espera fim de transmissão
      PORTD = SPDR;//escreve no port D o dado recebido
      PORTB |= (1<<SS);    //coloca SS em nivel alto (1), pois é o fim da transmissão.
      _delay_ms(1);//tempo para slave colocar dados no registrador
  }
   
  int main(void) 
  {
    
    SPI_inicializa();//inicializa SPI
    sei();//habilita interrupções
   
    while(1)
	{
      SPI_envia_byte(0X01); /*** Envia o primeiro comando: LIGAR LED***/
      _delay_ms(1000); /*** Delay de 1 segundo ***/
	   SPI_envia_byte(0x00); /*** Envia o segundo comando: DESLIGAR LED ***/
	   _delay_ms(1000);  /*** Delay de 1 segundo ***/
  }
   
    return 0;
  }