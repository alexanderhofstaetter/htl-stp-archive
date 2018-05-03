/////////////////////////////////////////////////////////////////////////////
//   Programmname : wuerfel_1BHEL_10_Hofstaetter.cpp
//
//   Autor   :  Alexander Hofstätter
//   Datum   :  20.01.2012
//   Version :  1
//
//   Aufgabe :  Wuerfeln bis die Summe der
//              gewuerfelten Zahlen 21 ergibt.
//
/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>


using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
  int r,sum;
  char key;

do
  {
      system("CLS");
      srand(time(NULL));                       // Zufallsreihe beginnen
      cout << " Wuerfeln bis die Summe der gewuerfelten Zahlen 21 ergibt" << endl << endl;

      for(sum=0;sum<21;)                // for-Schleife bis Summe größer als 21
      {
          getch();                     // Warten auf Tastendruck
          r = rand()%6 + 1;            // Zufallszahl von 1 bis 6
          sum = sum + r;
          cout << " Zahl = " << r << " Summe = " << sum << endl;  // Summe ausrechnen
      }



      cout << " ==================================" << endl;

  }while(key!=27);

  return 0;
}
