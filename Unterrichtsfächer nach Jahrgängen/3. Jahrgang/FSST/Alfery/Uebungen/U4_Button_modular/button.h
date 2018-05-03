#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include <string>
#include "graphics.h"

class Button
{  public:
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

#endif // BUTTON_H_INCLUDED
