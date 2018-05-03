/////////////////////////////////////////////////////////////////////////////
//   Programm : SDL_demo_CB.cpp
//
//   SDL Grafik Demo
//   entwickelt mit Code::Blocks
//
//   di w. alfery
/////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <math.h>
#include "SDL\SDL.h"
#include "SDL\SDL_endian.h"

//  globale Variable
SDL_Surface *SDL_screen;
int SDL_red,SDL_green,SDL_blue;
int SDL_x=0,SDL_y=0;

void sdlInit()
//  SDL initialisieren
{
   if ( SDL_Init(SDL_INIT_VIDEO) < 0 )
   {  fprintf(stderr, "SDL konnte nicht initialisiert werden:  %s\n", SDL_GetError());
      exit(1);
   }
   atexit(SDL_Quit);
}

void  setMode(int width, int height, int fullscreen)
//  Video Modus setzen
{
   if(fullscreen != 0)
   {  SDL_screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_FULLSCREEN |SDL_DOUBLEBUF);
   }
   else
   {  SDL_screen = SDL_SetVideoMode(width,height,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
   }
   if (!SDL_screen)
   {  fprintf(stderr, "Konnte Bildschirmmodus nicht setzen: %s\n", SDL_GetError());
      exit(1);
   }
}

void drawPixel(SDL_Surface *screen, int x, int y,Uint8 R, Uint8 G, Uint8 B)
//  Punkt an Position x,y zeichnen mit RGB-Farbwert
//  ausgeführt wie in der SDL Dokumentation angegeben
{
    Uint32 color = SDL_MapRGB(screen->format, R, G, B);

    if ( SDL_MUSTLOCK(screen) ) {
        if ( SDL_LockSurface(screen) < 0 ) {
            return;
        }
    }
    switch (screen->format->BytesPerPixel) {
        case 1: { /* vermutlich 8 Bit */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x;
            *bufp = color;
        }
        break;

        case 2: { /* vermutlich 15 Bit oder 16 Bit */
            Uint16 *bufp;

            bufp = (Uint16 *)screen->pixels + y*screen->pitch/2 + x;
            *bufp = color;
        }
        break;

        case 3: { /* langsamer 24-Bit-Modus, selten verwendet */
            Uint8 *bufp;

            bufp = (Uint8 *)screen->pixels + y*screen->pitch + x * 3;
            if(SDL_BYTEORDER == SDL_LIL_ENDIAN) {
                bufp[0] = color;
                bufp[1] = color >> 8;
                bufp[2] = color >> 16;
            } else {
                bufp[2] = color;
                bufp[1] = color >> 8;
                bufp[0] = color >> 16;
            }
        }
        break;

        case 4: { /* vermutlich 32 Bit */
            Uint32 *bufp;

            bufp = (Uint32 *)screen->pixels + y*screen->pitch/4 + x;
            *bufp = color;
        }
        break;
    }
    if ( SDL_MUSTLOCK(screen) ) {
        SDL_UnlockSurface(screen);
    }
    SDL_UpdateRect(screen, x, y, 1, 1);
}


void drawPixel(int x, int y)
//  überladene Funktion zur einfacheren Verwendung
//  zeichnet mit der gesetzten Farbe
//  der globalen Variablen SDL_red,SDL_green,SDL_blue
{  drawPixel(SDL_screen,x,y,SDL_red,SDL_green,SDL_blue);
}

void drawPixel(int x, int y, int r, int g, int b)
//  überladene Funktion zur einfacheren Verwendung
{  drawPixel(SDL_screen,x,y,r,g,b);
}

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
   const int W=800; const int H=600;             // Breite u. Höhe
   int r=100,g=100,b=100;                        // rgb-Farbwerte
   int x1,x2,y1,y2;                              // Endpunkte
   float k;                                      // Steigung
   int x,y;                                      // Koordinaten
   float xf,yf;

   sdlInit();                                    // SDL initialisieren
   setMode(W,H,0);                               // Video-Modus setzen
   SDL_WM_SetCaption(" Grafik  di w.alfery ",0); // Fenster-Beschriftung


   SDL_Delay(200);                               // Zeitverzögerung 200 ms
   for (xf=0,yf=600; xf<W; xf+=1,yf-=(float)H/W) // Linie von 0/600 nach 800/0 ziehen
   {  drawPixel((int)xf,(int)yf,r,g,b);          // über drawPixel
      b=(b+1)%255;                               // B-Farbintensität ändern
   }
   for (xf=0,yf=0; xf<W; xf+=1,yf+=(float)H/W)   // Linie von 0/0 nach 800/600 ziehen
   {  drawPixel((int)xf,(int)yf,r,g,b);          // über drawPixel
      b=(b+1)%255;                               // B-Farbintensität ändern
   }

   r=0;g=0;b=0;                                  // Farbwerte
   x1=150,x2=x1+512,y1=50,y2=y1+500;           // Eckpunkte
   for (y=y1;y<y2;y++)                           // alle y-Punkte
   {  for (x=x1;x<x2;x++)                        // alle x-Punkte
      {
         drawPixel(x,y,r,g,b);
         if (x%2) r=(r+1)%256;                   // Rot-Farbintensität variieren
      }
      if (g<255) g=g+1;                          // Grün-Farbintensität variieren
      else b=b+1;                                // Blau-Farbintensität variieren
   }


/////////////////////////////////////////////////////////////////////////////
// Ereignissteuerung für den Programmabbruch
/////////////////////////////////////////////////////////////////////////////
   int run = 1;
   while(run)
   {  SDL_Event event;
      while(SDL_PollEvent(&event))
      {  switch(event.type)
         {  case SDL_KEYDOWN : run=0;break;   // bei Tastendruck
            case SDL_QUIT    : run=0;break;   // bei Fenster schließen
         }
        }
    }

  return 0;
}

