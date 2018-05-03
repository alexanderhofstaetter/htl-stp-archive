/////////////////////////////////////////////////////////////////////////////
//   Programmname : Frame.cpp
//   DI W.Alfery
//
//   Frame & Event Handling über virtuelle Methoden
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
//   Klassendefinition "Frame"
/////////////////////////////////////////////////////////////////////////////
class Frame
{
   private :
     int running;                                // Status

   public :
     int width,height;                           // Fenstereigenschaften
     int col;
     int bkcol;
     char label[80];

   public :
     Frame(int width, int height, char label[]); // Konstruktor
     virtual ~Frame();                           // Destruktor

     void run();                                 // Ereignisschleife starten
     void exit();                                //                  beenden

     // virtuelle Ereignisbearbeitungsmethoden
     virtual void onMouseLeft();                 // Mausereignis Left Button Down
     virtual void onMouseLeftUp();               // Mausereignis Left Button Up
     virtual void onMouseRight();                // Mausereignis Right Button Down
     virtual void onMouseRightUp();              // Mausereignis Right Button Up
     virtual void onMouseMove(int x, int y);     // Mausereignis Move

     virtual void onKey  (int key);              // Tastaturereignis

};

/////////////////////////////////////////////////////////////////////////////
//   Methodendefinitionen der Klasse "Frame"
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Konstruktor
Frame::Frame(int width, int height, char label[])
{
    running=0;
    this->width=width; this->height=height;strcpy(this->label,label);

    initwindow(width,height,label);              // Fenster erzeugen

    col=COLOR(50,50,250);                        // Farben einstellen
    bkcol=COLOR(255,255,255);
    setbkcolor(bkcol);
    setcolor(col);
    cleardevice();

}

/////////////////////////////////////////////////////////////////////////////
//   Destruktor
Frame::~Frame()
{   closegraph();                                // Fenster schließen
}

////////////////////////////////////////////////////////////////////////////
//   Ereignisschleife starten
//   ( Abbruch mit running==0 )
void Frame::run()
{   running=1;                                   // Status running

    do
    {
       if (ismouseclick(WM_LBUTTONDOWN) )        // bei Mausereignis Left Button Down
       {   onMouseLeft();                        // Ereignisbehandlung
           clearmouseclick(WM_LBUTTONDOWN);
       }

       if (ismouseclick(WM_LBUTTONUP) )          // bei Mausereignis Left Button Up
       {   onMouseLeftUp();                      // Ereignisbehandlung
           clearmouseclick(WM_LBUTTONUP);
       }

       if (ismouseclick(WM_RBUTTONDOWN) )        // bei Mausereignis Right Button Down
       {   onMouseRight();                       // Ereignisbehandlung
           clearmouseclick(WM_RBUTTONDOWN);
       }

       if (ismouseclick(WM_RBUTTONUP) )          // bei Mausereignis Right Button Up
       {   onMouseRightUp();                     // Ereignisbehandlung
           clearmouseclick(WM_RBUTTONUP);
       }

       if (ismouseclick(WM_MOUSEMOVE) )          // bei Mausereignis Move
       {   int x,y;
           x = mousex();                         // aktuelle Mausposition abfragen
           y = mousey();
           onMouseMove(x,y);                     // Ereignisbehandlung
           clearmouseclick(WM_MOUSEMOVE);
       }

       if ( kbhit() )                            // bei Tastaturereignis
       {  int key;
          key=getch();
          onKey(key);
       }

    } while (running);

}

////////////////////////////////////////////////////////////////////////////
//   Ereignisschleife abbrechen
void Frame::exit()
{   running=0;                                   // Status halt
}

////////////////////////////////////////////////////////////////////////////
//   virtuelle Bearbeitungsmethoden
void Frame::onMouseLeft()
{
}
void Frame::onMouseLeftUp()
{
}
void Frame::onMouseRight()
{
}
void Frame::onMouseRightUp()
{
}
void Frame::onMouseMove(int x, int y)
{
}
void Frame::onKey  (int key)
{
}


/////////////////////////////////////////////////////////////////////////////
//   eigenes Anwendungsfenster erstellen über die abgeleitete Klasse "myFrame"
//   mit Redefinition aller benötigten Ereignisbearbeitungsmethoden
/////////////////////////////////////////////////////////////////////////////
class myFrame : public Frame
{
    public:
    myFrame(int width, int height, char label[]) : Frame(width,height,label)
    {
    }

    virtual void onMouseLeft()                   // bei linker Maustaste
    {   outtextxy(20,40," linke Maustaste  ");
    }

    virtual void onMouseLeftUp()                 // bei linker Maustaste aus
    {   outtextxy(20,40,"                             ");
    }

    virtual void onMouseRight()                  // bei rechter Maustaste
    {   outtextxy(20,40," Fenster löschen ");
    }

    virtual void onMouseRightUp()                // bei rechter Maustaste aus
    {   cleardevice();
    }

    virtual void onMouseMove(int x, int y)       // bei Maus bewegen
    {   char text[80];
        sprintf(text," Mausposition  x: %4d y: %4d ",x,y);
        outtextxy(20,80,text);
    }

    virtual void onKey(int key)                  // bei Tastatureingaben
    {   char text[80];
        sprintf(text," Taste : %c ",key);
        outtextxy(20,120,text);
        outtextxy(100,120," Programmende mit [ESC] ");

        if (key==27) exit();                     // bei ESC-Taste Programm abbrechen

    }

};



/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   printf(" frame & event handling          by w.alfery  \n");
   printf(" using virtual methods                        \n");

   myFrame f(500,200," Frame & Events ");        // Fenster erstellen
   f.run();                                      // Ereignisschleife starten

   return 0;
}


