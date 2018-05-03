/////////////////////////////////////////////////////////////////////////////
//   Programmname : messdaten.cpp
//   A. Hofstätter
//   formatiertes Einlesen einer CSV-Datei
//   CSV (comma seperate value) -  durch Komma getrennte Werte
/////////////////////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------
//   Header-Dateien
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//-----------------------------------------------------------------------
//   Funktionsdefinitionen

int dateifehler(FILE *datei,int wert);
void min_max(float a[], float &minimum, float &maximum,int anzahl);
void array_sort( float a[], int n);

//-----------------------------------------------------------------------
//   Hauptprogramm
int main()
{
   FILE *datei;
   system("CLS");
   float minimum,maximum;
   char dateiname[41]="messung.csv";
   char dateiname_ausgabe[41];
   printf(" CSV-Datei einlesen \n");
   printf(" Eingabedatei: ");
   scanf ("%s",dateiname);

   printf("\n         Wert | Einheit \n");
   printf("        ****************\n");

   datei = fopen(dateiname,"r");         // Dateiname über Aufrufparameter holen
   dateifehler(datei,1);

   char zeichen;
   int anzahl=1;
   while((zeichen=fgetc(datei))!=EOF)    // formatiert lesen
      if (zeichen == 10) anzahl++;
   rewind(datei);

   float *wert = new float[anzahl];
   char *einheit = new char[anzahl];

   for(int i=0;((fscanf(datei,"%f,%c\n",&wert[i],&einheit[i]))!=EOF && i < anzahl);i++)    // formatiert lesen
      printf(" %12.5f | %c\n",wert[i],einheit[i]);             // und ausgeben
   fclose(datei);

   min_max(wert,minimum,maximum,anzahl); // Min - Max Bestimmen

   printf("\n Es wurden %d Messwerte erfolgreich gelesen.\n",anzahl);
   printf(" Minimum und Maximum der Messwerte: \n");
   printf("  - Minimum: %f \n",minimum);
   printf("  - Maximum: %f \n",maximum);

   printf("\n\n Messdaten Export in formatierte Textdatei \n");
   printf(" Dateiname fuer Messdaten Export angeben: "); cin >> dateiname_ausgabe;

   datei = fopen(dateiname_ausgabe,"w");
   dateifehler(datei,2);
   {
      fprintf(datei,"**********************************\n");
      fprintf(datei,"* (c) Alexander Hofstaetter\n");
      fprintf(datei,"* Messwerttabelle - Exportdatei\n");
      fprintf(datei,"* Anzahl der Messwerte: %d\n",anzahl);
      fprintf(datei,"* Maximum: %f V\n",maximum);
      fprintf(datei,"* Minimum: %f V\n",minimum);
      fprintf(datei,"**********************************\n\n");
      fprintf(datei,"         Wert | Einheit \n");
      fprintf(datei,"        **************** \n");
   }

   array_sort(wert,anzahl);
   for(int i=0; i<anzahl; i++)
      fprintf(datei," %12.5f | %c \n",wert[i],einheit[i]);

   fprintf(datei,"**********************************");
   fprintf(datei,"\n\n* Ende der Datei\n");
   fprintf(datei,"**********************************");

   printf("\n Datei (%s) wurde erfolgreich geschrieben und exportiert.",dateiname_ausgabe);

   delete[] wert;
   delete[] einheit;
   fclose(datei);

   system("PAUSE");
   return 0;
}

int dateifehler(FILE *datei,int wert)
{  if( datei==NULL)
   {  printf(" Fehler beim Oeffnen ...\n");
      printf(" Programm neu öffnen!\n");
      exit(wert);
   }
}

void min_max(float a[], float &minimum, float &maximum,int anzahl)
{  minimum = a[0];
   maximum = a[0];
   for(int i=0; i<anzahl; i++)
   {  if (a[i] > maximum) maximum = a[i];
      if (a[i] < minimum) minimum = a[i];
   }
}

void array_sort( float a[], int n)
{  for (int i=0; i<n; i++)
   {  for (int j=i+1; j<n; j++)
      {  if (a[i]>a[j])
         {  float hilf=a[i];
            a[i]=a[j];
            a[j]=hilf;
         }
      }
   }
}
