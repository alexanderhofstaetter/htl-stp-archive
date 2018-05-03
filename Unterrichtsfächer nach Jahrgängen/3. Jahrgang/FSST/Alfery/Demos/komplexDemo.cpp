
/* ---------------------------------------------------------------------
	program name  :   komplexDemo.cpp
	autor         :   w.alfery

	Themen 	      :   eigene Klasse - komplex
	                  für die Verarbeitung von komplexen Zahlen
	                  und Berechnung mit den Operatoren +,-,*,/
  ----------------------------------------------------------------------
*/
//----------------------------------------------------------------------
//                       Include Dateien
   #include <stdio.h>
   #include <stdlib.h>
   #include <iostream>
   #include <string.h>
   #include <math.h>

using namespace std;

//----------------------------------------------------------------------
//                       Klassendeklaration

class komplex
{	public:
		float re,im;                                // Datenelemente
	public:
		komplex(float real,float imag)              // Konstuktoren
		{ re=real;im=imag;
		}
		komplex()
        {  re=0;im=0;
        }

		float real();                               // Realteil
		float imag();                               // Imaginärteil
		float betrag();                             // Betrag
		float phase();                              // Phase
		komplex conj();                             // konjugiert komplex
		komplex polar(float betrag,float phase );   // Polar zu Komponenten

		komplex operator+=(komplex &);              // Überladene Operatoren
		komplex operator-=(komplex &);              // mit einem Parameter

		friend komplex operator+(komplex &, komplex &);  // Überladene Operatoren
		friend komplex operator-(komplex &, komplex &);  // mit zwei Parametern
		friend komplex operator*(komplex &, komplex &);  // als friend-functions
		friend komplex operator/(komplex &, komplex &);
		friend int     operator==(komplex &, komplex &);
		friend int     operator!=(komplex &, komplex &);

};


//-----------------------------------------------------------------------
//                       externe Methoden Definitionen


	 inline float komplex::betrag()
	 {  return sqrt(re*re+im*im);
	 }

	 inline float komplex::phase()
	 {  return atan2(im,re)*180/M_PI;
	 }

	 inline komplex komplex::operator+=(komplex &z)    // Operator +=
	 {  re+=z.re;im+=z.im;
			return *this;
	 }

	 inline komplex operator+(komplex &z1, komplex &z2)// Operator +
	 {  return komplex(z1.re+z2.re,z1.im+z2.im);
	 }


//-----------------------------------------------------------------------
//                       Hauptprogramm

 int main()
 {  int i,anz;

	komplex z,z1(1.0,1.0),z2(-1.0,1.0);

    system("CLS");
	printf("\n                    Komplexe Rechnung  ");
	printf("\n                    so macht's Spass   ");

	printf("\n\n komplexe Größen  z1,z2 ");
	printf("\n  z1.re  =  %8.4f ",z1.re);
	printf("\n  z1.im  =  %8.4f ",z1.im);
	printf("\n  z2.re  =  %8.4f ",z2.re);
	printf("\n  z2.im  =  %8.4f ",z2.im);

	printf("\n\n Addition z1+= z2  ");
	z=z1; z1+=z2;
	printf("\n  z1.re  =  %8.4f ",z1.re);
	printf("\n  z1.im  =  %8.4f ",z1.im);

	printf("\n\n Addition z = z1 + z2  ");
	z1=z;
	z=z1+z2;
	printf("\n  z.re   =  %8.4f ",z.re);
	printf("\n  z.im   =  %8.4f ",z.im);
	printf("\n\n");

    system("PAUSE");
    return 0;

 }





