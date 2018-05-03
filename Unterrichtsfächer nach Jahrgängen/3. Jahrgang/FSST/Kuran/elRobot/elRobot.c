#include "elRobot.h"

volatile long htick, ltick;


void init(void)
{
    MCUCR |= (1<<JTD); //Jtag deaktivieren
    MCUCR |= (1<<JTD);

    CLKPR = 0b10000000;
	CLKPR = 0;


    DDRB = 0b11001111;  //LED INIT MOTOR_INIT   BEEPER_INIT;
    DDRD = 0b10001100;

    DDRF |= 0b11100000; //Motor Steuer Bits
    DDRC |= 0b01000000;

    ADCSRA = 0b10000101;  //AKKU ADC init

    TCCR4A = 0b00100001;  //Rechtes Rad
    TCCR4C |= 0b00001001;  //Linkes Rad
    TCCR4B = 0b00000001;

    TCCR1B = 0b11000100;    //Impulsgeber rechts start
    TIMSK1 = 0b00100000;

    TCCR3B = 0b11000100;    //Impulsgeber links start
    TIMSK3 = 0b00100000;

    TCNT1 = 0;
    TCNT3 = 0;

    TCCR0A = 0b00000010;        //Timer0 einstellungen CTC Mode top = OCR0A; toggle OCR0A output on compare Match
    TCCR0B = 0b00000011;        //Prescaler auf CLK/64 setzen
    TIMSK0 = 0b00000010;
    OCR0A = 255;

    htick =ltick = 0;

    sei();
}


void checkAkku(void)
{
    static int adcstate;
    static unsigned char flag;
    static int x;
    int i = 0, j = 0;

    if(adcstate == 0)
    {
        adcstate = 255;
    }

    ADMUX = 0b00100100;

    ADCSRA |= (1<<ADSC);
    while(ADCSRA & (1<<ADSC));
    adcstate = ADCH;

    if(adcstate < AKKUKRIT)
    {
        if(++x >= 100)
        {

        }

        while(1 && x >= 100)
        {
            PORTB &= 0xF0;
            PORTB |= 1<<flag;

            if(flag++ >= 3) {flag = 0;}

            for(i = 0; i < 10000; i++) for(j = 0; j < 10; j++);
        }
    }
    else
    {
        x = 0;
    }


    return;
}


void led(unsigned char ledv, char state)
{
    ledv &= 0x0F;

    switch(state)
    {
    case LED_MODE_R:
        PORTB &= ~(ledv);
        break;
    case LED_MODE_S:
        PORTB |= ledv;
        break;
    case LED_MODE_I:
        PORTB ^= ledv;
        break;
    default:
        break;
    }

    return;
}


void beeper_start(void)
{
    TCCR0A |= 0b01000000;
    return;
}

void beeper_stop(void)
{
    TCCR0A &= 0b00111111;
    return;
}

void beeper_setfreq(unsigned char freq)
{
    if(freq < 6) freq = 6;
    OCR0A = freq;
    return;
}

