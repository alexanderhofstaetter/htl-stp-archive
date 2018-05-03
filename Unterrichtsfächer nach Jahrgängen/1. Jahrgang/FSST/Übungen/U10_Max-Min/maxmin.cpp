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
 const int N=10;                  // Feldgröße
 int a[N];                        // Feldvariable a
 int b[N];
 int statistik[N];

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Variablen
/////////////////////////////////////////////////////////////////////////////
 int y,j,i;
 int max,min;
 int anzahl;
 int max_zahl;
 char key;
/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  srand(time(NULL));
   do
   {
       system("CLS");                 // Bildschrim löschen
       printf("  Maximum und Minimum eines Feldes \n");
       printf("  Wer ist der Groesste und wer der Kleinste ???\n");
       printf("  Anzahl und maximale Anzahl an gleichen Zahlen\n");
       printf("  Statistik fuer die H\x84ufigkeit\n");

       printf("\n\n Feld a[i] :");
       for (i=0;i<N;i++)
       {  a[i] = rand()%100 + 1;      // Zufallszahlen von 1 bis 100
          printf("%4d",a[i]);
       }

       printf("\n\n Feld b[i] :");
       for (i=0;i<N;i++)
       {  b[i] = rand()%100 + 1;
          printf("%4d",b[i]);
       }

       //---Maximum,Minimum Feld a bestimmen --------------------------------------------------------
       int max = a[0];                // erstes Maximum
       for (i=0;i<N;i++)              // Feld durchwandern
       {  if (a[i]>max) max=a[i];     // wer ist größer?
       }
       printf("\n\n Maximum Feld a = %d",max);

       int min = a[0];                // erstes Minimum
       for (i=0;i<N;i++)              // Feld durchwandern
       {  if (a[i]<min) min=a[i];     // wer ist kleiner?
       }
       printf("\n Minimum Feld a = %d \n",min);

       //---Maximum,Minimum Feld b bestimmen --------------------------------------------------------
       max = b[0];                // erstes Maximum
       for (i=0;i<N;i++)              // Feld durchwandern
       {  if (b[i]>max) max=b[i];     // wer ist größer?
       }
       printf("\n Maximum Feld b = %d",max);

       min = b[0];                // erstes Minimum;
       for (i=0;i<N;i++)              // Feld durchwandern
       {  if (b[i]<min) min=b[i];     // wer ist kleiner?
       }
       printf("\n Minimum Feld b = %d \n",min);

       //---Anzahl an gleichen Zahlen bestimmen -------------------------------------
       int zahl[anzahl];
       anzahl=0;
       for (i=0;i<N;i++)
       {   for(j=0;j<N;j++)
           {    if (a[i]==b[j])
                {   zahl[anzahl]=b[j];
                    anzahl++;
                    break;
                }
           }
       }

      if (anzahl>max_zahl) max_zahl=anzahl;
       printf("\n Anzahl an gleichen Zahlen = %d",anzahl);
       printf("\n bisher maximale Anzahl an gleichen Zahlen = %d",max_zahl);

       if(anzahl!=0)
       {
           printf("\n gleiche Zahlen =");
           for (i=0;i<anzahl;i++)
           {     printf("%4d",zahl[i]);
           }
       }
       else printf("\n gleiche Zahlen =  -- ");

       printf("\n\n   Statistik: \n");
       printf("   ********** \n\n");
       for(i=0;i<=N;i++)
       {
           if (anzahl==i) statistik[i]++;

       }


       for(i=0;i<N;i++)
       {
           printf("   %2d %5d\n",i,statistik[i]);
       }

       key=getch();
   }while(key!=27);

   cin >> i;
   printf("\n\n");
   system("PAUSE");
   return 0;
 }
