/////////////////////////////////////////////////////////////////////////////
//   Programmname : csv.cpp
//   DI W.Alfery
//   formatiertes Einlesen einer CSV-Datei
//   CSV (comma seperate value) -  durch Komma getrennte Werte
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <stdlib.h>



//-----------------------------------------------------------------------
//   globale Definitionen
const int N=100;
float daten[N];


//-----------------------------------------------------------------------
//   Hauptprogramm
int main(int argc, char *argv[])
{
   FILE *datei;
   int i,n;
   float x;
   char text[40];
   char dateiname[40]="messung.dat";

   system("CLS");
   printf(" CSV-Datei einlesen \n");
   printf(" Datei : ");
   scanf ("%s",dateiname);

   datei = fopen(dateiname,"r");         // Dateiname über Aufrufparameter holen
   if( datei==NULL)
   {  printf("Fehler beim Oeffnen ...\n");
      return 1;
   }

   n=0;
   while((fscanf(datei,"%d,%f,%s\n",&i,&x,text))!=EOF)    // formatiert lesen
   {
       printf(" i=%d  x=%f  Text=%s \n",i,x,text);// und ausgeben
       daten[n]=x;
       if (n>=N) break;
       n++;
   }


   fclose(datei);
   system("PAUSE");
   return 0;
}


