/////////////////////////////////////////////////////////////////////////////
//   Programmname : ball.cpp
//   DI W.Alfery
//
//   Ball - bewegen
//
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "graphics.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//                       Grafikfenster Konstante
/////////////////////////////////////////////////////////////////////////////
const int XMIN=0;  const int XMAX=600;      // Fenstergröße
const int YMIN=0;  const int YMAX=400;
const int HCOL=COLOR(220,220,240);          // Hintergrundfarbe
const int BCOL=COLOR(50,50,100);            // Ballfarbe



////////////////////////////////////////////////////////////////////////////
//                       Funktionsprototypen
/////////////////////////////////////////////////////////////////////////////
int cursor(int &x,int &y,int dx, int dy);
void grenzen (int &x,int &y,int xmin,int xmax, int ymin, int ymax);
void bewegen (int x0,int y0, int x, int y, int r);


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf(" Ball by w.alfery  \n ");

   // Grafikfenster
   initwindow(XMAX,YMAX,"Ball Demo");
   setbkcolor(HCOL);
   cleardevice();


   // Ball
   int x,y,r;                                    // Ball Position und Radius
   int x0,y0,dx,dy;
   x=x0=XMAX/2;
   y=y0=YMAX/2;
   r=20;
   dx=10;dy=10;

   setcolor(BCOL);                               // Farben einstellen
   setfillstyle(1,BCOL);
   fillellipse(x,y,r,r);                         // Ball zeichnen

   do
   {  x+=dx;y+=dy;
      bewegen(x0,y0,x,y,r);                      // Ball nach x,y bewegen
      x0=x;y0=y;
      if (x>XMAX-r) dx=-dx;                      // Richtungsumkehr
      if (x<r)      dx=-dx;
      if (y>YMAX-r) dy=-dy;
      if (y<r)      dy=-dy;
      delay(5.0);
   } while (!kbhit());                           // solange keine Taste gedrückt wird

   // Navigation
   int  change=0;                                // Anzeige Änderungen
   char key;                                     // Variable für Tastensteuerung
   dx=10;dy=10;
   do
   {

       change=cursor(x,y,dx,dy);                 // Cursorsteuerung
       grenzen(x,y,XMIN+r,XMAX-r,YMIN+r,YMAX-r); // x,y-Grenzen prüfen

       if (change)                               // bewegen bei Cursor-Änderungen
       {
          bewegen(x0,y0,x,y,r);                  // Ball nach x,y bewegen
          x0=x;y0=y;
          change=0;
       }

   } while (change>=0);


   closegraph();

   return 0;
}



/////////////////////////////////////////////////////////////////////////////
//                       Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

int cursor(int &x,int &y,int dx, int dy)
/////////////////////////////////////////////////////////////////////////////
//   Cursor Steuerung
//   Import/Export :  int x   ...  x-Position
//                    int y   ...  y-Position
//   Return        :  int     ...  Positionsänderung
/////////////////////////////////////////////////////////////////////////////
{
   // Cursortasten Codes
   const int UP    =72;
   const int DOWN  =80;
   const int LEFT  =75;
   const int RIGHT =77;
   const int ESC   =27;

   int  change=0;                      // Anzeige Änderungen
   char key;                           // Variable für Tastensteuerung

   //  Cursorsteuerung
   if (kbhit())                        // bei Tastendruck
   {
      key = getch();                   // welche Taste ?
      switch (key)
      { case UP    : y=y-dy;           // Cursor UP
                   break;
        case DOWN  : y=y+dy;           // Cursor DOWN
                   break;
        case LEFT  : x=x-dx;           // Cursor LEFT
                   break;
        case RIGHT : x=x+dx;           // Cursor DOWN
                   break;
        case ESC  : return -1;         // Abbruch
       }
       change=1;
    }
    return change;
 }




void grenzen (int &x,int &y,int xmin,int xmax, int ymin, int ymax)
/////////////////////////////////////////////////////////////////////////////
//   Begrenzung auf Bildbereich
//   Import        :  int xmin ...  x-Grenzen
//                    int xmax
//                    int ymin ...  y-Grenzen
//                    int ymax
//   Import/Export :  int x    ...  x-Position
//                    int y    ...  y-Position
/////////////////////////////////////////////////////////////////////////////
{  if (y<ymin)
   {  y=ymin;
   }
   else if (y>ymax)
   { y=ymax;
   }
   if (x<xmin)
   { x=xmin;
   }
   else if (x>xmax)
   { x=xmax;
   }
}


void bewegen (int x0,int y0, int x, int y, int r)
////////////////////////////////////////////////////////////////////////////
//   Ball von Position x0,y0 zu x,y bewegen
//   Import        :  int x0   ...  x-Anfangsposition
//                    int y0   ...  y-Anfangsposition
//                    int x    ...  x-Endposition
//                    int y    ...  y-Endposition
/////////////////////////////////////////////////////////////////////////////
{
   int bkcol=getbkcolor();             // Hintergrundfarbe abfragen
   int col=getcolor();                 // Zeichenfarbe abfragen

   setcolor(bkcol);                    // Zeichenfarbe auf Hintergrund einstellen
   setfillstyle(1,bkcol);              // Hintergrundfarbe einstellen
   fillellipse(x0,y0,r,r);             // Ball an alter Position löschen
                                       // ( mit Hintergrundfarbe überzeichnen )

   setcolor(col);                      // Zeichenfarbe rückstellen
   setfillstyle(1,col);                // Ballfarbe einstellen
   fillellipse(x,y,r,r);               // Ball an neuer Position zeichnen
}
