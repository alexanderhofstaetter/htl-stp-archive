/*
 OOP_dyn
_____________________________________________________________________________

Allgemein :
-----------------------------------------------------------------------------

Übungsaufgabe :  Klassendefinition, Konstruktoren, Instanzen

---------------------------------------------------------------------------

1)  Erstelle eine Klasse  "Person"
    mit den Datenelementen :  Name,alter,beruf, ...
    und den Methoden       :  eingabe();ausgabe();
    Erstelle die berladenen Konstruktoren :
    Person(); Person(char *n); Person(char* n,int a,char *b);
    Erzeuge zu diesen Klassen über die Konstruktoraufrufe
    mehrere Instanzen und verwende die Methoden dieser Objekte.


Zusatzaufgabe :

Die Aufgabe ist über ein Projekt zu erstellen.
Die Programmaufteilung ist so auszuführen, dass für jede Klassendefinition
eine eigene Headerdatei und für die externen Klassendefinitionen
eine gleichnamige CPP-Datei erstellt wird.

*/

//----------------------------------------------------------------------
//                       Include Dateien
   #include <stdio.h>
   #include <iostream>
   #include <string.h>

   using namespace std;

//----------------------------------------------------------------------
//                       Klassendeklaration

class  Person 			     //  Klasse  Person ---------------------
{
	public:                  // Datenelemente
	  char name[81];
	protected:
	  int alter;
	private:
	  char beruf[81];

	public:
	  Person()                  // Konstruktoren
      { strcpy(this->name,"noname");
        this->alter=0;
        strcpy(this->beruf,"");
      }

	  Person(char *name,int alter,char *beruf)
	  { strcpy(this->name,name);
        this->alter=alter;
        strcpy(this->beruf,beruf);
      }

      ~Person()
      {
         cout << " Destruktor von "<< name << endl;
      }

      void eingabe();          // Methoden
	  void ausgabe();
      void setName(char *name);

};


void Person::eingabe()       // externe Methoden-Definitionen
{  cout << "\n Name  = "; cin >> name;
   cout << " Alter = "; cin >> alter;
   cout << " Beruf = "; cin >> beruf;
}

void Person::ausgabe()
{  cout << name << "," << alter << "," << beruf;
}

void Person::setName(char *name)
{  strcpy(this->name,name);
}

//-----------------------------------------------------------------------
//                       Hauptprogramm
int main()
{
   Person *p,*liste;            // Zeiger auf Klasse Person

//   system("CLS");
   cout << endl << "  dynamische Personen  ";
   cout << endl << "  Bjarne :  ";

     p = new Person("Bjarne",25,"Softwareentwickler");
     p->ausgabe();

    {
       cout << " Person p1" << endl;
       Person p1("test",0,"");

       p1.ausgabe();

    }

   int n=3;
   char namen[10]="abcdefg";
   cout << endl << "  Liste :  ";
   liste = new Person[n];
   for (int i=0;i<3;i++)
   {  liste[i].setName(namen+i);
      cout << endl << i+1 << ". ";
      liste[i].ausgabe();
   }

   delete []liste;
   cout << endl << endl;
//   system("PAUSE");
}

