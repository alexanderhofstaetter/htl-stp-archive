/////////////////////////////////////////////////////////////////////////////
//   Programmname : cstrings.cpp
//
//   Aufgabe : Beispiele mit C-Strings
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string.h>                         // C-String Bibliothek

using namespace std;


int charsearch(char *s,char c)
{
    int i;
    int z=0;
    for(i=0;s[i];i++)
    {
        if(s[i]==c)
        {
            z++;
        }
    }
    return z;
}

int charreplace( char *s, char search, char replace )
{
    int i;
    int z=0;
    for(i=0;s[i];i++)
    {
        if(s[i]==search)
        {   s[i] = replace;
            z++;
        }
    }
    return z;
}

typedef char string100[101];
string100 text;


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
 {
   char such, ersatz, trenn;
   int anzahl;

   printf("\n\n Text = ");
   scanf("%s",text);                          // String einlesen

   printf("\n\n Suchzeichen = ");
   fflush(stdin);
   scanf("%c",&such);

   anzahl=charsearch(text,such);
   printf("Anzahl= %d",anzahl);



   return 0;
 }
