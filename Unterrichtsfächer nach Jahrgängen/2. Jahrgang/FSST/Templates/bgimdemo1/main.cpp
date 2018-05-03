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


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "graphics.h"              // Headerfile für WinBGIm Funktionen

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
       int i,ny,nx,x1,x2,y1,y2;
       printf(" Gitterlinien\n");
       printf(" by Alexander Hofst\x84tter\n");
       printf(" x1 =");
       cin >> x1;
       printf(" x2 =");
       cin >> x2;
       printf(" y1 =");
       cin >> y1;
       printf(" y2 =");
       cin >> x2;
       printf(" nx =");
       cin >> nx;
       printf(" ny =");
       cin >> ny;


       // Grafikfenster  erzeugen mit Breite=640, Höhe=480 und Beschriftung
       initwindow(640,320,"WinBGIm Demo");





       // Hintergrundfarbe festlegen
       setbkcolor(GREEN);
       // Fenster mit Hintergrundfarbe neu zeichnen_.
       cleardevice();

       // Zeichenfarbe festlegen
       //setcolor(BLUE);
       //rectangle(x1,y1,x2,y2);
       for (i=0,i<=nx,i=i+1)
       {
            line(x1,y1,(x2+i),(y2+i);

       }

       // Linie von x1,y1 zu x2,y2 ziehen
       /*line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
       line(getmaxx()/2, 0, getmaxx()/2, getmaxy());

       // neue Zeichenfarbe über RGB definieren
       setcolor(COLOR(250,50,50));
       // Kreis mit Mittelpunkt xr=320, yr=240 und Radius=150 zeichnen
       circle(320,240,150);

       setcolor(LIGHTGRAY);
       // Text an der Position x=500, y=10 ausgeben
       outtextxy(500,10," by di w.alfery ");
       */

       // auf Tastendruck warten
       getch();
       // Grafikfenster schließen
       closegraph();

       return 0;
}


