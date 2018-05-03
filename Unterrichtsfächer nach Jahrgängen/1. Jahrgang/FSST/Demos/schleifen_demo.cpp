/////////////////////////////////////////////////////////////////////////////
//   Programmname : schleifen.cpp
//   
//   Aufgabe :  for-, while-, do while - Schleifen  
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////    
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////    

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////    
//   Hauptprogramm 
/////////////////////////////////////////////////////////////////////////////    

int main()
{                                      
   int i; 
   
   cout << " Schleifen " << endl << endl;     
   cout << " mit einer Schleife die Zahlen von 1 bis 10 ausgeben " ;      
   
   cout << endl << " 1) mit der for- schleife   : ";
   for ( i=1;i<=10;i=i+1 ) 	      // Anfangswert (i=1); Bedingung (i<=10); Änderung (i=i+1)
   {  cout << setw(3) << i ;      // Laufvariable i ausgeben 
   }



   cout << endl << endl;     
   system("PAUSE");	
   return 0;

}

