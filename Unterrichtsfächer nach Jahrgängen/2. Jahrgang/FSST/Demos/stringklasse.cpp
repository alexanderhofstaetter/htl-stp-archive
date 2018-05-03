/////////////////////////////////////////////////////////////////////////////
//   Programmname : stringklasse.cpp
//
//   Aufgabe :  Verwendung der C++ Stringklasse string
//   di w.alfery
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <string>                      // Stringklasse Headerfile

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  int pos,n;

   string s1;                          // String(objekt) definieren
   string s2=s1;                       // String mit String s1 initialisieren
   string name(" klasse Strings ");    // String mit Anfangswert initialisieren
   string text(20,'/');                // String mit 20 '/'-Zeichen initialisieren
   string kopie(text);                 // String mit text initialisieren

   string liste[10]={"Eins","Zwei","Drei","Vier","Fuenf","Sechs","Sieben","eine","alte","Frau"};                   // Array mit 10 Strings

   const string OK_MSG="OK \n";        // Stringkonstante definieren

   system("CLS");                      // Bildschirm löschen
   cout << " C++ Strings " << endl << endl;
   cout << text << name << kopie << OK_MSG << endl; // Strings ausgeben

   cout << " Einlesen in String s1 : "; cin >> s1;  // Strings einlesen
   cout << " Stringlaenge von s1 = " << s1.length() << endl;
   cout << " Einlesen in String s2 : "; cin >> s2;
   cout << " Stringlaenge von s2 = " << s2.length() << endl << endl;
   text = s1 + s2;                     // Stringverkettung und Stringzuweisung
   cout << " Strings s1 und s2 verketten : " << text << endl;
   cout << " neue Stringlaenge   = " << text.length() << endl << endl;
   pos=s1.length();
   text.insert(pos,"-insert-");        // String an der Position pos einfügen
   cout << " String an bestimmter Position einfuegen : " << text << endl;
   text.erase(pos+1,n=6);              // ab der Position pos n Zeichen entfernen
   cout << " n-Zeichen ab bestimmter Position entfernen : " << text << endl;

   cout << " String zeichenweise ausgeben : ";
   for (int i=0; i<text.length();i++)
       cout << " " << text[i];         // einzelne Zeichen ausgeben

   cout << endl << endl << " einzelne Zeichen aendern : ";
   text[pos]='*';
   text[pos+1]='*';
   cout << text << endl << endl;

   system("PAUSE");
   system("CLS");
   text="Die Klasse string bietet gegenueber den C-Strings einige Vorteile.\
   Bei der Stringdefinition ist es nicht notwendig die Stringlaenge anzugeben.\
   Der erforderliche Speicherplatz wird bei der Programmausfuehrung dynamisch verwaltet.\
   C++ -Strings koennen mit den Operatoren =,+,==,<,>, ... verarbeitet werden.\
   Die String-Klasse enthaelt auch Funktionen (Methoden) wie length(), insert(), find() ... \n";

   cout << endl << "Text : " << endl;
   cout << text << endl;
   cout << "Suche mit find - " << endl;
   n = text.find("Die");               // Teilstring im String suchen
   if (n!=string::npos) cout << " \"Die\" ist an der Position : " << n << endl;
   n = text.find("Die",n+1);
   if (n!=string::npos) cout << " und an der Position : " << n << endl << endl;

   cout << "Ersetzen mit replace - " << endl;
   text.replace(4,13,"Stringklasse");  // Teilstring im String ersetzen
   kopie=text.substr(0,65) + " ... ";
   cout << "Text mit Ersetzungen : " << endl << kopie << endl << endl;

   cout << "String-Array ausgeben : " << endl;
   for (int i=0; i<10;i++)
       cout << liste[i] << ",";        // einzelne Strings des String Arrays liste ausgeben
   cout << endl << endl;

   text.clear();
   for (int i=0; i<10;i++)
       text += liste[i];               // Stringarray zu einem String verketten
   cout << "String-Array zu einem String verketten : " << endl;
   cout << text  << endl;

   cout << endl << endl;
   system("PAUSE");
   return 0;
 }


