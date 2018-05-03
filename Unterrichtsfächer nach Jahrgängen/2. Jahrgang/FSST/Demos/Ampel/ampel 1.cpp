/////////////////////////////////////////////////////////////////////////////
//   Programmname : ampel1.cpp
//   DI W.Alfery
//
//   Ampel - grafische Darstellung einer Verkehrsampel
//
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf(" Ampel 1 by w.alfery  \n ");

   // Grafikfenster  erzeugen mit Breite=640, Höhe=480 und Beschriftung
   initwindow(640,480,"WinBGIm Demo");

   // Hintergrundfarbe festlegen und neu zeichnen
   setbkcolor(COLOR(200,255,200));
   cleardevice();

   // Ampel Umriss zeichnen
   setcolor(COLOR(10,10,10));
   rectangle(100,100,250,400);

   // Ampel Fläche mit Farbe füllen
   setfillstyle(1,COLOR(150,150,150));
   bar(101,101,250,400);

   // Signalleuchte rot zeichnen
   setfillstyle(1,RED);
   fillellipse(175,150,40,40);
   // Signalleuchte gelb zeichnen
   setfillstyle(1,YELLOW);
   fillellipse(175,250,40,40);
   // Signalleuchte grün zeichnen
   setfillstyle(1,GREEN);
   fillellipse(175,350,40,40);

   // Ampel beschriften
   setcolor(BLACK);
   outtextxy(150,410," Ampel 1");

   // bei Tastendruck Grafikfenster schließen
   getch();
   closegraph();

   return 0;
}


