/*
 * main.h
 *
 * Created: 2/26/2026 8:47:47 AM
 *  Author: Administrator
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#define F_CPU 8000000UL

#define PIN_LAMP 0
#define PIN_RELAY 1
#define PIN_SPEAKER 2
#define PIN_DHT11 3
#define PIN_RESET 4
#define PIN_SET 5
#define PIN_INCREASE 6
#define PIN_REDUCE 7

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

#include "LCD1602.h"
#include "DHT11.h"


#endif /* MAIN_H_ */