/////////////////////////////////////////////////////////////////////////////
//   Programmname : fputs.cpp
//   DI W.Alfery
//   Aufgabe :  Textdatei zeilenweise schreiben und lesen
//
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

using namespace std;

//-----------------------------------------------------------------------
//                       Funktionen

int datei(char *dateiname)                  // neue Datei anlegen 
{  FILE *datei;                             // File Descriptor
   datei=fopen(dateiname,"w");              // Datei erstellen
   if(datei==NULL)                          // Fehlerbehandlung
   {  return EXIT_FAILURE; 
   }      
   fclose(datei);                           // Datei schließen
   return 0;
}

int zeileschreiben(char *dateiname, char *zeile ) // Zeile auf Datei schreiben
{  FILE *datei;                             // File Descriptor

   datei=fopen(dateiname,"a");              // Datei zum Anhängen öffnen 
   if(datei==NULL) return 1;                // Fehlerbehandlung

   fputs(zeile,datei);                      // zeilenweise auf Datei schreiben  

   fclose(datei);                           // Datei schließen
   return 0;
}


int dateilesen(char *dateiname)             // Datei zeilenweise lesen 
{  char zeile[80];                          // C-String 
   FILE *datei;                             // File Descriptor definieren

   datei=fopen(dateiname,"r");              // Datei zum Lesen öffnen
   if(datei==NULL) return 1;                // Fehlerbehandlung

   while(fgets(zeile,80,datei))             // zeilenweise von Datei lesen 
   {  printf("%s",zeile);                   // und am Bildschirm ausgeben  
   }

   fclose(datei);                           // Datei schließen
   return 0;
}



//-----------------------------------------------------------------------
//                       Hauptprogramm
int main()
{
   char dateiname[41]="text.txt";           // Dateiname
   char zeile[80];                          // String für eine Zeile
   int err,l;

   system("CLS");
   printf("\n zeilenweise schreiben und lesen  \n");
    
   printf("\n Dateiname = %s ",dateiname);
   if (datei(dateiname))                    // neue Datei anlegen 
   {  printf("\n Datei kann nicht erstellt werden  \n"); system("PAUSE");
      return 1;                             // Abbruch bei Fehler   
   }    

   printf("\n 5 Zeilen auf Datei schreiben : \n");
   for (l=1;l<=5;l++) 
   {  printf("%d:",l); 
      fgets(zeile,80,stdin);                // Zeile über Tastatur einlesen 
      zeileschreiben(dateiname,zeile);      // und auf Datei ausgeben 
   } 
 
   printf("\n Datei zeilenweise lesen : \n");
   dateilesen(dateiname);                   // Datei zeilenweise lesen  
 

   printf("\n\n");
   system("PAUSE");
   return EXIT_SUCCESS;

 }
