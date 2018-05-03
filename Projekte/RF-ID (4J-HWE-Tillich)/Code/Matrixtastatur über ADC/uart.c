/*
 * uart.c
 *
 *  Created on: 01.12.2012
 *      Author: mikrocontroller.net
 *         web: http://www.mikrocontroller.net
 *  sub Author: Pascal Gollor (www.pgollor.de)
 */


#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#include "uart.h"
#include "fifo.h" // erklärt im Artikel "FIFO mit avr-gcc"


// FIFO-Objekte und Puffer für die Ein- und Ausgabe

#define BUFSIZE_IN  0x0F
uint8_t inbuf[BUFSIZE_IN];
fifo_t infifo;

#define BUFSIZE_OUT 0xFF
uint8_t outbuf[BUFSIZE_OUT];
fifo_t outfifo;


void uart_init (unsigned long baudrate)
{
    uint8_t sreg = SREG;
    uint16_t ubrr = (uint16_t) ((uint32_t) F_CPU/(16UL*baudrate) - 1);

    UBRRH = (uint8_t) (ubrr>>8);
    UBRRL = (uint8_t) (ubrr);

    // Interrupts kurz deaktivieren
    cli();

    // UART Receiver und Transmitter anschalten, Receive-Interrupt aktivieren
    // Data mode 8N1, asynchron
    UCSRB = (1 << RXEN) | (1 << TXEN) | (1 << RXCIE);
    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);

    // Flush Receive-Buffer (entfernen evtl. vorhandener ungültiger Werte)
    do
    {
        // UDR auslesen (Wert wird nicht verwendet)
        UDR;
    }
    while (UCSRA & (1 << RXC));

    // Rücksetzen von Receive und Transmit Complete-Flags
    UCSRA = (1 << RXC) | (1 << TXC);

    // Global Interrupt-Flag wieder herstellen
    SREG = sreg;

    // FIFOs für Ein- und Ausgabe initialisieren
    fifo_init (&infifo,   inbuf, BUFSIZE_IN);
    fifo_init (&outfifo, outbuf, BUFSIZE_OUT);
}

// Empfangene Zeichen werden in die Eingangs-FIFO gespeichert und warten dort
ISR (USART_RXC_vect)
{
    _inline_fifo_put (&infifo, UDR);
}

// Ein Zeichen aus der Ausgabe-FIFO lesen und ausgeben
// Ist das Zeichen fertig ausgegeben, wird ein neuer SIG_UART_DATA-IRQ getriggert
// Ist die FIFO leer, deaktiviert die ISR ihren eigenen IRQ.
ISR (USART_UDRE_vect)
{
    if (outfifo.count > 0)
       UDR = _inline_fifo_get (&outfifo);
    else
        UCSRB &= ~(1 << UDRIE);
}

int uart_putc (const uint8_t c)
{
    int ret = fifo_put (&outfifo, c);

    UCSRB |= (1 << UDRIE);

    return ret;
}

void uart_puts (const char *s)
{
    do
    {
        uart_putc (*s);
    }
    while (*s++);
}

int uart_getc_nowait (void)
{
    return fifo_get_nowait (&infifo);
}

uint8_t uart_getc_wait (void)
{
    return fifo_get_wait (&infifo);
}




//------------------------------------------------------------------------------
void usart_write_P (const char *Buffer,...)
{
	va_list ap;
	va_start (ap, Buffer);

	int format_flag;
	char str_buffer[10];
	char str_null_buffer[10];
	char move = 0;
	char Base = 0;
	int tmp = 0;
	//char by;
	uint8_t by;
	char *ptr;

	//Ausgabe der Zeichen
	for(;;)
	{
		by = pgm_read_byte(Buffer++);
		if(by==0) break; // end of format string

		if (by == '%')
		{
			by = pgm_read_byte(Buffer++);
			if (isdigit(by)>0)
			{
				str_null_buffer[0] = by;
				str_null_buffer[1] = '\0';
				move = atoi(str_null_buffer);
				by = pgm_read_byte(Buffer++);
			}

			switch (by)
			{
			case '%':
				usart_write_char('%');
				break;
			case 's':
				ptr = va_arg(ap,char *);
				while(*ptr) { usart_write_char(*ptr++); }
				break;
			case 'b':
				Base = 2;
				goto ConversionLoop;
			case 'c':
				//Int to char
				format_flag = va_arg(ap,int);
				usart_write_char (format_flag++);
				break;
			case 'i':
				Base = 10;
				goto ConversionLoop;
			case 'o':
				Base = 8;
				goto ConversionLoop;
			case 'x':
				Base = 16;
				//****************************
				ConversionLoop:
				//****************************
				itoa(va_arg(ap,int),str_buffer,Base);
				int b=0;
				while (str_buffer[b++] != 0){};
				b--;
				if (b<move)
				{
					move -=b;
					for (tmp = 0;tmp<move;tmp++)
					{
						str_null_buffer[tmp] = '0';
					}
					//tmp ++;
					str_null_buffer[tmp] = '\0';
					strcat(str_null_buffer,str_buffer);
					strcpy(str_buffer,str_null_buffer);
				}
				usart_write_str (str_buffer);
				move =0;
				break;
			}
		}
		else
		{
			usart_write_char ( by );
		}
	}
	va_end(ap);
}

//----------------------------------------------------------------------------
