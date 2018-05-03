/////////////////////////////////////////////////////////////////////////////
//   Name: A. Hofstätter
//   Programmname : signale.cpp
//   Aufgabe :  Signalsamples und Signalanalyse
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include "graphics.h"
#include "getch_console.h"
#include <conio.h>

#include "signale.h"
#include "scope.h"

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Globale Definition von Feldern
/////////////////////////////////////////////////////////////////////////////

const int NMAX = 500;                  // Feldgröße NMAX
float signal[NMAX], signal1[NMAX];     // Signal Arrays

/////////////////////////////////////////////////////////////////////////////
//   Funktionsprototypen
/////////////////////////////////////////////////////////////////////////////

void ueberlagern(bool ueberlagerung);

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(NULL));
    float am,fn,az = 0;
    char key;
    bool ueberlagerung = false;
    do
    {
        system("CLS");
        printf(" numerischer Signalgenerator\n\n");
        printf(" [1] Zufallssignal\n");
        printf(" [2] Gleichsignal\n");
        printf(" [3] Rechtecksignal\n");
        printf(" [4] Sinussignal\n");
        printf(" [5] Impulssignal\n");
        printf(" [6] Signalueberlagerung\n");
        printf(" [7] Grafische Ausgabe\n");
        printf(" [ESC] Programmende");
        key = getch_console();

        if (key == 27) break;
        else if(key == '1')
        {   printf("\n\n Zufallssignal \n");
            printf(" Amplitude = ");  cin >> am;
            array_rand(signal, NMAX, am);
            ueberlagern(ueberlagerung);
        }
        else if(key == '2')
        {   printf("\n\n Gleichsignal \n");
            printf(" Amplitude = ");  cin >> am;
            array_dc(signal, NMAX, am);
            ueberlagern(ueberlagerung);
        }
        else if(key == '3')
        {   printf("\n\n Rechtecksignal \n");
            printf(" Amplitude = ");  cin >> am;
            printf(" Frequenzvielfaches = ");  cin >> fn;
            array_rect(signal, NMAX, am, fn);
            ueberlagern(ueberlagerung);
        }
        else if(key == '4')
        {   printf("\n\n Sinussignal \n");
            printf(" Amplitude = ");  cin >> am;
            printf(" Frequenzvielfaches = ");  cin >> fn;
            array_sinus(signal, NMAX, am, fn);
            ueberlagern(ueberlagerung);
        }
        else if(key == '5')
        {   printf("\n\n Impulssignal \n");
            printf(" Amplitude = ");  cin >> am;
            printf(" Auschaltszeit in Prozent = ");  cin >> az;
            array_impuls(signal, NMAX, am, az);
            ueberlagern(ueberlagerung);
        }
        else if(key == '6')
        {   do
            {   system("CLS");
                printf("\n Signalueberlagerung \n");
                printf(" Aktivieren: (0) Nein     (1) Ja\n\n");
                printf(" Momentan Aktiviert: ");
                if (ueberlagerung == 0) printf("Nein \n");
                else if (ueberlagerung == 1) printf("Ja\n");
                printf("\n [Enter] Zurueck ins Menu \n");
                if (key == '0') ueberlagerung = 0;
                if (key == '1') ueberlagerung = 1;
                key = getch_console();
            }while(key != 13);
            for(int i = 0; i < NMAX; i++)
                signal1[i] = 0;
        }
        else if(key == '7')
        {   // Grafikfenster  erzeugen mit Breite=600, Höhe=500 und Beschriftung
            initwindow(600,500,"Signal Analyse - by A.Hofstaetter");

            float ys1 = -100,ys2 = 100;                 // y-Skalenbereich Endwerte
            int x1 = 50,x2 = 550,y1 = 50,y2 = 450;      // Bildbereich Endwerte

            int bkcol = COLOR(220,220,250);             // Fenster Hintergrundfarbe
            setbkcolor(bkcol);                          // Hintergrundfarbe setzen
            cleardevice();                              // und ausfüllen

            int acol = COLOR(200,200,200);              // Achsen- und Gitterfarbe
            setcolor(acol);                             // Achsenfarbe setzen
            axes(x1,x2,y1,y2,ys1,ys2);                  // Diagrammfläche und Achsen darstellen

            setcolor(COLOR(50,50,250));                 // Diagrammfarbe setzen
            draw(signal1,NMAX,x1,x2,y1,y2,ys1,ys2);     // Signalarray signal1[i] darstellen

            char mittel_char[25], ss_char[25], rms_char[25];
            //setcolor(COLOR(150,150,150));

            float mittel,ss,rms;
            mittel = array_mittel(signal1,0,NMAX-1);
            ss = array_ss(signal1,0,NMAX-1);
            rms = array_rms(signal1,NMAX);

            sprintf(mittel_char," Mittel : %4.2f ",mittel);
            outtextxy(x1+10,y2-20,mittel_char);

            sprintf(ss_char," Uss : %4.2f ",ss);
            outtextxy(x1+210,y2-20,ss_char);

            sprintf(rms_char," RMS : %4.2f ",rms);
            outtextxy(x1+410,y2-20,rms_char);

            // bei Tastendruck Grafikfenster schließen
            getch();
            closegraph();
            key = 0;

        }
    }
    while(key != 27);
    printf("\n\n");
    system("PAUSE");
    return 0;
}

void ueberlagern(bool ueberlagerung)
{
    if(ueberlagerung == 0)
        for(int i = 0; i < NMAX; i++)
            signal1[i] = signal[i];
    else
        for(int i = 0; i < NMAX; i++)
            signal1[i] += signal[i];
}
