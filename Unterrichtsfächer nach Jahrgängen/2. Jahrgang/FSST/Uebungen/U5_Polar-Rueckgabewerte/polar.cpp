/////////////////////////////////////////////////////////////////////////////
//   Programmname : ampel1.cpp
//   das folgende Funktionen mit Rückgabewert definiert
//   Polarkoordinate Betrag   ( z = Wurzel(x²+y²) )
//   Polarkoordinate Winkel   ( phi = Arctan (y/x) )
//   in allen 4.Quadranten gültig !
//   x-Koordinate    ( x = betrag*cos(phi) )
//   y-Koordinate    ( y = betrag*sin(phi) )
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "bse_console.h"


using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Funktionsprototypen
/////////////////////////////////////////////////////////////////////////////

float winkel(int x1, int y1);
float betrag(int x1, int y1);
float x_kor(float betrag_z, float phi1);
float y_kor(float betrag_z, float phi1);

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
    char key;
    float f,c,l,r,z_j,z_c,z_l,w;
    do
    {
        clrscr();
        printf(" Komplexe Serienschaltung\n");
        printf(" ::::::::::::::::::::::::\n");
        printf(" Frequenz [Hz]: "); cin >> f;
        printf(" Widerstand [Ohm]: "); cin >> r;
        printf(" Spule [mH]: "); cin >> l; l*=0,001;
        printf(" Kondensator [uF]: "); cin >> c; c*=0,000001;

        w=2*M_PI*f;
        z_c=1/(w*c);
        z_l=w*l;
        z_j=z_c+z_l;

        printf("Z = %f + j%f\n\n",r,z_l);

        printf(" [1] Kartesische Koordinaten auf Polar Koordinaten\n");

        printf(" [1] Kartesische Koordinaten auf Polar Koordinaten\n");
        printf(" [2] Polar Koordinaten auf Kartesische Koordinaten\n\n");
        key = getch();
        float x,y,z,phi;

        if (key == '1')
        {
            printf(" X-Koordinate = "); cin >> x;
            printf(" Y-Koordinate = "); cin >> y;
            printf("\n Betrag z   = %.2f",betrag(x,y));
            printf("\n Winkel Phi = %3.2f Grad",winkel(x,y)*180/M_PI);
            key == getch();
        }
        else if (key == '2')
        {
            printf(" Betrag     = "); cin >> z;
            printf(" Winkel Phi = "); cin >> phi;
            printf("\n X-Koordinate = %.4f",x_kor(z,phi*M_PI/180));
            printf("\n y-Koordinate = %.4f",y_kor(z,phi*M_PI/180));
            key == getch();
        }

    }
    while(key != 27);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

float winkel(int x1, int y1)
/////////////////////////////////////////////////////////////////////////////
//   Betrag
//   Import : int x     ... X - Koordinate
//            int y     ... Y - Koordinate
//   Export : float     ... Winkel Phi
/////////////////////////////////////////////////////////////////////////////
{
    return atan2(y1,x1);
}

float betrag(int x1, int y1)
/////////////////////////////////////////////////////////////////////////////
//   Betrag
//   Import : int x     ... X - Koordinate
//            int y     ... Y - Koordinate
//   Export : float     ... Betrag
/////////////////////////////////////////////////////////////////////////////
{
    return sqrt(x1*x1+y1*y1);
}

float x_kor(float betrag_z, float phi1)
/////////////////////////////////////////////////////////////////////////////
//   X-Koordinate
//   Import : int z     ... betrag
//            int phi1  ... Winkel Phi
//   Export : float     ... X - Koordinate
/////////////////////////////////////////////////////////////////////////////
{
    return betrag_z*cos(phi1);
}

float y_kor(float betrag_z, float phi1)
/////////////////////////////////////////////////////////////////////////////
//   Y-Koordinate
//   Import : int z     ... betrag
//            int phi1  ... Winkel Phi
//   Export : float     ... Y - Koordinate
/////////////////////////////////////////////////////////////////////////////
{
    return betrag_z*sin(phi1);
}
