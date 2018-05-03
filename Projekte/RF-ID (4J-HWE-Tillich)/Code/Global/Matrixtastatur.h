#include <avr/io.h>					// Include File für IO Definitionen
#include <avr/interrupt.h>			// Include File für sei(), cli()
#include <util/delay.h>

//  PD0 PD1 PD2 PD3
//   |   |   |   |
//
//   1   2   3   A  -- PD4 Ausgang
//   4   5   6   B  -- PD5 Ausgang
//   7   8   9   C  -- PD6 Ausgang
//   *   0   #   A  -- PD7 Ausgang

#define PORT_USED PORTB
#define DDR_USED DDRB
#define PIN_USED PINB

unsigned char getTaste(void)
{
    char zeile,spalte;
    // *********** Auswertung der Zeile ***********************
    DDR_USED = 0xF0; //Zwischenschritt lt. Dantenblatt für Umkonfiguration der Portpins
    PORT_USED = 0xF0; //von INPUT mit Pull Up auf OUTPUT LOW
    DDR_USED = 0x0F; //PD 4-7 als OUTPUT (Spalten), PB 3-0 als INPUT (Zeilen)
    PORT_USED = PORT_USED | 0xF0; //PD 3-0 int. Pull Up Widerstände ein
    PORT_USED = PORT_USED & 0xF0; //PD 4-7 auf "0"
    
    switch ((PIND & 0xF0))
    {   // Spalte Zeile
        case 0xE0: //Zeile PD0 = "0" 0000 1110
            spalte = 1; break;
        case 0xD0: //Zeile PD1 = "0" 0000 1101
            spalte = 2; break;
        case 0xB0: //Zeile PD2 = "0" 0000 1011
            spalte = 3; break;
        case 0x70: //Zeile PD3 = "0" 0000 0111
            spalte = 4; break;
        default : //mehrere Tasten wurden gedrückt
            spalte = 0; break;
    }
    
    // ************ Auswertung der Spalten ******************
    DDR_USED = 0x0F; //Zwischenschritt lt. Dantenblatt für Umkonfiguration der Portpins
    PORT_USED = 0x0F; //von INPUT mit Pull Up auf OUTPUT LOW
    DDR_USED = 0xF0; //PB 4-7 als INPUT (Spalten), PD3-0 als OUTPUT (Zeilen)
    PORT_USED = (spalte | 0x0F); //Erg. von Zeile auf PD3-0 damit gedr. Zeile=0 und alle anderen Zeilen=1
    
    //PD 4-7 int. Pull Up Widerstände ein
    switch (PIN_USED & 0x0F) // oberen 4 Bit = 1 => gedr. Taste zieht dann Spalte von 1=>0
    { // Spalte Zeile
        case 0x0E: //Spalte PD4 = "0" 1110 0000
            zeile = 1; break;
        case 0x0D: //Spalte PD5 = "0" 1101 0000
            zeile = 2; break;
        case 0x0B: //Spalte PD6 = "0" 1011 0000
            zeile = 3; break;
        case 0x07: //Spalte PD7 = "0" 0111 0000
            zeile = 4; break;
        default: //mehrere Spalten sind auf "0"
            zeile = 0; break;
    }

    if      (zeile == 1 && spalte == 1) return '1';
    else if (zeile == 1 && spalte == 2) return '2';
    else if (zeile == 1 && spalte == 3) return '3';
    else if (zeile == 1 && spalte == 4) return 'A';
    else if (zeile == 2 && spalte == 1) return '4';
    else if (zeile == 2 && spalte == 2) return '5';
    else if (zeile == 2 && spalte == 3) return '6';
    else if (zeile == 2 && spalte == 4) return 'B';
    else if (zeile == 3 && spalte == 1) return '7';
    else if (zeile == 3 && spalte == 2) return '8';
    else if (zeile == 3 && spalte == 3) return '9';
    else if (zeile == 3 && spalte == 4) return 'C';
    else if (zeile == 4 && spalte == 1) return '*';
    else if (zeile == 4 && spalte == 2) return '0';
    else if (zeile == 4 && spalte == 3) return '#';
    else if (zeile == 4 && spalte == 4) return 'D';
    return 0;
}