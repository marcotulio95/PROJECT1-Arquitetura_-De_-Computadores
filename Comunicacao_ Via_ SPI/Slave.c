 
 /**************************************************************************
 *      Comununica��o entre dois Microcontroladores Utilizando  SPI (Slave)
 *
 * Universidade Federal de Goi�s
 * Microcontrolador Utilizado: AVR ATMega8
 * Grupo: Marco T�lio / Vitor do Vale Bernardo / Pablo Silva
 * Descri��o: Codigo Slave ir� receber os dados enviados pelo Master e colocara no PORTD,
 *            Ligando e desligando o LED.
 * 
 ************************************************************************/
    
   #define F_CPU 4000000UL           // Definindo o Clock do Microcontrolador
   #include <avr/io.h>
   #include <avr/interrupt.h>
   
   /*********************************
   *	Definindo os Registradores  *
   *********************************/
   
   #define MOSI     PINB3 /*******Definindo o PINB3 como entrada********/
   #define MISO     PINB4 /********Definindo o PINB4 como sa�da********/
   #define SCK      PINB5 /********Definindo o PINB5 como entrada********/
   #define DDR_SPI  DDRB
    
   char enviar=0;
    
   /*********************************
   *	Inicializando			    *
   *********************************/
   
   void SPI_Slave_inicializa(void)
   {
       DDR_SPI = (1<<MISO);
       SPCR = (1<<SPE)/*|(1<<CPOL)*/|(1<<SPIE); /****Aviva o SPI / polaridade do clock / habilita interrup��o de SPI ****/
   }
   
   /**** Vetor de Interrup��o *****/
   ISR (SPI_STC_vect)                         
   {
     SPDR = enviar; //envia dado anteriormente recebido
     PORTD = SPDR;
	 PORTC = SPDR;
     enviar = SPDR;
   }
   
   /*********************************
   *	Fun��o Principal		    *
   *********************************/
   int main(void) 
   { 
       SPI_Slave_inicializa();
       DDRD = 0xFF;
       DDRC = 0XFF;
	   sei();
	   
	   while(1){
		   
	   }

   }