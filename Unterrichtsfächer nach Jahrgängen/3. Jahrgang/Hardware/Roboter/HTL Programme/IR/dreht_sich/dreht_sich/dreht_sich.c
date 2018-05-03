////////////////////////////////////////////////////////////////////////////////
//
// HTL Adapterprint V1
//
// PRO-BOT128 mit ATmega32u4 dreht sich auf der Stelle wenn via IR ein Hindernis erkannt wird
//
// IR LEDs links (PD4) und IR LEDs rechts (PB0) senden abwechselnd 
// je ein 36 kHz Signal aus. Das 36 kHz Sigmal wird Timer4 am PC6 erzeugt
// 
// Der IR Empfänger (PD5) wertet das reflektierte Signal aus und dreht
// den Roboter
//
// fquarz = 8MHz 
//
/////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000UL

#include <avr/io.h>							//Registerdeklerationen
#include <avr/interrupt.h>					//Makros sei(), cli() und Interruptnamen
#include <util/delay.h>



ISR (TIMER4_COMPA_vect)						//IR-Empfänger TSOP1736
{	
	TCNT4 = 0;
	PORTC = PORTC^(1<<PORTC6);				//36 kHz Signal
}

void init_IR (void)
{
	DDRB = DDRB|(1<<DDB0);					//PB0 (IR-right) als Output
	DDRD = DDRD|(1<<DDD4);					//PD4 (IR-left) als Output
	DDRC = DDRC|(1<<DDC6);					//PC6 (IR-36kHz) als Output
	DDRD = DDRD&~(1<<DDD5);					//PD5 (IR-Empfänger) als Input
	PORTD = PORTD|(1<<PORTD5);				//PD5 int. Pull Up Widerstand ein
	DDRB = DDRB|(1<<DDB3);					//PB3 left Back LED als Output
	DDRD = DDRD|(1<<DDD2);					//PD2 right Front LED als Output
	PORTB = PORTB|(1<<PORTB3);				//alle Front- und Back-LEDs aus
	PORTD = PORTD|(1<<PORTD2);
	
 	TIMSK4 = TIMSK4 | (1<<OCIE4A);			//Timer_4 CompareA Interrupt freigeben
	OCR4A = 82;								//Endwert für 1/2* 1/36kHz = 13,89µs (111*125ns=13,875µs), 82 pass t lt. Messung
	TCCR4B = TCCR4B|(1<<CS40);				//:1 Teiler => dt=1/8MHz=125ns
	sei();
}
	 
void init_Motoren (void)
{
	CLKPR = 0x80;							//Ändern des internen CLK-Prescalers
	CLKPR = 0x01;							//16 Mhz :2 = 8 MHz 

/////////// Ports /////////////////
	DDRB = DDRB | (1<<DDB6);				//PB6 als Ausgang (normaler IO-Pin), linkes Rad
	DDRD = DDRD | (1<<DDD0);				//PD0 als Ausgang (OC0B), rechtes Rad
	DDRF = DDRF | (1<<DDF5);				//PF5 als Ausgang (Motor Driver Enable)

/////////// Timer 0 Fast PWM /////////////////	
	TCCR0A = TCCR0A | (1<<WGM00);
	TCCR0A = TCCR0A | (1<<WGM01);
	TCCR0B = TCCR0B &~(1<<WGM02);			//WGM2:0=3		Fast PWM

	TCCR0A = TCCR0A &~(1<<COM0A0);
	TCCR0A = TCCR0A | (1<<COM0A1);			//COM1:2=2      Non Inverting, für links (PB6/normaler IO-Pin)
	
	TCCR0A = TCCR0A &~(1<<COM0B0);
	TCCR0A = TCCR0A | (1<<COM0B1);			//COM1:2=2      Non Inverting, für rechts (PD0/OC0B)
	
	TCCR0B = TCCR0B|(1<<CS01);				//:8 Teiler, startet die PWM, fPWM_Interrupt = fquarz/(Teiler*256) = 3.9 kHz 
	
	TIMSK0 = TIMSK0|(1<<OCIE0A)|(1<<OCIE0B)|(1<<TOIE0);//Interrupts freigeben
	sei();									
}

// Interrupts für Fast PWM auf beliebigen Portpins
ISR(TIMER0_COMPA_vect)
{
	PORTB = PORTB &~ (1<<PORTB6);			//Motor links (PB6)
}

ISR(TIMER0_COMPB_vect)
{
	PORTD = PORTD &~ (1<<PORTD0);			//Motor rechts (PD0/OC0B)
}   

ISR(TIMER0_OVF_vect)
{
	PORTB = PORTB | (1<<PORTB6);			//Motor links
	PORTD = PORTD | (1<<PORTD0);			//Motor rechts
}


	 
void drive (unsigned char speed_left, unsigned char speed_right, unsigned char start_stop)
{
	OCR0B = speed_right;					//Geschwindigkeit links (0xFF vollgas vor, 0x00 vollgas retout, 0x80 stopp)
	OCR0A = speed_left;						//Geschwindigkeit rechts (0xFF vollgas vor, 0x00 vollgas retout, 0x80 stopp)

	if (start_stop == 1)
	{PORTF = PORTF | (1<<PORTF5);}			//Motor Driver Enable => Start
	else
	{PORTF = PORTF &~(1<<PORTF5);}			//Motor Driver Disable => Stopp
}



int main (void)
{
	MCUCR = MCUCR|(1<<JTD);				//JTAG disable
	MCUCR = MCUCR|(1<<JTD);

	init_Motoren();
	init_IR();
	
	while(1)
		{
			PORTD = PORTD&~(1<<PORTD4);							//IR-left ON
			PORTB = PORTB|(1<<PORTB0);							//IR-right OFF
			if (PIND&(1<<PIND5)) 
				{
					PORTB = PORTB&~(1<<PORTB2);					//LED left Back EIN
					drive(0x80,0x80,0);							//Motoren STOP	
				}	
			else 
				{
					PORTB = PORTB|(1<<PORTB2);					//LED left Back AUS
					drive(0x05,0xFF,1);							//drehen
				}					
			_delay_ms(10);
					
			PORTD = PORTD|(1<<PORTD4);							//IR-left OFF
			PORTB = PORTB&~(1<<PORTB0);							//IR-right ON
			if (PIND&(1<<PIND5)) 
				{
					PORTD = PORTD&~(1<<PORTD2);					//LED right front EIN
					drive(0x80,0x80,0);							//Motoren STOP	
				}	
			else 
				{
					PORTD = PORTD|(1<<PORTD2);					//LED right front AUS
					drive(0xFF,0x05,1);							//drehen
				}					
			_delay_ms(10);     
		}
}
