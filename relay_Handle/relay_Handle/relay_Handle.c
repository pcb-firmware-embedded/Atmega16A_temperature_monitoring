/*
* relay_Handle.c
*
* Created: 2/25/2026 6:54:46 PM
*  Author: Administrator
*/
#include "main.h"

void initialize_PORT();

uint8_t I_RH, D_RH, I_Temp, D_Temp, checkSum;
uint8_t insert_temp_for_lamp = 27,
		insert_temp_for_speaker = 30,
		insert_temp_for_relay = 33;

int main(void)
{
	char char_humidity[10], char_temperature[10];
	initialize_PORT();
	
	LCD_ini();
	UART_Init(51);
	
	_delay_ms(1000);
	UART_SendString("Bluetooth ready\r\n");
		
	while(1){
		send_First_Signal_to_DHT11();
		receive_Response_from_DHT11();

		I_RH = receive_data_from_DHT11();// humidity
		D_RH = receive_data_from_DHT11();
		I_Temp = receive_data_from_DHT11();// temperature
		D_Temp = receive_data_from_DHT11();
		checkSum = receive_data_from_DHT11();
		
		if((I_RH + D_RH + I_Temp + D_Temp) != checkSum){
			clearlcd();
			str_lcd("Error!!!");
		}
		else{
			itoa(I_RH, char_humidity, 10);
			itoa(I_Temp, char_temperature, 10);
			setpos(0,0);
			str_lcd("Temperature:");
			setpos(12,0);
			str_lcd(char_temperature);
			str_lcd("'C");
			
			setpos(1,1);
			str_lcd("Humidity:");
			setpos(11,1);
			str_lcd(char_humidity);
			str_lcd("%");
		}
		if(I_Temp > insert_temp_for_lamp){
			PORTA |= (1 << PIN_LAMP);
			_delay_ms(300);
			PORTA &= ~(1 << PIN_LAMP);
			_delay_ms(300);
		}
		if(I_Temp > insert_temp_for_speaker){
			PORTA |= (1 << PIN_SPEAKER);
			_delay_ms(100);
			} else{
			PORTA &= ~(1 << PIN_SPEAKER);
		}
		
		if(I_Temp > insert_temp_for_relay){
			PORTA |= (1 << PIN_RELAY);
			_delay_ms(100);
			} else{
			PORTA &= ~(1 << PIN_RELAY);
		}
		if(!(PINA & (1 << PIN_RESET))){
			insert_temp_for_lamp = 27;
			insert_temp_for_speaker = 30;
			insert_temp_for_relay = 33;
			PORTD |= (1 << 0);
		}
		UART_SendString("\r\nTemperature is");
		UART_SendString(I_Temp);
		UART_SendString("\r\n'C\r\n");
	}
}

void initialize_PORT (){
	DDRA |= (1 << PIN_LAMP) | (1 << PIN_RELAY) | (1 << PIN_SPEAKER);
	DDRA &= ~((1 << PIN_RESET)|(1 << PIN_INCREASE)|(1 << PIN_REDUCE)|(1 << PIN_SET));
	DDRD |= (1 <<0)|(1<<1)|(1 << 2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7);
	
	PORTA |= ((1 << PIN_RESET)|(1 << PIN_INCREASE)|(1 << PIN_REDUCE)|(1 << PIN_SET));
	PORTA &= ~((1 << PIN_LAMP) | (1 << PIN_RELAY) | (1 << PIN_SPEAKER));
	PORTD &= ~((1 <<0)|(1<<1)|(1 << 2)|(1<<3)|(1<<4)|(1<<5)|(1<<6)|(1<<7));
}