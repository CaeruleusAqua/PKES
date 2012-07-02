/*
 * space.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

volatile uint16_t tickslinks=0;
volatile uint16_t ticksrechts=0;


volatile uint8_t uart_str_complete = 0;     // 1 .. String komplett empfangen
volatile uint8_t uart_str_count = 0;
volatile char uart_string[UART_MAXSTRLEN + 1] = "";


struct {
	unsigned bSbutton_S0 :1;
	unsigned bSbutton_S1 :1;
	unsigned bSbutton_S2 :1;
	unsigned bSbutton_S3 :1;
} S;


int16_t Motor_1_Speed=0;
int16_t Motor_2_Speed=0;
int16_t Motor_old_1_Speed=0;
int16_t Motor_old_2_Speed=0;
int16_t Motor_1_adjSpeed=0;
int16_t Motor_2_adjSpeed=0;
int16_t esum;
int16_t esuml;
int16_t esumr;

enum rich{
	rechts,
	links,
	gerade
}richtung;



