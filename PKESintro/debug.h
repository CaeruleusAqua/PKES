/*
 * debug.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */
void blink(int8_t x) {
	ledOff(0);
	ledOff(1);
	ledOff(2);
	ledOff(3);
	_delay_ms(200);
	for (int i = 0; i < x; i++) {
		ledOn(0);
		ledOn(1);
		ledOn(2);
		ledOn(3);
		_delay_ms(200);
		ledOff(0);
		ledOff(1);
		ledOff(2);
		ledOff(3);
		_delay_ms(200);
	}

}

void display(int16_t number) {
	blink(1);
	ledOff(0);
	ledOff(1);
	ledOff(2);
	ledOff(3);
	if (number & (1 << 0)) {
		ledOn(0);
	}
	if (number & (1 << 1)) {
		ledOn(1);
	}
	if (number & (1 << 2)) {
		ledOn(2);
	}
	if (number & (1 << 3)) {
		ledOn(3);
	}
	while (1) {
		if (pushButton(0))
			break;
	}
	blink(2);
	if (number & (1 << 4)) {
		ledOn(0);
	}
	if (number & (1 << 5)) {
		ledOn(1);
	}
	if (number & (1 << 6)) {
		ledOn(2);
	}
	if (number & (1 << 7)) {
		ledOn(3);
	}
	while (1) {
		if (pushButton(0))
			break;
	}
	blink(3);
	if (number & (1 << 8)) {
		ledOn(0);
	}
	if (number & (1 << 9)) {
		ledOn(1);
	}
	if (number & (1 << 10)) {
		ledOn(2);
	}
	if (number & (1 << 11)) {
		ledOn(3);
	}
	while (1) {
		if (pushButton(0))
			break;
	}
	blink(4);
	if (number & (1 << 12)) {
		ledOn(0);
	}
	if (number & (1 << 13)) {
		ledOn(1);
	}
	if (number & (1 << 14)) {
		ledOn(2);
	}
	if (number & (1 << 15)) {
		ledOn(3);
	}
	while (1) {
		if (pushButton(0))
			break;
	}

}

void bar(int8_t channel){
	setADC(channel);
	int16_t data=0;
	_delay_us(125);
	for (int i = 0; i < 8; i++) {
			data += getData();
		}
		data >>= 3;
	if (data < 100) {
				ledOff(0);
				ledOff(1);
				ledOff(2);
				ledOff(3);
			}
			if (data < 300 && data >= 100) {
				ledOff(0);
				ledOff(1);
				ledOff(2);
				ledOn(3);
			}
			if (data < 500 && data >= 300) {
				ledOff(0);
				ledOff(1);
				ledOn(2);
				ledOn(3);
			}
			if (data < 800 && data >= 500) {
				ledOff(0);
				ledOn(1);
				ledOn(2);
				ledOn(3);
			}
			if (data >= 800) {
				ledOn(0);
				ledOn(1);
				ledOn(2);
				ledOn(3);
			}
}
