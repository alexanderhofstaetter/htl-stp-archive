#include <iostream>
#include <stdio.h>
#include <math.h>
#include "header\graphics.h"
#include "header\signale.h"

int scaly(int y1, int y2, float ys1, float ys2, float yf)
/////////////////////////////////////////////////////////////////////////////
//   Umrechnung von Funktionswert auf Bildwert für die y-Koordinate
//   Berechnung über : (y-y1)/(y2-y1)=-(yf-ys1)/(ys2-ys1)
//   Import : int y1     ... Bildbereich Endpunkt links
//            int y1     ... Bildbereich Endpunkt rechts
//            float ys1  ... Skalenbereich Endwert links
//            float ys2  ... Skalenbereich Endwert rechts
//            float yf   ... Funktionswert y
//   Return : int        ... Bildpunkt y
//
/////////////////////////////////////////////////////////////////////////////
{  return y2 - (y2-y1)*(yf-ys1)/(ys2-ys1);
}

int scalx(int x1, int x2, float xs1, float xs2, float xf)
/////////////////////////////////////////////////////////////////////////////
//   Umrechnung von Funktionswert auf Bildwert für die x-Koordinate
//   Berechnung über : (x-x1)/(x2-x1)=-(xf-xs1)/(xs2-xs1)
//   Import : int x1     ... Bildbereich Endpunkt links
//            int x1     ... Bildbereich Endpunkt rechts
//            float xs1  ... Skalenbereich Endwert links
//            float xs2  ... Skalenbereich Endwert rechts
//            float xf   ... Funktionswert x
//   Return : int        ... Bildpunkt x
//
/////////////////////////////////////////////////////////////////////////////
{  return x2 - (x2-x1)*(xf-xs1)/(xs2-xs1);
}

void axes(int x1, int x2, int y1, int y2, float ys1, float ys2)
/////////////////////////////////////////////////////////////////////////////
//   Diagrammfläche und Achsen darstellen
/////////////////////////////////////////////////////////////////////////////
{  int y0,dx,dy;
   int dbcol = COLOR(250,250,250);     // Diagramm Hintergrundfarbe

   setfillstyle(1,dbcol);              // Diagramm Hintergrund
   bar(x1,y1,x2,y2);
   rectangle(x1,y1,x2,y2);             // Diagrammrahmen zeichnen
   y0 = scaly(y1,y2,ys1,ys2,0);

   dx = (x2-x1)/5;                       // Achsengitter Unterteilung
   dy = (y2-y1)/4;
   for (int x=x1; x<x2; x+=dx)         // Achsengitter (Grid) zeichnen
      line(x,y1,x,y2);
   for (int y=y1; y<y2; y+=dy)
      line (x1,y,x2,y);

   setcolor(COLOR(0,0,0));
   line(x1,y0,x2,y0);                  // Null-Linie zeichnen
}

void draw(float s[], int n, int x1, int x2, int y1, int y2, float ys1, float ys2)
/////////////////////////////////////////////////////////////////////////////
//   grafische Diagrammdarstellung
/////////////////////////////////////////////////////////////////////////////
{  int i,x,y,y0;

   y0=y2-(int)((y2-y1)*(0.0-ys1)/(ys2-ys1));
   moveto(x1,y0);                      // zum Anfangspunkt bewegen
   for (i=0; i<n; i++)                 // für alle Feldelemente
   {  x = x1+i;                        // Bildpunkt x berechnen
      y = scaly(y1,y2,ys1,ys2,s[i]);   // Bildpunkt y berechnen
      lineto(x,y);                     // Linienzug ausgeben
   }
}
