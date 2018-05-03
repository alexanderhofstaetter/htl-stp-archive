/////////////////////////////////////////////////////////////////////////////
//   Programmname : schablone4.cpp
//
//   Autor   :  W. Alfery
//   Datum   :  01.09.2011
//   Version :  2
//
//   Aufgabe :  Programmaufbau eines C/C++-Programms
//              mit Programmwiederholung
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  für printf(), scanf()
 #include <stdlib.h>                 //  für system()
 #include "bse_console.h"            //  für getch()

 #define ESC 27                      //  ESC - Ersatztext definieren


/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  char antwort;
   int i=0;

   do                                  // Wiederholung mit do-while-Schleife
   {   /*  ...   ab hier den Programmteil einfügen
	       ...   dieser Programmteil wird solange wiederholt,
	       ...   bis die ESC - Taste gedrückt wird.
	   */
       textbackground(LIGHTGRAY);      // Hintergrundfarbe einstellen
       textcolor(BLUE);                // Textfarbe einstellen
       clrscr();                       // Bildschirm löschen

       gotoxy(2,2 );                   // Cursorposition
       printf(" Programmwiederholung ");

       gotoxy(2,4 );
       printf(" ->  %5d -mal",i++);





       gotoxy(5,25);                   // letzte Zeile
	   textcolor(RED);
	   printf(" Programm Ende mit [Esc]      ");
 	   antwort=getch();
   } while (antwort!=ESC);

}

/////////////////////////////////////////////////////////////////////////////

