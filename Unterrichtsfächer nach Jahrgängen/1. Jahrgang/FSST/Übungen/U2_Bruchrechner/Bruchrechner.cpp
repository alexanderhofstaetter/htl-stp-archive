/////////////////////////////////////////////////////////////////////////////
//   Programmname : bruch.cpp
//
//   Autor   :  A. Hofstätter
//   Datum   :  11.10.2011
//   Version :  1
//
//   Aufgabe :  Bruchrechnung mit Menü-Verzweigung
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>                  //  für printf(), scanf()
 #include <stdlib.h>                 //  für system()
 #include <conio.h>                  //  für getch()

 #define ESC 27                      //  ESC - Ersatztext definieren


/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()

{  char antwort;
   int menue;
   int z1,z2,z,n,n1,n2;
   float y;
   char close;

   do                                  // Wiederholung mit do-while-Schleife
{


       //antwort=getch();
       system("CLS");

       printf ("     /////////////////////////////////////////////////////////  \n");
       printf ("     //                   Bruchrechner                      //  \n");
       printf ("     //                   ~~~~~~~~~~~                       //  \n");
       printf ("     //                 Alex Hofst\x84tter                     //  \n");
       printf ("     /////////////////////////////////////////////////////////  \n");

       printf ("\n\n");
       printf ("Bitte w\x84hlen Sie eine entsprechende Option. \n");
       printf ("\n");
       printf ("   [1] ... Eingabe der Bruchzahlen \n");
       printf ("   [2] ... Bruchaddition  \n");
       printf ("   [3] ... Bruchsubtraktion \n");
       printf ("   [4] ... Bruchmultiplikation \n");
       printf ("   [5] ... Bruchdivision \n");
       printf ("   [ESC] ... Programmende \n");


       printf("\n\n");

       if(antwort=='1')                                 // If-Abfrage
       {
           printf ("  z1 =");                             // Ausgabe mit printf
           scanf ("%d",&z1);                              // Eingabe scanf

           printf ("  n1 =");
           scanf ("%d",&n1);

           printf ("  z2 =");
           scanf ("%d",&z2);

           printf ("  n2 =");
           scanf ("%d",&n2);

           printf("\n\n");
       }

       if(antwort=='2')
       {   z = z1+z2;
           n = n1*n2;
           y = (float)z/n;
           printf (" Bruchaddition  =  %d",z);            // Bruchaddition
           printf ("/");
           printf ("%d \n",n);
           printf (" Gleitkommaddition  =  %f",y);        // Gleitkommaaddition
       }

       if(antwort=='3')
       {   z = z1-z2;
           n = n1*n2;
           y = (float)z/n;
           printf (" Bruchsubtraktion  =  %d",z);         // Bruchsubtraktion
           printf ("/");
           printf ("%d \n",n);
           printf (" Gleitkommaddition  =  %f",y);        // Gleitkommaaddition
       }

       if(antwort=='4')
       {   z = z1*n2;
           n = n1*z2;
           y = (float)z/n;
           printf (" Bruchmultiplikation  =  %d",z);         // Bruchmultiplikation
           printf ("/");
           printf ("%d \n",n);
           printf (" Gleitkommamultiplikation  =  %f",y);        // Gleitkommaaddition
       }

       if(antwort=='5')
       {   z = z1/z2;
           n = n1/n2;
           y = (float)z/n;
           printf (" Bruchdivision  =  %d",z);         // Bruchdivision
           printf ("/");
           printf ("%d \n",n);
           printf (" Gleitkommadivision  =  %f",y);        // Gleitkommadivision
       }

       //printf("\n\n\n\n");
       antwort=getch();
       //printf(" Rechner neustarten mit  [Esc]      ");
       close=getch();


   } while (close!=ESC);
    return 0;
}


