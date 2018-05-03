////////////////////////////////////////////////////////////////////////////////
//
// PRO-BOT128 mit ATmega32u4 fährt irgendwie in der Gegend herum (keine Sensoren)
//                           Piept vor dem Wegfahren
// HTL Version V1 //         Front und Back LEDs blinken nach der Fahrt
//
// fquarz = 8MHz 
//
/////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000UL

#include <avr/io.h>							//Registerdeklerationen
#include <util/delay.h>						//maximal possible delay is 4294967,295 ms/ F_CPU in MHz = 5.368.709,78688 ms
#include <avr/interrupt.h>

void init_motoren (void)
{
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
	
	TCCR0B = TCCR0B|(1<<CS01);				//:8 Teiler, startet die PWM, fPWM_Interrupt = fquarz/(Teiler*256) = 3.9 kHz (besser wären 2kHz)
	
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


void init_LEDs (void)
{
//	DDRB = DDRB | (1<<DDB7);				//PB7 LED front left  ist auch PWM OC0A
	DDRD = DDRD | (1<<DDD2);				//PD2 LED front right
	DDRB = DDRB | (1<<DDB3);				//PB3 LED back left
//	DDRx = DDRx | (1<<DDxy);				//P-- LED back right    nicht beschaltet
	DDRB = DDRB | (1<<DDB1);				//PB1 LED line sensor	

	TIMSK3 = TIMSK3 | (1<<OCIE3A);			//Timer_3 CompareA Interrupt freigeben
	OCR3A = 781;							//Endwert für 100 ms (Teiler :1024)
	sei();	

	PORTB = PORTB|(1<<PORTB3)|(1<<PORTB1);		//alle LEDs aus	ohne PB7
	PORTD = PORTD|(1<<PORTD2);					//alle LEDs aus
}

void init_beep (void)
{
 	DDRB = DDRB | (1<<DDB5);				//PB5 als Ausgang (Lautsprecher)
	 
	TIMSK1 = TIMSK1 | (1<<OCIE1A);			//Timer_1 CompareA Interrupt freigeben
	OCR1A = 781;							//Endwert für 100 ms (Teiler :1024)
	sei();
}
	
void beep (char ein)
{
	if (ein == 1)
		{TCCR1B = TCCR1B|(1<<CS12)|(1<<CS10);}				//Timer1 :1024 Teiler => dt=1024/8MHz=128µs
	else
	{
		TCCR1B = TCCR1B&~(1<<CS12)&~(1<<CS11)&~(1<<CS10);	//Timer1 stop
		PORTB = PORTB &~ (1<<PORTB5);						//Lautsprecher aus
	}	
}

ISR (TIMER1_COMPA_vect)
{	
	TCNT1 = 0x0000;
	PORTB = PORTB^(1<<PORTB5);				//PB5 Lautsprecher aus/ein
}	
	
void blink (char ein)
{
	if (ein == 1)
		{TCCR3B = TCCR3B|(1<<CS32)|(1<<CS30);}				//Timer3 :1024 Teiler => dt=1024/8MHz=128µs
	else
	{
		TCCR3B = TCCR3B&~(1<<CS32)&~(1<<CS31)&~(1<<CS30);	//Timer3 stop
		PORTB = PORTB|(1<<PORTB3)|(1<<PORTB1);				//alle LEDs aus ohne PB7
		PORTD = PORTD|(1<<PORTD2);							//alle LEDs aus
	}	
}

ISR (TIMER3_COMPA_vect)
{	
	TCNT3 = 0x0000;
	PORTB = PORTB^((1<<PORTB3)|(1<<PORTB1));					//LEDs aus/ein ohne PB7
	PORTD = PORTD^(1<<PORTD2);									//LEDs aus/ein
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
	unsigned char i;

	MCUCR = MCUCR|(1<<JTD);					//JTAG disable
	MCUCR = MCUCR|(1<<JTD);

	CLKPR = 0x80;							//Ändern des internen CLK-Prescalers
	CLKPR = 0x01;							//16 Mhz :2 = 8 MHz 

	init_motoren();
	init_beep();
	init_LEDs();
	
	beep(1);								//1=Beep starten
	blink(1);								//1=blinken starten
	_delay_ms(3000);
	beep(0);								//0=Beep stoppen
	blink(0);								//0=blinken stoppen
	
	PORTB = PORTB&~(1<<PORTB7)&~(1<<PORTB3)&~(1<<PORTB1);	//alle LEDs ein
	PORTD = PORTD&~(1<<PORTD2);								//alle LEDs ein

	for (i=0;i<5;i++)
	{
		drive (0xFF, 0xFF, 1);	_delay_ms(1000);	//speed_left=0xFF, speed_right=0xFF, start = 1
		drive (0x80,0x80, 0);	_delay_ms(500);		//speed_left=0x80, speed_right=0x80, stopp = 0
		drive (0x00, 0x00, 1);	_delay_ms(1000);
		drive (0x80,0x80, 0);	_delay_ms(500);				
		drive (0x00, 0xAA, 1);	_delay_ms(2000);
		drive (0x80,0x80, 0);	_delay_ms(500);
		drive (0xAA, 0x00, 1);	_delay_ms(2000);
		drive (0x80,0x80, 0);	_delay_ms(500);       
		
		beep(1); blink(1); _delay_ms(2000);
		beep(0); blink(0); PORTB=PORTB&~(1<<PORTB3)&~(1<<PORTB1);PORTD=PORTD&~(1<<PORTD2);
	}	
	
	while(1)
	{
		PORTB = PORTB^((1<<PORTB3)|(1<<PORTB1));		//LEDs blinken lassen
		PORTD = PORTD^(1<<PORTD2);						//LEDs blinken lassen
		_delay_ms(750);
	}
				
	return 0;
}
