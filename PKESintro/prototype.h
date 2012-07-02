/*
 * prototype.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

void init();
void bar(int8_t data);
void setSpeed_1(int16_t speed);
void setSpeed_2(int16_t speed);
void setMotorBaseSpeed_1(int16_t speed);
void setMotorBaseSpeed_2(int16_t speed);
void modMotorBaseSpeed_1(int16_t speed);
void modMotorBaseSpeed_2(int16_t speed);
void modMotorSpeed_1(int16_t speed);
void modMotorSpeed_2(int16_t speed);
void setMotorSpeed_1(int16_t speed);
void setMotorSpeed_2(int16_t speed);
void strecke(uint16_t s);
ISR( INT3_vect);
ISR( INT2_vect);
void stopall();
void adjSpeed();
void line();
void lineInit();
void dist();
void setADC(uint8_t channel);
void display(int16_t number);
void blink(int8_t x);
void steuer(int16_t richtung);
uint8_t pushButton(uint8_t button);
uint16_t getData();
void USART0_Transmit(unsigned char data);
unsigned char USART0_Receive(void);
void handle_command(char com[]);
char * strcat(char *dest, char *src);
