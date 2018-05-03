/////////////////////////////////////////////////////////////////////////////
//   Programmname : button1.cpp
//   DI W.Alfery
//
//   Button - grafisches Bedienelement
//            ausgeführt mit einer Datenstruktur
//            und Funktionen
//
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "graphics.h"

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Struktur Button
/////////////////////////////////////////////////////////////////////////////
struct Button
{  int x1,y1;                          // Position links oben
   int w,h;                            // Breite, Höhe
   char label[80];                     // Beschriftung
   int status;                         // Status (0=Show,1=Focus,2=Clicked)
};


/////////////////////////////////////////////////////////////////////////////
//   Funktionen
/////////////////////////////////////////////////////////////////////////////
void button_draw(Button &b)
/////////////////////////////////////////////////////////////////////////////
//   Button zeichnen
//   Import : Button &b    ... Button Datenstruktur
/////////////////////////////////////////////////////////////////////////////
{
   // lokale Variable
   int x1,y1,x2,y2;                    // Eckpunkte
   int w,h;                            // Breite, Höhe
   int col,lcol,bcol;                  // Farben
   int mcol,mbcol;

   x1=b.x1;y1=b.y1;w=b.w;h=b.h;        // Daten übernehmen
   x2=x1+w;y2=y1+h;
   mcol = getcolor();                  // aktuelle Farbeinstellungen speichern
   mbcol = getbkcolor();

   switch (b.status)
   {  case 0 :                         // Button
        col=COLOR(5,120,170);          //   Umrandungsfarbe
        lcol=COLOR(50,50,150);         //   Zeichenfarbe
        bcol=COLOR(225,225,225);       //   Hintergrundfarbe
        break;
      case 1 :                         // Button Focus
        col=COLOR(5,120,170);
        lcol=COLOR(200,50,50);
        bcol=COLOR(225,225,225);
        break;
      case 2 :                         // Button Click
        col=COLOR(150,200,250);
        lcol=COLOR(200,50,50);
        bcol=COLOR(200,200,200);
        break;
   }

   setcolor(col);                      // Farben einstellen
   setfillstyle(1,bcol);
   setbkcolor(bcol);

   rectangle(x1,y1,x2,y2);             // Umrahmung zeichnen
   bar(x1+1,y1+1,x2,y2);               // Balken zeichnen
   setcolor(lcol);
   settextjustify(1,1);                // Text zentriert ausgeben
   outtextxy(x1+w/2,y1+h/2+5,b.label); // Button beschriften

   setcolor(mcol);                     // Farbeinstellungen wiederherstellen
   setbkcolor(mbcol);

}

int button_clicked(Button &b)
/////////////////////////////////////////////////////////////////////////////
//   Abfrage Button-Click
//   Import : Button &b    ... Button Datenstruktur
//   Return : int          ... 0 = not clicked / 1 = clicked
/////////////////////////////////////////////////////////////////////////////
{  int x,y,status=0;
   int x1,y1,x2,y2;

   x1=b.x1;y1=b.y1;x2=x1+b.w;y2=y1+b.h;
   x = mousex();                       // aktuelle Mausposition abfragen
   y = mousey();

   if ( x>=x1 && x<=x2 && y>=y1 && y<=y2)   // Ist Mauspos. innerhalb des Buttonbereichs ?
   {  status=1;
      if(ismouseclick(WM_LBUTTONDOWN))      // und dann Maus Click abfragen
      {  status=2;
         clearmouseclick(WM_LBUTTONDOWN);   // lösche Maus Click
      }

   }

   if (b.status!=status)               // bei Statusänderung
   {  b.status=status;
      button_draw(b);                  // Button neu zeichnen
   }

   return (status==2);                 // true bei clicked
}



/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf(" Button  by w.alfery  \n");
   printf(" mit Unterprogramm \n");

   // Grafikfenster erzeugen
   initwindow(450,150,"Button Demo");

   setbkcolor(WHITE);                  // Farben einstellen
   setcolor(COLOR(50,50,150));
   cleardevice();

   Button b1={100,50,100,30,"Enter",0};// Button festlegen
   Button b2={100,100,100,30,"Quit",0};

   button_draw(b1);                    // Button anzeigen
   button_draw(b2);

   int quit=0;
   do                                  // Ereignis Schleife
   {
      if (button_clicked(b1))          // Button "Enter" abfragen
      {  outtextxy(300,70," Button Click ");
         delay(250);
      }
      else
      {  outtextxy(300,70," Button Show  ");
      }

      if (button_clicked(b2))          // Button "Quit" abfragen
      {  quit=1;
         delay(250);
      }

   } while (!quit);

   closegraph();

   return 0;
}


