/////////////////////////////////////////////////////////////////////////////
//   Programmname : summe.cpp
//
//   Autor   :  A. Hofstätter
//   Datum   :  02.11.2011
//   Version :  1
//
//   Aufgabe : C/C++ - Aufgabe 8c
/////////////////////////////////////////////////

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;


/////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////

int main()
{




    int sum,n,d,i;
    float sumg,mittel,x;

    printf(" Summenausgabe der ganzen Zahlen 1 bis n: \n");
    printf(" n = ");
    scanf ("%d",&n);
    sum=0;
    for (int i=1; i<=n; i++)
    {
        sum = sum + i;
    }
    printf("\n Summe = %d\n\n",sum);

    printf(" Summenausgabe der geraden Zahlen 1 bis n: \n");
    sum=0;
    for (i=0; i<=n; i=i+2)
    {
        sum = sum + i;
    }
    printf(" Summe = %d\n",sum);

    printf("\n Summenausgabe der unganzen Zahlen 1 bis n: \n");
    sum=0;
    for (int i=1; i<=n; i=i+2)
    {
        sum = sum + i;
    }
    printf(" Summe = %d\n\n",sum);

    printf(" Mittelwert beliebiger Float Zahlen \n");
    printf(" Anzahl der Gleitkommazahlen = ");
    scanf ("%d",&n);
    sumg=0;
    for ( i=1;i<=n;i++ )
    {
        printf("\n %2d-ter Wert = ",i);
        scanf ("%f",&x);
        sumg=sumg+x;
    }
    mittel=sumg/n;
    printf(" Mittelwert = %6.2f \n\n\n",mittel);


    sum=0;
    do
    {
        printf("\n i = ",i);
        scanf ("%f",&d);
        sum=sum+d;
        printf(" Summe = %4d \n\n",sum);
        i++;
    }while (sum<=100);

    system("PAUSE");
    return 0;


}
