/**
 *   @file adc.h
 *
 *   @date 18.03.2013
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

#ifndef _ADC_H
#define _ADC_H

#include <avr/io.h>


void adc_init(void);
uint16_t adc_read(uint8_t kanal);
uint16_t adc_read_avg(uint8_t kanal, uint8_t messungen);


#endif // _ADC_H_
