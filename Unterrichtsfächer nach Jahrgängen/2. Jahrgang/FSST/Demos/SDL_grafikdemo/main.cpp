/////////////////////////////////////////////////////////////////////////////
//   Programm : SDL_diagramm.cpp
//   Diagramm Darstellungen
//
//   di w. alfery
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <math.h>
#include "SDL\SDL.h"
#include "SDL\SDL_endian.h"

#include "SDL_grafik.h"

void axes(int x1,int y1,int x2,int y2)
//  Achsen
{  fillRect(x1,y1,x2,y2,220,220,250);
   setColor(100,100,100);
   drawRect(x1,y1,x2,y2);                        // Rahmen
   drawLine(x1,(y1+y2)/2,x2,(y1+y2)/2);          // Mittellinie
}

void sinus(int x1,int y1,int x2,int y2,float am,float f, float phi)
//  Diagramm Darstellung
{  int   x,y,x0,y0;                              // x,y - Werte
   int   ym=(y1+y2)/2;                           // y-Mittellinie
   int   n=x2-x1;                                // x-Intervall

   setColor(100,100,250);
   x0=x1;y0=ym;
   for(x=0;x<n;x+=1)
   {  y = am*sin(2*M_PI*x*f/n - phi*M_PI/180);   // Sinuskurve berechnen
      drawLine(x0,y0,x1+x,ym-y);                 // Linienzug zeichen
      x0=x1+x;y0=ym-y;
   }
}


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
   const int W=1000; const int H=800;             // Fenster Breite u. Höhe

   /*  -------------------------  SDL - Init ------------------------------ */
   sdlInit();                                    // SDL initialisieren
   setMode(W,H,0);                               // Video-Modus setzen
   SDL_WM_SetCaption("Diagramm di w.alfery ",0); // Fenster-Beschriftung
   fillRect(0,0,W,H,420,420,420);                // Hintergrundfarbe

   /*  ---------------------  Achsen zeichnen  ---------------------------- */
   int   x1=50,x2=450,y1=50,y2=250;
   axes(x1,y1,x2,y2);

   /*  ---------------------  Sinus Diagramm   ---------------------------- */
   float am=(y2-y1)/2;                           // Amplitude
   float f=4;                                    // Frequenz
   float phi=0;                                  // Phase
   sinus(x1,y1,x2,y2,am,f,phi);

/////////////////////////////////////////////////////////////////////////////
// Ereignissteuerung für Tastatureingaben
/////////////////////////////////////////////////////////////////////////////

   int change=1,signal=1;
   Uint8 *keys;

   int run=1;
   while(run)
   {
      SDL_Event event;
      while(SDL_PollEvent(&event))
      {  switch(event.type)
         {  case SDL_QUIT    : run=0;break;      // Abbruch bei Fenster schließen
         }
      }

      keys = SDL_GetKeyState(NULL);              // Taste abfragen

      if (keys[SDLK_RIGHT])                      // bei Pfeiltaste rechts
      {  if ( f < 25 )   {f+=0.1*f;change=1;}    // Frequenz erhöhen
      }
      if (keys[SDLK_LEFT])                       // bei Pfeiltaste links
      {  if ( f > 0.5 )  {f-=0.1*f;change=1;}    // Frequenz verringern
      }
      if (keys[SDLK_ESCAPE])
      {   run=0;break;                           // Abbruch bei ESC-Taste
      }
      drawLine(1,1,200,200);


      if (change)                                // bei nderungen
      {  axes(x1,y1,x2,y2);                      // Achsen neu zeichnen
         //sinus(x1,y1,x2,y2,am,f,phi);            // Sinus ausgeben
         SDL_Flip(SDL_screen);                   // Framebuffer umschalten
         change=0;
      }

   }

   return 0;
}

