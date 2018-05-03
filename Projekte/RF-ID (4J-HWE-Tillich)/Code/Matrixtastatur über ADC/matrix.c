/**
 *   @file matrix.c
 *
 *   @date 04.03.2013
 * @author Pascal Gollor
 *     web http://www.pgollor.de
 *
 * @copyright Dieses Werk ist unter einer Creative Commons Lizenz vom Typ
 * Namensnennung - Nicht-kommerziell - Weitergabe unter gleichen Bedingungen 3.0 Deutschland zugänglich.
 * Um eine Kopie dieser Lizenz einzusehen, konsultieren Sie
 * http://creativecommons.org/licenses/by-nc-sa/3.0/de/ oder wenden Sie sich
 * brieflich an Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 * -- englisch version --
 * @n This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Germany License. To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to Creative Commons, 444 Castro Street, Suite 900, Mountain View, California, 94041, USA.
 *
 */

#include "matrix.h"
#include "adc.h"

#include <util/delay.h>			// delay_ms


/**
 * @brief gedrueckte Taste
 * @return Taste
 *
 * ADC 4x4 Matrix
 *
 * @n Pin: U/mV
 * @n 1: 1019
 * @n 2: 509
 * @n 3: 339
 * @n 4: 817
 * @n 5: 453
 * @n 6: 313
 * @n 7: 683
 * @n 8: 408
 * @n 9: 291
 * @n 0: 371
 * @n A: 254
 * @n B: 239
 * @n C: 226
 * @n D: 214
 * @n *: 586
 * @n #: 271
 */
uint8_t matrix_getKey(void)
{
	uint8_t taste = 'x';

	uint16_t adc = adc_read_avg(MATRIX_PIN, 3);
	if (adc > 200)
	{
		// Zeit zum Entprellen
		_delay_ms(10);

		// Anschliessend Wert zum verwerten einlesen
		uint16_t wert = adc_read_avg(MATRIX_PIN, 3);

		// wenn der Wert < 200 ist, dann wurde eine Taste zu kurz gedrueckt
		if (wert < 200)
			return 'x';

		// solange warten bis die Taste wieder losgelassen wurde
		while (adc != 0)
		{
			adc = adc_read_avg(MATRIX_PIN, 3);
		}

		// Taste auf der 4x4 Matrix
		if (wert > 998)
			taste = '1';
		else if (wert > 800)
			taste = '4';
		else if (wert > 668)
			taste = '7';
		else if (wert > 573)
			taste = '*';
		else if (wert > 498)
			taste = '2';
		else if (wert > 443)
			taste = '5';
		else if (wert > 399)
			taste = '8';
		else if (wert > 363)
			taste = '0';
		else if (wert > 331)
			taste = '3';
		else if (wert > 306)
			taste = '6';
		else if (wert > 284)
			taste = '9';
		else if (wert > 265)
			taste = '#';
		else if (wert > 248)
			taste = 'A';
		else if (wert > 233)
			taste = 'B';
		else if (wert > 220)
			taste = 'C';
		else if (wert > 209)
			taste = 'D';
	}

	// Taste ausgeben
	return taste;
}
