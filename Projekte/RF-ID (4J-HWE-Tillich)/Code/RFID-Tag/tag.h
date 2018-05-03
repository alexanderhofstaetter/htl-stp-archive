#ifndef _Manchester_h
#define _Manchester_h

#include <stdint.h>

#define TX_PORT PORTB
#define TX_DDR DDRB
#define TX_PIN PB0

void initTag(void);

void sendeByte(const uint8_t byte);
//Einzelnes Byte senden

void sendeDaten(const uint8_t* data, uint16_t bytes);
//Daten aus beliebg. vielen Bytes senden

void sendeHIGHBit(unsigned char anzahl);
// Ein Manchester HIGH senden (01)

void sendeLOWBit(unsigned char anzahl);
// Ein Manchester LOW senden (10)

uint16_t checksumme(const uint8_t* data, uint16_t bytes);
// Zum Berechnen der Checksumme

#endif