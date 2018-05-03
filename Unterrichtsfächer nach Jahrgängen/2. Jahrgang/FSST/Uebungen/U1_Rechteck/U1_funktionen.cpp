/////////////////////////////////////////////////////////////////////////////
//   Programmname : maxmin.cpp
//   Autor: Alex Hofstätter
//
//   Aufgabe :  größten Wert (Maximum) und kleinsten Wert (Minimum)
//              eines Feldes bestimmen
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
#include "bse_console.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Funktionen
/////////////////////////////////////////////////////////////////////////////
 void rechteck(int x1, int x2, int y1, int y2,char symbol)
 {   printf("\n\n\n");

     for(int x=x1; x<=x2; x++)
     {

         //printf("%c",symbol);

         for(int y=y1; y<=y2; y++)
         {
             gotoxy(x,y);

             printf("%c",symbol);


         }
     }
 }

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{

   int xx1;
   int xx2;
   int yy1;
   int yy2;
   char zeichen;
   printf("x1="); cin >> xx1;
   printf("\n");
   printf("x2="); cin >> xx2;
   printf("\n");
   printf("y1="); cin >> yy1;
   printf("\n");
   printf("y2="); cin >> yy2;
   printf("\n");
   printf("Zeichen="); cin >> zeichen;
   printf("\n");

   rechteck(xx1,xx2,yy1,yy2,zeichen);

   return 0;
 }
