/////////////////////////////////////////////////////////////////////////////
//   Programmname : sort_time.cpp
//
//   Aufgabe :  Zeitmessung zu Sortieralgorithmen
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Feldern
/////////////////////////////////////////////////////////////////////////////

 const int NMAX=10000;            // Feldgröße
 int a[NMAX];                     // Feldvariable a,b,c

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

void bubble_sort( int a[], int n)
/////////////////////////////////////////////////////////////////////////////
//   sortiert das Array a[] ansteigend nach der Methode Bubble-Sort
//   Import : int a[]      ... Integer-Array
//            int n        ... Anzahl der Feldelemente
//   Return : void         ... kein Rückgabewert
/////////////////////////////////////////////////////////////////////////////
{  int i,j,hilf;
   for (i=0;i<n;i++)              // nehme i-tes Element,
   {  for (j=i+1;j<n;j++)         // vergleiche mit den restlichen Elementen
	    {  if (a[i]>a[j])         // und tausche die Elemente wenn notwendig
 		   { int hilf=a[i];
             a[i]=a[j];
             a[j]=hilf;
           }
        }
   }
}

long timer ( int start )
/////////////////////////////////////////////////////////////////////////////
//   Zeitmessung  in  Millisekunden  
//   Import : int start    ... Starten mit 1, Stoppen mit 0     
//   Return : int          ... Zeitwert in ms   
/////////////////////////////////////////////////////////////////////////////
{  static long t1=0;
   long t2=t1;

   if (start!=0) t1=clock()*1000/CLOCKS_PER_SEC;        // Startzeitpunkt    
   if (start==0) t2=clock()*1000/CLOCKS_PER_SEC;        // Stoppzeitpunkt     
   return (t2-t1);                                      // Differenzzeit in ms
}   

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  int i, j;
   long t;
   
   system("CLS");                 // Bildschrim löschen
   cout << " Sortieren von Feldern " << endl << endl;
   cout << " Anzahl der Feldelemente = " << NMAX << endl;

   cout << " Feld a[i] : " << endl;
   srand(time(NULL));
   for (i=0;i<NMAX;i++)
   {  a[i] = rand()%1000 + 1;     // Zufallszahlen von 1 bis 1000
      // cout << setw(4) << a[i];
   }

   //----------------------- Bubble Sort    --------------------------
   cout <<  endl << " Bubble Sort    : " << endl;
   timer(1);                      // Stoppuhr starten  
   bubble_sort(a,NMAX);
   t=timer(0);                    // Stoppuhr stoppen  
   cout << " Zeit = " << t << endl;   

   cout << endl << endl;
   system("PAUSE");
   return 0;
 }


