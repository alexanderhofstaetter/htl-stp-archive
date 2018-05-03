/////////////////////////////////////////////////////////////////////////////
//   Programm : Schatzsuche
//
//   Autor   :  A. Hofstätter
//   Aufgabe :  Schatzsuche mit Cursorsteuerung
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>
 #include "conio2.h"
 #include <string>
 #include <windows.h>                // für Sleep()
 using namespace std;

//-----------------------------------------------------------------------
//                       Cursortasten Codes
 #define UP       72
 #define DOWN     80
 #define LEFT     75
 #define RIGHT    77
 #define POS1     71
 #define END      79
 #define PAGEUP   73
 #define PAGEDOWN 81
 #define ESC      27
 #define Q        113
 #define ausgabe printf
 #define eingabe scanf

//-----------------------------------------------------------------------
//              Positionen für Grube, Falle, Hilfe und Schatz

 int grube1_x1=15,grube1_x2=18,                 //Grube Koordinaten
     grube1_y1=10,grube1_y2=13;

 int grube2_x1=35,grube2_x2=38,                 //Grube Koordinaten
     grube2_y1=40,grube2_y2=43;

 int falle1_x1=75,falle1_x2=80,                 //Falle Koordinaten
     falle1_y1=40,falle1_y2=45;



 int hilfe1_x1=30,hilfe1_x2=35,                 //Hilfe Koordinaten
     hilfe1_y1=45,hilfe1_y2=50;

//....

 int schatz1_x1=75,schatz1_x2=80,               //Schatz Koordinaten
     schatz1_y1=45,schatz1_y2=50;

 int grube_count=0,
     grube_count_max=5;

/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////



int main()
{

   char key;                                // Variable für ein Zeichen
   int x,y,x1,y1,xmax,ymax,change;          // Variable für ganze Zahlen
   xmax=100;ymax=50;                        // Fenstergröße

   system("mode con cols=100 lines=50");    // Konsolen-Fenstergröße einstellen

   textcolor(LIGHTGREEN);                         // Textfarbe einstellen
   textbackground(DARKGRAY);               // Hintergrund einstellen
   _setcursortype(75);                     // Cursor auf volle Größe einstellen

   clrscr();                                // Bildschirm löschen
   gotoxy(1,1);  ausgabe ("    Cursorsteuerung mit Cursortasten  ");

   gotoxy(xmax/2,ymax/2);                   // Anfangsposition einstellen
   x = wherex();                            // x-Cursorposition ermitteln
   y = wherey();                            // y-Cursorposition ermitteln
   change=1;

   do
   {  Sleep(5);                             // 5ms Zeitverzögerung

      if (kbhit())                          // bei Tastendruck
      {
         key = getch();                     // welche Taste ?
         switch (key)
         { case UP : y=y-1;                 // Cursor UP
                     if (y<1 ) y=1;
                     break;
           case DOWN : y=y+1;               // Cursor DOWN
                     if (y>ymax) y=ymax;
                     break;
  	       case LEFT : x=x-1;               // Cursor LEFT
                     if (x<1 ) x=1;
                     break;
           case RIGHT : x=x+1;              // Cursor DOWN
                     if (x>xmax) x=xmax;
                     break;
           case POS1 : x=1;                 // POS1
                     break;
           case END  : x=xmax;              // END
                     break;
           case PAGEUP : y=1;               // PageUP
                     break;
           case PAGEDOWN : y=ymax;          // PageDOWN
                     break;
         }
         change=1;

      }

      if (change)
      {
         gotoxy(1,ymax);        // Position einstellen
         ausgabe("     Cursorposition  x=%4i y=%4i  Programmende mit ESC  ",x,y); // Koordinaten am Bildschirmrand ausgeben

         if (x>=hilfe1_x1 && x <= hilfe1_x2 && y>=hilfe1_y1 && y<=hilfe1_y2)        // Textausgabe bei überfahren der Hilfe
         {  gotoxy(1,y);
            ausgabe(" Der Schatz befindet sich weiter rechts ");
            Sleep(200);
            gotoxy(1,y);clreol();
         }


         if (x>=grube1_x1 && x <= grube1_x2 && y>=grube1_y1 && y<=grube1_y2)        // Textausgabe bei überfahren der Grube
         {  gotoxy(1,y);
            ausgabe(" Du bist leider in die Grube gefallen, du darfst noch %i -Mal in eine Grube fallen",grube_count);
            Sleep(400);
            gotoxy(1,y);clreol();
            grube_count++;

         }

        if (x>=grube2_x1 && x <= grube2_x2 && y>=grube2_y1 && y<=grube2_y2)        // Textausgabe bei überfahren der Grube
         {  gotoxy(1,y);
            ausgabe(" Du bist leider in die Grube gefallen, du darfst noch %i -Mal in eine Grube fallen",grube_count);
            Sleep(400);
            gotoxy(1,y);clreol();
            grube_count++;

         }

         if (grube_count>=grube_count_max)
        {
            gotoxy(xmax/2,1);
            clrscr();
            ausgabe("Du bist zum 5. mal in eine Grube gefallen, das Spiel beendet sich nun");
            Sleep(2800);
            key = ESC;
        }


         if (x>=falle1_x1 && x <= falle1_x2 && y>=falle1_y1 && y<=falle1_y2)        // Textausgabe bei überfahren der Fallen
         {
            Sleep(20);
            clrscr();
            gotoxy(1,1);  ausgabe ("Du bist leider in eine Falle gefallen, das Spiel wird sich nun beenden.");
            Sleep(2800);
            key = ESC;
         }

         if (x>=schatz1_x1 && x <= schatz1_x2 && y>=schatz1_y1 && y<=schatz1_y2)    // Textausgabe bei überfahren des Schatz
         {  gotoxy(1,y);
            ausgabe(" Glueckwunsch du hast den Schatz gefunden ");
            Sleep(200);
            system("CLS");
            gotoxy(1,y);clreol();
         }
        gotoxy(x,y);
        change=0;


      }




   } while(key!=ESC);
}

/////////////////////////////////////////////////////////////////////////////
