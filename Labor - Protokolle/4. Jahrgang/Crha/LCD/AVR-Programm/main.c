#define F_CPU 12000000UL

#include <avr/io.h>
#include "bildschirm.h"					

int main(void)
{
    DDRB = 0xFF;
	
	initialisieren();					        //Initialisierung
	char temp[20];
	
	void Lauftext()
	{
	  while(1)
	  {
	    char tmp;
	    char ausgabe[5] = "cc - labor"; 
    
	    string(ausgabe);
    
	    tmp = ausgabe[0];
    
	    for(int i = 0; i <= 6; i++)
	    {
	      ausgabe[i] = ausgabe [i+1];
	    }

	    ausgabe [4] = tmp;
	  }
	}
	

	
	/*
	
	//string("0, O, o, ");
    //senden(0b11011011);
	
	while(1)
	{for(int i=0;i<=100;i++)
	{	cmd(0xC0);
		sprintf(temp,"%3d", i);
		
		string(temp);
	}}*/
			
	//DDRB = DDRB |(1<<E)  |(1<<RS) |(1<<RW);               	//E,RS,RW als Ausgang
	//PORTB = PORTB & (~(1<<E) &  ~(1<<RS) &  ~(1<<RW));    //RS=0,E=0,RW=0

	return(0);
}