/////////////////////////////////////////////////////////////////////////////
//   Programmname : mad.cpp
//
//   Autor   :  DI W. Alfery
//
//   Aufgabe :
//   Erstelle das C++ Programm "mad_Klasse_katnr.cpp",
//   um das Spiel "Mensch Ärgere Dich nicht" auszuführen.
//
//   Das Spiel ist für 2 Spieler gedacht, die jeweils abwechselnd würfeln.
//   Das Würfeln wird dabei mit der Entertaste aktiviert und
//   über eine erzeugte Zufallszahl von 1 bis 6 ausgeführt.
//   Das Ergebnis sowie die erreichte Spielposition wird danach angezeigt.
//   Gelangt ein Spieler auf ein Feld des Gegners, so muss der Gegner
//   auf die Position 0 zurück.
//   Der Erste im Ziel ( Position 30 ) ist Sieger.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>
 #include <conio.h>
 #include "conio2.h"
 #include <stdlib.h>
 #include <time.h>

 using namespace std;

/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  char antwort;
   int schlg1,schlg2,r1,r2,pos1,pos2;
   const int ENDPOS=30;                       // Konstante Enposition bestimmen

   textcolor(BLUE);                           // Textfarbe einstellen
   textbackground(LIGHTGRAY);                 // Hintergrund einstellen

   do                                         // Programmwiederholung
   {
       clrscr();                              // Bildschirm löschen
       gotoxy(25,2);                          // Cursor auf Position x=25,y=2
       printf ("  Mensch \x84rgere Dich nicht \r\n");          // Ausgabe mit Textfarbe
       srand(time(NULL));       // Zufallsfolge initialisieren
       pos1=0;                  // Anfangsposition = 0
       pos2=0;
       r1=0;
       r2=0;


       do
       {
          textcolor(GREEN);
          //========Spieler1========//
          gotoxy(5,5);
          printf ("  Spieler 1 wuerfelt mit Tastendruck ");
          getch();              // warten auf Tastendruck
          r1=rand()%6 + 1 ;     // Zufallszahlen von 1 bis 6
          pos1 += r1;           // neue Position
          printf ("  = %4d  Position = %d ",r1,pos1);
          if (r1==6)
          {
              textcolor(BLUE);
              gotoxy(5,5);
              printf ("  Spieler 1 wuerfelt mit Tastendruck ");
              printf ("  = %4d  Position = %d ",r1,pos1);
              printf ("\n\n      Spieler 1 hat 6 gewuerfelt, mit Tastendruck nochmals wuerfeln.");
              r1=rand()%6 + 1 ;     // Zufallszahlen von 1 bis 6
              pos1 += r1;           // neue Position
              textcolor(GREEN);
          }

          schlg1=0;
          if (pos1==pos2)
          {
              textcolor(BLUE);
              pos2=0;
              gotoxy(5,5);
              printf ("\n\n      Spieler 1 schl\x84gt Spieler 2, dieser geht wieder auf Anfang.");
              textcolor(GREEN);
          }
          else
          {
              gotoxy(5,5);
              printf ("\n\n                                                                     ");
          }
          gotoxy(1,15); printf ("Spieler 1     |");clreol();
          gotoxy(15+pos1,15); printf("1");
          gotoxy(15+ENDPOS,15); printf ("|");


          //========Spieler2========//
          textcolor(RED);
          gotoxy(5,6);
          printf ("  Spieler 2 wuerfelt mit Tastendruck ");
          getch();              // warten auf Tastendruck
          r2=rand()%6 + 1 ;     // Zufallszahlen von 1 bis 6
          pos2 += r2;           // neue Position
          printf ("  = %4d  Position = %d ",r2,pos2);
          if (pos2==pos1)
          {
              textcolor(BLUE);
              pos1=0;
              gotoxy(5,5);
              printf ("\n\n      Spieler 2 schl\x84gt Spieler 1, dieser geht wieder auf Anfang.");
              textcolor(RED);
          }
          else
          {
              gotoxy(5,5);
              printf ("\n\n                                                                     ");
          }
          gotoxy(1,16); printf ("Spieler 2     |");clreol();
          gotoxy(15+pos2,16); printf("2");
          gotoxy(15+ENDPOS,16); printf ("|");


       } while ((pos1 < ENDPOS) && (pos2 < ENDPOS));

       textcolor(BLUE);
       printf("\n\n\nSpieler ");

       if (pos1>pos2)           //Gewinnabfrage
           printf("1");
       else
           printf("2");

       printf(" hat gewonnen!");
       printf("\n~~~~~~~~~~~~~~~~~~~~~~\n\n");

       gotoxy(30,25);
	   printf(" Programm Ende mit [Esc]      ");
 	   antwort=getch();

   } while (antwort!=27);

}

/////////////////////////////////////////////////////////////////////////////
