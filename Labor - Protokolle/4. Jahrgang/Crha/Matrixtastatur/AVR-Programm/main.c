/**Aufgabe 1*/
#include <avr/io.h>					// Include File für IO Definitionen
#include <avr/interrupt.h>			// Include File für sei(), cli()
#include <util/delay.h>

//  PD5 PD3 PD4
//
//   |   |   |
//
//   1   2   3   -- PD1 Ausgang
//
//   4   5   6   -- PD2 Ausgang
//
//   7   8   9   -- PD0 Ausgang

unsigned char matrix(void)
{
    unsigned char taste=0;

    PORTD |=  0b00000110; 	//Setzt PB1 UND PB2 auf 1
    PORTD &= ~0b11111110; 	//Setzt PB0 auf 0

    _delay_ms(1);		  	//Stellt Änderung sicher

    if     (!(PIND & 0b00100000))   taste=7;	//PD5=0, daher Taste 7
    else if(!(PIND & 0b00010000))   taste=8;	//PD4=0, daher Taste 8
    else if(!(PIND & 0b00001000))   taste=9;	//PD3=0, daher Taste 9

    PORTD |=  0b00000001; 	//Setzt PB0 auf 1
    PORTD &= ~0b11111101; 	//setzt PB1 auf 0

    _delay_ms(1);

    if     (!(PIND & 0b00100000))   taste=4; 	//PD5=0, daher Taste 4
    else if(!(PIND & 0b00010000))   taste=5; 	//PD4=0, daher Taste 5
    else if(!(PIND & 0b00001000))	taste=6; 	//PD3=0, daher Taste 6

    PORTD |=  0b00000010; 	//Setzt PB1 auf 1
    PORTD &= ~0b11111011;	//Setzt PB2 auf 0

    _delay_ms(1);

    if     (!(PIND & 0b00100000))   taste=1; 	//PD5=0, daher Taste 1
    else if(!(PIND & 0b00010000))	taste=2; 	//PD4=0, daher Taste 2
    else if(!(PIND & 0b00001000))	taste=3; 	//PD3=0, daher Taste 3

    return taste;
}

int main(void)
{
    DDRD = 0b00000111;      //Tastaur - PD0..PD2 - Ausgänge, PD3..PD7 - Eingänge
    PORTD =	0xFF;           //Tastaur - PD0..PD2 - High setzen, PD3..PD7 - Int. Pull-Up

    DDRB = 0xFF;          	//LEDs als Ausgänge
    PORTB = 0;         	    //LEDs -> 0

    while(1)
    {   PORTB = 0x00;		//Am Beginn jeder Schleifenwiederholung PORTB 0 setzen.

        switch(matrix())
        {   case 1 : PORTB |=  (1<<PB0); break;
            case 2 : PORTB |=  (1<<PB1); break;
            case 3 : PORTB |=  (1<<PB2); break;
            case 4 : PORTB |=  (1<<PB3); break;
            case 5 : PORTB |=  (1<<PB4); break;
            case 6 : PORTB |=  (1<<PB5); break;
            case 7 : PORTB |=  (1<<PB6); break;
            case 8 : PORTB |=  (1<<PB7); break;
            case 9 : PORTB = 0xFF;       break;
        }
    }
}
