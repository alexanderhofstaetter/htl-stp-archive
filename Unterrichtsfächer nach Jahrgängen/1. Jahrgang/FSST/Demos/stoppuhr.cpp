//////////////////////////////////////////////////////////////////////////////
//   Programmname : stoppuhr.cpp
//   w.alfery
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

//  selbstdefinierte Funktion  timer(int)   
long timer ( int start )
/////////////////////////////////////////////////////////////////////////////
//   Zeitmessung  in  Millisekunden
//   Import : int start    ... Starten mit 1, Stoppen mit 0
//   Return : long         ... Zeitwert in ms
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
{
   cout << endl << " Stoppuhr" << endl;

   cout << endl << " Zeitmessung in ms ... " << endl;
   cout << " Start mit Entertaste "; cin.get();
   timer(1);                                            // Timer starten 
   cout << " Stop  mit Entertaste "; cin.get();
   cout << " Zeit = " << timer(0) << "ms" << endl;      // Timer stoppen   

   cout << endl << endl;
   system("PAUSE");
   return 0;
}


