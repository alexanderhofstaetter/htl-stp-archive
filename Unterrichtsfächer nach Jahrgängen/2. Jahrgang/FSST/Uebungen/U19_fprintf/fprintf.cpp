/////////////////////////////////////////////////////////////////////////////
//   Programmname : fprintf.cpp
//   A.H.
//   Aufgabe :  CSV Dateien
//
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

using namespace std;

//-----------------------------------------------------------------------
//                       Hauptprogramm
int main()
{
   srand(time(NULL));
   char dateiname[41]="werte.csv";           // Dateiname

   FILE *datei;
   printf("\n CSV-Datei schreiben \n");

   datei = fopen(dateiname,"w"); // Dateiname über Aufrufparameter holen
   if( datei==NULL)
   {  printf("Fehler beim Oeffnen ...\n");
      exit(1);
   }

   printf("Schreibe in Datei: \n");
   int r;
   for(int i=0;i<10;i++)
   {
      r=rand()%100+1;
      fprintf(datei,"%2d : %2d\n",i,r);
      fprintf(stdout,"%2d : %2d\n",i,r);
   }

   fclose(datei);

   FILE *datei1;
   printf("\n\n CSV-Datei einlesen \n");

   datei1 = fopen(dateiname,"r"); // Dateiname über Aufrufparameter holen
   if( datei1==NULL)
   {  printf("Fehler beim Oeffnen ...\n");
      exit(1);
   }

   int a,b;
   while((fscanf(datei1,"%2d : %2d\n",&a,&b))!=EOF) // formatiert lesen
      fprintf(stdout,"%2d : %2d\n",a,b);// und ausgeben



   printf("\n\n");
   system("PAUSE");
   return EXIT_SUCCESS;

}
