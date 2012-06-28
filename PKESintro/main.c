/*
 * main.c
 *
 *  Created on: Apr 16, 2012
 *      Author: Sebastian Zug
 *              Eclipse AVR Project
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/atomic.h>
#include "define.h"
#include "prototype.h"
#include "space.h"
#include "init.h"
#include "motor.h"
#include "button.h"
#include "sensors.h"
#include "interrupt.h"
#include "regler.h"
#include "debug.h"

int main(void) {
	init();
	sei();
	//enableACD();
	//lineInit();
	//distInit();
	VccOn(6);
	VccOn(7);
	_delay_ms(100);
	while (1) {
		//line();
		//dist();
		if (tickslinks < 500)
			setMotorBaseSpeed_1(500);
		else
			setMotorBaseSpeed_1(0);

		if (ticksrechts < 500)
			setMotorBaseSpeed_2(500);
		else
			setMotorBaseSpeed_2(0);

		if (pushButton(2)) {
			modMotorBaseSpeed_1(50);
			modMotorBaseSpeed_2(50);
		}
		if (pushButton(0)) {
			modMotorBaseSpeed_1(-50);
			modMotorBaseSpeed_2(-50);
		}
		if (pushButton(0)) {
			modMotorBaseSpeed_1(-50);
			modMotorBaseSpeed_2(-50);
		}
		if (pushButton(1)) {
			modMotorBaseSpeed_1(255);
			modMotorBaseSpeed_2(255);
		}
		adjSpeed();
	}

	return (1); // sollte nie erreicht werden
}

