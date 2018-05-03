#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

int start,spieler,abheben,key,stapel;
string spieler_1,spieler_2;

int main()
{

   do
   {
      cout << "                               ===============" << endl;
      cout << "                               ==Kartenspiel==" << endl;
      cout << "                               ===============" << endl;
      stapel=10;
      abheben=spieler=0;
      srand(time(NULL));
      start=rand()%2+1;
      spieler_1="Spieler 1";
      spieler_2="Spieler 2";

      /*cout << "Name Spieler 1: ";
      cin >> spieler_1;
      cout << endl;

      cout << "Name Spieler 2: ";
      cin >> spieler_2;
      cout << endl;
      */

      cout << endl << "    ++++++ Der Stapel hat " << stapel << " Karten! ++++++" << endl;
      do
      {

         if (start==1)
         {
            cout << endl << spieler_1 << " ist am Zug";
            do {
               cout << endl << "Zahl zwischen 1-3: ";
               abheben=(int)getch()- '0';

            } while(abheben <= 0 || abheben > 3 || (stapel-abheben)<0);
            cout << abheben;

            stapel=stapel-abheben;
            cout << endl << "\n    ++++++ Der Stapel hat nun " << stapel << " Karten! ++++++" << endl;
            spieler=1;
            start=2;
            if(stapel<=0)break;

         }

         if(start==2)
         {
            srand(time(NULL));
            cout << endl << "PC ist am Zug" << endl;
            abheben=stapel%4;

            if (abheben==0) abheben=1;
            stapel=stapel-abheben;
            cout << "Der Pc zieht " <<  abheben;

            if (abheben==1) cout << " Karte";
            else cout << " Karten";

            cout << " vom Stapel" << endl << endl;
            cout << "    ++++++ Der Stapel hat nun " << stapel << " Karten! ++++++" << endl;
            spieler=2;
            start=1;
            if(stapel<=0)break;
         }

      } while(stapel!=0);

      cout << endl << "                        ============================" << endl;
      if (spieler==1)
      {
         cout << "                        || " << spieler_1 << " hat gewonnen ||" << endl;
      }
      if (spieler==2)
      {
         cout << "                        ||   Der Pc hat gewonnen  ||" << endl;
      }
      if (spieler==3)
      {
         cout << "                        || " << spieler_2 << " hat gewonnen ||" << endl;
      }
      cout << "                        ============================" << endl << endl;


      //printf("Nach der %2d. Runde hat Spieler 1 bereits %2d Mal gewonnen und der PC %d Mal \n\n",runden,spieler_win,pc_win);
      cout << "Taste drucken zum neu Spielen" << endl;
      //cout << "Tase L/l zum Zuruecksetzen der Runden und Gewinnzahlen druecken\n" << endl;
      cout << "Ende mit ESC" << endl;
      key=getch();
      /*if (key=='L' || key=='l')
      {
          runden=pc_win=spieler_win=0;
          stapel=10;
          abheben=spieler=0;
          cout << "Erfolgreich zurückgesetzt, Runden: 0" << endl;

      }*/
      system("CLS");

   } while(key!=27);
   system("PAUSE");
   return 0;
}
