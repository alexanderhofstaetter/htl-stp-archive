///////////////////////////////////////////////////////////////////////////////
//
// ATmega 32U4 HTL-Print
//
// alle Pins toggeln
//
///////////////////////////////////////////////////////////////////////////////

#include <avr/io.h>

int main (void)
{
	MCUCR = MCUCR|(1<<JTD);			//JTAG disable
	MCUCR = MCUCR|(1<<JTD);

//	DDRB = DDRB|(1<<DDB6);
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;
	DDRE = 0xFF;
	DDRF = 0xFF; 
	
	while(1)
	{
//		PORTB = PORTB^(1<<PORTB6);
		PORTB = PORTB^0xFF;
		PORTC = PORTC^0xFF;
		PORTD = PORTD^0xFF;
		PORTE = PORTE^0xFF;
		PORTF = PORTF^0xFF;  
	}
}