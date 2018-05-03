////////////////////////////////////////////////////////////////////////////////
//
// HTL Adapterprint V1
//
// PRO-BOT128 mit ATmega32u4 pendelt zwischen 2 dicken schwarzen Linien (Line Sensor)
//                           Piept vor dem Wegfahren               
//
// fquarz = 8MHz 
//
/////////////////////////////////////////////////////////////////////////////////

#define F_CPU 8000000UL
#define STOP	20							//mit diesem Wert experimentieren (z.B. 200)

#include <avr/io.h>							//Registerdeklerationen
#include <util/delay.h>						//maximal possible delay is 4294967,295 ms/ F_CPU in MHz = 5.368.709,78688 ms
#include <avr/interrupt.h>

////globale Variable ////////
unsigned int Linienwerte[2];					//enthält die ADC Werte


void init (void)
{
	MCUCR = MCUCR|(1<<JTD);					//JTAG disable
	MCUCR = MCUCR|(1<<JTD);
	
	CLKPR = 0x80;							//Ändern des internen CLK-Prescalers
	CLKPR = 0x01;							//16 Mhz :2 = 8 MHz 

///////////////////////////// Motoren /////////////////////////////////////////////////

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


///////////////////////////// LEDs /////////////////////////////////////////////////

//	DDRB = DDRB | (1<<DDB7);				//PB7 LED front left   hat auch die PWM (OC0A) oben
	DDRD = DDRD | (1<<DDD2);				//PD2 LED front right
	DDRB = DDRB | (1<<DDB3);				//PB3 LED back left
//	DDRx = DDRx | (1<<DDxy);				//P-- LED back right    nicht beschaltet
	DDRB = DDRB | (1<<DDB1);				//PB1 LED line sensor	

	TIMSK3 = TIMSK3 | (1<<OCIE3A);			//Timer_3 CompareA Interrupt freigeben
	OCR3A = 781;							//Endwert für 100 ms (Teiler :1024)
	sei();	

	PORTB = PORTB|(1<<PORTB3)|(1<<PORTB1);	//alle LEDs aus
	PORTD = PORTD|(1<<PORTD2);				//alle LEDs aus


///////////////////////////// Beep /////////////////////////////////////////////////
  	DDRB = DDRB | (1<<DDB5);				//PB5 als Ausgang (Lautsprecher)
	 
	TIMSK1 = TIMSK1 | (1<<OCIE1A);			//Timer_1 CompareA Interrupt freigeben
	OCR1A = 781;							//Endwert für 100 ms (Teiler :1024)
	sei();

///////////////////////////// Line Sensor /////////////////////////////////////////////////
	DDRF = DDRF&~(1<<DDF0)&~(1<<DDF1);		//PF0/ADC0 line sensor left und PF1/ADC1 line sensor right als INPUT
	DDRB = DDRB | (1<<DDB1);				//PB1 LED Line Sensor OUTPUT
	
	PORTB = PORTB&~(1<<PORTB1);									//LED Line Sensor ON
	ADCSRA = ADCSRA|(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);			//Wandler ein,:64 Teiler
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


ISR (TIMER1_COMPA_vect)						// Beeper
{	
	TCNT1 = 0x0000;
	PORTB = PORTB^(1<<PORTB5);				//PB5 Lautsprecher aus/ein
}	


ISR (TIMER3_COMPA_vect)						//blinken
{	
	TCNT3 = 0x0000;
	PORTB = PORTB^((1<<PORTB3)|(1<<PORTB1));//LEDs aus/ein
	PORTD = PORTD^(1<<PORTD2);				//LEDs aus/ein
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


	
void blink (char ein)
{
	if (ein == 1)
		{TCCR3B = TCCR3B|(1<<CS32)|(1<<CS30);}				//Timer3 :1024 Teiler => dt=1024/8MHz=128µs
	else
	{
		TCCR3B = TCCR3B&~(1<<CS32)&~(1<<CS31)&~(1<<CS30);	//Timer3 stop
		PORTB = PORTB|(1<<PORTB3)|(1<<PORTB1);				//alle LEDs aus
		PORTD = PORTD|(1<<PORTD2);							//alle LEDs aus
	}	
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



void Linie_ADCs (unsigned int *data)
{
		ADMUX  = ADMUX |(1<<REFS0);									//Vref=AVCC, rechtsbündig, ADC0/PF0 Line Sensor Left
		ADMUX  = ADMUX&~(1<<MUX0);
		ADCSRA = ADCSRA | (1<<ADSC);								//Start Wandlung
		while(!(ADCSRA & (1<<ADIF)));								//warten bis Wandlung fertig ist
		ADCSRA = ADCSRA | (1<<ADIF);								//Clear ADIF
		data[0] = ADCL + (ADCH<<8);									//Wert Line Sensor Left
	
		ADMUX  = ADMUX |(1<<REFS0)|(1<<MUX0);						//Vref=AVCC, rechtsbündig, ADC1/PF1 Line Sensor Right
		ADCSRA = ADCSRA | (1<<ADSC);								//Start Wandlung
		while(!(ADCSRA & (1<<ADIF)));								//warten bis Wandlung fertig ist
		ADCSRA = ADCSRA | (1<<ADIF);								//Clear ADIF
		data[1] = ADCL + (ADCH<<8);									//Wert Line Sensor Right
}



int main (void)
{
	unsigned char speedLeft,speedRight;
	unsigned char j,k;						//Hilfsvariablen
		
	init();

	beep(1);								//1=Beep starten
	blink(1);								//1=blinken starten
	_delay_ms(2000);
	beep(0);								//0=Beep stoppen
	blink(0);								//0=blinken stoppen
	
	PORTB = PORTB &~(1<<PORTB1);					//LED Line Sensor EIN
	for (j=0;j<255;j++) {Linie_ADCs(Linienwerte);}	//Werte ausführlich lange auslesen, "ADC Warmlauf"
	
	speedLeft = speedRight = 0xE0;					//vmax vorwärts
	drive(speedLeft,speedRight,1);
	k=0;
	while (1)
	//while(k<10)										//10x hin und her fahren
		{
			Linie_ADCs(Linienwerte);
			if ((Linienwerte[0] < STOP) && (Linienwerte[1] < STOP))
			{
				k++;
				drive(128,128,0);					//Motor STOPP
				speedLeft  = ~speedLeft;			//in Gegenrichtung fahren
				speedRight = ~speedRight;
				drive(speedLeft,speedRight,1);
				_delay_ms(500);						//um vom überfahrenen Strich zurücksetzen
			} 	
		}
	drive(128,128,0);								//Motor STOPP
	PORTB = PORTB | (1<<PORTB1);					//LED Line Sensor AUS	
	
	while(1)										//Endlosschleiofe
	{
		PORTB = PORTB&~(1<<PORTB3);					//Blitzlicht Front und Back LEDs
		PORTD = PORTD&~(1<<PORTD2);
		_delay_ms(50);
		PORTB = PORTB|(1<<PORTB3);
		PORTD = PORTD|(1<<PORTD2);
		_delay_ms(1000);
	}
	
	return 0;
}
