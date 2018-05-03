/////////////////////////////////////////////////////////////////////////////
//   Programmname : sortiere.cpp
//   Autor: Alex Hofstätter
//
//   Aufgabe :  Auswertung eines Rennens
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <conio.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Feldern
/////////////////////////////////////////////////////////////////////////////
 const int N=3;
 int startn[N];
 float ergebnis[N];
 string name[N];
 int schluessel[N];
 int rang[N];

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen von Variablen
/////////////////////////////////////////////////////////////////////////////
 int j,i;
 float hilf;
 char key;
 string hilfe;
/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  srand(time(NULL));

//\204 \216 \224 \231 \201 \232
//ä    Ä     ö    Ö    ü    Ü8

   do
   {
       system("CLS");                 // Bildschrim löschen
       printf("                                 Rennauswertung\n");
       printf("                                 ~~~~~~~~~~~~~~\n");
       printf("\n [1] Zufallszahlen f\201r die Startnummern und Zeiten ");
       printf("\n [2] Manueller Eingabemodus");
       printf("\n [Q] Beenden");
       key=getch();
       for (i=0;i<N;i++)
       {   schluessel[i]=i;
           rang[i]=i+1;
           if(key=='1')
           {   printf("\n\n Name f\201r %d. Fahrer einlesen\n",i+1);
               ergebnis[i]=((float)rand()/RAND_MAX)+rand()%100+1;
               startn[i]=rand()%20+1;
               printf(" Name f\201r Startnummer %d : ",startn[i]);     cin >> name[i];
               printf(" %2d. Fahrer:  Startnummer %2d        Zeit: %6.3f Sekunden \n",i+1,startn[i],ergebnis[i]);
           }
           if(key=='2')
           {   printf("\n\n Name, Startnummer und dazu geh\224riges Ergebnis f\201r %d. Fahrer einlesen\n",i+1);
               printf(" Startnummer : "); cin >> startn[i];
               printf(" Name f\201r Startnummer %d : ",startn[i]); cin >> name[i];
               printf(" Ergebnis in [s] f\201r %s (%d) : ",name[i].c_str(),startn[i]); cin >> ergebnis[i];
           }
           if(key=='q') return 0;
       }

       printf("\n\n");
       printf("===================================Rangliste===================================\n\n");
       for (i=0;i<N;i++)
       {   for(j=i+1;j<N;j++)
           {   if(ergebnis[j]<ergebnis[i])
               {   hilf=schluessel[i]; schluessel[i]=schluessel[j]; schluessel[j]=hilf;  //Reihenfolge tauschen
                   //hilf=startn[i]; startn[i]=startn[j]; startn[j]=hilf;
                   //hilfe=name[rang[i]]; name[i]=name[j]; name[j]=hilfe;
               }
           }
           printf("    %d.ter Platz : %s Startnummer %2d 8 mit der Zeit von  %6.3f Sekunden \n",i+1,name[schluessel[i]].c_str(),startn[schluessel[i]],ergebnis[schluessel[i]]);
       }

       printf("\n\n");
       printf("============================alphabetische Rangliste============================\n\n");
       for (i=0;i<N;i++)
       {   for(j=i+1;j<N;j++)
           {   if(name[j]>name[i])
               {   hilf=schluessel[i]; schluessel[i]=schluessel[j]; schluessel[j]=hilf;  //Reihenfolge tauschen
               }
           }
           printf("     %s (%2d) ist %2d.ter Platz mit der Zeit von  %6.3f Sekunden \n",name[schluessel[i]].c_str(),startn[schluessel[i]],rang[schluessel[i]],ergebnis[schluessel[i]]);
       }
       key=getch();
   }while(key!='q');

   printf("\n\n");
   system("PAUSE");
   return 0;
 }
