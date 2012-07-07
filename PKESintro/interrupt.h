/*
 * interrupt.h
 *
 *  Created on: 26.05.2012
 *      Author: time
 */

ISR( INT2_vect) {
	tickslinks++;
	if(tickslinks>120)ledOff(0);
	else ledOn(0);
}

ISR( INT3_vect) {
	ticksrechts++;
	if(ticksrechts>120)ledOff(1);
	else ledOn(1);
}


ISR(USART_RXC_vect)
{
  unsigned char nextChar;
  // Daten aus dem Puffer lesen
  nextChar = UDR1;
  ledOn(0);
  ledOn(1);
  ledOn(2);
  ledOn(3);
  if( uart_str_complete == 0 ) {	// wenn uart_string gerade in Verwendung, neues Zeichen verwerfen

    // Daten werden erst in uart_string geschrieben, wenn nicht String-Ende/max Zeichenlänge erreicht ist/string gerade verarbeitet wird
    if( nextChar != '\n' &&
        nextChar != '\r' &&
        uart_str_count < UART_MAXSTRLEN ) {
      uart_string[uart_str_count] = nextChar;
      uart_str_count++;
    }
    else {
      uart_string[uart_str_count] = '\0';
      uart_str_count = 0;
      uart_str_complete = 1;
      handle_command(uart_string);
    }
  }
}



