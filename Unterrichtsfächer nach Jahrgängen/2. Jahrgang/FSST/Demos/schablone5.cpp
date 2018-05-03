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
       system("CLS");                  // Bildschirm löschen

       gotoxy(5,5 );
       printf(" Programmwiederholung ");

       gotoxy(5,6 );
       printf(" ->  %5d -mal",i++);







	   printf("\n\n\n\n");
	   printf(" Programm Ende mit [Esc]      ");
 	   antwort=getch();
   } while (antwort!=ESC);

}

/////////////////////////////////////////////////////////////////////////////

