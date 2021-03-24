/*
 * finger_3.c
 *
 * Created: 7/23/2018 4:45:28 PM
 * Author : acpas
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif 

#define D4 eS_PORTB1
#define D5 eS_PORTB2
#define D6 eS_PORTB3
#define D7 eS_PORTB4
#define RS eS_PORTC0
#define EN eS_PORTC1
#define U_TRIG	PINC0
#define U_ECHO	PIND2
#define GREEN	PINB7

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lcd.h"
#include "r305.h"
	
	
	void usart_init();
	void usart_string_transmit(char *string);
	void usart_data_transmit(unsigned char data );
	unsigned char usart_data_receive( void );


	unsigned char cmd1[]={"AT"};
	unsigned char cmd2[]={"AT+CMGF=1"};
	unsigned char cmd3[]={"AT+CMGS="};
	unsigned char cmd4[]={"You have received a Item"};
	unsigned char cmd5[]={"+94764642025"};
	unsigned char cmd6[]={"AT+CSCA=\"+947100003\""};
		unsigned char cmd7[]={"+94764732800"};

	
static volatile int pulse = 0;
static volatile int i=0,k=0,t=1;
uint16_t len,ret;

//gsm 
int dilax(){
	
	int a,k;

		_delay_ms(500);
		
		for(a=0;cmd1[a]!='\0';a++)
		
		{
			UDR=cmd1[a];
			_delay_ms(100);
		}
		
		UDR = ('\r');
		_delay_ms(500);
		
		
		for(a=0;cmd2[a]!='\0';a++)
		{
			UDR = cmd2[a];
			_delay_ms(100);
		}
		
		UDR = ('\r');
		_delay_ms(500);
		
		for(a=0;cmd3[a]!='\0';a++)
		{
			UDR = cmd3[a];
			_delay_ms(100);
		}
		
		UDR = ('"');
		_delay_ms(100);
		
		
		for(a=0;cmd5[a]!='\0';a++)
		{
			UDR = cmd5[a];
			_delay_ms(100);
		}
		
		UDR = ('"');
		_delay_ms(100);

		UDR = ('\r');
		_delay_ms(500);
		
		for(a=0;cmd4[a]!='\0';a++)
		{
			UDR = cmd4[a];
			_delay_ms(100);
		}
		UDR =(26);
		_delay_ms(100);
		PORTD &= ~(1<<PORTD6);
	}
	
	


int thanu(){
	
	
	int a,k;


		_delay_ms(500);
		
		for(a=0;cmd1[a]!='\0';a++)
		
		{
			UDR=cmd1[a];
			_delay_ms(100);
		}
		
		UDR = ('\r');
		_delay_ms(500);
		
		
		for(a=0;cmd2[a]!='\0';a++)
		{
			UDR = cmd2[a];
			_delay_ms(100);
		}
		
		UDR = ('\r');
		_delay_ms(500);
		
		for(a=0;cmd3[a]!='\0';a++)
		{
			UDR = cmd3[a];
			_delay_ms(100);
		}
		
		UDR = ('"');
		_delay_ms(100);
		
		
		for(a=0;cmd7[a]!='\0';a++)
		{
			UDR = cmd7[a];
			_delay_ms(100);
		}
		
		UDR = ('"');
		_delay_ms(100);

		UDR = ('\r');
		_delay_ms(500);
		
		for(a=0;cmd4[a]!='\0';a++)
		{
			UDR = cmd4[a];
			_delay_ms(100);
		}
		UDR =(26);
		_delay_ms(100);
		PORTD &= ~(1<<PORTD6);
	}
	
	


void usart_init()
{
	UBRRH = 0;
	UBRRL =51;
	UCSRB|= (1<<RXEN)|(1<<TXEN);
	UCSRC |= (1 << URSEL)|(3<<UCSZ0);
}

void usart_data_transmit(unsigned char data )
{
	while ( !( UCSRA & (1<<UDRE)) )
	;
	UDR = data;
	_delay_ms(1);
}

void usart_string_transmit(char *string)
{
	while(*string)
	{
		usart_data_transmit(*string++);
	}
}

unsigned char usart_data_receive( void )
{
	while ( !(UCSRA & (1<<RXC)) )
	;
	return UDR;
}


int ir(){
	
		DDRA=0b10000111;
		DDRB = 0b00000000;

		
		if (!bit_is_set(PINB, 0))
		{
				PORTA=0b10000001;
			_delay_ms(150);
			
			
		}
		if (!bit_is_set(PINB, 2))
		{
				PORTA =0b10000010;
				dilax();
			_delay_ms(150);
		}
		if (!bit_is_set(PINB, 4))
		{
				PORTA =0b10000100;
				thanu();
				
			_delay_ms(150);
		}
		//PORTA=0b10000000;
		//PORTA |= (1<<PA7);
		PORTA &= ~((1<<PINA0)|(1<<PINA1)|(1<<PINA2));
		
}
int fun1(){
	int s=1;
	while(s)
	{
		PORTA |= (1<<PA3);
	//	PORTC |= (1<<PINC2);
		_delay_ms(100);
		
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA4);
			_delay_us(2180);
			PORTA &= ~(1<<PA4);
			_delay_us(17860);
			
		}
		_delay_ms(4000);
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA4);
			_delay_us(1250);
			PORTA &= ~(1<<PA4);
			_delay_us(19500);
	s=0;
	}
	}
  }
int fun2(){
	int s=1;
	while(s)
	{
		PORTA |= (1<<PA3);
		_delay_ms(100);
		
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA5);
			_delay_us(2180);
			PORTA &= ~(1<<PA5);
			_delay_us(17860);
			
		}
		_delay_ms(4000);
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA5);
			_delay_us(1250);
			PORTA &= ~(1<<PA5);
			_delay_us(19500);
			s=0;
		}
	}
}
int fun3(){
	int s=1;
	while(s)
	{
		PORTA |= (1<<PA3);
		PORTC |= (1<<PINC2);
		_delay_ms(100);
		
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA6);
			
			_delay_us(2180);
			PORTA &= ~(1<<PA6);
			_delay_us(17860);
			
		}
		_delay_ms(4000);
		for(int i=0;i<50;i++){
			PORTA |= (1<<PA6);
			_delay_us(1250);
			PORTA &= ~(1<<PA6);
			_delay_us(19500);
			s=0;
		}
	}
}

	ISR(INT0_vect)
	{
		if(i == 1)
		{
			TCCR1B = 0;
			pulse = TCNT1;
			TCNT1 = 0;
			i = 0;
		}

		if(i==0)
		{
			TCCR1B |= 1<<CS10;
			i = 1;
		}
	}


void tx (unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));				// wait while register is free
	UDR = data;									// load data in the register
}

unsigned char rx (void)
{
	while(!((UCSRA) & (1<<RXC)));					// wait while data is being received
	return UDR;									// return 8-bit data
}
int finger(){
	if(t>3){t=1;}
	uint16_t code;
	char *arr = malloc(sizeof(char)*16);
	
	
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRB = 0xFF;
	DDRA=0xFF;
	finger_init();
	code = finger_read();
	if(code!=2){
		//_delay_ms(1000);
		
		
		
		
		
		code = finger_generate_char_file(1);
		
		arr = finger_get_response_string(code);
		
		code = finger_search();
		if(code!=0){
			
			switch(code){
				case 10752:
				
				PORTA= fun1();
				k=0;
				_delay_ms(10);
				break;
				
				case 11520:
				//PORTC |= (1<<PINC2);
				PORTA= fun2();
				k=0;
				_delay_ms(10);
				break;
				
				case 512:
				//PORTC |= (1<<PINC2);
				PORTA= fun3();
				k=0;
				_delay_ms(10);
				break;
				k=0;
				PORTC &= ~(1<<PINC2);
			}
		}
		
		else{
			PORTD=0b10000000;
			_delay_ms(4000);
			PORTD=0b00000000;
			k=k+t;
			if(k>6){k=0;}
			if(k==6){
				PORTC=0b10000010;
				_delay_ms(4000);
				PORTC=0b00000000;
				k=0;
			}
		}
		t++;
	}
	//main();
}
int main(void)
{	
 usart_init();

  
while(1){
  
	  PORTA |= (1<<PINA7) ;
	 // PORTA=0b10000000;
	  _delay_ms(20);
	  ir();
	  finger();
	   
  
	  
	  PORTA &= ~(1<<PINA7);
	  _delay_ms(30);
	 
  
}
	
}

