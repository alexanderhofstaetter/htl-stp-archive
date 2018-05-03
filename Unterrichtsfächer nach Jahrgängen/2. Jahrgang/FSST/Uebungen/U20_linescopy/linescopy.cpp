/////////////////////////////////////////////////////////////////////////////
//   Programmname : linescopy.cpp
//   A. Hofstätter
//   Aufgabe :  linescopy.cpp
//
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <string.h>                         // C-String Bibliothek
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

#define LF 10

//-----------------------------------------------------------------------
//                       Hauptprogramm
int main()
{
   char dateiname_quelle[41]="text.txt";
   char dateiname_ziel[41]="kopie.txt";
   char menu,zeichen;
   char zeile[121];

   //printf(" Dateiname (Quelle) eingeben : ");
   //cin >> dateiname_quelle;
   printf(" Dateiname (Ziel) eingeben : ");
   cin >> dateiname_ziel;

   do
   {
   system("CLS");
   printf(" Dateien Zeilenweisen kopieren und schreiben\n\n");

   printf("\n [1] Datei ausgeben\n");
   printf(" [2] Bestimmte Zeilen kopieren\n");
   printf(" [3] Bestimmte Zeilen mit Suchzeichen kopieren\n");
   menu = getch();

   FILE *datei;
   FILE *neuedatei;

   if(menu == '1')
   {
      system("CLS");
      datei=fopen(dateiname_quelle,"r"); // Datei zum Lesen öffnen
      if(datei==NULL) exit(1); // Fehlerbehandlung
      while(fgets(zeile,121,datei)) // zeilenweise von Datei lesen
         printf("%s",zeile); // und am Bildschirm ausgeben
      fclose(datei);
   }

   char zeile_anfang,zeile_anzahl;
   if(menu == '2')
   {
      printf("\n Zeile wo begonnen werden soll zu kopieren: "); cin >> zeile_anfang;
      printf(" Anzahl der Zeilen: "); cin >> zeile_anzahl;

      neuedatei = fopen(dateiname_ziel,"w");
      if(datei==NULL) exit(1);               // Fehlerbehandlung
      datei = fopen(dateiname_quelle,"r");   // Datei zum Lesen öffnen
      if(datei==NULL) exit(1);               // Fehlerbehandlung
/*
      int j=0;
      for (int i=1;feof(datei) != EOF;i++)
      {  fgets(zeile,121,datei);
         if (i >= zeile_anfang);
         {  fputs(zeile,neuedatei);
            j++;
            if (j==zeile_anzahl); break;
         }
      }
*/    int i=0;
      while(fgets(zeile,121,datei))
      {  //if (i >= zeile_anfang )
            fputs(zeile,neuedatei);
         //i++;
      }

      fclose(datei);
      fclose(neuedatei);
   }

   printf("\n\nTaste druecken ...");
   menu = getch();
   }while(menu != 27);


   printf("\n\n");
   system("PAUSE");
   return EXIT_SUCCESS;

}
