/////////////////////////////////////////////////////////////////////////////
//   Programmname : plot.cpp
//   DI W.Alfery
//
//   erstellt am : 10.10.2010
//
//   Funktionsplotter - grafische Darstellung von Funktionen
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
#include "plot.h"


/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinition
/////////////////////////////////////////////////////////////////////////////
float f(float x)
/////////////////////////////////////////////////////////////////////////////
//   Funktion y(x)
//   Import : float x     ... unabhängige Variable
//   Return : float       ... Funktionswert y
//
/////////////////////////////////////////////////////////////////////////////
{   float y;
    y=x;                                   // Testfunktion y=x
    return y;
}


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   // Grafikfenster  erzeugen mit Breite=600, Höhe=400 und Beschriftung
   initwindow(600,600,"Funktionsplotter © di w.alfery");

   float xs1=-10,xs2=10,ys1=-10,ys2=10;// Skalenbereich Endwerte
   int   x1=50,x2=550,y1=50,y2=550;    // Bildbereich Endwerte

   int bkcol =COLOR(220,220,250);      // Hintergrundfarbe
   int acol  =COLOR(50,50,200);        // Achsenfarbe
   int fcol  =COLOR(200,50,50);        // Diagrammfarbe

   setbkcolor(bkcol);                  // Hintergrundfarbe setzen
   cleardevice();                      // u. zeichnen

   viewport(x1,x2,y1,y2);              // Diagramm Bereich festlegen
   scales(xs1,xs2,ys1,ys2);            // Skalenbereich festlegen
   drawAxes(acol);                     // Achsen darstellen
   drawFunction(f,0.1,fcol);           // Funktion darstellen


   // bei Tastendruck Grafikfenster schließen
   getch();
   closegraph();

   return 0;
}

