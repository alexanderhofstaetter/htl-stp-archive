/////////////////////////////////////////////////////////////////////////////
//   Programmname : board.cpp
//   DI W.Alfery
//
//   Control Board -  Steuerungsanzeige
//   mit Verwendung von "controlboard"
//   zur Eingabe u. Anzeige von Ports
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "bse_console.h"              // für getch(),kbhit(),Sleep(), ...
#include "controlboard.h"             // für grafisches Controlboard


///////////////////////////////////////////////////////////////////////////////
//   globale Definitionen
///////////////////////////////////////////////////////////////////////////////
typedef unsigned char byte;          // Typdefinition für Byte (8 Bit)


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf("\n    Control Board \n");
   printf("    mit Grafikdisplay der Ports \n");


   int i=0;
   byte p1,p2;                        // Ports p1, p2 definieren
   p1=p2=0x0;                         // Anfangswerte für p1,p2 setzen

   drawBoard();                       // Control Board anzeigen

   while(1)                           // Endlos Schleife
   {
      p2=i++;                         // Ausgangsport um eins hochzählen

      updateBoard(&p1,&p2);           // Control Board Pins aktualisieren

      gotoxy(5,5);
      printf("Port p1=%3X hex %3d dez",p1,p1);   // Anzeige im Konsolenfenster
      gotoxy(5,6);
      printf("Port p2=%3X hex %3d dez",p2,p2);

      Sleep(50);                      // 50 ms warten
   }

   clearBoard();                      // Control Board schließen

   return 0;
}


