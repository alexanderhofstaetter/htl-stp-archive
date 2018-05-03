/////////////////////////////////////////////////////////////////////////////
//   Programmname  : figuren.cpp
//   Programmierer : w.alfery
//   Datum         :
//
//   Aufgabe :  Figuren über geschachteltete Schleifen
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  für printf(), scanf()
 #include <stdlib.h>                 //  für system()
 #include <conio.h>                  //  für getch()


 using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   int i,j,x,y;

   printf(" Figuren \n\n");
   printf(" 1) Rechteck : \n");

   x=10;
   y=5;

   for ( j=1;j<=y;j=j+1 ) 	      // Hauptschleife für Höhe y
   {
      for ( i=1;i<=x;i=i+1 ) 	  // Unterschleife für Breite x
      {  printf("%c",(char) 254);
      }
      printf("\n");
   }


   printf("\n\n");
   system("PAUSE");
   return 0;

}

