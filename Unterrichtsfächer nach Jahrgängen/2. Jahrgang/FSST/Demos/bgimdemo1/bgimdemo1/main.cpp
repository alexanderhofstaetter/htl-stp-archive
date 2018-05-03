/////////////////////////////////////////////////////////////////////////////
//   Programmname : bgim_demo.cpp
//   DI W.Alfery
//
//   WinBGIm Demo - Grafikfenster erzeugen,
//                  Farben einstellen,
//                  Linien u. Kreis zeichnen
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "graphics.h"              // Headerfile für WinBGIm Funktionen

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   printf(" WinBGIm Demo \n ");
   printf(" by w.alfery  \n ");

   // Grafikfenster  erzeugen mit Breite=640, Höhe=480 und Beschriftung
   initwindow(640,480,"WinBGIm Demo");

   // Hintergrundfarbe festlegen
   setbkcolor(LIGHTBLUE);
   // Fenster mit Hintergrundfarbe neu zeichnen
   cleardevice();

   // Zeichenfarbe festlegen
   setcolor(BLUE);
   // Linie von x1,y1 zu x2,y2 ziehen
   line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
   line(getmaxx()/2, 0, getmaxx()/2, getmaxy());

   // neue Zeichenfarbe über RGB definieren
   setcolor(COLOR(250,50,50));
   // Kreis mit Mittelpunkt xr=320, yr=240 und Radius=150 zeichnen
   circle(320,240,150);

   setcolor(LIGHTGRAY);
   // Text an der Position x=500, y=10 ausgeben
   outtextxy(500,10," by di w.alfery ");

   // auf Tastendruck warten
   getch();
   // Grafikfenster schließen
   closegraph();

   return 0;
}


