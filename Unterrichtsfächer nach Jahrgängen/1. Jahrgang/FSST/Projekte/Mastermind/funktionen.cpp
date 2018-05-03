/****************************************************************************
 * @file funktionen.cpp
 *
 * Projektname : Mastermind
 * Autor:
 * Alexander Hofstätter
 *
 * Funktions Definitionen für Mastermind
 *
 * © 2012 Alexander Hofstätter
 *
 ***************************************************************************/

 #ifndef _FUNKTIONEN_CPP_
 #define _FUNKTIONEN_CPP_
 #include "deklarationen.h"

void farbewechseln( int farbe[], int xpos, int startx, int abstand)
{   for ( int i = 0; i < farben_max; i++)
    {   if (xpos == startx +  i * abstand)              // aktuelle X-Position gleich dem Anfangswert von x + i mal abstand
        {   if (farbe[i] >= (farben_max-1))  farbe[i] = 0;  // Wenn die letzte Farbe erreicht ist, springe zur 1.ten Farbe
            else farbe[i]++;                            // Sonst ( farbe < farben_max && farbe >= 0 ), nächste Farbe
        }
       if (farbe[i] == hintergrund)                    // Hintergrundfarbe überspringen
            farbe[i]++;
    }
}

void farbausgabe ( int farbe[], int ypos, int abstand )
{   int x = startx - feld_breite/2;
    for ( int i = 0 ; i < felder_max; i++, x += abstand)
    {   for ( int y1 = -feld_hoehe/2; y1 <= feld_hoehe/2; y1++) // Cursor vertikale mittig setzen
        {   textcolor(farbe[i]);                                // Setze Zeichenfarbe vom Array
            gotoxy(x,ypos+y1);                                     // Cursor platzieren
            for ( int l=1; l<=feld_breite; l++)                 // Ganze Breite ausfüllen
            {   printf("%c",BLOCK);                             // Ascii Zeichen 219 ausgeben
            }
        }
    }
}

void zufallsfarbe ( int farbe[] )
{   array_init(farbe,SCHWARZ,felder_max);           // Array initialisieren
    for( int i = 0; i < felder_max; i++)            // Array durchlaufen
    {   farbe[i] = rand() % farben_max ;            // Zufallszahl von 0 bis farben_max
        if (farbe[i] == hintergrund)                // Hintergrundfarbe überspringen
            farbe[i]++;
        for(int j = 0; j < i; j++)                  // Alle bisherigen Farben durchlaufen
        {   if(farbe[j] == farbe[i])                // Prüfe ob Farbe schon vorhanen ist
            {   i--; break;                         // Wenn ja: Schleife abbrechen und array nochmal durchlaufen
            }
        }
    }
}

void trennlinie (int laenge, int x, int y, char zeichen, int zeilen, int color)
{   textcolor(color);                       // gewählte Farbe setzen
    for (int i=0;i<zeilen;i++)              // durchläuft die Zeilen
    {   gotoxy((x-laenge)/2,y+i);           // zentriert die Trennlinie
        for (int j=0;j<laenge;j++)          // Pro Zeile, die volle Länge ausgeben
            printf("%c",zeichen);           // Zeichen ausgeben
    }
    textcolor(menuefarbe);                  // Die Farbe zurück auf die Menüfarbe setzen
}

void array_init ( int array[], int wert, int max )
{   for ( int i=0; i<max; i++)   // durchläuft das ganze Array
        array[i]=wert;           // und weißt jedem Feldelement einen Wert zu
}

int einstellungen (int ypos, int starty, string menue_name, string fehler, int max_wert, int wert)
{   int zahl;
    do
    {   zahl = 0;                                           // Hilfsvariable initialisieren
        gotoxy(30,starty-1);
        printf(">> Bearbeitungsmodus\n\n");                 // Bearbeitungsmodus in rot ausgeben
        gotoxy(7,starty+1+ypos);                            // Cursor auf passendem Menüeintrag platzieren
        printf ("[%d] ... %-20s  ...   %4d   neuer Wert: ",ypos, menue_name.c_str(), wert);     // Menüeintrag in rot überschreiben
        scanf("%d",&zahl);                                  // Neuen Wert einlesen
        if (zahl <= max_wert)return zahl;                   // Wenn der Wert den Vorgaben entspricht, dann Wert zurückgeben und abbrechen
        gotoxy(2,25);                                       // Cursor am unteren Fensterrand platzieren
        printf("%s",fehler.c_str());                        // Wenn nicht, dann passenden Fehler ausgeben
    }while(zahl > max_wert);                                // Solange wiederholen bis der Wert passt
    return zahl;
}

void setze_hintergrund(int x_max, int y_max, int color)
{   textbackground(color);              // Setz den neuen Hintergrund
    for (int i=0;i<y_max;i++)           // Fensterbreite durchlaufen
        for (int j=0;j<x_max/10;j++)    // Fensterhöhe durchlaufen
            printf("           ");
    gotoxy(1,1);                        // Positioniert den Cursor auf 1|1
}

void goto_printf(int x, int y, string ausgabe)
{   gotoxy(x,y);
    printf ("%s",ausgabe.c_str());
}

int menue_start(int art_color, int breite, string menue_name)
{   textbackground(hintergrund);        // Setzt die Hintergrundfarbe
    clrscr();
    textcolor(art_color);               // Setzt die Textfarbe
    gotoxy(1,1);
    int x = breite/2-35;                // Berechnet die Mitte für den Text
    goto_printf(x,wherey(),"    MMMM     MMMM      AAA      SSSSSSSS   TTTTTTTTTTTT  EEEEEEE  RRRRR   \n");
    goto_printf(x,wherey(),"    MM MM   MM MM     AA AA    SSSS            TTT       EE       RR  RR  \n");
    goto_printf(x,wherey(),"    MM  MM MM  MM    AAAAAAA    SSSSSSSS       TTT       EEEEEEE  RRRRR   \n");
    goto_printf(x,wherey(),"    MM   MMM   MM   AA     AA        SSSS      TTT       EE       RR  RR  \n");
    goto_printf(x,wherey(),"    MM    M    MM  AA       AA  SSSSSSSS       TTT       EEEEEEE  RR   RR \n\n");

    goto_printf(x,wherey(),"               MMMM     MMMM  IIIIIIIIIII  NNNN    NN  DDDDD    \n");
    goto_printf(x,wherey(),"               MM MM   MM MM      III      NN NN   NN  DD  DDD  \n");
    goto_printf(x,wherey(),"               MM  MM MM  MM      III      NN  NN  NN  DD   DDD \n");
    goto_printf(x,wherey(),"               MM   MMM   MM      III      NN   NN NN  DD  DDD  \n");
    goto_printf(x,wherey(),"               MM    M    MM  IIIIIIIIIII  NN    NNNN  DDDDDD \n\n\n\n");
    textcolor(menuefarbe);
    printf ("  %s\n\n\n",menue_name.c_str());
    return wherey()-2;                  // Gibt die aktuelle Y-Position als Rückgabewert zurück

}

int vergleichen(int array_1[], int array_2[], int xpos)
{   int direkt = 0, indirekt = 0;               // lokale Zählvariablen für direkte und indirekte Treffer
    for(int i = 0; i < felder_max; i++)
        for(int j = 0; j < felder_max; j++)
            if (array_1[i] == array_2[j])       // Prüfe ob irgendeine Farbe des array_2 gleich einer Farbe des array_1 ist
            {   if (array_1[i] == array_2[i])   // Wenn beide Farben den gleichen Index haben -> direkter Treffer
                {   direkt++; break;
                }
                else
                {   indirekt++; break;          // Bei zwei gleichen Farben mit unterschiedlichem Index  -> indirekter Treffer
                }
            }
    gotoxy(xpos+2,wherey());                    // Positioniere Cursor 2 Zeichen entfernt vom rechten äußerem Feld
    textcolor(LIGHTRED);                        // Setze Zeichenfarbe
    for (int i = 0 ; i < direkt; i++)
        printf("%2c",'+');                      // Gibt das Zeichen '+' für jeden direkten Treffer in schwarz aus
    textcolor(WHITE);
    for (int i = 0 ; i < indirekt; i++)
        printf("%2c",'*');                      // Gibt das Zeichen '*' für jeden indirekten Treffer in weiß aus
    return direkt;
}

int datei(char *dateiname)
{   FILE *datei;                            // Zeiger auf datei
    char zeichen;                           // char Variable um die Zeichen auszugeben
    datei = fopen(dateiname,"r");           // Datei zum Lesen öffnen
    if(datei==NULL)                         // Fehlerbehandlung
        return 1;
    while ((zeichen=fgetc(datei))!=EOF)     // zeichweise lesen bis Dateiende erreicht ist
    {   putchar(zeichen);                   // Zeichen am Bildschirm ausgeben
    }
    fclose(datei);                          // Datei schließen
    return 0;
}

#endif /* _FUNKTIONEN_CPP_ */
