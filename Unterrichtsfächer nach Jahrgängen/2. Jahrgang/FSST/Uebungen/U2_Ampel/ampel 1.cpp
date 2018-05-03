/////////////////////////////////////////////////////////////////////////////
//   Programmname : ampel1.cpp
//   Mister xy
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

#define GRAY 8

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Funktionen
/////////////////////////////////////////////////////////////////////////////

void ampel(int x1, int x2, int breite, int farbe);
/////////////////////////////////////////////////////////////////////////////
//   Ampel
//   Import : int x1     ... Ampel Position links
//            int y1     ... Ampel Position rechts
//            int breite ... Ampel breite
//            int farbe  ... Farbe bestimmen ( 1 = rot, 2 = orange, 3 = gruen )
/////////////////////////////////////////////////////////////////////////////

void ampel(int x1, int y1, int breite, int farbe)
{
   setfillstyle(1,farbe);
   switch (x1)
   {  case 1: x1 = 175; break;
      case 2: x1 = 375; break;
   }
   switch (y1)
   {  case 1: y1 = 150; break;
      case 2: y1 = 250; break;
      case 3: y1 = 350; break;
   }
   fillellipse(x1,y1,breite,breite);
}

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   // Grafikfenster  erzeugen mit Breite=640, Höhe=480 und Beschriftung
   initwindow(640,480,"Ampel by A. Hofstaetter");
   int x1=0;
   setbkcolor(COLOR(200,255,200));
   cleardevice();

   setcolor(COLOR(10,10,10));
   rectangle(100,100,250,400);          // Ampel1 Umriss zeichnen
   rectangle(300,100,450,400);

   setfillstyle(1,COLOR(100,100,100));
   bar(100,100,250,400);                // Ampel1 Fläche mit Farbe füllen
   bar(300,100,450,400);

   setcolor(BLACK);
   outtextxy(150,411,"Ampel 1");       // Ampel1 beschriften
   outtextxy(350,411,"Ampel 2");

   for (int i=1;i<=2;i++)
   {  for (int j=1;j<=3;j++)
      {   ampel(i,j,40,8);
      }
   }
   do
   {
      ampel(x1,1,40,RED);
      ampel(2,3,40,GREEN);
      delay(2000);
      for (int i=0;i<=3;i++)
      {  ampel(2,3,40,GRAY);
         delay(500);
         ampel(2,3,40,GREEN);
         delay(500);
      }
      ampel(2,3,40,GRAY);
      ampel(1,2,40,YELLOW);
      ampel(2,2,40,YELLOW);
      delay(1000);
      for (int i=1;i<=2;i++)
      {  for (int j=1;j<=3;j++)  ampel(i,j,40,GRAY);
      }
      ampel(1,3,40,GREEN);
      ampel(2,1,40,RED);
      delay(2000);
      for (int i=0;i<=3;i++)
      {  ampel(1,3,40,GRAY);
         delay(500);
         ampel(1,3,40,GREEN);
         delay(500);
      }
      ampel(1,3,40,GRAY);
      ampel(1,2,40,YELLOW);
      ampel(2,2,40,YELLOW);
      delay(1000);
      for (int i=1;i<=2;i++)
      {  for (int j=1;j<=3;j++)  ampel(i,j,40,GRAY);
      }
   }while(1);
   closegraph();

   return 0;
}


