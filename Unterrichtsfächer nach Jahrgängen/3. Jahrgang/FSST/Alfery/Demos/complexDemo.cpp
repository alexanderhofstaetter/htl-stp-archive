
/* ---------------------------------------------------------------------
	program name  :   complexDemo.cpp
	autor         :   Prof.W.ALFERY

	Themen 	      :   Verwendung der C++-Bibliothek  complex  
	                  zur Verarbeitung von komplexen Zahlen verwenden

  ----------------------------------------------------------------------
*/
//----------------------------------------------------------------------
//                       Include Dateien
   #include <stdio.h>
   #include <iostream>
   #include <string.h>
   #include <complex>

   using namespace std;


//-----------------------------------------------------------------------
//                       Hauptprogramm

 int main()
 {  int i,anz;
   
	complex<float> z1(1.0,1.0),z2(-1.0,1.0),z3;     // Template typisieren

    system("CLS");
	cout << "\n                    Komplexe Rechnung  ";
	cout << "\n                    mit der Bibliothek complex ";

	cout << "\n\n komplexe Zahlen : ";
	cout << "\n z1:" << z1;
	cout << "\n z2:" << z2;

	cout << "\n\n Real- u.Imaginaerteil : ";
	cout << "\n z1 - real :" << z1.real();
	cout << "\n z1 - imag :" << z2.imag();

	cout << "\n\n Addition z3=z1+z2 : ";
	z3=z1+z2;
	cout << "\n z3:" << z3;

	cout << "\n Subtraktion z3=z1-z2 : ";
	z3=z1-z2;
	cout << "\n z3:" << z3;

    cout << "\n Multiplikation z3=z1*z2 : ";
	z3=z1*z2;
	cout << "\n z3:" << z3;

    cout << "\n Division  z3=z1/z2 : ";
	z3=z1/z2;
	cout << "\n z3:" << z3;

    cout << "\n Wurzel z3=sqrt(z1) : ";
	z3=sqrt(z1);	
    cout << "\n z3:" << z3;

	system("PAUSE");
    return 0;
 }





