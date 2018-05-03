#define F_CPU 4000000UL
#include <avr/io.h>
#include <avr/delay.h>
#define DIN_0 PORTB=PORTB&~(1<<PB0); //DIN = 0
#define DIN_1 PORTB=PORTB|(1<<PB0); //DIN = 1
#define CLK_0 PORTB=PORTB&~(1<<PB1); //CLK = 0
#define CLK_1 PORTB=PORTB|(1<<PB1); //CLK = 1
#define CS_0 PORTB=PORTB&~(1<<PB2); //CS = 0
#define CS_1 PORTB=PORTB|(1<<PB2); //CS = 1
void sende (unsigned char reg_adr, unsigned char daten);
int main(void)
{
    CLKPR = 0x80; //Ändern des internen CLK-Prescalers
    CLKPR = 0x02; //16 Mhz :1 = 8 MHz
    _delay_ms(1000);
    
    ///////// μC Init. für DIN, CLK, CS /////////////////////////
    DDRB = DDRB|(1<<DDB0)|(1<<DDB1)|(1<<DDB2); //DIN, CLK und CS als Output
    ///////// Initialisierung des MAX7221 /////////////////////////
    
    sende (0x0C,0x01); // Shut Down - Normal Operation
    sende (0x0A,0xFF); // Intensity maximal
    sende (0x0B,0x01); // LED Display mit 8 Stellen
    sende (0x09,0xFF); // BCD-B Codierung für alle 8 Stellen
    
    //sende (0x0F,0xFF); // Display Test
    ////////// Ausgabe von 7 6 5 4 3 2 1 0 am Display ////////////
    
    sende (0x01,0x00); // Ausgabe von 0
    char i;
    while(1)
    {
        for(i = 0;i < 10;i++)
        {
            sende (0x01,i+0x80); // Ausgabe von 0
            _delay_ms(1000);
        }
    }
}
void sende (unsigned char reg_adr, unsigned char daten)
{
    unsigned char Maske = 0x80; // 1000 0000
    unsigned char i; // Zählvariable
    CS_0;
    CLK_0; // Start serielle Datenübertragung
    for(i=1; i<=8; i++) // Schleife zur Ausgabe der 8 Adress-Bits
    {
        if(reg_adr & Maske) {DIN_1;} //Parallel => Serienwandlung
        else {DIN_0;}
        CLK_1; //CLK ausgeben
        CLK_0;
        Maske = Maske>>1; // 1 Bit nach rechts verschieben
    }
    Maske = 0x80;
    for(i=1; i<=8; i++) // Schleif zur Ausgabe der 8 Daten-Bits
    {
        if(daten & Maske){ DIN_1;} // Parallel => Serienumwandlung
        else {DIN_0;}
        CLK_1;
        CLK_0;
        Maske = Maske>>1; // Maske um 1 Bit nach rechts verschieben
    }
    DIN_0; // Serielle Datenleitung auf 0
    CS_1; // Übernahme der Adr.- und Daten-Bits
}