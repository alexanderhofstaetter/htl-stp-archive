#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <math.h>

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
{   float mittel = 0;
    for(int i = n1; i < n2; i++)
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
    for (int i = n1; i < n2; i++)
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
    for (int i = n1; i < n2; i++)
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

float array_rms ( float a[], int n1, int n2 )
/////////////////////////////////////////////////////////////////////////////
//   RMS-Wert ( echter Effektivwert ) der Feldwerte berechnen
//   RMS  =  Wurzel aus dem Mittelwert der Quadrate der Signalwerte (Feldelemente)
//   Import : float a[i] ...  Feld
//            int n1     ...  Index 1
//            int n2     ...  Index 2
//   Export : float      ...  Effektivwert
//
///////////////////////////////////////////////////////////
{   float rms = 0;
    for (int i = n1; i < n2; i++)
        rms = rms + a[i]*a[i];
    return sqrt(rms/(n2+1-n1));
}
