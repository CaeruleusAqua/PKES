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
#include <stdlib.h>
#include <util/atomic.h>
#include "define.h"
#include <util/setbaud.h>
#include "prototype.h"
#include "space.h"
#include "init.h"
#include "motor.h"
#include "button.h"
#include "sensors.h"
#include "interrupt.h"
#include "regler.h"
#include "debug.h"
#include "serial.h"

int main(void) {
	init();
	sei();
	//enableACD();
	//VccOn(6);
	//VccOn(7);
	//uint16_t s = 0;
	_delay_ms(100);
	while (1) {
		/*if (pushButton(0)) {
			tickslinks = 0;
			ticksrechts = 0;
			s = 382;

		}
		if (pushButton(1)) {
			tickslinks = 0;
			ticksrechts = 0;
			s = 573;

		}
		if (pushButton(2)) {
			tickslinks = 0;
			ticksrechts = 0;
			s = 764;

		}
		strecke(s);
		adjSpeed();
*/		_delay_ms(100);

	}

	return (1); // sollte nie erreicht werden
}

