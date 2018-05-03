/////////////////////////////////////////////////////////////////////////////
//   Name: A. Hofstätter
//   Programmname : woerterbuch.cpp
//   Aufgabe :  Wörterbuch Deutsch-Englisch
//              C/C++ - Aufgabe 12e
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Globale Definition von Feldern
/////////////////////////////////////////////////////////////////////////////

const int N = 10;
string dict[N]=
{  "Eins-One",
   "Zwei-Two",
   "Drei-Three",
   "Vier-Four",
   "Fuenf-Five",
   "Sechs-Six",
   "Sieben-Seven",
   "Kindergarten-kindergarden",
   "Tasche-bag",
   "Passwort-password",
};

void sortieren(string text[])
{  for (int i=0; i<N; i++)
   {  for (int j=i+1; j<N; j++)
      {  if (text[i]>text[j])
         {  string hilf=text[i];
            text[i]=text[j];
            text[j]=hilf;
         }
      }
   }
}
void ausgabe(string text[])
{  for (int i=0; i<N; i++)
      cout << i << ": " << text[i] << endl;
}
/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   char menu;

   do
   {
      system("CLS");
      printf(" Woerterbuch \n");
      ausgabe(dict);
      printf("\n");

      string suche;
      printf(" Woerterbuch durchsuchen : \n");
      printf(" Suchtext = ");
      cin  >> suche;

      for (int i=0; i<N; i++)
      {
         int pos=dict[i].find(suche);
         if (pos==0) cout << dict[i] << endl;
      }
      printf("\n");

      printf(" nach Anfangsbuchstaben durchsuchen : \n");
      printf(" Anfangsbuchstabe = ");
      char zeichen;
      cin  >> zeichen;
      for (int i=0; i<N; i++)           // Wörterbuch durchsuchen
      {  string wort = dict[i];
         if (tolower(wort[0])==tolower(zeichen))
            cout << dict[i] << endl;
      }
      printf("\n");

      printf(" Woerterbuch alphabetisch sortieren: \n");
      sortieren(dict);
      ausgabe(dict);


      printf(" Programmende mit [ESC]");
      printf(" Nochmal mit [Enter]");
      menu=getch();
   }
   while(menu!=27);

   printf("\n\n");
   system("PAUSE");
   return 0;

}
