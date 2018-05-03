/////////////////////////////////////////////////////////////////////////////
//   Programmname : schleifen.cpp
//
//   Autor   :  A. Hofstätter
//   Datum   :  07.10.2011
//   Version :  1
//
//   Aufgabe : C++ Schleifen - Prog7e
/////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
    int i,n1;
    float x,x1,x2,xinc;
    int i;
    cout << endl << " Ausgabe der Zahlen von 1 bis 10 mit 3 Schleifen: ";
    cout << endl << " 1) mit der for- schleife       : ";       //Mit einer for-Schleife
    for ( i=1; i<=10; i=i+1 )
       cout << setw(3) << i ;

    cout << endl << " 2) mit der while- schleife     : ";       //Mit einer while-Schleife
    i=1;
    while(i<=10)
    {   cout << setw(3) << i ;
        i++;
    }

    cout << endl << " 3) mit der do-while- schleife  : ";       //Mit einer do-while-Schleife
    i=1;
    do
    {   cout << setw(3) << i;
        i++;
    }
    while(i<=10);


///////////////////////////////////
    printf("\n\n n1= ");
    cin >> n1;
    cout << endl << "\n Alle geraden Zahlen von 0 bis n1 : \n\n";
    i=0;
    while(i<=n1)
    {
        cout << setw(4) << i ;
        i=i+2;
    }

//////////////////////////////////////
    cout << endl << "\n Alle ungeraden Zahlen von 1 bis n1 : \n\n";
    i=1;
    while(i<=n1)
    {
        cout << setw(4) << i ;
        i=i+2;
    }

//////////////////////////////

    cout << endl << "\n Ausgabe von -1 bis +1 mit der Erhoehung 0.1\n\n";
    cout.precision(1);
    x=-1;
    for (x=-1; x<=1; x=x+0.1)
    {
        cout << setw(6) << x ;
    }
//////////////////////////////////

    cout << endl << "\n Ausgabe von x1 bis x2 mit der Erhoehung xinc\n\n";

    printf("\n x1= ");
    cin >> x1;
    printf("\n x2= ");
    cin >> x2;
    printf("\n xinc= ");
    cin >> xinc;

    for (x=x1; x<=x2; x=x+xinc)
    {
        cout << setw(4) << x;
    }

    printf("\n\n\n Eingabewiederholung bis x im Bereich von x1 bis x2 liegt.");

    printf("\n Bitte x1 eingeben. x1 = ");
    cin >> x1;
    printf("\n Bitte x2 eingeben. x2 = ");
    cin >> x2;
    printf("\n Bitte x eingeben. x = ");
    cin >> x;
    int ok;
    do
    {
        if(x>=x1 && x<=x2)
        {
            cout << " Eingabe in Ordnung!";
            cout << x << " liegt zwischen " << x1 << " und " << x2 << endl;
            ok=1;
        }
        else
        {
            printf(" x ist nicht liegt nicht zwischen x1 und x2");
            printf("\n Bitte x erneut eingeben. x = ");
            cin >> x;
            ok=0;
        }

    }
    while(!ok);

    cout << endl << endl << endl;
    system("PAUSE");
    return(0);

}

