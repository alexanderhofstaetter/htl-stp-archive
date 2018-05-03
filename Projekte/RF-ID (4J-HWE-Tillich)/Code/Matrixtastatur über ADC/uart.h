/*
 * uart.h
 *
 *  Created on: 01.12.2012
 *      Author: mikrocontroller.net
 *         web: http://www.mikrocontroller.net
 *  sub Author: Pascal Gollor (www.pgollor.de)
 */

#ifndef UART_H_
#define UART_H_


#include <avr/io.h>
#include <avr/pgmspace.h>
#include <stdio.h>

extern void uart_init (unsigned long);
extern int uart_putc (const uint8_t);
void uart_puts (const char *s);
extern uint8_t uart_getc_wait (void);
extern int uart_getc_nowait (void);

void usart_write_P (const char *Buffer,...);

#define usart_init(baudrate) uart_init(baudrate);
#define usart_write_char(c) uart_putc(c);
#define usart_write_str(c) uart_puts(c);
#define usart_write(format, args...)   usart_write_P(PSTR(format) , ## args);
#define printf(format, args...) usart_write_P(PSTR(format), ## args);

static inline void uart_flush (void)
{
	while (UCSRB & (1 << UDRIE));
}


#endif /* UART_H_ */
