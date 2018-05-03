/////////////////////////////////////////////////////////////////////////////
//   Name: A. Hofstätter
//   Programmname : cstring_analyse.cpp
//   Aufgabe : C/C++ - Aufgabe 13
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
#include <conio.h>
#include <ctype.h>
#include <windows.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Typdefinition
/////////////////////////////////////////////////////////////////////////////

typedef char string100[101];

/////////////////////////////////////////////////////////////////////////////
//   Funktionen
/////////////////////////////////////////////////////////////////////////////

int zeichensuche( char *s , char c )
{  int anzahl;
   for (int i=0; s[i]; i++)
      if ( s[i]==c ) anzahl++;
   return anzahl;
}

int zeichenersatz( char *s, char such, char ersatz)
{  int anzahl;
   for (int i=0; s[i]; i++)
      if ( s[i]==such )
      {  s[i]=ersatz;
         anzahl++;
      }
   return anzahl;
}

void grossbuchstaben( char *s)
{  for (int i=0; s[i]; i++)
      s[i]=toupper(s[i]);
}

int charpos( char *s, char such)
{  for (int i=0; s[i]; i++)
      if ( s[i]==such ) return i;
   return -1;
}

int charpos( char *s, char such, int n)
{  int anzahl=0;
   for (int i=0; s[i]; i++)
      if ( s[i]==such )
      {  anzahl++;
         if (anzahl == n) return i;
      }
   return -1;
}

void stringcut( char *s, char limit)
{  int index = charpos(s,limit);
   if (index != -1) s[index] = '\0';
}

void stringcut( char *s, char limit, int n)
{  int index = charpos(s,limit,n);
   if (index != -1) s[index] = '\0';
}

void stringcut_pos( char *s, char *s1, int n1, int n2)
{  for (int i=0; i<n2; i++)
      s1[i]=s[n1+i];
}

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   string100 text,text1;
   char menue,zeichen,ersatz;
   int n,pos1,pos2;

   printf(" Text einlesen: ");
   do
   {
      printf(" C-Strings\n");
      printf(" =========\n");
      system("CLS");
      gets(text);

      printf("\n W\x84hlen Sie eine der folgenden Optionen\n\n");
      printf(" [1] Bestimmte Zeichen suchen\n");
      printf(" [2] Suchen und ersetzen\n");
      printf(" [3] 1. Auftreten eines Zeichens\n");
      printf(" [4] Abschneiden beim 1-ten Auftreten eines Zeichens\n");
      printf(" [5] Abschneiden beim n-ten Auftreten eines Zeichens\n");
      printf(" [6] In Grossbuchstaben umwandeln\n");
      printf(" [7] String zwischen zwei Positionen auschneiden\n");
      printf(" [ESC] Programmende\n");
      menue=getch();
      system("CLS");

      printf(" Aktueller text: %s\n\n",text);
      if(menue=='1')
      {  printf(" Zeichen: "); cin >> zeichen;
         printf(" Anzahl von '%c' im Text: %d  \n\n",zeichen,zeichensuche(text,zeichen));
      }

      if(menue=='2')
      {  printf(" Zeichen: "); cin >> zeichen;
         printf(" Ersetzen durch: "); cin >> ersatz;
         zeichenersatz(text,zeichen,ersatz);
         printf("\n Alle '%c' wurden durch '%c' ersetzt: %s\n", zeichen,ersatz,text);
      }

      if(menue=='3')
      {  printf(" Zeichen: ");
         cin >> zeichen;
         printf(" Das Zeichen '%c' kommt in Text als erstes an %d-ter Stelle vor\n",charpos(text,zeichen)+1);
         printf("\n =========\n");
      }

      if(menue=='4')
      {  printf(" Zeichen: "); cin >> zeichen;
         stringcut(text,zeichen);
         printf(" Der Text nach dem Zeichen '%c' wurde abgeschnitten: %s\n",zeichen,text);
      }


      if(menue=='5')
      {  printf(" Zeichen: "); cin >> zeichen;
         printf(" Position n: "); cin >> n;
         stringcut(text,zeichen,n);
         printf(" Der Text nach dem %d-ten Auftreten '%c' wurde abgeschnitten: %s\n",n,zeichen,text);
      }

      if(menue=='6')
      {  grossbuchstaben(text);
         printf(" Der Text wurde in Grossbuchstaben umgewandelt: \n %s",text);
      }

      if(menue=='7')
      {  printf(" Eingabe der Positionen zwischen(!) denen der Text ausgeschnitten werden soll ");
         printf(" Position 1: "); cin >> pos1;
         printf(" Position 2: "); cin >> pos2;
         stringcut_pos(text, text1, pos1, pos2);
         printf("  Ausgeschnittener String: %s\n",text1);
      }

      printf("\n Zurueck ins Menu mit ENTER");
      getch();
   }
   while(menue!=27);

   printf("\n\n");
   system("PAUSE");
   return 0;

}
