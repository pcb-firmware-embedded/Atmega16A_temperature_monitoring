/*
 * DHT11.h
 *
 * Created: 2/26/2026 9:38:06 AM
 *  Author: Administrator
 */ 


#ifndef DHT11_H_
#define DHT11_H_

#include "main.h"

void send_First_Signal_to_DHT11();
void receive_Response_from_DHT11();
uint8_t receive_data_from_DHT11();

#endif /* DHT11_H_ */