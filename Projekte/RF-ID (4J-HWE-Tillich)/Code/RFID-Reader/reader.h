
#ifndef __ManchesterRX__
#define __ManchesterRX__

#include <stdint.h>

#define RX_DDR DDRB
#define RX_PORT PINB
#define RX_PIN PB3

#define LED PD7
#define LED_PORT PORTD
#define LED_DDR DDRD

#define HIGH 0b0011
#define LOW  0b1100

#define CONNECTION_TIME 77

#define BUFFER_SIZE 128

struct Queue
{
    uint8_t data[BUFFER_SIZE];
    
    uint8_t size;
};

int8_t popQ(struct Queue* queue);

void pushQ(struct Queue* queue, const uint8_t c);

uint8_t interpretSamples(const uint32_t samps);

void initRX(void);

void startRX(void);
void stopRX(void);

uint32_t getSamples(void);

uint16_t checksumme(const uint8_t* data, uint16_t bytes);
// Zum Berechnen der Checksumme

#endif
