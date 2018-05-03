/////////////////////////////////////////////////////////////////////////////
//   Programmname : head_reader.cpp
//   w.alfery
//
//	 Binärdatei mit Kopfteil (head)
//   und Datensätzen (data) lesen
//
//
/////////////////////////////////////////////////////////////////////////////

//--------------------  Header-Dateien   ----------------------------------//
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//----------------------  struct header  -------------------------------- //
struct header                          // Struktur header
{  char kennung[5];                    //    Kennung
   int  bytesprodaten;                 //    Datensatz Größe       Adresse
   long anzahl;                        //    Anzahl der Daten        Ort
};

//----------------------  struct dataset -------------------------------- //
struct dataset                         // Struktur dataset
{  int nummer;                         //    Nummer
   float wert;                         //    Wert
   char text[20];                      //    Text
};

char dateiname[41] = "file.headerdemo"; // externer Dateiname


//---------------------------  main  -------------------------------------//
int main()
{
   int i,ds,hs,n,pos;
   FILE* datei;

   // Strukturvariable für Binärdateizugriff
   header h={"TYP0",                // Strukt.Var. für Head
             sizeof(dataset),
             0};
   hs=sizeof(header);               // Bytegröße von "head"

   dataset d;                       // Strukt.Var. für Datensatz
   ds=sizeof(dataset);              // Bytegröße von "dataset"

   // --- Binärdatei erstellen ---
   datei=fopen(dateiname,"w");      // Datei öffnen
   if (datei==NULL) return -1;

   n=5;                             // Anzahl von Datensätzen
   // Header auf Datei schreiben
   h.anzahl=n;
   fwrite(&h,hs,1,datei);
   // evtl. zuvor positionieren mit
   // fseek(datei,hs,0);
   // 5 Datensätze auf Datei schreiben
   for (i=0;i<n;i++)
   {  d.nummer=i+1;
      d.wert=1.0/(i+1);
      sprintf(d.text," %d-ter von %d ",i+1,n);
      fwrite(&d,ds,1,datei);
   }

   fclose(datei);

   // --- Binärdatei lesen ---
   // Datei öffnen
   datei=fopen(dateiname,"r");
   if (datei==NULL) return -2;

   header hr;
   // Header von Datei lesen
   fread(&hr,hs,1,datei);
   printf("\n");
   printf(" Header von %s \n",dateiname);
   printf(" Kennung   :%s\n",hr.kennung);
   printf(" Bytes/Set :%d\n",hr.bytesprodaten);
   printf(" Anzahl    :%ld\n",hr.anzahl);
   printf(" ------------------------------\n\n");

   // 1. Datensatz von Datei lesen
   pos=0;
   printf(" %d-ten Datensatz lesen \n",pos+1);
   if(fseek(datei,hs+pos*ds,0)==0)
   {  fread(&d,ds,1,datei);
      printf("%2d %6.2f %s \n",d.nummer,d.wert,d.text);
   }
   printf("\n");

   fclose(datei);
   return 0;

}

