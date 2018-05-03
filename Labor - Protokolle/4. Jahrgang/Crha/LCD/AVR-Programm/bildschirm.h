//////////////////////////////////////////////////////////////////////////////
//
// Headerfile LCD.h zur LCD Ansteuerung am Port B für das HTL Demoboard
//
// Funktionen: initialisieren(), cmd(char data), senden(char data)
//          string(char *data)
//
// initialisieren();             initialisiert Port D
//                                und LCD im 4-Bit Mode, 2 Zeilen, 5x7 Dots
//                                - Bsp. Aufruf: initialisieren();
//
// cmd(char data);  schickt Befehl ans LCD
//                                - Bsp. Aufruf: cmd(0xC5);  //gehe zu 2. Zeile, 6. Position
//
// senden(char data);  schickt Daten ans LCD
//                                - Bsp. Aufruf: senden(0xEF); //sendet ein ö
//
// string(char *data); schickt eine Zeichenkette ans LCD
//                                - Bsp. Aufruf: string("Hallo");    //sendet Hallo
//
// Pinbelegung am Board:
// LCD | Atmega32U4 | Bemerkung
// ----|------------|--------------------
// DB7 |    PB3     |
// DB6 |	PB2     |
// DB5 |	PB1     |
// DB4 |	PB0     |
// DB3 |	-       | wird nicht benötigt
// DB2 |	-       | wird nicht benötigt
// DB1 |	-       | wird nicht benötigt
// DB0 |	-       | wird nicht benötigt
// E   |	PB4     |
// RW  |	PB5     |
// RS  |	PB6     |
// VO  |    PB7     |
// VDD |    GND     |
// VSS |    5V      |
//
////////////////////////////////////////////////////////////////////////////////

//-- Hier die Pinzuordnung bei Bedarf aendern (siehe Tabelle oben) --//
#define DB7	PB3
#define DB6	PB2
#define DB5	PB1
#define DB4	PB0
#define E	PB4
#define RW  PB5
#define RS	PB6
#define VO  PB7

// PORT Zuordnung muss im gesamten LCD.h angepasst werden!
// d.h. PORTB und DDRB durch gewünschten anderen Port ersetzen
//
//------------------- Ende Pinzuordnung ------------------------------//


#include <avr/io.h>
#include <util/delay.h>		// _delay_ms() geht nur bis max. 262.14 ms / F_CPU !!!

void delay_ms (unsigned int ms)   //Hilfsfunktion: Zeitvernichtung
{   int i;
	for (i=0; i<ms; i++)
	{
		_delay_ms(1);
	}
}

void Enable(void)		//Hilfsfunktion: H=>L Flanke der Enable Leitung (E)
{
	PORTB = PORTB | (1<<E);	//E = 1
	delay_ms(5);
	PORTB = PORTB &~(1<<E);	//E = 0
	delay_ms(5);
}

////////////////////////////////////////////////////////////////////////////
// initialisieren(..) Initialisierung: Port D, 4-Bit Mode, 2 Zeilen, 5x7 Dots
void initialisieren(void)
{
	DDRB = DDRB |(1<<E)  |(1<<RS) |(1<<RW);               	//E,RS,RW als Ausgang
	DDRB = DDRB |(1<<DB7)|(1<<DB6)|(1<<DB5)|(1<<DB4);		//DB7..DB4 als Ausgang

	delay_ms(50);	//lt. Datenblatt min. 15ms nach Power ON warten
	PORTB = PORTB & (~(1<<E) &  ~(1<<RS) &  ~(1<<RW)); //RS=0,E=0,RW=0

// Function Set
	//DB7..DB4 = 0011
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
	PORTB = PORTB | (1<<DB5) | (1<<DB4);
	Enable();

	//DB7..DB4 = 0011
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
	PORTB = PORTB | (1<<DB5) | (1<<DB4);
	Enable();

	//DB7..DB4 = 0011
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6));	//Interface auf 8 Bit
	PORTB = PORTB | (1<<DB5) | (1<<DB4);
	Enable();

	//DB7..DB4 = 0010
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) &~(1<<DB4));
	PORTB = PORTB | (1<<DB5);					//Interface auf 4 Bit
	Enable();

// 2-zeilig, 5x8 Matrix //
	//DB7..DB4 = 0010
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) &~(1<<DB4));
	PORTB = PORTB | (1<<DB5);					//Upper Nibble
	Enable();

	//DB7..DB4 = 1000
	PORTB = PORTB | (1<<DB7);					//Lower Nibble
	PORTB = PORTB & (~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4));
	Enable();

//Display Off //
	//DB7..DB4 = 0000
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
	Enable();

	//DB7..DB4 = 1000
	PORTB = PORTB | (1<<DB7);					//Lower Nibble
	PORTB = PORTB & (~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4));
	Enable();

//Clear Display //
	//DB7..DB4 = 0000
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
	Enable();

	//DB7..DB4 = 0001
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5)); //Lower Nibble
	PORTB = PORTB | (1<<DB4);
	Enable();

//No Display Shift //
	//DB7..DB4 = 0000
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
	Enable();

	//DB7..DB4 = 0011
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6));	//Lower Nibble
	PORTB = PORTB | (1<<DB5) | (1<<DB4);
	Enable();

// Display ON , Cursor ON, Blinken ON //
	//DB7..DB4 = 0000
	PORTB = PORTB & (~(1<<DB7) & ~(1<<DB6) & ~(1<<DB5) & ~(1<<DB4)); //Upper Nibble
	Enable();

	//DB7..DB4 = 1111
	PORTB = PORTB | (1<<DB7) | (1<<DB6) | (1<<DB5) | (1<<DB4);	//Lower Nibble
	Enable();
}

////////////////////////////////////////////////////////////////////////////
// senden(..) sendet 1 Byte im 4-Bit Mode
void senden(char data)
{
	char temp = data;

		PORTB = PORTB | (1<<RS);	//SFR vom LCD mit RS auf Daten umschlten

		//Upper Nibble senden
		if (temp & 0b10000000) {PORTB = PORTB | (1<<DB7);}
		else {PORTB = PORTB & ~(1<<DB7);}

		if (temp & 0b01000000) {PORTB = PORTB | (1<<DB6);}
		else {PORTB = PORTB & ~(1<<DB6);}

		if (temp & 0b00100000) {PORTB = PORTB | (1<<DB5);}
		else {PORTB = PORTB & ~(1<<DB5);}

		if (temp & 0b00010000) {PORTB = PORTB | (1<<DB4);}
		else {PORTB = PORTB & ~(1<<DB4);}

		Enable();
		delay_ms(1);

		//Lower Nibble senden
		if (temp & 0b00001000) {PORTB = PORTB | (1<<DB7);}
		else {PORTB = PORTB & ~(1<<DB7);}

		if (temp & 0b00000100) {PORTB = PORTB | (1<<DB6);}
		else {PORTB = PORTB & ~(1<<DB6);}

		if (temp & 0b00000010) {PORTB = PORTB | (1<<DB5);}
		else {PORTB = PORTB & ~(1<<DB5);}

		if (temp & 0b00000001) {PORTB = PORTB | (1<<DB4);}
		else {PORTB = PORTB & ~(1<<DB4);}

		Enable();
		delay_ms(1);

}

////////////////////////////////////////////////////////////////////////////
// cmd(..) Befehl senden im 4-Bit Mode
void cmd(char data)
{
	char temp = data;

		PORTB = PORTB & ~(1<<RS);	//SFR vom LCD mit RS auf Befehle umschalten

		//Upper Nibble senden
		if (temp & 0b10000000) {PORTB = PORTB | (1<<DB7);}
		else {PORTB = PORTB & ~(1<<DB7);}

		if (temp & 0b01000000) {PORTB = PORTB | (1<<DB6);}
		else {PORTB = PORTB & ~(1<<DB6);}

		if (temp & 0b00100000) {PORTB = PORTB | (1<<DB5);}
		else {PORTB = PORTB & ~(1<<DB5);}

		if (temp & 0b00010000) {PORTB = PORTB | (1<<DB4);}
		else {PORTB = PORTB & ~(1<<DB4);}

		Enable();
		delay_ms(1);

		//Lower Nibble senden
		if (temp & 0b00001000) {PORTB = PORTB | (1<<DB7);}
		else {PORTB = PORTB & ~(1<<DB7);}

		if (temp & 0b00000100) {PORTB = PORTB | (1<<DB6);}
		else {PORTB = PORTB & ~(1<<DB6);}

		if (temp & 0b00000010) {PORTB = PORTB | (1<<DB5);}
		else {PORTB = PORTB & ~(1<<DB5);}

		if (temp & 0b00000001) {PORTB = PORTB | (1<<DB4);}
		else {PORTB = PORTB & ~(1<<DB4);}

		Enable();
		delay_ms(1);

}

////////////////////////////////////////////////////////////////////////////
// string(..) sendet ganzen String im 4-Bit Mode
void string(char *data)
{
	    while (*data != '\0')	//bis zum letzten Zeichen
        	{senden(*data++);}
}