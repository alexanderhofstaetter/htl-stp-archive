//----------------------------------------------------------
//(c) Strasser
//----------------------------------------------------------

#ifndef ELROBOT_H_INCLUDED
#define ELROBOT_H_INCLUDED

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#define LED_VL 4        //V wie Vlügel
#define LED_VR 1
#define LED_HR 2
#define LED_HL 8

#define LED_MODE_S 1
#define LED_MODE_R 0
#define LED_MODE_I 2

#define LED_EIN 1
#define LED_AUS 0

#define AKKUKRIT 195
#define AKKUNIED 205

void init(void);

void checkAkku(void);

void drive(unsigned char l, unsigned char r);

void beeper_start(void);
void beeper_stop(void);
void beeper_setfreq(unsigned char freq);

unsigned long getms(void);
unsigned long getus(void);

void led(unsigned char led, char status);
void mledg(int status);
void mledr(int status);


#endif // ELROBOT_H_INCLUDED
