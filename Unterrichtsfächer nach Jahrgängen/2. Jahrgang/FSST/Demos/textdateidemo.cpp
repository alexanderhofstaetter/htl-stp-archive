/////////////////////////////////////////////////////////////////////////////
//   Programmname : zeichen.cpp
//   DI W.Alfery
//   Aufgabe :  Textdatei zeichenweise lesen 
//
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;

#define LF 10                               // Steuerzeichen LF

//-----------------------------------------------------------------------
//                       Hauptprogramm
int main()
{
   char dateiname[41]="text.txt";           // Dateiname
   char c;                                  // ein Zeichen

   FILE *datei;                             // Filepointer

   system("CLS");
   printf("\n Textdatei lesen \n");
   printf("\n Dateiname = %s ",dateiname);
   // printf("\n neuer Dateiname = ");
   // scanf("%s",dateiname);

   datei=fopen(dateiname,"r");              // Datei zum Lesen öffnen
   if(datei==NULL)                          // Fehlerbehandlung
   {  printf("\n Datei kann nicht geoeffnet werden \n");
      exit(1);                              // dann Programmabbruch
   }

   printf("\n\n Datei Inhalt : \n");

   while ((c=fgetc(datei))!=EOF)            // bis Dateiende lesen
   {  putchar(c);                           // Zeichen am Bildschirm ausgeben
   }

   fclose(datei);                           // Datei schließen

   printf("\n\n");
   system("PAUSE");
   return 0;
}
