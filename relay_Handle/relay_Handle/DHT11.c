// /*
//  * DHT11.c
//  *
//  * Created: 2/26/2026 9:38:19 AM
//  *  Author: Administrator
//  */ 
// 
#include "DHT11.h"

uint8_t data = 0; 

void send_First_Signal_to_DHT11(){
	DDRA |= (1 << PIN_DHT11);
	PORTA &= ~(1 << PIN_DHT11);
	_delay_ms(20);
	PORTA |= (1 << PIN_DHT11);
}

void receive_Response_from_DHT11(){
	DDRA &= ~(1 << PIN_DHT11);
	while(PINA & (1 << PIN_DHT11));
	while((PINA & (1 << PIN_DHT11))==0);
	while(PINA & (1 << PIN_DHT11));
}
// 
uint8_t receive_data_from_DHT11(){
	for(int i = 0; i < 8; i++){
		while((PINA & (1<<PIN_DHT11))==0);
		_delay_us(30);
		if(PINA & (1<<PIN_DHT11))/* if high pulse is greater than 30ms */
		data = (data<<1)|(0x01);	/* then its logic HIGH */
		else			/* otherwise its logic LOW */
		data = (data<<1);
		while(PINA & (1<<PIN_DHT11));
	}
	return data;
}

