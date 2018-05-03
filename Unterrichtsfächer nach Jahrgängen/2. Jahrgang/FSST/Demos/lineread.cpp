/////////////////////////////////////////////////////////////////////////////
//   Programmname : lineread.cpp
//   DI W.Alfery
//   Aufgabe :  Zeilen von Textdatei lesen
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
   char s[81];                              // String
   int z1,z2,z;                             // Anzahl der Zeilen

   FILE *datei;                             // Filepointer

   system("CLS");
   printf("\n Textdatei lesen \n");
   printf("\n Dateiname = ");
   scanf("%s",dateiname);

   printf("\n ab  Zeile = ");
   scanf("%d",&z1);
   printf("\n bis Zeile = ");
   scanf("%d",&z2);

   datei=fopen(dateiname,"r");              // Datei zum Lesen ˆffnen
   if(datei==NULL)                          // Fehlerbehandlung
   {  printf("\n Datei kann nicht geoeffnet werden \n");
      exit(1);                              // dann Programmabbruch
   }

   printf("\n\n Datei Inhalt : \n");

   z=1;
   while (fgets(s,80,datei))               // zeilenweise bis Dateiende lesen
   {  if(z>=z1) printf("%s",s);            // Zeile am Bildschirm ausgeben
      if(z>=z2) break;                     // bei nz-Zeilen abbrechen
      z++;
   }

   fclose(datei);                           // Datei schlieﬂen

   printf("\n\n");
   system("PAUSE");
   return 0;
}
