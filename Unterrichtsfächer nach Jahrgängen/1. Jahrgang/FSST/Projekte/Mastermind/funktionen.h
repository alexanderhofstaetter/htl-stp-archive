/****************************************************************************
 * @file funktionen.h
 *
 * Projektname : Mastermind
 * Autor:
 * Alexander Hofstätter
 *
 * Funktions Prototypen für Mastermind
 *
 * © 2012 Alexander Hofstätter
 *
 ***************************************************************************/

 #ifndef _FUNKTIONEN_H_
 #define _FUNKTIONEN_H_

void farbewechseln( int farbe[], int xpos, int startx, int abstand);
/**
 *  Wechseln der Farbe eines einzelnes Feldes.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Farbe gewechselt wird
 *                         int xpos       ... Wert für die momentane X-Position
 *                         int startx     ... Wert für die X-Position des ersten Feldes
 *                         int abstand    ... Wert für den Abstand der Felder
 */

void farbausgabe ( int farbe[], int ypos, int abstand );
/**
 *  Gibt alle Farben eines Arrays in Blöcken aus.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Farbe ausgegebn wird
 *                         int ypos       ... Wert für die momentane Y-Position
 *                         int abstand    ... Wert für den Abstand der Felder
 */

void zufallsfarbe ( int farbe[]);
/**
 *  Weißt dem Array eine zufällige Farbe zu.*/
/*  Import (Eingabedaten): int farbe[]    ... Array dessen Werte zugewiesen werden
 */

void trennlinie (int laenge, int x, int y, char zeichen, int zeilen, int color);
/**
 *  Gibt eine Trennlinie mit variablen Daten aus.*/
/*  Import (Eingabedaten): int laenge      ... Wert für die Länge
 *                         int x           ... Wert für die X-Position
 *                         int y           ... Wert für die Y-Position
 *                         char zeichen    ... Charakter für das Symbol
 *                         int zeilen      ... Wert für Anzahl der Zeilen
 *                         int color       ... Wert für die Farbe
 */

void array_init ( int array[], int wert, int max );
/**
 *  Initialisiert ein Arrays.*/
/*  Import (Eingabedaten): int array[]     ... Gibt das Array an
 *                         int wert        ... Wert für die Initialisierung
 *                         int max         ... Wert für das letzte Feldelement
 */

int einstellungen (int ypos, int starty, string menue_name, string fehler, int max_wert, int wert);
/**
 *  Lest neue Werte für beliebige Variablen ein.*/
/*  Import (Eingabedaten): int ypos              ... Wert für die Platzierung in Y-Position
 *                         int starty            ... Wert für die 1. Y-Position
 *                         string menue_name     ... String für den Namen des Menüeintrages
 *                         string fehler         ... String für die Fehlerausgabe
 *                         int max_wert          ... Wert für die Bedingung
 *                         int wert              ... Wert für die Farbe
 *  Return (Rückgabewert): Wert der geänderten Variable
 */

void setze_hintergrund(int x_max, int y_max, int color);
/**
 *  Überschreibt das komplette Fenster mit einem neuem Hintergrund.*/
/*  Import (Eingabedaten): int x_max     ... Wert für die Fensterbreite
 *                         int y_max     ... Wert für die Fensterbreite
 *                         int color     ... Wert für die Hintergrundfarbe
 */

void goto_printf(int x, int y, string ausgabe);
/**
 *  Platziert den Cursor und gibt über printf einen string aus.*/
/*  Import (Eingabedaten): int x              ... Wert für die X-Position
 *                         int y              ... Wert für die Y-Position
 *                         string ausgabe     ... String für die Ausgabe
 */

int menue_start(int art_color, int breite, string menue_name);
/**
 *  Erste Funtkion in jedem Menü oder Untermenü.*/
/*  Import (Eingabedaten): int art_color         ... Wert für die Farbe der Ascii_art
 *                         int breite            ... Wert für die Fensterbreite
 *                         string menue_name     ... String für den Menünamen
 *  Return (Rückgabewert): Aktuelle Y-Position
 */

int vergleichen(int array_1[], int array_2[], int xpos, int ypos);
/**
 *  Prüft die direkten und indirekten Treffer und gibt die Hilfestellung aus.*/
/*  Import (Eingabedaten): int array_1[]     ... Wert für die Platzierung in Y-Position
 *                         int array_2[]     ... Wert für die 1. Y-Position
 *                         int xpos          ... Wert für die X-Position der Hilfestellung
 *  Return (Rückgabewert): Wert der direkten Treffer
 */

int datei(char *dateiname);
/**
 *  Öffnet eine Datei zum lesen und gibt sie 1:1 am Bildschirm aus.*/
/*  Import (Eingabedaten): char *dateiname   ... Charakter für den Dateiname inkl. Pfad
 *  Return (Rückgabewert): Fehler beim lesen: 1
                           Alles OK: 0
 */

#endif /* _FUNKTIONEN_H_ */
