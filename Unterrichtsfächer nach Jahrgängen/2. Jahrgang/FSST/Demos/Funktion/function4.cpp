/////////////////////////////////////////////////////////////////////////////
//   Programmname : function4.cpp
//   DI W.Alfery
//   erstellt am  : 9.11.2010
//
//   Aufgabe :  Bruchrechnung über Funktionen
//              mit Referenzparameter
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Funktions-Prototypen
/////////////////////////////////////////////////////////////////////////////

float bruch(int z,int n );
void bruch_add(int z1,int n1,int z2,int n2,int &z,int &n);



/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   int z1,n1,z2,n2,z,n;
   float q;

   cout << " Bruchrechnung " << endl << endl;
   cout << " Bruch 1 : " << endl;
   cout << " z1=";
   cin  >> z1;
   cout << " n1=";
   cin  >> n1;
   cout << " Bruch 2 : " << endl;
   cout << " z2=";
   cin  >> z2;
   cout << " n2=";
   cin  >> n2;

   bruch_add(z1,n1,z2,n2,z,n);

   cout << " Addition = " << z << "/" << n << endl;
   cout << " Quotient = " << bruch(z,n) << endl;



   cout << endl << endl;
   system("PAUSE");
   return 0;

}

/////////////////////////////////////////////////////////////////////////////
//   Funktions-Definitionen
/////////////////////////////////////////////////////////////////////////////

float bruch(int z,int n )
///////////////////////////////////////////////////////////
//   Bruch
//   Import : int z    ...  Zaehler
//            int n    ...  Nenner
//   Return   float    ...  Quotient
///////////////////////////////////////////////////////////
{
    return (float)z/n;
}

void bruch_add(int z1,int n1,int z2,int n2,int &z,int &n)
///////////////////////////////////////////////////////////
//   Berechnung der Bruchaddition
//   Import : int z1   ...  Zaehler1
//            int n1   ...  Nenner1
//            int z2   ...  Zaehler2
//            int n2   ...  Nenner2
//   Export : int &z   ...  Zaehler der Addition
//            int &n   ...  Nenner der Addition
///////////////////////////////////////////////////////////
{
    z=z1*n2+z2*n1;
    n=n1*n2;

}


