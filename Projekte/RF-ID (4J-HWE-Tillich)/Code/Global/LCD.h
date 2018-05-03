//////////////////////////////////////////////////////////////////////////////
//
// Headerfile LCD.h zur LCD Ansteuerung am Port D
//
// Befehle: LCD_init(), LCD_cmd(char data), LCD_send(char data)
//          LCD_string(char *data)
//
// LCD_init();               initialisiert Port D
//                           und LCD im 4-Bit Mode, 2 Zeilen, 5x7 Dots
//                           Bsp.: LCD_init();
//
// LCD_cmd(char data);       schickt Befehl ans LCD
//                           Bsp.: LCD_cmd(0xC5);  //gehe zu 2. Zeile, 6. Position
//
// LCD_send(char data);      schickt Daten ans LCD
//                           Bsp.: LCD_send(0xEF); //sendet ein …
//
// LCD_string(char *data);   schickt eine Zeichenkette ans LCD
//                           Bsp.: LCD_string("Hallo");    //sendet Hallo
//
// Pinbelegung am Board:
// LCD | Atmega16 | Bemerkung
// ----|----------|--------------------
// DB7 |    PD3   |
// DB6 |	PD2   |
// DB5 |	PD1   |
// DB4 |	PD0   |
// DB3 |	-     | wird nicht benštigt
// DB2 |	-     | wird nicht benštigt
// DB1 |	-     | wird nicht benštigt
// DB0 |	-     | wird nicht benštigt
// E   |	PD5   |
// R/W |	-     | per HW auf GND gelegt
// RS  |	PD4   |
//
////////////////////////////////////////////////////////////////////////////////

//-- Hier die Pinzuordnung bei Bedarf aendern (siehe Tabelle oben) --//
#define DB7	PD7
#define DB6	PD6
#define DB5	PD5
#define DB4	PD4
#define E	PD3
#define RS	PD2

//------------------- Ende Pinzuordnung ------------------------------//


#include <avr/io.h>
#include <util/delay.h>		// _delay_ms() geht nur bis max. 262.14 ms / F_CPU !!!


void delay_ms (unsigned int ms)   //Hilfsfunktion: Zeitvernichtung
{
    for (unsigned int i=0; i<ms; i++)
    {
        _delay_ms(1);
    }
    
}

void Enable(void)		//Hilfsfunktion: H=>L Flanke der Enable Leitung (E)
{
    PORTD = PORTD | (1<<E);	//E = 1
    delay_ms(5);
    PORTD = PORTD &~(1<<E);	//E = 0
    delay_ms(5);
}

////////////////////////////////////////////////////////////////////////////
//
// LCD_init(..) Initialisierung: Port D, 4-Bit Mode, 2 Zeilen, 5x7 Dots
//
////////////////////////////////////////////////////////////////////////////
void LCD_init(void)
{
    DDRD = DDRD |(1<<E) |(1<<RS);               			//E,RS als Ausgang
    DDRD = DDRD |(1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4);		//DB7..DB4 als Ausgang
    
    delay_ms(50);	//lt. Datenblatt min. 15ms nach Power ON warten
    PORTD = PORTD & (~(1<<RS) &  ~(1<<E)); //RS=0,E=0 (RW=0 per HW)
    
    // Function Set
    //DB7..DB4 = 0011
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
    PORTD = PORTD | (1<<DB5) | (1<<DB4);
    Enable();
    
    //DB7..DB4 = 0011
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
    PORTD = PORTD | (1<<DB5) | (1<<DB4);
    Enable();
    
    //DB7..DB4 = 0011
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
    PORTD = PORTD | (1<<DB5) | (1<<DB4);
    Enable();
    
    //DB7..DB4 = 0010
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) &~(1<<DB4));
    PORTD = PORTD | (1<<DB5);					//Interface auf 4 Bit
    Enable();
    
    // 2-zeilig, 5x8 Matrix //
    //DB7..DB4 = 0010
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) &~(1<<DB4));
    PORTD = PORTD | (1<<DB5);					//Upper Nibble
    Enable();
    
    //DB7..DB4 = 1000
    PORTD = PORTD | (1<<DB7);					//Lower Nibble
    PORTD = PORTD & (~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4));
    Enable();
    
    //Display Off //
    //DB7..DB4 = 0000
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
    Enable();
    
    //DB7..DB4 = 1000
    PORTD = PORTD | (1<<DB7);					//Lower Nibble
    PORTD = PORTD & (~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4));
    Enable();
    
    //Clear Display //
    //DB7..DB4 = 0000
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
    Enable();
    
    //DB7..DB4 = 0001
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5)); //Lower Nibble
    PORTD = PORTD | (1<<DB4);
    Enable();
    
    //No Display Shift //
    //DB7..DB4 = 0000
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
    Enable();
    
    //DB7..DB4 = 0011
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6));	//Lower Nibble
    PORTD = PORTD | (1<<DB5) | (1<<DB4);
    Enable();
    
    // Display ON , Cursor ON, Blinken ON //
    //DB7..DB4 = 0000
    PORTD = PORTD & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
    Enable();
    
    //DB7..DB4 = 1111
    PORTD = PORTD | (1<<DB7) | (1<<DB6) | (1<<DB5) | (1<<DB4);	//Lower Nibble
    Enable();
}

////////////////////////////////////////////////////////////////////////////
//
// LCD_send(..) sendet 1 Byte im 4-Bit Mode
//
////////////////////////////////////////////////////////////////////////////
void LCD_send(char data)
{
    char temp = data;
    
    PORTD = PORTD | (1<<RS);	//SFR vom LCD mit RS auf Daten umschlten
    
    //Upper Nibble senden
    if (temp & 0b10000000) {PORTD = PORTD | (1<<DB7);}
    else {PORTD = PORTD & ~(1<<DB7);}
    
    if (temp & 0b01000000) {PORTD = PORTD | (1<<DB6);}
    else {PORTD = PORTD & ~(1<<DB6);}
    
    if (temp & 0b00100000) {PORTD = PORTD | (1<<DB5);}
    else {PORTD = PORTD & ~(1<<DB5);}
    
    if (temp & 0b00010000) {PORTD = PORTD | (1<<DB4);}
    else {PORTD = PORTD & ~(1<<DB4);}
    
    Enable();
    delay_ms(1);
    
    //Lower Nibble senden
    if (temp & 0b00001000) {PORTD = PORTD | (1<<DB7);}
    else {PORTD = PORTD & ~(1<<DB7);}
    
    if (temp & 0b00000100) {PORTD = PORTD | (1<<DB6);}
    else {PORTD = PORTD & ~(1<<DB6);}
    
    if (temp & 0b00000010) {PORTD = PORTD | (1<<DB5);}
    else {PORTD = PORTD & ~(1<<DB5);}
    
    if (temp & 0b00000001) {PORTD = PORTD | (1<<DB4);}
    else {PORTD = PORTD & ~(1<<DB4);}
    
    Enable();
    delay_ms(1);
    
}

////////////////////////////////////////////////////////////////////////////
//
// LCD_cmd(..) Befehl senden im 4-Bit Mode
//
////////////////////////////////////////////////////////////////////////////
void LCD_cmd(char data)
{
    char temp = data;
    
    PORTD = PORTD & ~(1<<RS);	//SFR vom LCD mit RS auf Befehle umschalten
    
    //Upper Nibble senden
    if (temp & 0b10000000) {PORTD = PORTD | (1<<DB7);}
    else {PORTD = PORTD & ~(1<<DB7);}
    
    if (temp & 0b01000000) {PORTD = PORTD | (1<<DB6);}
    else {PORTD = PORTD & ~(1<<DB6);}
    
    if (temp & 0b00100000) {PORTD = PORTD | (1<<DB5);}
    else {PORTD = PORTD & ~(1<<DB5);}
    
    if (temp & 0b00010000) {PORTD = PORTD | (1<<DB4);}
    else {PORTD = PORTD & ~(1<<DB4);}
    
    Enable();
    delay_ms(1);
    
    //Lower Nibble senden
    if (temp & 0b00001000) {PORTD = PORTD | (1<<DB7);}
    else {PORTD = PORTD & ~(1<<DB7);}
    
    if (temp & 0b00000100) {PORTD = PORTD | (1<<DB6);}
    else {PORTD = PORTD & ~(1<<DB6);}
    
    if (temp & 0b00000010) {PORTD = PORTD | (1<<DB5);}
    else {PORTD = PORTD & ~(1<<DB5);}
    
    if (temp & 0b00000001) {PORTD = PORTD | (1<<DB4);}
    else {PORTD = PORTD & ~(1<<DB4);}
    
    Enable();
    delay_ms(1);
    
}

////////////////////////////////////////////////////////////////////////////
//
// LCD_string(..) sendet ganzen String im 4-Bit Mode
//
////////////////////////////////////////////////////////////////////////////
void LCD_string(char *data)
{
    while (*data != '\0')	//bis zum letzten Zeichen		
    {LCD_send(*data++);}
}
