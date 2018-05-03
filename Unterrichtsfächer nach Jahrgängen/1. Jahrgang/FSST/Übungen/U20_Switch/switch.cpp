/////////////////////////////////////////////////////////////////////////////
//   Programmname : Kursanmeldung_1BHEL_10.cpp
//
//   Autor   :  A. Hofstätter
//   Datum   :  07.11.2011
//   Version :  1
//
//   Aufgabe :  Erstelle das C/C++ Programm "Kursanmeldung_klasse_katnr.cpp"
//              zur Erfassung und Bewertung von Prüfungen.
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
{  string monat_char;
   char name[30],vorname[30],klasse[30],key,menue;
   int monat,tag,jahr,punktezahl,KATNR;
   int start=0;
   const int KATNR_MAX=24;
   do                                  // Wiederholung mit do-while-Schleife
{

       system("CLS");

       printf ("     /////////////////////////////////////////////////////////  \n");
       printf ("     //                  Kursanmeldung                      //  \n");
       printf ("     //                   ~~~~~~~~~~~                       //  \n");
       printf ("     //                 Alex Hofstaetter                    //  \n");
       printf ("     /////////////////////////////////////////////////////////  \n");
       printf ("\n\n");
       printf ("  Bitte w\x84hlen Sie einen entsprechenden Menuepunkt. \n");
       printf ("\n");
       printf ("   [1] ... Erfassung \n");
       printf ("   [2] ... Pruefung  \n");
       printf ("   [3] ... Bestaetigung \n");
       printf ("   [ESC] ... Programmende \n");
       printf("\n\n");

       if(menue=='1')                                    // Einlesen in alle Werte: Vorname, Name, Klasse, Katalognummer, Datum
       {   cout << "  Vorname = ";
           cin >> vorname;

           printf ("\n  Name = ");
           cin >> name;

           printf ("\n  Klasse = ");
           cin >> klasse;

           printf ("\n  Katalognummer = ");
           cin >> KATNR;
           do                                             // Prüft ob Tag Ungültig
           {
               if (KATNR < 1 || KATNR > KATNR_MAX)
               {
                   printf("\n Ungueltige Katalognummer (1-%d)\n",KATNR_MAX);
                   printf ("\n  Katalognummer = ");
                   cin >> KATNR;
                   start = 1;
               }

           } while (KATNR < 1 || KATNR > KATNR_MAX);


           printf ("\n  ~~~~~~~~~~~~~~~~~~\n");
           printf (  "  ~~Pruefungsdatum~~\n");
           printf (  "  ~~~~~~~~~~~~~~~~~~\n");
           printf ("\n  Tag = ");
           cin >> tag;
           do                                             // Prüft ob Tag Ungültig
           {
               if (tag <= 0 || tag > 31)
               {
                   printf("\n Ungueltiger Tag (1-31)\n");
                   printf ("\n  Tag = ");
                   cin >> tag;
               }
           } while (tag <= 0 || tag > 31);


           printf ("\n  Monat = ");
           cin >> monat;
           do                                             // Prüft ob Monat Ungültig
           {
                if (monat <= 0 || monat > 12)
                {
                    printf("\n Ungueltiges Monat (1-12)\n");
                    printf ("\n  Monat = ");
                    cin >> monat;
                }

           } while (monat <= 0 || monat > 12);

           switch (monat)                           //Monat als Bezeichnung ausgeben
                   {
                       case 1:  printf("  Monat = (Januar)");   monat_char = "Januar"; break;
                       case 2:  printf("  Monat = (Februar)");  monat_char = "Februar"; break;
                       case 3:  printf("  Monat = (Maerz)");    monat_char = "Maerz"; break;
                       case 4:  printf("  Monat = (April)");    monat_char = "April"; break;
                       case 5:  printf("  Monat = (Mai)");      monat_char = "Mai"; break;
                       case 6:  printf("  Monat = (Juni)");     monat_char = "Juni"; break;
                       case 7:  printf("  Monat = (juli)");     monat_char = "Juli"; break;
                       case 8:  printf("  Monat = (August)");   monat_char = "August"; break;
                       case 9:  printf("  Monat = (September)"); monat_char = "September"; break;
                       case 10: printf("  Monat = (Oktober)");  monat_char = "Oktober"; break;
                       case 11: printf("  Monat = (November)"); monat_char = "November"; break;
                       case 12: printf("  Monat = (Dezember)"); monat_char = "Dezember"; break;
                       default: printf("\n Ungueltiges Monat  (1-12)\n\n");
                                printf ("  Monat = ");
                                cin >> monat;
                                break;
                   }

           printf("\n\n");

           printf ("  Jahr = ");
           cin >> jahr;
           do                                             // Prüft ob Tag Ungültig
           {
               if (jahr > 2011 || jahr < 2011)
               {
                   printf("\n Ungueltiges Jahr (2011)\n");
                   printf ("\n  Jahr = ");
                   cin >> jahr;
               }
           } while (jahr > 2011 || jahr < 2011);

           cout << "  Erfolgreich angemeldet!" << endl << endl;


       }


       if(menue=='2')
       {
           cout << "  Punktezahl = ";
           cin >> punktezahl;
           cout << endl;

           switch (punktezahl)
           {
               case 0:  case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:     printf("  Note: Nicht genuegend");  break;
               case 9:  case 10: printf("  Note: Genuegend");break;
               case 11: case 12: printf("  Note: Befriedigend"); break;
               case 13: case 14: printf("  Note: Gut");   break;
               case 15:  case 16: printf("  Note: Sehr gut");   break;
               default:  printf("  Ungueltige Punktezahl (0-16)\n\n");
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
           cout << "\n  HTL STP, " << tag << "." <<  monat_char  << "."  <<  jahr  << endl;
       }



       menue = getch();


   } while (menue!=ESC);
    return 0;
}

