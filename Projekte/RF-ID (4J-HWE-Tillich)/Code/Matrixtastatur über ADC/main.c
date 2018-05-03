/*
 * main.c
 *
 *  Created on: 25.01.2013
 *      Author: kalle
 */

#include <avr/io.h>
#include <avr/interrupt.h>	// sei
#include <util/delay.h>			// delay_ms

#include "uart.h"						// uart (RS232)
#include "adc.h"
#include "matrix.h"


#define CR "\r\n"

#define BAUDRATE 9600


int main()
{
	adc_init();

	// initialisiere uart
	usart_init(BAUDRATE);
	sei();

	_delay_ms(100);
	printf("-- start --" CR CR);
	_delay_ms(100);



	while (1)
	{
		uint8_t taste = matrix_getKey();

		// Taste ausgeben
		printf("Taste: %c" CR, taste);
		uart_flush();
	}

	return 0;
}
