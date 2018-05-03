/////////////////////////////////////////////////////////////////////////////
//   Programmname : zufallszahlen.cpp
//
//   Autor   :  Wolfgang Alfery
//   Datum   :  25.01.2011
//   Version :  1
//
//   Aufgabe :  Zufallszahlen erzeugen
//
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
  int zahl,sum,i;
  char antwort;
  const char ESC=27;

  srand(time(NULL));                       // neue Zufallsreihe beginnen

  do
  {
      system ("CLS");
      cout << " Zufallszahlen " << endl << endl ;

      sum=0;
      for ( i=1;i<=5;i++)                  // Schleife für 5 Durchläufe
      {
          zahl = rand()%10 + 1;            // Zufallszahl von 1 bis 10

          sum  = sum + zahl;               // Summe berechnen

          cout << " Zahl  = " << zahl  << endl;
          getch();                         // warten bis Tastendruck

     }

      cout << " ----------------------" << endl;
      cout << " Summe = " << sum << endl; // Summe ausgeben

      cout << endl << endl;
      cout << " Programmende mit [ESC] " << endl;
      antwort = getch();

  } while (antwort!=ESC);

  return 0;
}
