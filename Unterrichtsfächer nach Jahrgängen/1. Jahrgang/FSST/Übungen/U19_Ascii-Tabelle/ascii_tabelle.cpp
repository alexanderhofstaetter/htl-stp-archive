/////////////////////////////////////////////////////////////////////////////
//   Programmname  : ascii-tabelle.cpp
//   Programmierer : A. Hofstätter
//   Datum         : 27.03.12
//
//   Aufgabe :  Tabelle
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  für printf(), scanf()
 #include <stdlib.h>                 //  für system()
 #include <conio.h>                  //  für getch()
 #include <iostream>

 using namespace std;


/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   int x,a,b,c;
   c=32;
   char key,typ;

   printf("  | 0 1 2 3 4 5 6 7 8 9 A B C D E F \n");
   printf("----------------------------------- \n");
   printf(" 0|\n");
   printf(" 1|\n");

   for ( a=2; a<=15; a++ )
   {
       printf("%2X|",a);
       b=c+15;
       for( c=c; c<=b; c++ ) 	      // Hauptschleife für Spalten
       {
           printf("%2c",c);
       }
       printf("\n");
   }

   do
   {
       printf("\nChar-Variable: ");
       key=getch();
       printf("\n\n");
       printf("Zeichen: %c   Dez: %3d   Hex: 0x%3X   Zeichentyp: ",key,key,key);
       if (key>=0x30 && key<=0x39 )
       {
           printf("Ziffer\n");
       }
       else if (key>=0x41 && key<=0x5A )
       {
           printf("Groszbuchstabe\n");
       }
       else if (key>=0x61 && key<=0x7A )
       {
           printf("Kleinbuchstabe\n");
       }
       else
       {
           printf("Sonderzeichen\n");
       }

   }while(key!=27);

   printf("\n\n");
   system("PAUSE");
   return 0;

}

