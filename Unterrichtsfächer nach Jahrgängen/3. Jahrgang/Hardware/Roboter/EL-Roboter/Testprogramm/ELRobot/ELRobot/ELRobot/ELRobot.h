/*
 * ELRobot.h
 *
 * Created: 21.11.2012 10:33:58
 *  Author: Admin
 */ 


#ifndef ELROBOT_H_
#define ELROBOT_H_

// Richtung von Motorsteuerung abhängig von Übersetzungsverhältnis
#define CHANGE_DIRECTION	1		// wenn 1 -> Richtung wird umgekehrt

#define DEBUG_PIN		4			// PB4
#define DEBUG_PIN2		5			// PD5

#define ONE_TURN		10			// 10 Impulse = 1 Umdrehung
#define STOPP			0			// Bei Fast Stopp werden Impulse nicht abgefragt
#define ROT_180			((ONE_TURN)*70)/100			// 7 Impulse für 180° Drehung

//*************************************************************************************************
//*** Getriebe & MOTOR Daten ***
//*************************************************************************************************

#define GEAR_RATIO		344.2		// Übersetzungsverhältnis Getriebebox
#define MOTOR_RPS		31.94		// Umdrehungen/Sek. bei 1V, Freilauf
#define WHEEL_RPS		0.0928		// Reifenumdrehung/Sek. bei 1V
#define MAX_VOLTAGE		5			// Versorgungsspannung Motor (5V oder 7V)
#define MIN_U_PWM		MAX_VOLTAGE/256		// Motorspannung -> 256 Werte PWM
#define PWM_1V			256/MAX_VOLTAGE		// entspricht 1V
#define MIN_PWM			3*PWM_1V	// entspricht 3V
#define MAX_IMPULSTIME	335			// in Millisekunden (geringste Drehzahl)
#define DELTA_IMPULSTIME 67			// Timerwert 67 -> 2.15ms Änderung bei PWM Änderung um 1

//*************************************************************************************************
//*** MOTOR ***
//*************************************************************************************************

// MotorPins
#define MOT_L_V			5			// PF5
#define MOT_L_B			6			// PF6
#define MOT_R_V			7			// PF7
#define MOT_R_B			6			// PC6

#define MOTOR_R			6			// PB6
#define MOTOR_L			7			// PD7

// Motor Funktion
#if (CHANGE_DIRECTION==1)
#define MOT_FORWARD		1
#define MOT_BACKWARD	0
#else
#define MOT_FORWARD		0
#define MOT_BACKWARD	1
#endif
#define MOT_FAST_STOPP	2

#define PWM_STOPP		0

//*************************************************************************************************
//*** LED *****
//*************************************************************************************************

// LED Pins
#define LED_RV			0			// PB0
#define LED_RH			1			// PB1
#define LED_LV			2			// PB2
#define LED_LH			3			// PB3
// Duo LED
#define LED_ROT			2			// PD2
#define LED_GRUEN		3			// PD3

//*************************************************************************************************
//*** INFRAROT ***
//*************************************************************************************************

#define IR_SENDER		6			// PD6
#define IR_EMPF_R		1			// ADC1
#define IR_EMPF_L		0			// ADC0

//*************************************************************************************************
//*** IMPULSGEBER ***
//*************************************************************************************************

#define WHEEL_RIGHT		4			// PD4
#define WHEEL_LEFT		7			// PC7

//*************************************************************************************************
//*** BEEPER ***
//*************************************************************************************************

// Beeper Pins
#define BEEPER			7			// PB7
// Toene
#define NONE			0
#define BEEP			8
#define c				(118/2)		// entspricht 264Hz -> c'
#define d				((c*9/8)-c) // entspricht d'
#define e				((c*5/4)-c) // entspricht e'
#define f				((c*4/3)-c) // entspricht f'
#define g				((c*3/2)-c) // entspricht g'
#define a				((c*5/3)-c) // entspricht a'
#define h				((c*15/8)-c) // entspricht h'
#define c_2				((c*2/1)-c) // entspricht c''

//*************************************************************************************************
//*** FUNKTIONSPROTOTYPEN ***
//*************************************************************************************************

void set_fuses(void);
void init(void);
void pwm_timer_init(void);
void pwm_timer_start(void);
void pwm_timer_stop(void);
void odometer_timer_init(void);
void odometer_links_start(void);
void odometer_rechts_start(void);
void odometer_links_stop(void);
void odometer_rechts_stop(void);
void timer_beeper_init(void);
void timer_beep_tone(unsigned int frequenz);
void timer_beep_melodie(void);
void beep(unsigned char);
void drive_Robot(unsigned char, unsigned char, unsigned char, unsigned char, unsigned int, unsigned int);

//*************************************************************************************************
//  Funktionen
//*************************************************************************************************

void set_fuses(void)
{
	MCUCR |= (1<<JTD);
	MCUCR |= (1<<JTD);
	
	CLKPR = 0b10000000;
	CLKPR = 1;
}

void init(void)
{
	DDRB |= (1<<BEEPER) | (1<<MOTOR_R) | (1<<DEBUG_PIN) | (1<<LED_LH) | (1<<LED_LV) | (1<<LED_RH) | (1<<LED_RV);
	PORTB |= (1<<DEBUG_PIN) | (1<<LED_LH) | (1<<LED_LV) | (1<<LED_RH) | (1<<LED_RV);
	
	DDRF |= (1<<MOT_L_V) | (1<<MOT_L_B) | (1<<MOT_R_V);
	PORTF = 0;
	
	DDRD |= (1<<DEBUG_PIN2) | (1<<MOTOR_L) | (1<<IR_SENDER) | (1<<LED_GRUEN) | (1<<LED_ROT);
	PORTD |= (1<<DEBUG_PIN2);// | (1<<WHEEL_RIGHT);
	
	DDRC |= (1<<MOT_R_B);
//	PORTC |= (1<<WHEEL_LEFT);

	pwm_timer_init();
	odometer_timer_init();
	timer_beeper_init();
	sei();
}

void pwm_timer_init(void)
{
	// Timer 4
	//MOTOR RECHTS
	TCCR4A |= (1<<COM4B1) | (1<<PWM4B);		// OC4B aktiviert bei Compare Match, PWM4B aktiviert
	//MOTOR LINKS
	TCCR4C |= (1<<COM4D1) | (1<<PWM4D);		// OC4D aktiviert bei Compare Match, PWM4D aktiviert 
}

void pwm_timer_start(void)
{
	// Timer 4
	//MOTOR RECHTS
	TCCR4A |= (1<<COM4B1) | (1<<PWM4B);		// OC4B aktiviert bei Compare Match, PWM4B aktiviert
	//MOTOR LINKS
	TCCR4C |= (1<<COM4D1) | (1<<PWM4D);		// OC4D aktiviert bei Compare Match, PWM4D aktiviert

	TCCR4B = 0;
	TCCR4D = 0;
	TCCR4E = 0;
	
	TCNT4 = 0;
	DT4 = 0;								// Dead Time Generator aus
	
	OCR4B = PWM_STOPP;						// PWM 0%
	OCR4D = PWM_STOPP;						// PWM 0%
	
	TCCR4B |= (1<<CS40);					// ca. 64kHz
	
	status |= (1<<STATUS_PWM_TIMER);
}

void pwm_timer_stop(void)
{
	TCCR4B = 0;
	TCCR4A = 0;
	TCCR4C = 0;
	status &= ~(1<<STATUS_PWM_TIMER);
}

void odometer_timer_init(void)
{
	TCCR1A = 0;
	TCCR1B = (1<<ICNC1);					// Input Capture Mode aktiviert
	TCCR1C = 0;
	TCCR3A = 0;
	TCCR3B = (1<<ICNC3);					// Input Capture Mode aktiviert
	TCCR3C = 0;
}

void odometer_links_start(void)
{
	motor_left_count = 0;
	check_impuls_left = 0;
	TIMSK3 |= (1<<ICIE3);
	ICR3 = 0;
	TCNT3 = 0;		
	TCCR3B |= (1<<CS32);
	TIFR3 |= (1<<ICF3);
}

void odometer_rechts_start(void)
{
	motor_right_count = 0;
	check_impuls_right = 0;
	TIMSK1 |= (1<<ICIE1);
	ICR1 = 0;
	TCNT1 = 0;
	TCCR1B |= (1<<CS12);
	TIFR1 |= (1<<ICF1);
}

void odometer_links_stop(void)
{
	TCCR3B &= ~((1<<CS32) | (1<<CS31) | (1<<CS30));
}

void odometer_rechts_stop(void)
{
	TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
}

void timer_beeper_init(void)
{
	//Timer0
	TCNT0 = 0;
	OCR0A = 0;
	
	TCCR0A |= (1<<COM0A0) | (1<<WGM01) | (1<<WGM00);
	TCCR0B |= (1<<WGM02);
	
}

void timer_beep_tone(unsigned int frequenz)
{
	OCR0A = frequenz;
	TCCR0B |= (1<<CS02);
}

void timer_beep_melodie(void)
{
	
}

void drive_Robot(unsigned char dir_motr, unsigned char pwm_rechts, unsigned char dir_motl, unsigned char pwm_links, unsigned int impulse_rechts, unsigned int impulse_links)
{
	
	// MOTOR RECHTS	
	if (dir_motr == 2)
	{
		pwm_timer_stop();
		PORTB |= (1<<MOTOR_R);
		PORTF &= ~(1<<MOT_R_V);
		PORTC &= ~(1<<MOT_R_B);
	}
	else if (dir_motr == 1)
	{
		if(!(status&(1<<STATUS_PWM_TIMER)))
		{
			pwm_timer_start();
		}
		PORTF |= (1<<MOT_R_V);
		PORTC &= ~(1<<MOT_R_B);
	}
	else
	{
		if(!(status&(1<<STATUS_PWM_TIMER)))
		{
			pwm_timer_start();
		}
		PORTF &= ~(1<<MOT_R_V);
		PORTC |= (1<<MOT_R_B);
	}
	
	// MOTOR LINKS
	if (dir_motl == 2)
	{
		pwm_timer_stop();
		PORTD |= (1<<MOTOR_L);
		PORTF &= ~(1<<MOT_L_V);
		PORTF &= ~(1<<MOT_L_B);
	}
	else if (dir_motl == 1)
	{
		if(!(status&(1<<STATUS_PWM_TIMER)))
		{
			pwm_timer_start();
		}
		PORTF |= (1<<MOT_L_V);
		PORTF &= ~(1<<MOT_L_B);
	}
	else
	{
		if(!(status&(1<<STATUS_PWM_TIMER)))
		{
			pwm_timer_start();
		}
		PORTF &= ~(1<<MOT_L_V);
		PORTF |= (1<<MOT_L_B);
	}
	
	if (status&(1<<STATUS_PWM_TIMER))
	{
		OCR4B = pwm_rechts;
		OCR4D = pwm_links;
			
		impuls_right_set = impulse_rechts;
		impuls_left_set = impulse_links;
		
		if (pwm_rechts != PWM_STOPP)
		{
			odometer_rechts_start();
			status &= ~(1<<STATUS_MOT_R_READY);
		}
		else
		{
			status |= (1<<STATUS_MOT_R_READY);
		}
		
		if (pwm_links != PWM_STOPP)
		{
			odometer_links_start();
			status &= ~(1<<STATUS_MOT_L_READY);
		}
		else
		{
			status |= (1<<STATUS_MOT_L_READY);
		}
		
		status |= (1<<STATUS_BUSY);		
	}
}

unsigned char check_impulse(void)
{	
	//if (status&(1<<STATUS_MOT_R_READY))
	//{	
		//TCCR1B &= ~((1<<CS12) | (1<<CS11) | (1<<CS10));
		//TIMSK1 = 0;
		//OCR4B = PWM_STOPP;
	//}

	//if (status&(1<<STATUS_MOT_L_READY))
	//{
		//TCCR3B &= ~((1<<CS32) | (1<<CS31) | (1<<CS30));
		//TIMSK3 = 0;
		//OCR4D = PWM_STOPP;
	//}

	if (status&(1<<STATUS_MOT_R_READY) && status&(1<<STATUS_MOT_L_READY))
	{
		status &= ~(1<<STATUS_BUSY);
		return 1;
	} 
	else
	{
		return 0;
	}
}

void beep(unsigned char times)
{
	for (int i=0; i < times ; i++)
	{
		timer_beep_tone(BEEP);
		_delay_ms(100);
		timer_beep_tone(NONE);
		_delay_ms(100);
	}
}


#endif /* ELROBOT_H_ */
