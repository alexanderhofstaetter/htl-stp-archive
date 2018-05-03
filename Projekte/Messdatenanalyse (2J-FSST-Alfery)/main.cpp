/****************************************************************************
 * @file main.cpp
 *
 * Projektname : Messdatenanalyse
 * Autor : Alexander Hofstätter
 *
 * Aufgabe:
 *
 *   Messdaten sind in einer Textdatei zeilenweise mit Angabe
 *   der laufenden Nummer, dem Messwert und Angabe der Einheit gespeichert.
 *   Am Anfang der Datei befindet sich ein Kopfteil (Header) mit allg. Angaben.
 *   (wie Titel und Datum der Messreihe, Kommentar zur Messung)
 *   Der Datenteil wird dann über den Eintrag "Messwerte: " eingeleitet.
 *   Die Messdaten sollen eingelesen, analysiert und grafisch dargestellt werden.
 *   Die Analyse soll die Anzahl der Messdaten, den Mittelwert,
 *   den Maximal- und Minimalwert, sowie den RMS-Wert ermitteln und
 *   als Protokolldatei im Textformat und als Webseite ausgeben.
 *
 * © 2013 Alexander Hofstätter
 *
 ***************************************************************************/

#define ESC 27
#define LF 10

/**----------- Header-Dateien ---------------------------------------------*/

#include <stdio.h>
#include <time.h>
#include <windows.h>                // Für SetConsoleTitle
#include <conio.h>
#include <iostream>
#include <direct.h>
#include "header\graphics.h"        // Grafik Bibliothek

#include "header\getch_console.h"
#include "header\signale.h"
#include "header\scope.h"

using namespace std;                // Namensraum für Standardbibliothk

/**----------- Funktions-Prototypen ---------------------------------------*/

void analyse(float s[], int n1, int n2, int x1, int x2, int y1, int y2);
void zeilen_header(FILE *datei);
int StringLenght (char string[]);
void StringReplace (char suchtext[], char replaceText [], int &pos, char html[], FILE *datei);
void StringReplace (char suchtext[], float replaceWert, int &pos, char html[], FILE *datei);

/**----------- Hauptprogramm ----------------------------------------------*/
int main()
{  char key;
   SetConsoleTitle(" Messdatenanalyse :: CSV, \270 2013 by A. Hofst\204tter");   // Konsolen Titel setzen

   do
   {
      system("CLS");
      char zeichen;
      int anzahl = 0,                           // Anzahl der Feldelemente aus CSV-Datei
          channel_anzahl = 0,                   // Anzahl an gefunden Kanälen in CSV-Datei
          zeichen_anzahl = 0;                   // Anzahl an Zeichen der Beispiel-HTML Datei im Array
      bool ch1_enable = true, ch2_enable = true;//Ob Kanal grafisch angezeigt wird oder nicht
      char text[51], dateiname[51];
      char dateipfad[256], dateipfad1[256];
      time_t timer = time(NULL);                // Erhält die Tageszeit
      struct tm *tblock = localtime(&timer);    // Wandelt Datum und Zeit in eine Struktur um

      getcwd(dateipfad,256);
      sprintf(dateipfad1,"%s\\",dateipfad);

      FILE *datei;
      printf(" Messdatenanalyse\n");
      printf(" ================\n");
      printf(" Bei Erstbenutzung lesen Sie unbedingt die beiliegende Dokumentation! \n\n");
      printf(" Sie befinden sich momentan in folgendem Verzeichnis: \n %s\n\n",dateipfad1);
      do
      {  printf(" Eingabedatei (z.B. scope.csv): "); cin >> dateiname;
         datei = fopen(dateiname,"r");
         if (datei == NULL)
            printf(" Fehler beim oeffnen der Datei. Versuchen Sie es erneut.\n\n");
      } while(datei == NULL);

      channel_anzahl = 0;
      while ( (zeichen = fgetc(datei)) != LF)
         if (zeichen == ',') channel_anzahl++;

      if (channel_anzahl > 2)
         printf(" Ungueltige Datei angegebn.");

      anzahl = 0;
      while ( (zeichen = fgetc(datei)) != EOF)
         if (zeichen == LF) anzahl++;
      rewind(datei);

      // Dynamische Arrays erstellen mit der Anzahl der Messwerte(zeit,ch1,ch2)
      float *zeit = new float[anzahl],
            *ch1  = new float[anzahl],
            *ch2  = new float[anzahl];

      if (channel_anzahl == 1)
         delete[] ch2;

      fscanf(datei,"%s\n",text);
      fscanf(datei,"%s\n",text);

      for(int i=0; i<anzahl; i++)
      {  if (channel_anzahl == 1)
            fscanf(datei,"%f,%f\n",&zeit[i], &ch1[i]);
         if (channel_anzahl == 2)
            fscanf(datei,"%f,%f,%f\n",&zeit[i], &ch1[i], &ch2[i]);
      }
      fclose(datei);

      datei = fopen("export-sample.html","r");
      if (datei == NULL)
      {  printf("Fehler beim oeffnen der Datei. Stellen Sie sicher das sich die Sample-HTML Datei im richtigen Verzeichniss liegt.\n");
         exit(-2);
      }

      zeichen_anzahl = 0;
      while ((zeichen = fgetc(datei)) != EOF)
         zeichen_anzahl++;
      rewind(datei);

      char *html = new char[zeichen_anzahl];

      for(int i = 0; i < zeichen_anzahl; i++)
      {  html[i]=fgetc(datei);
         if (html[i] == EOF) break;
      }
      fclose(datei);

      datei = fopen("export.html","w");
      if (datei == NULL)
      {  printf("Fehler beim oeffnen der Datei. Stellen Sie sicher das sich die HTML Datei, welche als Vorlage dient im richtigen Verzeichniss liegt.\n");
         exit(-3);
      }

      char SuchText[51];
      char* SuchPos;

      for(int i = 0; i < zeichen_anzahl; i++)                        // Schleife für ganze HTML Datei im Array
      {  if (html[i] == EOF) break;
         fputc(html[i],datei);                                       // HTML Datei aus Beispieldatei ausgeben

         strcpy(SuchText,"/*$datenarray$*/");
         SuchPos = strstr(html,SuchText);
         if (i == (SuchPos-html-1))                                  // Position erreicht wo String gefunden wurde
         {  if (channel_anzahl == 1)
               fprintf(datei,"['x', 'Kanal 1'],");
            else
               fprintf(datei,"['x', 'Kanal 1', 'Kanal 2'],");
            for(int j = 0; j < anzahl; j++)
            {  if (channel_anzahl == 1)
                  fprintf(datei,"['', %e]",ch1[j]);                  // Messdaten ausgeben
               else
                  fprintf(datei,"['', %e, %e]",ch1[j],ch2[j]);
               if (j == (anzahl-1)) break;                           // Bei vorletztem Wert abbrechen um kein "," auszugeben
               fprintf(datei,",\n");
            }
            i += StringLenght(SuchText);                             // Suchtext im Array bei Ausgabe überspringen
         }

         sprintf(text,"%d.%d.%04d - %02d:%02d",tblock->tm_mday,tblock->tm_mon+1,tblock->tm_year+1900,tblock->tm_hour,tblock->tm_min);
         StringReplace("<!--$datum-->",text,i,html,datei);
         StringReplace("<!--$dateiname-->",dateiname,i,html,datei);
         StringReplace("<!--$dateipfad-->",dateipfad1,i,html,datei);
         StringReplace("<!--$min1-->",array_min(ch1,0,anzahl),i,html,datei);
         StringReplace("<!--$max1-->",array_max(ch1,0,anzahl),i,html,datei);
         StringReplace("<!--$mittel1-->",array_mittel(ch1,0,anzahl),i,html,datei);
         StringReplace("<!--$rms1-->",array_rms(ch1,0,anzahl),i,html,datei);
         sprintf(text,"%d",anzahl);
         StringReplace("<!--$anzahl-->",text,i,html,datei);

         if(channel_anzahl != 1)   // Wenn mehr als ein Kanal vorhanden ist
         {  StringReplace("<!--$min2-->",array_min(ch2,0,anzahl),i,html,datei);
            StringReplace("<!--$max2-->",array_max(ch2,0,anzahl),i,html,datei);
            StringReplace("<!--$mittel2-->",array_mittel(ch2,0,anzahl),i,html,datei);
            StringReplace("<!--$rms2-->",array_rms(ch2,0,anzahl),i,html,datei);
         }

         if(channel_anzahl != 1)    // CSS in HTML-Datei bei einem Kanal
            StringReplace("/*Kanal1+2 CSS*/","#kanal1 { float: left; }",i,html,datei);

         if(channel_anzahl == 1)    // CSS in HTML-Datei bei zwei Kanälen
            StringReplace("/*Kanal1 ONLY CSS*/","#kanal2 { display: none; }",i,html,datei);
      }

      fclose(datei);

      datei = fopen("export.txt","w");
      if (datei == NULL)
      {  printf("Fehler beim oeffnen der Datei. \n");
         exit(-4);
      }

      fprintf(datei,"********************************************\n");
      fprintf(datei,"* Messdatenanalyse\n");
      fprintf(datei,"* Datum: %d.%d.%04d - %02d:%02d\n",tblock->tm_mday,tblock->tm_mon+1,tblock->tm_year+1900,tblock->tm_hour,tblock->tm_min);
      fprintf(datei,"* Anzahl der Messdaten: %d\n",anzahl);
      fprintf(datei,"* Anzahl der Kanaele: %d\n",channel_anzahl);
      fprintf(datei,"* Eingabedatei: %s\n",dateiname);
      fprintf(datei,"********************************************\n\n\n");
      fprintf(datei,"******************\n");
      fprintf(datei,"* Analyse Kanal 1*\n");
      fprintf(datei,"******************\n");
      fprintf(datei,"  Minimum: %f\n",array_min(ch1,0,anzahl));
      fprintf(datei,"  Maximum: %f\n",array_max(ch1,0,anzahl));
      fprintf(datei,"  Mittelwert: %f\n",array_mittel(ch1,0,anzahl));
      fprintf(datei,"  RMS-Wert: %f\n\n",array_rms(ch1,0,anzahl));
      fprintf(datei,"******************\n");
      fprintf(datei,"* Analyse Kanal 2*\n");
      fprintf(datei,"******************\n");
      fprintf(datei,"  Minimum: %f\n",array_min(ch2,0,anzahl));
      fprintf(datei,"  Maximum: %f\n",array_max(ch2,0,anzahl));
      fprintf(datei,"  Mittelwert: %f\n",array_mittel(ch2,0,anzahl));
      fprintf(datei,"  RMS-Wert: %f\n\n",array_rms(ch2,0,anzahl));
      fclose(datei);

      printf(" Alle Daten wurden erfolgreich verarbeitet. \n Die Dateien export.html und export.txt wurden erfolgreich erstellt.\n\n");
      printf(" ENTER druecken um Garfikausgabe zu starten.\n");
      printf(" ESC um Programm zu beenden\n\n");
      key = getch_console();

      // Dynamische Arrays wieder löschen
      delete[] html;

      // Berechnungen und Variablen
      int x1 = 50,x2 = 1050, y1 = 50,y2 = 550;     // Bildbereich Endwerte
      float ys1 = -15, ys2 = 15;                   // y-Skalenbereich Endwerte
      int dx = (x2-x1)/5;                            // Achsengitter Unterteilungen
      int dy = (y2-y1)/4;
      int faktor = anzahl/(x2-x1);                 // Feldelemente dividiert durch die Breite
      anzahl /= faktor;

      initwindow(x1+x2,y1+y2,"Messdatenanalyse - (c) A. Hofstaetter");     // Grafikfenster öffnen

      // Farben definieren
      int  bkcol = COLOR(220,220,250);             // Fenster Hintergrundfarbe
      int   acol = COLOR(200,200,200);             // Achsen- und Gitterfarbe
      int ch1col = COLOR(250,0,0);                 // Farbe für Kanal 1
      int ch2col = COLOR(0,0,250);                 // Farbe für Kanal 2

      do
      {
         setbkcolor(bkcol);                        // Hintergrundfarbe setzen
         cleardevice();                            // und ausfüllen

         setcolor(acol);
         axes(x1,x2,y1,y2,ys1,ys2);                  // Diagrammfläche und Achsen darstellen

         sprintf(text," Anzahl an Kanaelen: %d",channel_anzahl);
         outtextxy(x1,y1-17,text);

         setcolor(ch1col);
         if (ch1_enable == true) outtextxy(x1,y2," [1] Kanal 1 ausblenden");
         else                    outtextxy(x1,y2," [1] Kanal 1 einblenden");

         if (ch1_enable == true)
         {  setcolor(ch1col);
            draw(ch1,anzahl,x1,x2,y1,y2,ys1,ys2);    // Signalarray darstellen
            analyse(ch1,0,anzahl,x1,x2,y1,y2);
         }

         if(channel_anzahl != 1)
         {  setcolor(ch2col);
            if (ch2_enable == true) outtextxy(x1,y2+15," [2] Kanal 2 ausblenden");
            else                    outtextxy(x1,y2+15," [2] Kanal 2 einblenden");

            if (ch2_enable == true)
            {  setcolor(ch2col);
               draw(ch2,anzahl,x1,x2,y1,y2,ys1,ys2);
               analyse(ch2,0,anzahl,x1,x2,y1+20,y2);
            }
         }

         setcolor(BLACK);
         outtextxy(x1,y2+30," [ESC] Grafikfenster schließen");

         sprintf(text," %4.1f V",ys2/2);
         outtextxy(x1-40,y1-10+dy,text);

         sprintf(text," %4.1f V",0.0);
         outtextxy(x1-40,y1-5+2*dy,text);

         sprintf(text," %4.1f V",ys1/2);
         outtextxy(x1-42,y1-0+3*dy,text);

         key = getch();

         if     (key == '1' && ch1_enable == true)   ch1_enable = false;
         else if(key == '1' && ch1_enable == false)  ch1_enable = true;

         if     (key == '2' && ch2_enable == true)   ch2_enable = false;
         else if(key == '2' && ch2_enable == false)  ch2_enable = true;

         // bei ESC Taste Grafikfenster schließen
      } while(key != ESC);
      closegraph();

      if(channel_anzahl == 1)
      {  delete[] zeit;
         delete[] ch1;
      }
      else
      {  delete[] zeit;
         delete[] ch1;
         delete[] ch2;
      }

      key = getch_console();
   } while(key!=ESC);
   return 0;
}

void analyse(float s[], int n1, int n2, int x1, int x2, int y1, int y2)
{  float mittel = array_mittel(s,n1,n2);
   float    max =    array_max(s,n1,n2);
   float    min =    array_min(s,n1,n2);
   float    rms =    array_rms(s,n1,n2);

   char text[25];

   sprintf(text," Mittel : %4.2f ",mittel);
   outtextxy(x1+10,y1+10,text);

   sprintf(text," Min : %4.2f ",min);
   outtextxy(x2/2-72,y1+10,text);

   sprintf(text," Max : %4.2f ",max);
   outtextxy(x2/2+48,y1+10,text);

   sprintf(text," RMS : %4.2f ",rms);
   outtextxy(x2-90,y1+10,text);
}

int StringLenght (char string[])
{  int i = 0;
   while(1)
   {  if (string[i] == '\0') return i;
      i++;
   }
   return -1;
}

void StringReplace (char suchtext[], char replaceText [], int &pos, char html[], FILE *datei)
{  char* SuchPos = strstr(html,suchtext);
   if (pos == (SuchPos-html-1))
   {  fprintf(datei,replaceText);
      pos += StringLenght(suchtext);
   }
}

void StringReplace (char suchtext[], float replaceWert, int &pos, char html[], FILE *datei)
{  char* SuchPos = strstr(html,suchtext);
   if (pos == (SuchPos-html-1))
   {  fprintf(datei,"%f",replaceWert);
      pos += StringLenght(suchtext);
   }
}
