#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000

#define DIN_0 PORTB=PORTB&~(1<<PB0);  //DIN = 0
#define DIN_1 PORTB=PORTB|(1<<PB0);   //DIN = 1
#define CLK_0 PORTB=PORTB&~(1<<PB1);  //CLK = 0
#define CLK_1 PORTB=PORTB|(1<<PB1);   //CLK = 1
#define CS_0  PORTB=PORTB&~(1<<PB2);  //CS = 0
#define CS_1  PORTB=PORTB|(1<<PB2);   //CS = 1

/* Aufgabe Nr. 1*/
void sende (unsigned char control, unsigned char daten)
{
    unsigned char Maske = 0x80; // 1000 0000
    unsigned char i; // Zählvariable
    
    CS_0; CLK_0; // Start serielle Datenübertragung
    
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Adress-Bits
    {
        if(control & Maske){ DIN_1;} //Parallel => Serienwandlung
        else DIN_0;
        CLK_1; //CLK ausgeben
        CLK_0;
        Maske = Maske>>1; // 1 Bit nach rechts verschieben
    }
    
    Maske = 0x80;
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Daten-Bits
    {
        if(daten & Maske){DIN_1;} // Parallel => Serienumwandlung
        else DIN_0;
        CLK_1;
        CLK_0;
        Maske = Maske>>1; // Maske um 1 Bit nach rechts verschieben
    }
    DIN_0; // Serielle Datenleitung auf 0
    CS_1;  // Übernahme der Adr.- und Daten-Bits
}

int main(void)
{
    CLKPR=0x80;
    CLKPR=0x01;
    
    DDRB |= (1<<DDB0)|(1<<DDB1)|(1<<DDB2); // Ausgänge setzen
    
    unsigned char control=0,data=0;
    uint8_t loutstat=0;
    control=0x0E;
    
    while(1)
    {
        if(data==255)
            data=0;
        else
            data++;
        
        if(loutstat==1)
            control |= (1<<6);
        else
            control &= ~(1<<6);
        
        sende(control,data);
        
        if(loutstat==0)
            loutstat=1;
        else
            loutstat=0;
        _delay_us(10);
    }
}
/* Ende Aufgabe Nr. 1*/

/* Aufgabe Nr. 2*/
/*
void sende (unsigned char control, unsigned char daten)
{
    unsigned char Maske = 0x80; // 1000 0000
    unsigned char i; // Zählvariable
    CS_1; CLK_1; // Start serielle Datenübertragung
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Adress-Bits
    {
        if(control & Maske){ DIN_1;} //Parallel => Serienwandlung
        else DIN_0;
        CLK_0; //CLK ausgeben
        CLK_1;
        Maske = Maske>>1; // 1 Bit nach rechts verschieben
    }
    Maske = 0x80;
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Daten-Bits
    {
        if(daten & Maske){DIN_1;} // Parallel => Serienumwandlung
        else DIN_0;
        CLK_0;
        CLK_1;
        Maske = Maske>>1; // Maske um 1 Bit nach rechts verschieben
    }
    DIN_0; // Serielle Datenleitung auf 0
    CS_0; // Übernahme der Adr.- und Daten-Bits
}
int main(void)
{
    CLKPR=0x80;
    CLKPR=0x01;
    DDRB |= (1<<DDB0)|(1<<DDB1)|(1<<DDB2);  // Ausgänge setzen
 
    while(1)
    {
        sende(50,50);
        _delay_ms(1);
    }
}
*/
/* Ende Aufgabe Nr. 2*/