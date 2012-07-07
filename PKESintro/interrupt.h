/*
 * interrupt.h
 *
 *  Created on: 26.05.2012
 *      Author: time
 */

ISR( INT2_vect) {
	tickslinks++;
	if (tickslinks > 120)
		ledOff(0);
	else
		ledOn(0);
}

ISR( INT3_vect) {
	ticksrechts++;
	if (ticksrechts > 120)
		ledOff(1);
	else
		ledOn(1);
}

ISR( USART1_RX_vect) {
	unsigned char nextChar;
	nextChar = UDR1;
	if (uart_str_complete == 0) {
		if (nextChar != '\n' && nextChar != '\r'
				&& uart_str_count < UART_MAXSTRLEN) {
			uart_string[uart_str_count] = nextChar;
			uart_str_count++;
		} else {
			uart_string[uart_str_count] = '\0';
			uart_str_complete = 1;

			_delay_ms(100);

			char tmp[uart_str_count];
			strcpy(tmp,uart_string);
			uart_str_count = 0;
			uart_str_complete = 0;
			handle_command(tmp);
		}
	}
}

