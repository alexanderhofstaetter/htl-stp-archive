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
       int i,ny,nx,x1=0,x2=0,y1=0,y2=0;
       printf(" Gitterlinien\n");
       printf(" by Alexander Hofst\x84tter\n");
    /*   printf(" x1 =");
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

*/

       initwindow(640,320,"aaaaWinBGIm Demo");      // Grafikfenster  erzeugen mit Breite=640, Höhe=480 und Beschriftung
       setbkcolor(GREEN);                       // Hintergrundfarbe festlegen
       setcolor(BLUE);                          // Zeichenfarbe festlegen
       rectangle(x1,y1,x2,y2);                  // Rechtekc fetslegen
       for (i=1;i<nx;i++)
       {
            line(x1+i,y1,x2+i,y2);

       }

       //Linie von x1,y1 zu x2,y2 ziehen
       //line(0, getmaxy()/2, getmaxx(), getmaxy()/2);
       //line(getmaxx()/2, 0, getmaxx()/2, getmaxy());


       setcolor(COLOR(250,50,50));               // neue Zeichenfarbe über RGB definieren
       circle(320,240,150);                      // Kreis mit Mittelpunkt xr=320, yr=240 und Radius=150 zeichnen
       setcolor(LIGHTGRAY);
       outtextxy(500,10," by wi w.alfery ");     // Text an der Position x=500, y=10 ausgeben
       getch();                                  // auf Tastendruck warten
       closegraph();                             // Grafikfenster schließen

       return 0;
}


