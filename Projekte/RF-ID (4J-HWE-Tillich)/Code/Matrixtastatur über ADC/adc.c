/**
 *   @file adc.c
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


#include "adc.h"

/**
 * @brief ADC initialisieren
 *
 * Initialisieren fuer 16MHz
 * 16MHz / 128 = 125kHz
 * Der ADC sollte immer im Bereich von 50 - 200kHz arbeiten.
 */
void adc_init(void)
{
  uint16_t result;

  // Aref als Referenzspannung beim Atmega16/32
  ADMUX |= (0<<REFS1) | (0<<REFS0);

  // Teiler auf 128 stellen bei 16MHz = 125kHz
	ADCSRA |= (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);

	// ADC aktivieren
  ADCSRA |= (1<<ADEN);

  // dummy read
  ADCSRA |= (1<<ADSC); // single conversion
  while (ADCSRA & (1<<ADSC) ) {} // wait until ready
  result = ADCW; // der ADC muss ausgelesen werden da dieser den Wert sonst speichert
}

/**
 * @brief Messung
 * @param Kanal
 * @return 10bit ADC Wert
 */
uint16_t adc_read(uint8_t kanal)
{
  // Kanal waehlen, ohne andere Bits zu beeinflussen
  ADMUX = (ADMUX & ~(0x1F)) | (kanal & 0x1F);
  ADCSRA |= (1<<ADSC);            // single conversion
  while (ADCSRA & (1<<ADSC) ) {}  // wait until ready

  return ADCW;
}


/**
 * @brief Mehrfachmessung
 * @param Kanal
 * @param Haeufigkeit der Messungen
 * @return 10bit ADC Wert
 */
uint16_t adc_read_avg(uint8_t kanal, uint8_t messungen)
{
  uint32_t result = 0;

  for (uint8_t i = 0; i < messungen; ++i )
    result += adc_read(kanal);

  return (uint16_t)(result / messungen);
}
