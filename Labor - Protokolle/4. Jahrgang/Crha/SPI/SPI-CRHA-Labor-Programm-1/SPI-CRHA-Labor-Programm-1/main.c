#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000

#define DIN0 PORTB=PORTB&~(1<<PB0); //DIN = 0
#define DIN1 PORTB=PORTB|(1<<PB0);  //DIN = 1

#define CLK0 PORTB=PORTB&~(1<<PB1); //CLK = 0
#define CLK1 PORTB=PORTB|(1<<PB1);  //CLK = 1

#define CS0  PORTB=PORTB&~(1<<PB2); //CS = 0
#define CS1  PORTB=PORTB|(1<<PB2);  //CS = 1

void sende (unsigned char adr, unsigned char daten)
{
    unsigned char Maske = 0x80; // 1000 0000
    unsigned char i; // Zählvariable
    
    CS0;
    CLK0;
    
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Daten-Bits
    {
        if(adr & Maske) // Parallel => Serienumwandlung
        {
            DIN1;
        }
        
        else
        {
            DIN0;
        }
        
        CLK1;
        CLK0;
        Maske = Maske>>1; // Maske um 1 Bit nach rechts verschieben
    }
    
    
    Maske = 0x80;
    for(i=1; i<=8; i++) // Schleif zur Ausgabe der 8 Daten-Bits
    {
        if(daten & Maske){ DIN1;} // Parallel => Serienumwandlung
        else {DIN0;}
        CLK1;
        CLK0;
        Maske = Maske>>1; // Maske um 1 Bit nach rechts verschieben
    }
    DIN0; // Serielle Datenleitung auf 0
    CS1; // Übernahme der Adr.- und Daten-Bits
}

int main(void)
{
    CLKPR=0x80;
    CLKPR=0x01;
    
    DDRB |= (1<<DDB0)|(1<<DDB1)|(1<<DDB2);
    
    sende(7,7);
}