/*
 * serial.h
 *
 *  Created on: 24.05.2012
 *      Author: time
 */

void USART1_Transmit(char data) {

	while (!(UCSR1A & (1 << UDRE1)))
		; // Wait for empty transmit buffer

	UDR1 = data; // Put data into buffer, sends the data
}

void uart_puts(char *s) {
	while (*s) { /* so lange *s != '\0' also ungleich dem "String-Endezeichen(Terminator)" */
		USART1_Transmit(*s);
		s++;
	}
}

void handle_command(char *com) {
	if (com[0] == 'b') { //Version Handler
		uart_puts("Robby serial Interface");
	} else

	if (com[0] == 'D') {//SET MOTOR SPEED
		if (!com[1]) {
			uart_puts("error");
			return;
		}
		int l = 0, r = 0, i = 2;
		while (com[i] >= '0' && com[i] <= '9') {
			l *= 10;
			l += (com[i] - '0');
			i++;
		}
		i++;
		while (com[i] >= '0' && com[i] <= '9') {
			r *= 10;
			r += (com[i] - '0');
			i++;
		}
		char s[8];
		uart_puts(itoa(r, s, 10));
		setMotorBaseSpeed_1(l);
		setMotorBaseSpeed_2(r);
	} else

	if (com[0] == 'E') {//GET MOTOR SPEED
		char sr[30];
		char sl[30];
		char dest[30] = "e,";
		strcat(dest, itoa(Motor_1_Speed, sr, 10));
		strcat(dest, ",");
		strcat(dest, itoa(Motor_2_Speed, sl, 10));
		uart_puts(dest);
	} else if (com[0] == 'I') {//SET ADC
		if (!com[1]) {
			uart_puts("error");
			return;
		}
		setADC(com[2] - '0');
		char s[20];
		char dest[] = "i,";
		strcat(dest, utoa(getData(), s, 10));
		uart_puts(dest);
	} else  {
		uart_puts("unknown command");
	}

}
