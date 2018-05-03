/////////////////////////////////////////////////////////////////////////////
//   Programm : cursordemo
//
//   Autor   :  A. Hofstaetter
//   Aufgabe :  Cursor Steuerung
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

/////////////////////////////////////////////////////////////////////////////

 #define UP       72
 #define DOWN     80
 #define LEFT     75
 #define RIGHT    77
 #define POS1     71
 #define END      79
 #define PAGEUP   73
 #define PAGEDOWN 81
 #define ESC      27


 int grube1_x1=25,grube1_x2=30,                 //Grube 1 Koordinaten
     grube1_y1=5 ,grube1_y2=10;

 int falle1_x1=85,falle1_x2=90,                 //Falle 1 Koordinaten
     falle1_y1=45,falle1_y2=55;

 int hilfe1_x1=50,hilfe1_x2=55,                 //Hilfe1 Koordinaten
     hilfe1_y1=30,hilfe1_y2=35;


 //....



 int schatz1_x1=90,schatz1_x2=94,                //Hilfe1 Koordinaten
     schatz1_y1=35,schatz1_y2=37;



/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{

   char key;                                // Variable für ein Zeichen
   int x,y,x1,y1,xmax,ymax,change;          // Variable für ganze Zahlen
   xmax=100;ymax=50;                        // Fenstergröße

   system("mode con cols=100 lines=50");    // Konsolen-Fenstergröße einstellen

   textcolor(BLACK);                        // Textfarbe einstellen
   textbackground(RED);                     // Hintergrund einstellen
   _setcursortype(100);                     // Cursor auf volle Größe einstellen

   clrscr();                                // Bildschirm löschen
   gotoxy(1,1);  cprintf ("    Cursorsteuerung mit Cursortasten  ");

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
      {  gotoxy(1,ymax);                    // x,y-Positionsanzeige
         cprintf("     Cursorposition  x=%4i y=%4i    Abbruch mit ESC  ",x,y);

         if (x>=hilfe1_x1 && x <= hilfe1_x2 && y>=hilfe1_y1 && y<=hilfe1_y2)
         {  gotoxy(1,y);
            printf(" Der Schatz ist weiter rechts ");
            Sleep(200);
            gotoxy(1,y);clreol();
         }


         if (x>=grube1_x1 && x <= grube1_x2 && y>=grube1_y1 && y<=grube1_y2)
         {  gotoxy(1,y);
            printf(" In die Grube gefallen ");
            Sleep(200);
            gotoxy(1,y);clreol();
         }

         if (x>=falle1_x1 && x <= falle1_x2 && y>=falle1_y1 && y<=falle1_y2)
         {  gotoxy(1,y);
            printf(" HAHA du NOOB ");
            Sleep(200);
            gotoxy(1,y);clreol();
         }

         if (x>=schatz1_x1 && x <= schatz1_x2 && y>=schatz1_y1 && y<=schatz1_y2)
         {  gotoxy(1,y);
            printf(" JAAAA du bist REICH ");
            Sleep(200);
            gotoxy(1,y);clreol();
         }
        gotoxy(x,y);                       // x,y Position einstellen
        change=0;
      }



   } while(key!=ESC);

}

/////////////////////////////////////////////////////////////////////////////
