/////////////////////////////////////////////////////////////////////////////
//   Programmname : plot.cpp
//   DI W.Alfery
//
//   erstellt am : 10.10.2010
//
//   Funktionsplotter - grafische Darstellung von Funktionen
//
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
//   Funktions Prototypen
/////////////////////////////////////////////////////////////////////////////

float function(float x);
float function2(float x);
int scalx(int x1, int x2, float xs1, float xs2, float xf);
int scaly(int y1, int y2, float ys1, float ys2, float yf);



/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   // Grafikfenster  erzeugen mit Breite=600, Höhe=400 und Beschriftung
   initwindow(600,500,"Funktionsplotter © di w.alfery");

   float xs1=-10,xs2=10,ys1=-2,ys2=2;  // Skalenbereich Endwerte
   float xf,yf;                        // Funktionswerte
   int   x1=50,x2=550,y1=50,y2=450;    // Bildbereich Endwerte
   int   x0,y0;                        // Diagramm Ursprung
   int   x,y;                          // Bildwerte

   int bkcol =COLOR(220,220,250);      // Hintergrundfarbe
   int dbcol =COLOR(250,250,250);      // Diagramm Hintergrundfarbe
   int acol  =COLOR(50,50,200);        // Achsenfarbe
   int fcol  =COLOR(200,50,50);        // Diagrammfarbe

   setbkcolor(bkcol);                  // Farben setzen
   cleardevice();
   setcolor(acol);

   setfillstyle(1,dbcol);              // Diagramm Hintergrund
   bar(x1,y1,x2,y2);
   rectangle(x1,y1,x2,y2);             // Diagrammrahmen zeichnen
   x0=scalx(x1,x2,xs1,xs2,0);          // xf=0 -> Bildpunkt für Koordinaten Ursprung
   y0=scaly(y1,y2,ys1,ys2,0);          // yf=0
   line(x0,y1,x0,y2);                  // x-Achse zeichnen
   line(x1,y0,x2,y0);                  // y-Achse zeichnen

   setcolor(fcol);
   moveto(x1,y0);                      // zum Anfangspunkt bewegen
   for (xf=xs1;xf<=xs2;xf+=0.1)        // Berechnung für den gesamten Skalenbereich
   {
       yf = function(xf);              // yf-Funktionswert aus xf berechnen

       x=scalx(x1,x2,xs1,xs2,xf);      // x-Bildpunkt berechnen
       y=scaly(y1,y2,ys1,ys2,yf);      // y-Bildpunkt berechnen

       lineto(x,y);                    // Linienzug ausgeben
   }

   setcolor(COLOR(50,200,50));
   moveto(x1,y0);
   for (xf=xs1;xf<=xs2;xf+=0.1)        // Diagramm - Sinusüberlagerung
   {
       yf = function2(xf);
       x=scalx(x1,x2,xs1,xs2,xf);
       y=scaly(y1,y2,ys1,ys2,yf);
       lineto(x,y);
   }


   // bei Tastendruck Grafikfenster schließen
   getch();
   closegraph();

   return 0;
}


/////////////////////////////////////////////////////////////////////////////
//   Funktions Definitionen
/////////////////////////////////////////////////////////////////////////////


float function(float x)
/////////////////////////////////////////////////////////////////////////////
//   Funktion y(x)
//   Import : float x     ... unabhängige Variable
//   Return : float       ... Funktionswert y
//
/////////////////////////////////////////////////////////////////////////////
{   float y;
    //y=x;                                    // Testfunktion y=x
    y=sin(x);                               // Sinusfunktion
    return y;
}

float function2(float x)
{   float y;
    y=sin(x)+1.0/3*sin(3*x)+1.0/5*sin(5*x); // Sinusüberlagerung
    return y;
}


int scalx(int x1, int x2, float xs1, float xs2, float xf)
/////////////////////////////////////////////////////////////////////////////
//   Umrechnung von Funktionswert auf Bildwert für die x-Koordinate
//   ( Berechnung über : (x-x1)/(x2-x1)=(xf-xs1)/(xs2-xs1) )
//   Import : int x1     ... Bildbereich Endpunkt links
//            int x2     ... Bildbereich Endpunkt rechts
//            float xs1  ... Skalenbereich Endwert links
//            float xs2  ... Skalenbereich Endwert rechts
//            float xf   ... Funktionswert x
//   Return : int        ... Bildpunkt x
//
/////////////////////////////////////////////////////////////////////////////
{  int x;
   x = x1 + (x2-x1)*(xf-xs1)/(xs2-xs1);
   return x;
}

int scaly(int y1, int y2, float ys1, float ys2, float yf)
/////////////////////////////////////////////////////////////////////////////
//   Umrechnung von Funktionswert auf Bildwert für die y-Koordinate
//   ( Berechnung über : (y2-y)/(y2-y1)=-(yf-ys1)/(ys2-ys1) )
//   Import : int y1     ... Bildbereich Endpunkt links
//            int y2     ... Bildbereich Endpunkt rechts
//            float ys1  ... Skalenbereich Endwert links
//            float ys2  ... Skalenbereich Endwert rechts
//            float yf   ... Funktionswert yf
//   Return : int        ... Bildpunkt y
//
/////////////////////////////////////////////////////////////////////////////
{  int y;
   y = y2 -  (y2-y1)*(yf-ys1)/(ys2-ys1);
   return y;
}

