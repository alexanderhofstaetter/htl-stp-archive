/////////////////////////////////////////////////////////////////////////////
//   Programmname : main.cpp
//
//   Autor   :  Alex Hofstätter
//   Datum   :  04. Okt. 2013
//   Version :  1.0
//
//   Aufgabe :  Programmaufbau eines C/C++-Programms
//
/////////////////////////////////////////////////////////////////////////////

/**----------- Header-Dateien ---------------------------------------------*/

using namespace std;                // Namensraum für Standardbibliothk
#include <iostream>
#include <string.h>

/**----------- Klassen ----------------------------------------------------*/

class Auto
{
   public:
      char marke[40];
   protected:
      int baujahr;

   private:
      int km;

   public:
      Auto();
      Auto(char *m);
      Auto(char *m, int b);
      Auto(char *m, int b, int km);
      void  set();
      void print();
      int getBaujahr();
      void setMarke(char *m);
      void drive(int km);

};

/**----------- Hauptprogramm ----------------------------------------------*/
int main()
{
   Auto audi1;
   int km;

   Auto audi2("audi");
   audi2.print();
   cout << endl;

   Auto audi3("vw", 1905);
   audi3.print();
   cout << endl;

   Auto audi4("BMW", 2012, 53122);
   audi4.print();
   cout << endl;

   audi1.set();
   audi1.print();
   cout << endl;
   audi1.setMarke("4RingeAuto");
   cout << " Fahren - Kilometer: "; cin >> km;
   audi1.drive(km);
   cout << endl << " Baujahr: " << audi1.getBaujahr() << endl << endl;

   audi1.print();

   return 0;
}

/**----------- externe Methodendefintionen der Klasse "auto" --------------*/

Auto::Auto()
{
   strcpy(marke,"");
   baujahr = 0;
   km = 0;

}

Auto::Auto(char *m)
{
   strcpy(marke,m);
}

Auto::Auto(char *m, int b)
{
   strcpy(marke,m);
   baujahr = b;
}

Auto::Auto(char *m, int b, int km)
{
   strcpy(marke,m);
   baujahr = b;
   Auto::km = km;
}

void Auto::set()
{
   cout << " Automarke = "; cin >> marke;
   cout << " Baujahr = "; cin >> baujahr;
   cout << " Kilometerstand = "; cin >> km;
}

void Auto::print()
{
   cout << " Automarke: " << marke << endl;
   cout << " Baujahr: " << baujahr << endl;
   cout << " Kilometerstand: " << km << endl;
}

int Auto::getBaujahr()
{
   return baujahr;
}

void Auto::setMarke(char *m)
{
   strcpy(marke,m);
}

void Auto::drive(int km)
{
   Auto::km += km;
}
