/////////////////////////////////////////////////////////////////////////////
//   Programmname : main.cpp
//
//   Autor   :  Alex Hofstätter
//   Datum   :  11. Okt. 2013
//   Version :  1.0
//
//   Aufgabe :  Stammbau
//
/////////////////////////////////////////////////////////////////////////////

/**----------- Header-Dateien ---------------------------------------------*/

using namespace std;                // Namensraum für Standardbibliothk
#include <iostream>
#include <string.h>
#include <math.h>

/**----------- Klassen ----------------------------------------------------*/

typedef struct person PERS;

struct person
{
   char name[100];
   person *father;
   PERS *mother;
};

/**----------- Hauptprogramm ----------------------------------------------*/
int main()
{
   person mensch[100];

   for (int i=0; i<100; i++)
   {
      for (int j=0; j<N; j++)
      {
         int ebene_anzahl = pow(2,i+1) - pow(2,i);
         int ebene_start = pow(2,i) - 1;

         sprintf(mensch[i].name,"Person %d",i);
         mensch[i].father = &mensch[ebene_anzahl];
         mensch[i].mother = &mensch[i+1];
   }

   return 0;
}

void ElternZuweisen(PERS *p)
{
   p.father =

}

int Ebene(int index)
{

   for (int i=0; i<index; i++)
   {  if ((pow(2,i)-1; >= i) && (pow(2,i+1)-1 <=i ) )
         return
   }
}
