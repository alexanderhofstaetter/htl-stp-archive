/////////////////////////////////////////////////////////////////////////////
//   Programmname : rekursion.cpp
//
//   Aufgabe :  Beispiel zu rekursivem Funktionsaufruf -  
//              Die Berechnung der Fakultät n! 
//                n! = 1.2.3. ... (n-1).n   
//              ist auch über die Rekursion 
//                n! = n.(n-1)!  
//              berechenbar.
// 
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

long fakult(long n)
{  if ( n > 1 ) return ( n*fakult(n-1) );	 // rekursiver Aufruf von fakult
   else         return 1;                    // Abbruch bei n<=1
}

long fakultdemo(long n)                      // Demo Version zu fakult() 
{  long f;                                   
   cout << " n= " << n  << endl;			 // Ausgabe von n 
   if ( n > 1 )
   {  f= n*fakultdemo(n-1);
  	  cout << " f= " << f << endl;           // Ausgabe der aktuellen Faktultät
	  return f;
   }
   else
   {  cout << " Abbruch bei n<=1 mit f=1" << endl;  // Abbruch bei n<=1
	  return 1;                             
   }
}

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  int n,f;
   
   system("CLS");                
   cout << " rekursive Berechnung von n! " << endl << endl; 
   do
   {  cout << " Eingabe n = " ;
      cin >> n;
   }  while (!((n>0)&&(n<=12)));              // sonst Zahlenüberlauf ! 
   
   f=fakult(n);
   cout << " n! = " << f << endl << endl ;

   cout << " rekursive Aufruf-Reihenfolge : " << endl;
   f=fakultdemo(n);

   cout << endl << endl; 
   system("PAUSE"); 
   return 0;
 }
 

