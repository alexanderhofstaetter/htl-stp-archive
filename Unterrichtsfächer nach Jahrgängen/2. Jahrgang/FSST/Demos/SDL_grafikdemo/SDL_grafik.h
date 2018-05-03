///////////////////////////////////////////////////////////////////////////////
//
//    SDL_grafik
//    selbstdefinierte Funktionen
//    für Punkte, Linien, Rechtecke, Kreise
//    und Bitmap Dateien
//
//    di w.alfery
//
///////////////////////////////////////////////////////////////////////////////

#ifndef _SDL_grafik_alfe_H
#define _SDL_grafik_alfe_H

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

void setColor(int r, int g, int b)
//  RGB Farbwerte setzen -
//  die globalen Variablen SDL_red,SDL_green,SDL_blue
{   SDL_red=r; SDL_green=g; SDL_blue=b;
}

void drawLine(int x1, int y1, int x2, int y2)
//  Linie von x1,y1 nach x2,y2 ziehen
//  nach dem Bresenham-Algorithmus
{
   int x=x1,y=y1;
   int error, delta, schwelle, dx, dy, inc_x, inc_y;

   dx = x2 - x1;
   dy = y2 - y1;

   if (dx>0) inc_x= 1; else inc_x=-1;
   if (dy>0) inc_y= 1; else inc_y=-1;

   if (abs(dy) < abs(dx))
   {  error = - abs(dx);
      delta = 2*abs(dy);
      schwelle = 2*error;
      while (x != x2)
      {  drawPixel(x,y);
         x += inc_x; error += delta;
         if (error >0)
         {  y +=inc_y; error += schwelle;
         }
      }
    }
    else
    {  error = - abs(dy);
       delta = 2*abs(dx);
       schwelle = 2*error;
       while (y != y2)
       {  drawPixel(x,y);
          y += inc_y;  error += delta;
          if (error >0)
          {  x += inc_x; error += schwelle;
          }
       }
    }
    drawPixel(x,y);
}

void drawCircle( int xm, int ym, int r)
//  Kreis mit Mittelpunkt xm,ym und Radius r ziehen
//  nach dem Bresenham-Algorithmus
{  int x,y,d,dx,dxy;
   x=0; y=r; d=1-r;
   dx=3; dxy=-2*r+5;
   while (y>=x)
   {  drawPixel( xm+x,ym+y );
      drawPixel( xm+y,ym+x );
      drawPixel( xm+y,ym-x );
      drawPixel( xm+x,ym-y );
      drawPixel( xm-x,ym-y );
      drawPixel( xm-y,ym-x );
      drawPixel( xm-y,ym+x );
      drawPixel( xm-x,ym+y );
      if (d<0)
      {  d=d+dx;  dx=dx+2; dxy=dxy+2; x++;
      }
      else
      {  d=d+dxy; dx=dx+2; dxy=dxy+4; x++; y--;
      }
   }
}

void drawArc( int xm, int ym, int r, float phi1, float phi2)
//  Kreisbogen mit Mittelpunkt xm,ym und Radius r
//  von phi1 bis phi2
{  int x,y;                                      // x,y-Koordinatenwerte für Pixel
   float phi;                                    // Winkel
   float dphi=1.0/(r);                           // Winkelinkrement

   phi1=phi1*M_PI/180;                           // phi1,phi2 auf Radiant umrechen
   phi2=phi2*M_PI/180;
   for(phi=phi1;phi<=phi2;phi+=dphi)
   {   x = (int)r*cos(phi);
       y = (int)r*sin(phi);
       drawPixel(xm+x,ym-y);
   }
}

void drawRect( int x1, int y1, int x2, int y2)
//  Rechteck mit Eckpunkten x1,y1 und x2,y2 ziehen
{   drawLine(x1,y1,x2,y1);
    drawLine(x2,y1,x2,y2);
    drawLine(x1,y2,x2,y2);
    drawLine(x1,y1,x1,y2);
}

Uint32 fillRect( int x1, int y1, int x2, int y2, int r, int g, int b)
//  Rechteck mit Farbe füllen
{   Uint32 color;
    SDL_Rect a;
    a.x=x1;a.y=y1;a.w=x2-x1+1;a.h=y2-y1+1;
    color = SDL_MapRGB(SDL_screen->format, r, g, b);
    SDL_FillRect(SDL_screen, &a, color);
    SDL_UpdateRect(SDL_screen,a.x,a.y,a.w,a.h);
    return color;
}

void clearScreen()
//  Bildschirm löschen
{   Uint32 color;
    color = SDL_MapRGB(SDL_screen->format, 0, 0, 0);
    SDL_FillRect(SDL_screen, 0, color);
    SDL_UpdateRect(SDL_screen, 0, 0, 0, 0);
}

void setClipRect( int x1, int y1, int x2, int y2)
//  Rechteckgrenzen (Clipping Rectangle) zum Zeichnen festlegen
{   SDL_Rect a;
    a.x=x1;a.y=y1;a.w=x2-x1+1;a.h=y2-y1+1;
    SDL_SetClipRect(SDL_screen,&a);
}

int inRect( int x, int y, int x1, int y1, int x2, int y2)
//  prüfen ob die Koordinaten x,y
//  innerhalb des Rechteckbereiches x1,y1,x2,y2 liegen
{   if ( x>=x1 && x<=x2 )
    {  if ( y>=y1 && y<=y2 ) return 1;
    }
    return 0;
}

SDL_Surface* drawBMP(char *datei, int x, int y)
//  BMP-Datei laden und anzeigen
//  für andere Bildformate ist die Bibliothek SDL_image notwendig
{
    SDL_Surface *bild,*screen=SDL_screen;
    SDL_Rect ziel;

    bild = SDL_LoadBMP(datei);                   // BMP-Datei in ein Surface laden
    if ( bild == NULL ) {
        fprintf(stderr, "'%s' konnte nicht geladen werden: %s\n", datei, SDL_GetError());
        return NULL;
    }

    if (bild->format->palette && screen->format->palette)
    {  SDL_SetColors(screen,bild->format->palette->colors,0,bild->format->palette->ncolors);
    }

    ziel.x = x;
    ziel.y = y;
    ziel.w = bild->w;
    ziel.h = bild->h;
    SDL_BlitSurface(bild, NULL, screen, &ziel);  // auf den Bildschirm kopieren
                                                 // Surfaces sollten nicht gelockt sein
    SDL_UpdateRects(screen, 1, &ziel);           // Bildschirm-Bereich auffrischen

    return bild;
}

void moveBMP(SDL_Surface *bild, Uint32 bgcolor, int x0, int y0,int x, int y)
//  BMP-Datei von Position x0,y0 auf x,y bewegen
{
    SDL_Surface *screen=SDL_screen;
    SDL_Rect ursprung,ziel;

    ursprung.x=x0;
    ursprung.y=y0;
    ursprung.w=bild->w;
    ursprung.h=bild->h;

    ziel.x = x;
    ziel.y = y;
    ziel.w = bild->w;
    ziel.h = bild->h;

    SDL_FillRect(SDL_screen, &ursprung, bgcolor);// Hintergrundfarbe ergänzen
    SDL_BlitSurface(bild, NULL, screen, &ziel);  // Bild umblenden
    SDL_UpdateRects(screen, 1, &ursprung);       // Bildschirm-Bereich auffrischen
    SDL_UpdateRects(screen, 1, &ziel);           // Bildschirm-Bereich auffrischen
}

void freeBMP(SDL_Surface *bild)
//  Surface mit BMP-Datei freigeben
{   SDL_FreeSurface(bild);
}


#endif

