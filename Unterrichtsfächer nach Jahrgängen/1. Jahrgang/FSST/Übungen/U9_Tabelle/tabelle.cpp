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
 #include <iostream>

 using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   int i,r,u,y,j;
   const int i_max = 10;
   const int r_max = 10;
   u=2;

   for ( r=1;r<=r_max;r=r+1 ) 	      // Hauptschleife für Höhe y
   {
      printf("%2d",r);
      if (u<2);
      {
          printf("|");
      }


     /* for ( y=1;y<=i_max;y++ )
      {
          printf("%2d",r);
          printf("-");
      }*/

      for ( i=1;i<=i_max;i=i+1 ) 	  // Unterschleife für Breite x
      {
          printf("%2d",r);
          u=r*i;
          printf("%4d",u);
      }
      printf("\n");

   }

   /*printf("\n\n 2) Zahlen - Quadrat : \n");

   for ( j=1;j<=l;j=j+1 ) 	      // Hauptschleife für Höhe x2
   {
      for ( i=1;i<=l;i=i+1 ) 	  // Unterschleife für Breite x2
      {  cout << j;               // Zahl ausgeben
      }
      printf("\n");
   }

   printf("\n\n 3) Zahlen- Dreieck \n");

   for ( j=1;j<=l;j=j+1 ) 	      // Hauptschleife für Höhe y
   {
      for ( i=1;i<=j;i=i+1 ) 	  // Unterschleife für Breite x
      {  cout << i;
      }
      printf("\n");
      i=1;
   }

   printf("\n\n 4) Baum \n");
   printf("\n Zeichen = ");
   char zeichen;
   cin >> zeichen;
   for(int i=l/2-1,j=1;i>=0;i--,j+=2)
    {
        for(int f=0;f<l;f++)
        {
            if(f<=i)
            {
                cout << " ";
            }
            else if(f<=i+j)
            {
                cout << zeichen;
            }
            else
            {
                cout << " ";
            }
        }
        printf("\n");

    }




   */
   printf("\n\n");
   system("PAUSE");
   return 0;

}

