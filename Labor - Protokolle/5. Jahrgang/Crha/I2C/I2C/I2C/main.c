#ifndef F_CPU            //Wenn CPU-Takt nicht bereits definiert wurde...
#define F_CPU 16000000   //...dann definiere ihn auf 16MHz
#endif

#include "i2cmaster.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void) {
    
    i2c_init();                // Starte I2C Bus
    
    while(1)
    {
        
        for (int i = 0; i<=255; i++)
        {   i2c_start(0b10010000);
            i2c_write(0b01000000);
            i2c_write(i);
            i2c_stop();
        }
        
        for (int i = 255; i>=0; --i)
        {   i2c_start(0b10010000);
            i2c_write(0b01000000);
            i2c_write(i);
            i2c_stop();
        }
    }
    
    
    
    
    
    
    
    
        
        
    
}

/*#ifndef F_CPU            //Wenn CPU-Takt nicht bereits definiert wurde...
#define F_CPU 16000000   //...dann definiere ihn auf 16MHz
#endif

#include "i2cmaster.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char adr1_w = 0b01110000;  // write-address
volatile unsigned char adr1_r = 0b01110001;  // read-address

unsigned char read_data;               // Variable für Leseergebnis

int main(void) {
    cli();              // Interrupts deaktiviert
    
    cli();                     // Interrupts deaktiviert
    i2c_init();                // Starte I2C Bus

    
    read_data = 0xff;   // Grundwert für 'read_data'
    
    sei();              // Interrupts aktiviert
    
    while(1)
    {
        sei();            // Interrupts aktiviert
        
        i2c_start(adr1_w);
        i2c_write(0b11111011);
 
        i2c_start(adr1_r);           // Starte Lesezugriff
        read_data = i2c_readNak();   // read_data mit Leseergebnis beschreiben
        
        
        if(read_data == 0xff)
        {
            i2c_start(adr1_w);           // Starte Lesezugriff
            i2c_write(0b11111101);
            _delay_ms(20);
            i2c_write(0b11111110);
            _delay_ms(20);
        
        }
        
        else
        {
            i2c_start(adr1_w);           
            i2c_write(0b11111100);
            
        }

        
        
        
    }
}



#define F_CPU 16000000
#include <avr/io.h>
#include "i2cmaster.h"

int main(void)
{
    CLKPR = 0x80;   //Interner Clock-Prescaler to 1
    CLKPR = 0x00;
    DDRD = DDRD | (1<<DDD0) | (1<<DDD1); //PD0 und PD1 als Output
    TWBR = 32;
    
    i2c_init();
    
    while(1)
    {
        TWCR = TWCR | (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //START
        while(!(TWCR&(1<<TWINT)));//wait until Start is sent
        
        
        
        
        TWDR = 0b01110000; //Adr. 0111 0000W + Write (W=1 -> wir lesen!!!)
        TWCR = (1<<TWINT) | (1<<TWEN);//Send
        while(!(TWCR&(1<<TWINT))); //wait until Address is sent
        
        TWDR = 0; //Data Byte
        TWCR = (1<<TWINT) | (1<<TWEN);//Send Data Byte
        while(!(TWCR&(1<<TWINT))); //Wait until Data is sent
        
    
        
        
        TWCR = TWCR | (1<<TWINT) | (1<<TWSTO) | (1<<TWEN); //STOP
    }
}


int main(void)
{
    CLKPR = 0x80; //Interner Clock-Prescaler to 1
    CLKPR = 0x00; 
    DDRD = DDRD | (1<<DDD0) | (1<<DDD1);
    DDRB = DDRB | (1<<DDB0);
    TWBR = 32;
    while(1)
    {
        TWCR = TWCR | (1<<TWINT) | (1<<TWSTA) | (1<<TWEN); //START
        while(!(TWCR&(1<<TWINT))); //wait until Start is sent
        TWDR = 0b01110000; //Adr. 0111 0000W + Write (W=0)
        TWCR = (1<<TWINT) | (1<<TWEN);//Send
        while(!(TWCR&(1<<TWINT))); //wait until Address is sent
        while(1)
        {
            TWDR = 0xff; //Data Byte
            TWCR = (1<<TWINT) | (1<<TWEN);//Send Data Byte
            while(!(TWCR&(1<<TWINT)));//Wait until Data is sent
            TWDR = 0x00;
            TWCR = (1<<TWINT) | (1<<TWEN); //Data Byte sende
            while(!(TWCR&(1<<TWINT)));
        }
        TWCR = TWCR | (1<<TWINT) | (1<<TWSTO) | (1<<TWEN); //STOP
    }
}
*/