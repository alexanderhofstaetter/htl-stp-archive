/////////////////////////////////////////////////////////////////////////////
//   Programmname : rechner-c.c
//
//   Autor   :  A.Hofstätter
//   Datum   :  07.10.2011
//   Version :  1
//
//   Aufgabe :  Rechner mit printf, scanf
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>                  //  für getch()

 #define ESC 27                      //  ESC - Ersatztext definieren


/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{
   char antwort;
   int menue;
   int x1,x2,y;
   float z;

    do
{

       system("CLS");

       printf ("    /////////////////////////////////////////////////////////  \n");
       printf ("    //                    Rechner-c                        //  \n");
       printf ("    //                   ~~~~~~~~~~~                       //  \n");
       printf ("    //                 Alex Hofstaetter                    //  \n");
       printf ("    /////////////////////////////////////////////////////////  \n");

//////////////////////////////////////////////////////////////////////

       printf ("  x1 =");                             // Ausgabe mit printf
       scanf ("%d",&x1);                              // Eingabe scanf

       printf ("  x2 =");
       scanf ("%d",&x2);

//////////////////////////////////////////////////////////////////////

       printf("\n\n");
       printf ("1 -> Summe \n");
       printf ("2 -> Differenz \n");
       printf ("3 -> Produkt \n");
       printf ("4 -> Quotient \n");
       printf("\n");
       printf ("Bitte auswaehlen 1,2,3 oder 4 \n");
       menue = getch ();
       printf("\n\n");

//////////////////////////////////////////////////////////////////////

       if(menue=='1')                                 // If-Abfrage
       {
            y = x1 + x2;
            printf (" Summe   =  %d  \n",y);             // Addition
       }

       if(menue=='2')
       {   y = x1 - x2;
           printf (" Differenz   =  %d  \n",y);         // Subtraktion
       }

       if(menue=='3')
       {   y = x1 * x2;
           printf (" Produkt   =  %d  \n",y);           // Multiplikation
       }

       if(menue=='4')
       {    y = x1 / x2;
            printf (" ganzzahl Quotient   =  %d  \n",y);          // ganzahlige Division

            y = x1 % x2;
            printf (" ganzzahliger Rest   =  %d  \n",y);          // ganzzahliger Rest

            z = (float) x1 / x2;
            printf (" Gleitkommaquotient   =  %f  \n",z);         // Gleitkomma Division
       }

//////////////////////////////////////////////////////////////////////

       printf("\n\n\n\n");
	   printf(" Rechner neustarten mit  [Esc]      ");
       antwort=getch();

//////////////////////////////////////////////////////////////////////
}
    while (antwort!=ESC);

   return 0;

}

//////////////////////////////////////////////////////////////////////

