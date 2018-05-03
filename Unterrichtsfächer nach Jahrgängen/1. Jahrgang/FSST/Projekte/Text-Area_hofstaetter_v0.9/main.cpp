/////////////////////////////////////////////////////////////////////////////
//   Programmname : textbuffer.cpp
//   Autor: Alex Hofstätter
//
//   Aufgabe :  Text-Area
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
 #include <stdio.h>
 #include <stdlib.h>
 #include <iostream>
 #include <iomanip>
 #include <time.h>
 #include <conio.h>
 #include "conio2.h"
 #include <string>
 #include <windows.h>

 using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Feldern
/////////////////////////////////////////////////////////////////////////////
 const int RMAX=24;
 const int CMAX=79;
 char textarea[RMAX][CMAX];
/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Variablen
/////////////////////////////////////////////////////////////////////////////
 int j,i,control,anzahl;
 char key;
/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////RRG
int main()
{

   //system("mode con cols=80 lines=25");    // Konsolen-Fenstergröße einstellen

   textcolor(BLUE);                         // Textfarbe einstellen
   textbackground(DARKGRAY);               // Hintergrund einstellen
   do
   {
       control=anzahl=0;
       clrscr();                                // Bildschirm löschen
       gotoxy(1,25);
       printf(" Eingabemodus[ESC] -- [c] clear  -- [r] reload  -- [q] quit  --");
       gotoxy(1,1);

       for (i=0;i<RMAX;i++)
       {   for(j=0;j<CMAX;j++)
           {   key=getch();
               if (key==13) printf("\n");
               if (key==27) control=1;
               if (control==1)
               {   gotoxy(1,25);
                   textcolor(RED);
                   printf(" Eingabemodus[ESC] -- [c] clear  -- [r] reload  -- [q] quit  --");
                   textcolor(BLUE);
                   key=getch();
                   if (key==27) control=0;
                   if (key=='c')
                   {   clrscr();
                       control=0;
                   }
                   if (key=='r')
                   {   clrscr();
                       for (i=0;i<RMAX;i++)
                       {   for(j=0;j<CMAX;j++)
                           {
                               putch(textarea[i][j]);
                           }
                           printf("\n");
                       }
                       control=0;
                   }
                   if(control==0)
                   {   textcolor(BLUE);
                       gotoxy(1,25);
                       printf(" Eingabemodus[ESC] -- [c] clear  -- [r] reload  -- [q] quit  --");
                       gotoxy(1,1);
                   }
               }
               else
               {   textarea[i][j]=key;
                   putch(textarea[i][j]);
               }
           }
           printf("\n");
       }
       key=getch();

   } while(key!='q');
}

/////////////////////////////////////////////////////////////////////////////
