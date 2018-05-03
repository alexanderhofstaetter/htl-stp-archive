/////////////////////////////////////////////////////////////////////////////
//   Programmname : wettrennen.cpp
//
//   erstellt am  :
//   von          :
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


/////////////////////////////////////////////////////////////////////////////
//   globale Struktur Definitionen
/////////////////////////////////////////////////////////////////////////////

typedef char string[41];

typedef struct rennauto
{
    string modell;           // Modellname
    int  kw;                 // Leistung in kW
};

typedef struct teilnehmer
{




};

const int N=3;               // Anzahl der Teilnehmer

teilnehmer liste[N]=         // Teilnehmerliste - Fixstarter
{



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

int suchename(teilnehmer t[], string name, int i1,int i2);
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
   const char ESC=27;                            // Ordinalwert für Escape-Taste
   int i,nr;
   string name;


   do
   {   printf("\n Teilnehmerliste : \n");
       for (i=0;i<N;i++)
       {  print(liste[i]);
       }

       printf("\n Zeiterfassung   : \n");
       // ...



       printf("\n Suche nach Teilnehmer : \n");
       printf(" Name = ");
       scanf("%s",name);
       // ...




       printf("\n\n Programmende mit [ESC] \n");
       auswahl=getch();
   } while(auswahl!=ESC);

   printf("\n\n");
   return 0;
 }

/////////////////////////////////////////////////////////////////////////////
//   Funktions Definitionen
/////////////////////////////////////////////////////////////////////////////

 void print(teilnehmer &t)
 {




 }

 void zeit(teilnehmer &t)
 {




 }

 int suchename(teilnehmer t[], string name, int i1,int i2)
 {




 }

