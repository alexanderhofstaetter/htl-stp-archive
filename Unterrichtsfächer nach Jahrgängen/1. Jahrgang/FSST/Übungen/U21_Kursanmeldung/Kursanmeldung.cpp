/////////////////////////////////////////////////////////////////////////////
//   Programmname : Kursanmeldung_1BHEL_10.cpp
//
//   Autor   :  A. Hofstätter
//   Datum   :  07.11.2011
//   Version :  1
//
//   Aufgabe :  Erstelle das C/C++ Programm "Kursanmeldung_klasse_katnr.cpp"
//              zur sErfassung und Bewertung von Prüfungen.
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Headerdateien
/////////////////////////////////////////////////////////////////////////////

 #include <iostream>
 #include <stdio.h>                  //  für printf(), scanf()
 #include <stdlib.h>                 //  für system()
 #include <conio.h>                  //  für getch()
 #include <string>
 #include <windows.h>

 using namespace std;

 #define ESC 27                      //  ESC - Ersatztext definieren


/////////////////////////////////////////////////////////////////////////////
//    Hauptprogramm
/////////////////////////////////////////////////////////////////////////////

int main()
{  char key,menue;
   char name[30],vorname[30],klasse[30];
   int monat,tag,jahr,punktezahl,KATNR;
   int KATNR_MAX=24;
   do                                  // Wiederholung mit do-while-Schleife
{


       //menue=getch();
       system("CLS");

       printf ("     /////////////////////////////////////////////////////////  \n");
       printf ("     //                  Kursanmeldung                      //  \n");
       printf ("     //                   ~~~~~~~~~~~                       //  \n");
       printf ("     //                 Alex Hofstaetter                    //  \n");
       printf ("     /////////////////////////////////////////////////////////  \n");

       printf ("\n\n");
       printf ("Bitte w\x84hlen Sie eine entsprechende Option. \n");
       printf ("\n");
       printf ("   [1] ... Erfassung \n");
       printf ("   [2] ... Pruefung  \n");
       printf ("   [3] ... Bestaetigung \n");
       printf ("   [ESC] ... Programmende \n");



       printf("\n\n");

       if(menue=='1')                                    // Einlesen in alle Werte: Vorname, Name, Klasse, Katalognummer, Datum
       {
           cout << "  Vorname = ";
           cin >> vorname;
           cout << endl;

           printf ("  Name = ");
           cin >> name;
           cout << endl;

           printf ("  Klasse = ");
           cin >> klasse;
           cout << endl;

           printf ("  Katalognummer = ");
           cin >> KATNR;
           cout << endl;
           do                       // Prüft ob Katalognummer ungültig
           {   printf(" Ungueltige Katalognummer (1-%d)\n\n",KATNR_MAX);
               printf("  Katalognummer = ");
               cin >> KATNR;
               cout << endl;
           } while (KATNR <= 0 || KATNR > KATNR_MAX);


           printf ("  Pruefungsdatum TT.MM.JJ\n\n");
           printf ("  Tag = ");
           cin >> tag;
           cout << endl;

           do                                             // Prüft ob Tag Ungültig
           {
               printf(" Ungueltiger Tag (1-31)\n\n");
               printf ("  Tag = ");
               cin >> tag;
               cout << endl;
           } while (tag <= 0 || tag > 31);


           printf ("  Monat = ");
           cin >> monat;
           do                                             // Prüft ob Monat Ungültig
           {   if (monat <= 0 || monat > 12)
               {
               printf(" Ungueltiges Monat (1-12)\n\n");
               printf ("  Tag = ");
               cin >> tag;
               cout << endl;
               }
               else (monat > 0 && monat <= 12)
               {
                   switch (monat)                           //Monat als Bezeichnung ausgeben
                   {
                       case 1:  printf("  Monat = (Januar)");   break;
                       case 2:  printf("  Monat = (Februar)");  break;
                       case 3:  printf("  Monat = (Maerz)");    break;
                       case 4:  printf("  Monat = (April)");    break;
                       case 5:  printf("  Monat = (Mai)");      break;
                       case 6:  printf("  Monat = (Juni)");     break;
                       case 7:  printf("  Monat = (juli)");     break;
                       case 8:  printf("  Monat = (August)");   break;
                       case 9:  printf("  Monat = (September)");break;
                       case 10: printf("  Monat = (Oktober)");  break;
                       case 11: printf("  Monat = (November)"); break;
                       case 12: printf("  Monat = (Dezember)"); break;
                       default:
                                printf("\n Ungueltiges Monat  (1-12)\n\n");
                                printf ("  Monat = ");
                                cin >> monat;
                                break;
                   }
               }

           } while (monat <= 0 || monat > 12);




           cout << endl << endl;

           printf ("  Jahr = ");
           cin >> jahr;
           cout << endl;

           if (jahr <= 1000 || jahr >= 9999)
           {
               printf(" Ungueltiges Jahr (1000 - 9999)");
               printf ("\n  Jahr = ");
               cin >> jahr;
               cout << endl;

               if (jahr <= 1000 || jahr >= 9999)
               {
                   printf(" Ungueltiges Jahr (1000 - 9999)");
                   printf ("\n  Jahr = ");
                   cin >> jahr;
                   cout << endl;
                   if (jahr <= 1000 || jahr >= 9999)
                   {
                       printf(" Ungueltiges Jahr (1000 - 9999)");
                       printf ("\n  Jahr = ");
                       cin >> jahr;
                       cout << endl;
                   }
               }
           }

           cout << "  Erfolgreich angemeldet!" << endl << endl;
           cout << "  [2] ... Programmende" << endl;
           cout << "  [3] ... Bestaetigung" << endl;


       }


       if(menue=='2')
       {
           cout << "  Punktezahl = ";
           cin >> punktezahl;
           cout << endl;

           switch (punktezahl)
           {
               case 0:  printf("  Note: Nicht genuegend");  break;
               case 1:  printf("  Note: Nicht genuegend");  break;
               case 2:  printf("  Note: Nicht genuegend");  break;
               case 3:  printf("  Note: Nicht genuegend");  break;
               case 4:  printf("  Note: Nicht genuegend");  break;
               case 5:  printf("  Note: Nicht genuegend");  break;
               case 6:  printf("  Note: Nicht genuegend");  break;
               case 7:  printf("  Note: Nicht genuegend");  break;
               case 8:  printf("  Note: Nicht genuegend");  break;
               case 9:  printf("  Note: Genuegend");break;
               case 10: printf("  Note: Genuegend");  break;
               case 11: printf("  Note: Befriedigend"); break;
               case 12: printf("  Note: Befriedigend"); break;
               case 13:  printf("  Note: Gut");   break;
               case 14:  printf("  Note: Gut");   break;
               case 15:  printf("  Note: Sehr gut");   break;
               case 16:  printf("  Note: Sehr gut");   break;
               default:  printf(" Ungueltige Punktezahl (0-16)\n\n");
                         printf ("  Ereichte Punktzahl = ");
                         cin >> punktezahl;
                         cout << endl;
                         break;
           }
       }
       if(menue=='3')     // Bestätigung ausgeben
       {

           cout << "  " << vorname << " " << name << " Klasse: " << klasse << " mit der Katalognummer " << KATNR << "," << endl;
           cout << "  wurde erfolgreich in den Kurs eingetragen und hat " << punktezahl << " Punkte." << endl;
       }



       menue = getch();
       key=getch();

   } while (key!=ESC);
    return 0;
}


/////////////////////////////////////////////////////////////////////////////

