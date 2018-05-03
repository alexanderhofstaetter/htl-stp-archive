/////////////////////////////////////////////////////////////////////////////////////////////
//
//           Programmname : Schablone.cpp
//           Autor : Alexander Hofstätter
//           Datum : 2011-09-27
//           Version : 1
//           Aufgabe : C++ Programm
//                     Rechner für Addition, Subtraktion,
//                     Multiplikation, Division
//
///////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

		int y,x1,x2;           													// Variablen Definition
		float z;            												    // Gleitkomma Variablen Definition


			cout << "    /////////////////////////////////////////////////////////" << endl;
            cout << "    //                    Rechner-cpp                      //" << endl;
            cout << "    //                    ~~~~~~~~~~                       //" << endl;
            cout << "    //                  Alex Hofstaetter                   //" << endl;
            cout << "    /////////////////////////////////////////////////////////" << endl;
            cout << endl << endl;



        cout << " Eingabe x1= ";                   						// Eingabe Auforderung
        cin >> x1;                                  					// Einlesen über Tastatur

        cout << " Eingabe x2= ";
        cin >> x2;

            cout << endl << endl;




            y= x1 + x2;
            cout << " Summe= " << y << endl;                                // Addition

            y= x1 - x2;
            cout << " Differenz= " << y << endl;                            // Subtraktion

            y= x1 * x2;
            cout << " Produkt= " << y << endl;                              // Divison

            y= x1 / x2;
            cout << " ganzzahl Division= " << y << endl;                    // ganzzahl Division

            y= x1 % x2;
            cout << " ganzzahlliger Rest= " << y << endl;                   // ganzzahliger Rest

            z=  (float) x1 / x2;
            cout << " Gleitkomma Quotient= " << z << endl;                  // Gleitkomma Quotient





            cout << endl << endl;
            cout << endl << endl;


            cout << "Summe: ";
            for (int i=1;i<x1+x2+1; i++)                                      // Schleife Summe
                {   cout << "*";  }

            cout << endl << endl;
            cout << endl << endl;


            cout << "Produkt: ";
            for (int i=1;i<x1*x2+1; i++)                                      // Schleife Produkt
				{   cout << "*";  }

			cout << endl << endl;
            cout << endl << endl;


            cout << "Quotient: ";
            for (int i=1;i<x1/x2+1; i++)                                      // Schleife Produkt
				{   cout << "*";  }



            cout << endl << endl;
            cout << endl << endl;


    //system("PAUSE");
    //return 0;
}

