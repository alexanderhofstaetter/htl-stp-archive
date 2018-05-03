/////////////////////////////////////////////////////////////////////////////
//   Programmname : scope.cpp
//   DI W.Alfery
//
//   erstellt am : 10.11.2010
//
//   Scope - Darstellung von Zeitsignalen
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
//   globale Variable
/////////////////////////////////////////////////////////////////////////////

const int NMAX=500;                     // Anzahl der Samples
float s[NMAX],g[NMAX];                  // Signalfelder


/////////////////////////////////////////////////////////////////////////////
//   Funktions Prototypen
/////////////////////////////////////////////////////////////////////////////

// Signalfunktionen
void dc(float s[],int n,float am);                       // Gleichsignal
void sinus(float s[],int n,float am,float fn,float phi); // Sinussignal
void super(float g[],float s[],int n );                  // Überlagerung

// Signalanalyse Funktionen
float mittel(float s[],int n);                           // Mittelwert
float vss(float s[],int n);                              // Spitze-Spitze-Wert
float rms(float s[],int n);                              // RMS-Wert

// Scope Funktionen
int scaly(int y1, int y2, float ys1, float ys2, float yf); // y-Bildpunkt berechnen
void axes(int x1, int x2, int y1, int y2, float ys1, float ys2); // Scope mit Achsengitter Darstellung
void draw(float s[], int n, int x1, int x2, int y1, int y2, float ys1, float ys2); // Signal Darstellung


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   // Grafikfenster  erzeugen mit Breite=600, Höhe=400 und Beschriftung
   initwindow(600,500,"Scope © di w.alfery");

   float ys1=-100,ys2=100;             // y-Skalenbereich Endwerte
   int   x1=50,x2=550,y1=50,y2=450;    // Bildbereich Endwerte

   int bkcol =COLOR(220,220,250);      // Fenster Hintergrundfarbe
   setbkcolor(bkcol);                  // Hintergrundfarbe setzen
   cleardevice();                      // und ausfüllen

   int acol  =COLOR(200,200,200);      // Achsen- und Gitterfarbe
   setcolor(acol);                     // Achsenfarbe setzen
   axes(x1,x2,y1,y2,ys1,ys2);          // Diagrammfläche und Achsen darstellen

   sinus(s,NMAX,50,2,0);               // 1. Sinussignal erzeugen
   setcolor(COLOR(50,50,250));         // Diagrammfarbe setzen
   draw(s,NMAX,x1,x2,y1,y2,ys1,ys2);   // Signalarray s[i] darstellen

   sinus(g,NMAX,25,5,45);              // 2. Sinussignal erzeugen
   setcolor(COLOR(50,250,50));         // Diagrammfarbe setzen
   draw(g,NMAX,x1,x2,y1,y2,ys1,ys2);   // Signalarray g[i] darstellen

   super(g,s,NMAX);                    // Überlagerung
   setcolor(COLOR(250,50,50));         // Diagrammfarbe setzen
   draw(g,NMAX,x1,x2,y1,y2,ys1,ys2);   // Signalüberlagerung darstellen

   char text[50];                      // C-String zur Anzeige
   float m=mittel(g,NMAX);             // Mittelwert berechnen
   sprintf(text,"Mean:%5.2f",m);       // Umwandlung auf C-String
   setcolor(COLOR(150,150,150));
   outtextxy(x1,y2-20,text);           // Textausgabe

   float vs=vss(g,NMAX);               // Spitze-Spitze-Wert berechnen
   sprintf(text,"Vss:%5.2f",vs);       // Umwandlung auf C-String
   setcolor(COLOR(150,150,150));
   outtextxy(x1+100,y2-20,text);       // Textausgabe

   float eff=rms(g,NMAX);              // RMS-Wert berechnen
   sprintf(text,"RMS:%5.2f",eff);      // Umwandlung auf C-String
   setcolor(COLOR(150,150,150));
   outtextxy(x1+200,y2-20,text);       // Textausgabe



   // bei Tastendruck Grafikfenster schließen
   getch();
   closegraph();

   return 0;
}


/////////////////////////////////////////////////////////////////////////////
//   Funktions Definitionen
/////////////////////////////////////////////////////////////////////////////

void dc(float s[], int n, float am)
/////////////////////////////////////////////////////////////////////////////
//   Gleichsignal
//   Import : int n      ... Anzahl der Samples
//            float am   ... Amplitude
//   Export : float s[]  ... Signalfeld
//
/////////////////////////////////////////////////////////////////////////////
{  int i;
   for (i=0;i<n;i++)
   {  s[i] = am;
   }
}

void sinus(float s[], int n, float am, float fn, float phi)
/////////////////////////////////////////////////////////////////////////////
//   Sinussignal
//   Import : int n      ... Anzahl der Samples
//            float am   ... Amplitude
//            float fn   ... Frequenzvielfaches
//            float phi  ... Phasenverschiebung
//   Export : float s[]  ... Signalfeld
//
/////////////////////////////////////////////////////////////////////////////
{  int i;
   for (i=0;i<n;i++)
   {  s[i] = am*sin(2*M_PI*i*fn/n + M_PI*phi/180);
   }
}

void super(float g[], float s[], int n )
/////////////////////////////////////////////////////////////////////////////
//   Überlagerung (Addition) zweier Signalfelder
//   Import : int n      ... Anzahl der Samples
//            float s[]  ... Signalfeld
//   Import/Export :
//            float g[]  ... Gesamtsignal
/////////////////////////////////////////////////////////////////////////////
{  int i;
   for (i=0;i<n;i++)
   {  g[i] += s[i];
   }
}

float mittel(float s[],int n)
/////////////////////////////////////////////////////////////////////////////
//   Signal Mittelwert berechnen
//   Import : int n      ... Anzahl der Samples
//            float s[]  ... Signalfeld
//   Return : float      ... Mittelwert
//
/////////////////////////////////////////////////////////////////////////////
{  int i;
   float sum=0;
   for (i=0;i<n;i++)
   {  sum += s[i];
   }
   return sum/n;
}

float vss(float s[],int n)
/////////////////////////////////////////////////////////////////////////////
//   Spitze-Spitze Wert berechnen
//   Import : int n      ... Anzahl der Samples
//            float s[]  ... Signalfeld
//   Return : float      ... Spitze-Spitze-Wert
//
/////////////////////////////////////////////////////////////////////////////
{  int i;
   float max=s[0],min=s[0];

   for (i=0;i<n;i++)
   {  if (max<s[i]) max=s[i];
      if (min>s[i]) min=s[i];
   }
   return max-min;
}

float rms(float s[],int n)
/////////////////////////////////////////////////////////////////////////////
//   RMS Wert (Effektivwert) berechnen
//   Import : int n      ... Anzahl der Samples
//            float s[]  ... Signalfeld
//   Return : float      ... RMS-Wert
//
/////////////////////////////////////////////////////////////////////////////
{  int i;
   float sumq=0;

   for (i=0;i<n;i++)
   {  sumq += s[i]*s[i];
   }
   return sqrt(sumq/n);
}


int scaly(int y1, int y2, float ys1, float ys2, float yf)
/////////////////////////////////////////////////////////////////////////////
//   Umrechnung von Funktionswert auf Bildwert für die y-Koordinate
//   ( Berechnung über : (y-y1)/(y2-y1)=-(yf-ys1)/(ys2-ys1) )
//   Import : int y1     ... Bildbereich Endpunkt links
//            int y1     ... Bildbereich Endpunkt rechts
//            float ys1  ... Skalenbereich Endwert links
//            float ys2  ... Skalenbereich Endwert rechts
//            float y    ... Funktionswert y
//   Return : int        ... Bildpunkt y
//
/////////////////////////////////////////////////////////////////////////////
{  int y;
   y = y2 -  (y2-y1)*(yf-ys1)/(ys2-ys1);
   return y;
}


void axes(int x1, int x2, int y1, int y2, float ys1, float ys2)
/////////////////////////////////////////////////////////////////////////////
//   Diagrammfläche und Achsen darstellen
/////////////////////////////////////////////////////////////////////////////
{  int x,y,y0,dx,dy;
   int dbcol =COLOR(250,250,250);      // Diagramm Hintergrundfarbe

   setfillstyle(1,dbcol);              // Diagramm Hintergrund
   bar(x1,y1,x2,y2);
   rectangle(x1,y1,x2,y2);             // Diagrammrahmen zeichnen
   y0=y2-(int)((y2-y1)*(0.0-ys1)/(ys2-ys1));  // yf=0

   line(x1,y0,x2,y0);                  // Null-Linie zeichnen

   dx=(x2-x1)/5;                       // Achsengitter Unterteilung
   dy=(y2-y1)/4;
   for (x=x1;x<x2;x+=dx)               // Achsengitter (Grid) zeichnen
   {  line(x,y1,x,y2);
   }
   for (y=y1;y<y2;y+=dy)
   {  line (x1,y,x2,y);
   }

}

void draw(float s[], int n, int x1, int x2, int y1, int y2, float ys1, float ys2)
/////////////////////////////////////////////////////////////////////////////
//   grafische Diagrammdarstellung
/////////////////////////////////////////////////////////////////////////////
{  int i,x,y,y0;

   y0=y2-(int)((y2-y1)*(0.0-ys1)/(ys2-ys1));
   moveto(x1,y0);                      // zum Anfangspunkt bewegen
   for (i=0;i<n;i++)                   // für alle Feldelemente
   {
       x = x1+i;                       // Bildpunkt x berechnen
       y = scaly(y1,y2,ys1,ys2,s[i]);  // Bildpunkt y berechnen
       lineto(x,y);                    // Linienzug ausgeben
   }

}


