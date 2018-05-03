/////////////////////////////////////////////////////////////////////////////
//   Programmname : datei1.cpp
//
//   erstellt am  : 4.4.13
//   von          : Alex Hofstätter
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

#define LF 10

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
   int n_c,n_lf;
   char zeichen,suche,ersatz;

   char dateiname[80];

   FILE *datei;
   datei = fopen("txt.txt","r");
   if(datei==NULL)
   {  printf("Fehler beim oeffnen!");
      exit(-1);
   }

   n_c=0;
   n_lf=0;
   while((zeichen=fgetc(datei))!=EOF)
   {  if (zeichen==LF)
      {  n_lf++;
         printf("\n");
      }
      else
      {  putchar(zeichen);
         n_c++;
      }
   }

   printf("\n\n Zeichen: %d   Zeilen: %d\n\n",n_c,n_lf+1);

   printf(" Zeichen suchen: ");
   cin >> suche;
   printf(" Zeichen ersetzen: ");
   cin >> ersatz;
   printf("\n Alle '%c' werden nun durch '%c' ersetzt ...",suche,ersatz);

   printf("\n\n Bitte waehlen Sie einen Dateinamen (z.B. dateiname.txt): ");
   cin >> dateiname;

   FILE *neuedatei;
   neuedatei = fopen(dateiname,"w");

   if(neuedatei==NULL)
   {  printf(" Fehler beim erstellen der Datei!");
      exit(-1);
   }
   rewind(datei);
   while((zeichen=fgetc(datei))!=EOF)
   {  if (zeichen == suche)
         fputc(ersatz,neuedatei);
      else
         fputc(zeichen,neuedatei);
   }
   fputc(LF,neuedatei);
   fclose(datei);
   fclose(neuedatei);

   return 0;
}
