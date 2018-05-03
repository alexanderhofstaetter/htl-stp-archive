/////////////////////////////////////////////////////////////////////////////
//   Programmname : signale_demo.cpp
//   di w.alfery
//
//   erstellt am  : 9.11.2010
//
//   Aufgabe :  Funktionen für Signalerzeugung
//              und Signalanalyse
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bse_console.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen
/////////////////////////////////////////////////////////////////////////////

  const int ESC=27;

  const int NMAX=10;                  // Feldgröße NMAX
  float s[NMAX];                      // Signal Array


/////////////////////////////////////////////////////////////////////////////
//   Funktions-Prototypen
/////////////////////////////////////////////////////////////////////////////

void array_out( float a[], int n);
void array_dc( float a[], int n, float am);
void array_sinus ( float a[], int n, float am, float fn );




/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   char antwort;
   float am,fn,phi;

   do
   {

       system("CLS");                  // Bildschirm löschen
       gotoxy(1,1);
       printf(" Signalgenerator \n");
       printf(" --------------- \n");

       printf(" 1 ... Gleichsignal    \n");
       printf(" 2 ... Sinussignal     \n");
       printf(" 3 ... Rechtecksignal  \n");
       printf(" 4 ... Impulssignal    \n");
       printf(" 5 ... Saegezahnsignal    \n");
       printf(" 6 ... Rauschsignal    \n");
       printf(" 7 ... Ueberlagerung [Ein/Aus] \n");
       printf(" 8 ... Tabelle         \n");
       printf(" 9 ... Signal ruecksetzen \n");

       printf(" ESC ... Programmende  \n");

       antwort = getch();

       switch(antwort)
       {
           case '1' :
              clrscr();
              printf(" Gleichsignal \n");
              printf(" Gleichanteil = ");
              scanf ("%f",&am);
              // Gleichsignal zuweisen
              array_dc(s,NMAX,am);                 // Gleichsignal mit Amplitude=1
              break;

           case '2' :
              clrscr();
              printf(" Sinussignal \n");
              printf(" Amplitude = ");
              scanf ("%f",&am);
              printf(" Frequenz  = ");
              scanf ("%f",&fn);
              // Gleichsignal zuweisen
              array_sinus(s,NMAX,am,fn);              // Sinussignal mit Amplitude=1
              break;


          case '8' :
              clrscr();
              printf(" Signal Tabelle \n");
              array_out( s,NMAX );
              getch();
              break;

       }


   } while (antwort!=ESC);


}

/////////////////////////////////////////////////////////////////////////////
//   Funktions-Definitionen
/////////////////////////////////////////////////////////////////////////////

void array_dc( float a[], int n, float am)
/////////////////////////////////////////////////////////////////////////////
//   Gleichsignal Samples mit Amplitude "am"
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude (Gleichsignalwert)
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{   int i;
    for (i=0;i<n;i++)
    {  a[i]=am;
    }
}

void  array_sinus ( float a[], int n, float am, float fn )
/////////////////////////////////////////////////////////////////////////////
//   Sinussamples dem Feld a[] zuweisen
//   nach der Formel  a[i] = am*sin(2*M_PI*i*fn/n)
//        mit Amplitude am und Frequenzvielfaches fn
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude
//            float fn   ...  Frequenzvielfaches
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{   int i;
    for (i=0;i<n;i++)
    {  a[i]= am*sin(2*M_PI*i*fn/n);
    }
}


void array_out( float a[], int n)
/////////////////////////////////////////////////////////////////////////////
//   Ausgabe des Arrays a[] auf Konsole
//   Import : int n      ...  Feldgröße
//            float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{   int i;
    for (i=0;i<n;i++)
    {  printf(" a[i] = %6.2f \n",a[i]);
    }
    printf("\n");
}

