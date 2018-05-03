/////////////////////////////////////////////////////////////////////////////
//   Name: A. Hofstätter
//   Programmname : memory.cpp
//   Aufgabe :  Memory
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Globale Definition von Feldern
/////////////////////////////////////////////////////////////////////////////

const int NMAX = 20;                   // Feldgröße NMAX
const int MMAX = 10;                   // Feldgröße MMAX
typedef int feld[NMAX][MMAX];

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(NULL));
    float am,fn = 0;
    char key;
    do
    {
        system("CLS");
        printf("Memory");
        printf("Verfuegbare Karten: \n");
        for ( int i=0; i<NMAX; i++ )
        {   printf("%2|",i);
            for( int j=0; j<MMAX; j++ ) 	      // Hauptschleife für Spalten
            {
                printf("%2c",(char)feld[i][j]);
            }
            printf("\n");
        }


    }
    while(1);

    printf("\n\n");
    system("PAUSE");
    return 0;

}

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

void array_rand(float a[], int n, float am)
/////////////////////////////////////////////////////////////////////////////
//   dem Array a n-Zufallszahlen mit der Amplitude am
//   Import : float n    ...  Feldgröße
//            float am   ...  Amplitude
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{
    for(int i = 0; i < n; i++)
        a[i] = 2*am*((float)rand()/RAND_MAX) - am;
}

void array_dc(float a[], int n, float am)
/////////////////////////////////////////////////////////////////////////////
//   Gleichsignal Samples mit Amplitude "am"
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude (Gleichsignalwert)
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{
    for(int i = 0; i < n; i++)
        a[i] = am;
}

void  array_sinus(float a[], int n, float am, float fn)
/////////////////////////////////////////////////////////////////////////////
//   Sinussamples dem Feld a[] zuweisen
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude
//            float fn   ...  Frequenzvielfaches
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{
    for(int i = 0; i < n; i++)
        a[i] = am*sin(2*M_PI*i*fn/n);
}

void  array_rect(float a[], int n, float am, float fn)
/////////////////////////////////////////////////////////////////////////////
//   Rechtecksamples dem Feld a[] zuweisen
//        mit Amplitude am und Frequenzvielfaches fn
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude
//            float fn   ...  Frequenzvielfaches
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{
    array_sinus(a,n,am,fn);
    for( int i=0; i<n; i++)
    {   if(a[i] < 0) a[i] = -am;
        else if(a[i] > 0) a[i] = am;
    }
}

void array_out(float a[], int n)
/////////////////////////////////////////////////////////////////////////////
//   Ausgabe des Arrays a[] auf Konsole
//   Import : int n      ...  Feldgröße
//            float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{   for(int i = 0; i < n; i++)
        printf("%d %3.4f ",i,a[i]);
}

float array_mittel(float a[], int n1, int n2)
/////////////////////////////////////////////////////////////////////////////
//   Summe  der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Mittelwert
//
///////////////////////////////////////////////////////////
{
    float mittel = 0;
    for(int i = n1; i <= n2; i++)
        mittel += a[i];
    return mittel/(n2+1-n1);
}

float array_min ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Minimum der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Minimum
//
///////////////////////////////////////////////////////////
{   float min = a[0];	// vorläufiges Minimum ist erstes Feldelement
    for (int i = n1; i <= n2; i++)
        if (min > a[i]) min = a[i];
    return min;
}

float array_max ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Maximum (Spitzenwert) der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Maximum (Spitzenwert)
//
///////////////////////////////////////////////////////////
{   float max = a[0];	// vorläufiges Maximum ist erstes Feldelement
    for (int i = n1; i <= n2; i++)
        if (max < a[i]) max = a[i];
    return max;
}

float array_rms ( float a[], int n )
/////////////////////////////////////////////////////////////////////////////
//   RMS-Wert ( echter Effektivwert ) der Feldwerte berechnen
//   RMS  =  Wurzel aus dem Mittelwert der Quadrate der Signalwerte (Feldelemente)
//   Import : float a[i] ...  Feld8
//            int n      ...  Feldgröße
//   Export : float      ...  Effektivwert
//
///////////////////////////////////////////////////////////
{   float rms = 0;
    for (int i = 0; i < n; i++)
        rms = rms + a[i]*a[i];
    return sqrt(rms/n);
}
