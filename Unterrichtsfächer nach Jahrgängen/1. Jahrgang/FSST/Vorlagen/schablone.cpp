/////////////////////////////////////////////////
//   Programmname : Schablone.cpp
//   Autor   : Wolfgang Alfery
//   Datum   : 14.09.2011
//   Version : 1
//   Aufgabe : C++ Programm Schablone
/////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>

using namespace std;
int a = 141;
int b = 565;


/////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////

int main()
{
    cout << "Hello world!" << endl;
    printf(" a: %4d  b: %4d \n",a,b);
    a=a^b;
    b=b^a;
    a=a^b;
    printf(" a: %4d  b: %4d \n",a,b);
    system("PAUSE");
    return 0;

}
