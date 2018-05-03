/****************************************************************************
 * @file deklarationen.h
 *
 * Projektname : Mastermind
 * Autor:
 * Alexander Hofstätter
 *
 * Variablen Deklarationen für Mastermind
 *
 * © 2012 Alexander Hofstätter
 *
 ***************************************************************************/

 #ifndef _DEKLARATIONEN_H_
 #define _DEKLARATIONEN_H_

 #define ESC        27
 #define BLOCK      219
 #define ENTER      13
 #define LINKS      75
 #define RECHTS     77
 #define RUNTER     80
 #define RAUF       72
 #define BACKSPACE  8
 #define SPACE      32
 #define SCHWARZ    0
 #define BLAU       1
 #define ROT        4
 #define FALSE      0
 #define TRUE       1

 int felder_max = 4;   // Anzahl der Farbfelder
 int farben_max = 4;   // Anzahl der Farben
 int runden_max = 12;  // Anzahl der maximalen runden
 int feld_hoehe = 3;   // Höhe eines einzelnen Feldes
 int feld_breite = 5;  // Breite eines einzelenen Feldes
 int startx,endx;      // Variable für erstes und leztztes Feld
 const int hintergrund = DARKGRAY;      // Hintergrundfarbe konstant auf dunkelgrau setzen
 const int menuefarbe = BLAU;           // Textfarbe konstant auf blau setzen
 const int fenster_breite = 110;        // Fensterbreite konstant auf 150 zeichen setzen

#endif /* _DEKLARATIONEN_H_ */
