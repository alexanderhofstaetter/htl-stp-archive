/////////////////////////////////////////////////////////////////////////////
//   Programmname : wettrennen.cpp
//
//   erstellt am  : 7.3.13
//   von          : Alex Hofstätter
//
//   Aufgabe :  Erfassung und Verarbeitung der Teilnehmer eines Autorennens
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>                         // C-String Bibliothek
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Struktur Definitionen
/////////////////////////////////////////////////////////////////////////////

typedef char string1[41];

typedef struct rennauto
{
   string1 modell;           // Modellname
   int kw;                  // Leistung in kW
};

typedef struct teilnehmer
{
   string1 name;
   rennauto fahrzeug;
   float zeit;
};

const int N=4;               // Anzahl der Teilnehmer
teilnehmer liste[N]=         // Teilnehmerliste - Fixstarter
// Name              ,  Modell      ,KW  ,Zeit
{  {"Alex"           ,{"VW Golf"    ,90} ,34.091},
   {"Fritzi Franz"   ,{"BMW 5er"    ,165},29.312},
   {"Julius Bergmann",{"Opel Meriva",45} ,43.029},
   {"Elisabeth Maier",{"Audi R8 V12",212},27.192}
};

/////////////////////////////////////////////////////////////////////////////
//   Funktions Prototypen
/////////////////////////////////////////////////////////////////////////////

void registrierung(teilnehmer &t);
// Erfassung (Eingabe) der Komponenten name,fahrzeug

void zeit(teilnehmer &t);
// Erfassung (Eingabe) der Rennzeit

void print(teilnehmer &t);
// Ausgabe der Teilnehmerdaten

int suchename(teilnehmer t[], string1 name, int i1,int i2);
// Suche nach einem bestimmten Teilnehmernamen
// in der Liste t[] beginnend ab Index i1 bis i2
// Rückgabewert = Index des gefundenen Teilnehmers
//              = -1    wenn nicht vorhanden

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   char auswahl;                                 // Auswahlzeichen für Programmabbruch
   string1 name;

   do
   {
      system("CLS");
      printf("\n Aktuelle Teilnehmerliste : \n");
      for (int i=0; i<N; i++)
      {  print(liste[i]);
         printf("\n");
      }

      printf("\n Um Teilnehmer (e)inzulesen druecken Sie die Taste e sonst ANY KEY !\n");
      auswahl = getch();

      if(auswahl == 'E' | auswahl == 'e')
      {  printf("Sie muessen %d Teilnehmer einlesen!",N);
         printf("\n Registrierung : \n\n");
         for (int i=0; i<N; i++)
         {  printf(" %d. Teilnehmer \n",i+1);
            registrierung(liste[i]);
            printf("\n");
         }

         printf("\n Zeiterfassung : \n");
         for (int i=0; i<N; i++)
         {  zeit(liste[i]);
            printf("\n");
         }
      }

      printf("\n Suche nach Teilnehmer : \n");
      printf(" Name = ");
      scanf("%s",name);
      int index = suchename(liste,name,0,N);

      if (index >= 0)
      {  printf("\n Folgende(r) Teilnehmer wurde gefunden: \n");
         print(liste[index]);
      }
      else printf("\n Keine Teilnehmer gefunden: ");

      printf("\n\n Programmende mit [ESC] \n");
      auswahl=getch();
   } while(auswahl!=27);

   printf("\n\n");
   return 0;
}

/////////////////////////////////////////////////////////////////////////////
//   Funktions Definitionen
/////////////////////////////////////////////////////////////////////////////

void print(teilnehmer &t)
{  printf(" Name: %-15s | Fahrzeug: %-12s mit %3d kW | Zeit: %3.3f",t.name,t.fahrzeug.modell, t.fahrzeug.kw, t.zeit);
}

void zeit(teilnehmer &t)
{  printf(" Zeit fuer %s = ",t.name);
   cin >> t.zeit;
}

void registrierung(teilnehmer &t)
{  printf("  Name = "); cin >> t.name;
   printf(" Fahrzeugdaten: \n");
   printf("  Modell = "); cin >> t.fahrzeug.modell;
   printf("  KW = "); cin >> t.fahrzeug.kw;
   t.zeit=0;
}

int suchename(teilnehmer t[], string1 name, int i1, int i2)
{  string1 original;
   for(int i=i1; i<i2; i++)
   {  original = _strlwr(t[i].name);
      if(strstr(original,_strlwr(name)))
         return i;
   }
   return -1;
}

void rangliste(teilnehmer t[],int timekeys[],int i1, int i2);
// Ermittlung der Reihung nach ansteigender Zeit
// durch Sortierung ¸ber das Schl¸sselfeld timekeys
// f¸r die Teilnehmerliste t[] beginnend ab Index i1 bis i2

void namensort(teilnehmer t[],int namekeys[],int i1, int i2);
// Sortierung der Teilnehmer
// nach den Namen

void kwsort(teilnehmer t[],int kwkeys[],int i1, int i2);
// Sortierung der Teilnehmer
// nach der Leistung (kw)

