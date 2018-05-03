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
#include <conio.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Feldern
/////////////////////////////////////////////////////////////////////////////
 const int N=6;                  // Feldgröße
 int ziehung[N];                        // Feldvariable a
 int tipps[N];
 int hilf;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Variablen
/////////////////////////////////////////////////////////////////////////////
 int y,j,i;
 int max,min;
 int anzahl;
 int wh;
 int zahl;
 char key;
/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  srand(time(NULL));
   do
   {
       system("CLS");                 // Bildschrim löschen
       printf("  Lotto 6 aus 45 \n");
       printf("\n Tipps   :");

       for (i=0;i<N;i++)
       {   tipps[i] = rand()%45 + 1;
           wh=0;
/*         do
           {   zahl = rand()%45 + 1;      // Zufallszahlen von 1 bis 45
               for(j=0;j<i;j++)
               {   if (tipps[i]==tipps[j])
                   {   wh=1;break;
                   }
               }
               tipps[i]=zahl;
           }while(wh!=0);
*/
       }

       for (i=0;i<N;i++)
       {   for(j=i+1;j<N;j++)
           {   if(tipps[j]<tipps[i])
               {   y=tipps[i];
                   tipps[i]=tipps[j];
                   tipps[j]=y;
               }
           }
           printf("%4d",tipps[i]);
       }

       printf("\n\n Ziehung :");
       for (i=0;i<N;i++)
       {   wh=0;
           ziehung[i] = rand()%45 + 1;
/*           do
           {   zahl = rand()%45 + 1;      // Zufallszahlen von 1 bis 45
               for(j=0;j<i;j++)
               {   if (ziehung[i]==ziehung[j])
                   {   wh=1;break;
                   }
               }
               tipps[i]=zahl;
           }while(wh!=0);
*/     }

       for (i=0;i<N;i++)
       {   for(j=i+1;j<N;j++)
           {   if(ziehung[j]<ziehung[i])
               {   y=ziehung[i];
                   ziehung[i]=ziehung[j];
                   ziehung[j]=y;
               }
           }
           printf("%4d",ziehung[i]);
       }

       //---Anzahl an gleichen Zahlen bestimmen -------------------------------------
       anzahl=0;
       for (i=0;i<N;i++)
       {   for(j=0;j<N;j++)
           {    if (tipps[i]==ziehung[j])
                {   anzahl++;
                    break;
                }
           }
       }

       printf("\n\n Anzahl der gleichen Zahlen : %d ",anzahl);
       printf("\n\n Gewinnsumme : ");
       switch(anzahl)
       {    case 0 : printf(" Leider kein Gewinn \n"); break;
            case 1 : printf(" 2,50            \n"); break;
            case 2 : printf(" 10,00 \n"); break;
            case 3 : printf(" 100,00 \n"); break;
            case 4 : printf(" 100,00 \n"); break;
            case 5 : printf(" 126,76 \n"); break;
            case 6 : printf(" 5.173.949,00 \n"); break;
       }
       key=getch();
   }while(key!=27);

   printf("\n\n");
   system("PAUSE");
   return 0;
 }
