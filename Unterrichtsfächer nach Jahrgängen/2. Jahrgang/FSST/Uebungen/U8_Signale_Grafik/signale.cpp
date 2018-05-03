#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

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
        else if(a[i] >= 0) a[i] = am;
    }
}

void array_impuls(float a[], int n, float am, float az)
/////////////////////////////////////////////////////////////////////////////
//   Impulssamples dem Feld a[] zuweisen
//        mit Amplitude am und Auschaltzeit az
//   Import : int n      ...  Feldgröße
//            float am   ...  Amplitude
//            float az   ...  Frequenzvielfaches
//   Export : float a[i] ...  Feld
//
///////////////////////////////////////////////////////////
{
    int auschaltpunkt = n*az/100;           // Auschaltzeitpunkt berechnen
    for(int i = 0; i < n; i++)
        a[i] = 0;                           // Array 0 zuweisen
    for(int i = 0; i < auschaltpunkt; i++)
        a[i] = am;                          // Array bis zum AZP Werte zuweisen
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

float array_ss ( float a[], int n1 , int n2 )
/////////////////////////////////////////////////////////////////////////////
//   Spitze-Spitze-Wert der Feldelemente des Arrays a berechnen
//   von Index n1 bis Index n2
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Spitze-Spitze-Wert
//
///////////////////////////////////////////////////////////
{
    return sqrt(array_max(a,n1,n2)*array_max(a,n1,n2)) + sqrt(array_min(a,n1,n2)*array_min(a,n1,n2));
}

float array_rms ( float a[], int n )
/////////////////////////////////////////////////////////////////////////////
//   RMS-Wert ( echter Effektivwert ) der Feldwerte berechnen
//   RMS  =  Wurzel aus dem Mittelwert der Quadrate der Signalwerte (Feldelemente)
//   Import : float a[i] ...  Feld
//            int n      ...  Feldgröße
//   Export : float      ...  Effektivwert
//
///////////////////////////////////////////////////////////
{   float rms = 0;
    for (int i = 0; i < n; i++)
        rms = rms + a[i]*a[i];
    return sqrt(rms/n);
}
