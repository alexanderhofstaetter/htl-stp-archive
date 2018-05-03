/////////////////////////////////////////////////////////////////////////////
//   Programmname : button1.cpp
//   Autor: Alex Hofstätter
//
//   Button - grafisches Bedienelement
//            ausgeführt mit einer Klasse
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

#define Show 0
#define Focus 1
#define Clicked 2

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Klasse Button
/////////////////////////////////////////////////////////////////////////////
class Button
{
   public:
      int x1,y1;                          // Position links oben
      int w,h;                            // Breite, Höhe
      char label[80];                     // Beschriftung

   private:
      int status;                         // Status (Show,Focus,Clicked)

   public:
      Button(int x1, int y1, int w, int h, char label[]);
      void draw();
      int clicked();
};

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  printf(" Button by A.Hofstaetter  \n");
   printf(" mit Klassen \n");

   // Grafikfenster erzeugen
   initwindow(450,150,"Button");

   setbkcolor(WHITE);                  // Farben einstellen
   setcolor(COLOR(50,50,150));
   cleardevice();

   Button b1(100,50,100,30,"Enter");
   Button b2(100,100,100,30,"Quit");

   b1.draw();                          // Button anzeigen
   b2.draw();

   int quit=0;
   do                                  // Ereignis Schleife
   {
      if (b1.clicked())                // Button "Enter" abfragen
      {  outtextxy(300,70," Button Click ");
         delay(250);
      }
      else
         outtextxy(300,70," Button Show  ");

      if (b2.clicked())                // Button "Quit" abfragen
      {  quit=1;
         delay(250);
      }

   } while (!quit);

   closegraph();

   return 0;
}

/////////////////////////////////////////////////////////////////////////////
//   Externe Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////
Button::Button(int x1, int y1, int w, int h, char label[])
/////////////////////////////////////////////////////////////////////////////
//   Standard Konstruktor
//   Import : int x1       ... x-Achse Anfangswert
//   Import : int y1       ... y-Achse Anfangswert
//   Import : int w        ... Breite
//   Import : int h        ... Höhe
//   Import : char label[] ... Label für Button
/////////////////////////////////////////////////////////////////////////////
{  this->x1=x1;
   this->y1=y1;
   this->w=w;
   this->h=h;
   strcpy(this->label,label);

}

void Button::draw()
/////////////////////////////////////////////////////////////////////////////
//   Button zeichnen
/////////////////////////////////////////////////////////////////////////////
{
   // lokale Variable
   int x2,y2;                          // Eckpunkte
   int col,lcol,bcol;                  // Farben
   int mcol,mbcol;

   x2=x1+w;y2=y1+h;
   mcol = getcolor();                  // aktuelle Farbeinstellungen speichern
   mbcol = getbkcolor();

   switch (status)
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
   outtextxy(x1+w/2,y1+h/2+5,label);   // Button beschriften

   setcolor(mcol);                     // Farbeinstellungen wiederherstellen
   setbkcolor(mbcol);

}

int Button::clicked()
/////////////////////////////////////////////////////////////////////////////
//   Abfrage Button-Click
//   Return : int          ... 0 = not clicked / 1 = clicked
/////////////////////////////////////////////////////////////////////////////
{  int status=0;
   int x2=x1+w;
   int y2=y1+h;
   int x = mousex();                       // aktuelle Mausposition abfragen
   int y = mousey();

   if ( x>=x1 && x<=x2 && y>=y1 && y<=y2)   // Ist Mauspos. innerhalb des Buttonbereichs ?
   {  status=1;
      if(ismouseclick(WM_LBUTTONDOWN))      // und dann Maus Click abfragen
      {  status=2;
         clearmouseclick(WM_LBUTTONDOWN);   // lösche Maus Click
      }
   }

   if (this->status!=status)               // bei Statusänderung
   {  this->status=status;
      draw();                  // Button neu zeichnen
   }

   return (status==2);                 // true bei clicked
}
