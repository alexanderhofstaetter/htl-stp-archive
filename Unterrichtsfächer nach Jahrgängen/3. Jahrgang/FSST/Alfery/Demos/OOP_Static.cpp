/* ---------------------------------------------------------------------
	program name  :   Static.cpp
	Autor         :   Prof.W.ALFERY

	Themen 		  :   static Elemente

  ----------------------------------------------------------------------
*/
//----------------------------------------------------------------------
//                       Include Dateien
   #include <stdio.h>
   #include <iostream>
   #include <math.h>

using namespace std;

//----------------------------------------------------------------------
//

class  teilnehmer    				 //  Klasse  teilnehmer --------
{
    private:
		static int anzahl;           //  static Datenelement

    public:
        int nummer;

		teilnehmer(int nr)           //  Konstruktor
		{  nummer=nr;
		   anzahl++;                 //  zählt anzahl weiter
		}

		static int zahl()            //  static  Funktion
        {  return anzahl;
        }

};

int teilnehmer::anzahl=0;            //  static Element initialisieren !

//-----------------------------------------------------------------------
//                       Hauptprogramm

int main()
{  int i,anz;
   teilnehmer p1(1),p2(2),p3(3);

   cout << endl << "  Static Elemente  " << endl;
   cout << endl << "  es gibt 3 Teilnehmer --- ";
   cout << endl << "  Teilnehmer Nummer = " << p1.nummer;
   cout << " Anzahl = " << p1.zahl();
   cout << endl << "  Teilnehmer Nummer = " << p2.nummer;
   cout << " Anzahl = " << p2.zahl();
   cout << endl << "  Teilnehmer Nummer = " << p3.nummer;
   cout << " Anzahl = " << p3.zahl() << endl;


   teilnehmer p4(4);

   cout << endl << "  es wird ein neuer Teilnehmer definiert  --- ";
   cout << endl << "  Teilnehmer Nummer = " << p4.nummer;
   cout << " Anzahl = " << p4.zahl() << endl << endl;

   // static Funktionen können auch direkt aufgerufen werden
   // ( ohne Instanz über die Bereichsangabe der Klasse )
   cout << "  static-Funktionsaufruf ueber Scopeangabe der Klasse --- " << endl;
   cout << "  Anzahl = " << teilnehmer::zahl();

   cout << endl << endl;
   system("PAUSE");
 }
