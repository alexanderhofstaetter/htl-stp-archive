#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <stdint.h>

#include "../Global/Manchester.h"
#include "../Global/LCD.h"

#include "reader.h"

volatile uint32_t samples = 0;
volatile uint8_t samplesReady = 0;
volatile int8_t sampleCount = DATA_SAMPLES - 1;
uint8_t receiving = 0, data = 0, connectionCount = 0;

int main(void)
{
    
    struct Queue q = {.size = 0};
    uint16_t chksm;
    
    LCD_init();
    initRX();
    startRX();
    
    while(1)
    {
        if (receiving && samplesReady && interpretSamples(getSamples()))
        {
            pushQ(&q,data);
            
            if (q.size == 14) break;
        }
    }
    
    stopRX();
    
    chksm = checksumme(q.data,12);
    
    CLEAR_BIT(LED_PORT,LED);
    
    if (chksm == ((q.data[12] << 8) | q.data[13])) // alles OK, checksumme passt!!
        SET_BIT(LED_PORT,LED);
    
    LCD_string(q.data);
    
    return 0;
    
}

int8_t popQ(struct Queue* queue)
{
    unsigned char i = 0, j = 1;
    char item = queue->data[0];
    
    /* Alle Elemente ins strukt */
    for (; j < queue->size; ++j, ++i)
    { queue->data[i] = queue->data[j]; }
    
    /* Letztes Element löschen */
    queue->data[--queue->size] = 0;
    
    return item;
}

void pushQ(struct Queue* queue, const uint8_t c)
{
    if (queue->size < BUFFER_SIZE)
    { queue->data[queue->size++] = c; }
}

uint16_t checksumme(const uint8_t* data, uint16_t bytes)
{
    
    uint16_t summe1 = 0xFF;
    uint16_t summe2 = 0xFF;
    
    uint16_t laenge;
    
    while (bytes)
    {
        /* Maximale Länge bevor Overflow ensteht */
        laenge = (bytes > 20) ? 20 : bytes;
        
        bytes -= laenge;
        
        do
        {
            summe1 += *(data++);
            summe2 += summe1;
        }
        
        while (--laenge);
        
        summe1 = (summe1 & 0xFF) + (summe1 >> 8);
        summe2 = (summe2 & 0xFF) + (summe2 >> 8);
    }
    
    /* Zur Sicherheit unnötiges abschneiden */
    summe1 = (summe1 & 0xFF) + (summe1 >> 8);
    summe2 = (summe2 & 0xFF) + (summe2 >> 8);
    
    /* Beiden Summen als 16 Bit Wert zurückgeben*/
    return summe2 << 8 | summe1;
}

uint32_t getSamples(void)
{
    /* Flag zurücksezen */
    samplesReady = 0;
    
    return samples;
}

void initRX(void)
{
    /* RX Pin als Input setzen */
    CLEAR_BIT(RX_DDR,RX_PIN);
    
    /* LED Pin als Ausgang setzen */
    SET_BIT(LED_DDR,LED);
    
    /* Enable pin change interrupt */
    PCICR |= (1<<PCIE0);
    
    /* Pin change ISR auf PCINT1 (PB1) */
    SET_BIT(PCMSK0,PCINT1);
    
    /* Timer1 mit clk/4096 prescaler einschalten */
    TCCR1A |= 0x0D;
    
    /* overflow interrupt für Timer1 */
    SET_BIT(TIMSK0,TOIE1);
    
    /* Sample alle 100 µs */
    OCR0A = SAMPLE_TIME;
    
    /* output compare interrupt für Timer0 */
    SET_BIT(TIMSK0,OCIE0A);
    
    /* Timer0 mit clk/8 prescaler, ergibt 1µs pro zyklus, -> bei 8Mhz.
       Timer0 wird benutzt zum samplen */
    SET_BIT(TCCR0B,CS01);
}

void startRX(void)
{
    uint8_t preambleBit, lows = 0, highs = 0;
    
    SET_BIT(LED_PORT,LED);
    
    /* ISR gloabl freigeben*/
    sei();
    
    /* Zurücksetzen */
    TCNT0 = TCNT1 = 0;
    
    /* Einschalten während SYNC, -> wird 0 wenn die datenübertragung aus ist*/
    receiving = 1;
    
    /* Individuelle Bits zählen */
    sampleCount = 3;

    samples = 0;
    
    /* so lange daten empfangen werden */
    while (receiving)
    {
        if (samplesReady)
        {
            /* bit abfragen */
            preambleBit = getSamples();
            
            sampleCount = 3;
            
            /* Die Präabmel enthällt 6 low bits (10) und 2 high bits (01), alles ander setzen den counter wrt zurück auf 0 */
            if (preambleBit == LOW)
            {
                if (!highs)
                    ++lows;
                
                else
                    lows = highs = 0;
            }
            
            else if (preambleBit == HIGH)
            {
                if (lows >= 6)
                {
                    if (++highs >= 2)
                        break;
                }
                
                else
                    lows = highs = 0;
            }
            
            else
            {
                lows = highs = 0;
                sampleCount = 2;
            }
        }
    }
    
    sampleCount = DATA_SAMPLES - 1;
}


void stopRX(void)
{
    receiving = 0;
    
    /* Timer/Counter aussschalten*/
    CLEAR_BIT(TIMSK0,OCIE0A);
    CLEAR_BIT(LED_PORT,LED);
}

uint8_t interpretSamples(const uint32_t samps)
{
    int8_t i = 7;
    
    uint8_t bit;
    
    for (; i >= 0; --i)
    {
        /* Aktuelles Bit holen */
        bit = (samps >> (i*4)) & 0x0F;
        
        if (bit == HIGH)
            SET_BIT(data,i);
        
        else if (bit == LOW)
            CLEAR_BIT(data,i);
        
        else return 0;
    }
    
    return 1;
}

ISR(TIMER1_OVF_vect)
{
    if (++connectionCount >= CONNECTION_TIME)
    {
        connectionCount = 0;
        
        stopRX();
    }
}

ISR(PCINT0_vect)
{
    /* Timer setzen, was er bei einem pin change sein soll, 52 istatt 50 wegen Overhead des ISR Aufruf*/
    TCNT0 = 52;
}

ISR(TIMER0_COMPA_vect)
{
    /* Wenn aktuelles Sample hight ausliest -> setze aktuelles bit auf HIGH */
    if (IS_SET(RX_PORT,RX_PIN))
    {
        /* timer nach ganzem bit wieder resetten */
        TCNT0 = 1;
        
        SET_BIT(samples,sampleCount);
    }
    
    /* sonst aktuelles bit auf LOW setzen */
    else
    {
        /* timer nach sampling zurücksetzen */
        TCNT0 = 1;
        
        CLEAR_BIT(samples,sampleCount);
    }
    
    /* wenn bit fertig ist -> samplesReady flag setzen */
    if (! sampleCount--)
    {
        samplesReady = 1;
        sampleCount = DATA_SAMPLES - 1;
    }
}