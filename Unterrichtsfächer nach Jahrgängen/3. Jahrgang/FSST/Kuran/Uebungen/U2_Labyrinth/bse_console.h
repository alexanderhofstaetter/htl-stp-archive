/* ========================================================================== */
/*                                                                            */
/*   Dateiname: bse_console.h                                                 */
/*     Version: 1.3                                                           */
/*     Autoren: Jens Herbst, Tobias Ackermann, Matthias Ebert                 */
/*       Datum: 24.04.10                                                      */
/*                                                                            */
/*   Situation: Codeblocks/DevC++ mit dem gcc-Compiler von MinGW sowie        */
/*              VC++ 2005/2008 haben unvollstaendige conio.h-Versionen.       */
/*              Beide enthalten nur die folgenden Basis-Funktionen:           */
/*              getch(), getche(), kbhit(), putch(), ungetch()                */
/*              cgets(), cprintf(), cputs(), cscanf()                         */
/*                                                                            */
/*       siehe: Programme/CodeBlocks/MinGW/include/conio.h                    */
/*              Programme/CodeBlocks/MinGW/include/wincon.h                   */
/*              Programme/Microsoft Visual Studio 200x/VC/include/conio.h     */
/*              Programme/Microsoft Visual Studio 200x/VC/include/wincon.h    */
/*              Damit lassen sich keine Cursor-Steuerungen vornehmen,         */
/*              wie mit dem conio.h-Original von Borland                      */
/*                                                                            */
/*        Ziel: Folgende Funktionen werden deshalb in dieser bse_console.h    */
/*              hinzugefuegt:                    (seit Version)               */
/*              int  maxcols(void);                    (1.2)---------         */
/*              int  maxrows(void);                    (1.2)---------         */
/*              void gotoxy(int, int);       (1.0)-------------------         */
/*              int  wherex(void);                     (1.2)---------         */
/*              int  wherey(void);                     (1.2)---------         */
/*              void textcolor(int color);        (1.1)--------------         */
/*              void textbackground(int color);   (1.1)--------------         */
/*              void clrscr(void);                (1.1)--------------         */
/*              void _setcursortype(int type);    (1.1)--------------         */
/*              void delay(int msec);                  (1.2)---------         */
/*              void randomize(void);             (1.1)--------------         */
/*              int  random(int);                 (1.1)--------------         */
/*              int  setconsole(char* title);               (1.3)----         */
/*              int  resetconsole(void);                    (1.3)----         */
/*                                                                            */
/*          OS: DOS-Programme, cmd-Konsole von Windows                        */
/*                                                                            */
/*     History: 1.0     02.02.09                                              */
/*              nur gotoxy()                                                  */
/*              1.1     04.02.09                                              */
/*              einige Funktionen und Kommentare hinzugefuegt                 */
/*              1.2     07.02.09                                              */
/*              einige Funktionen und Kommentare hinzugefuegt und geaendert   */
/*              1.2.1   13.02.09                                              */
/*              Bugfix: "DWORD ergebnis" statt int in Funktion clrscr()       */
/*              1.2.2   22.02.09                                              */
/*              Visual C++ Compatibilitaet hinzugefuegt und geprueft          */
/*              cols(), rows(), maxcols(), maxrows() praezisiert              */
/*              _setcursortype() funktioniert jetzt                           */
/*              Versuche mit Tastatur- und Maus-Events hinzugefuegt (am Ende) */
/*              1.3     24.04.10                                              */
/*              setconsole(), resetconsole() hinzugefuegt                     */
/*              Einige Noten-Konstanten für Sound() hinzugefuegt              */
/*              Tastatur-Konstanten für Sondertasten hinzugefuegt             */
/*                                                                            */
/*       Usage: Diese Datei bse_console.h in den Projektordner aufnehmen      */
/*              und in den eigenen Quellcode integrieren:                     */
/*              #include "bse_console.h"                                      */
/*              Bei MINGW muss beim Uebersetzen folgendes angegeben werden    */
/*              gcc test.c -o text.exe                                        */
/*                                                                            */
/*        ToDo: Komfortable sichere Eingaberoutine mit fflush()-Bufferleerung */
/*              und Funktionstasten/Sondertasten/Pfeiltasten - Auswertung     */
/*              Testing ...                                                   */
/*                                                                            */
/* Feedback an: Matthias.Ebert@BS-Erlangen.de                                 */
/*                                                                            */
/*     Tipps: - Die Funktion Sleep(int millisekunden) in der Windows-API      */
/*              ersetzt die sleep(int sekunden)-Funktion von dos.h            */
/*            - Die Funktion Beep( int frequenz_in Hz, int dauer_in ms)       */
/*              ersetzt die sound(), nosound()-Funktionen von conio.h         */
/*              z.B. A = 440Hz muesste funktionieren                          */
/*            - fflush(stdin) loescht den Eingabe-Tastaturpuffer              */
/*            - Funktionstasten geben beim ersten getch() eine 0 zurueck      */
/*              und erst beim zweiten getch() einen unterscheidbaren Wert     */
/*                                                     Viel Spass!            */
/* ========================================================================== */
/*   Inspiriert von ... http://molhanec.net/conio_doc.html                    */
/*              und ... http://conio.sourceforge.net/                         */
/*                                                                            */
/*     Quellen: http://www.codeblocks.org                                     */
/*              http://www.mingw.org                                          */
/*              http://www.microsoft.com/germany/Express/download             */
/* ========================================================================== */
/*                                                                            */
/* Was aus der conio.h von MinGW und VC++ brauchbar ist                       */
/*                                                                            */
/* int getch()  liest ein Zeichen bzw. besser eine Taste von der Tastatur.    */
/*              Ist auf der Taste ein Zeichen, so erhält man den Ascii Code   */
/*              bei Spezialtasten erhält man 0 und muss dann noch             */
/*              (Funktionstasten, Cursortasten) zu erhalten                   */
/*                                                                            */
/* int kbhit()  hat der Benutzer auf eine Taste gedrückt ?                    */
/*              Wenn man mit getch liest, dann wartet getch bis der           */
/*              Benutzer eine Taste drückt - in der Zwischenzeit              */
/*              kann das Programm nichts tun. kbhit wartet nicht sondern      */
/*              schaut nur nach ob einen Taste gedrückt ist. Wenn ja          */
/*              kann das Programm mit getch lesen, wenn nein kann man         */
/*              z.b. etwas ausgeben und später nochmal mit kbhit abfragen     */
/*                                                                            */
/* void putch(ascci-code)                                                     */
/*              gibt ein Zeichen aus, Vorteil gegenüber printf ist, dass mehr */
/*              ascii codes darstellbar sind.                                 */
/*                                                                            */
/* ========================================================================== */

/**
 *  Merker setzen, damit der Code beim Kompilieren nur einmal durchlaufen wird
 */
#ifndef _BSE_CONSOLE_H   /* wenn nicht definiert, durchlaufe ... bis #endif   */
#define _BSE_CONSOLE_H   /* definiere Merker */


/**
 *  Includieren der benoetigten Header, die in MinGW und VC++ bereits existieren
 */
#include <windows.h>  /* fuer GetStdHandle(), Sleep(), Beep(), etc            */
#include <stdlib.h>   /* fuer system(), srand(), rand()                       */
#include <time.h>     /* fuer time()                                          */
#include <conio.h>    /* includiert die (unvollstaendige) Implementierung     */


/**
 *  Erlaubt einige MinGW conio.h Funktionen ohne Unterstrich
 */
#ifdef _CONIO_H_      /* nur wenn conio.h von MinGW includiert wurde          */
#define cgets   _cgets
#define cprintf _cprintf
#define cputs   _cputs
#define cscanf  _cscanf
#endif	/* _CONIO_H_ */

/**
 *  Konstanten fuer Sondertasten
 */
#define ESC   27
#define ENTER 13
#define UP    72
#define LEFT  75
#define RIGHT 77
#define DOWN  80
// Funktionstasten liefern erst eine 0, und dann
#define F1	  59
#define F2	  60
#define F3	  61
#define F4	  62
#define F5	  63
#define F6	  64
#define F7	  65
#define F8	  66
#define F9	  67
#define F10	  68


/**
 *  Cursor-Fuellung in Prozent der Zellhoehe
 */
#define _NOCURSOR        0
#define _NORMALCURSOR   20
#define _SOLIDCURSOR   100

/**
 *  Konstanten fuer Sound und Sleep
 *  z.B.  Beep(c2,ACHTELNOTE);
 *        Sleep(VIERTELNOTE);
 */
const int ACHTELNOTE = 200;
const int VIERTELNOTE = 400;
const int HALBENOTE = 800;
const int GANZENOTE = 1600;
const double a = 440;   // 440 Hz
const double h = 493.88330125612411183075454185884;
const double c2 = 523.25113060119726935569998704661;
const double d2 = 587.32953583481512052556602772116;
const double e2 = 659.25511382573985947168352209311;
const double f2 = 698.45646286600776889075048127982;
const double g2 = 783.99087196349858817139906091965;
const double a2 = 880;  // Eine Oktave hoeher: Verdoppelung der Frequenz
const double h2 = 987.76660251224822366150908371768;//((2^(1/12))^2)*a2;
const double c3 = 1046.5022612023945387113999740932;//((2^(1/12))^1)*h2;
const double d3 = 1174.6590716696302410511320554423;//((2^(1/12))^2)*c3;
const double e3 = 1318.5102276514797189433670441862;//((2^(1/12))^2)*d3;
const double f3 = 1396.9129257320155377815009625596;//((2^(1/12))^1)*e3;
const double g3 = 1567.9817439269971763427981218393;//((2^(1/12))^2)*f3;
const double a3 = 1760;//((2^(1/12))^2)*g3;



/** EGA-Farben
 *  Die Int-Konstanten (von 0 beginnend) sind BLACK=0, BLUE=1,...WHITE=15;
 *  und koennen in allen Unterprogrammen gelesen aber nicht geaendert werden
 */
enum                  /*  Zugeordnete Werte */
{                     /*  HEX   BIN   DEZ   */
    BLACK,            /*  0x0   0000    0   */
    BLUE,             /*  0x1   0001    1   */
    GREEN,            /*  0x2   0010    2   */
    CYAN,             /*  0x3   0011    3   */
    RED,              /*  0x4   0100    4   */
    MAGENTA,          /*  0x5   0101    5   */
    BROWN,            /*  0x6   0110    6   */
    LIGHTGRAY,        /*  0x7   0111    7   */
    DARKGRAY,         /*  0x8   1000    8   */
    LIGHTBLUE,        /*  0x9   1001    9   */
    LIGHTGREEN,       /*  0xA   1010   10   */
    LIGHTCYAN,        /*  0xB   1011   11   */
    LIGHTRED,         /*  0xC   1100   12   */
    LIGHTMAGENTA,     /*  0xD   1101   13   */
    YELLOW,           /*  0xE   1110   14   */
    WHITE             /*  0xF   1111   15   */
};
/*
    Aufbau des EGA-Farbinformationen-Bytes: XBBBFFFF
    F = 4 Bits fuer die Vordergrund-Mischfarbe einer Zelle
    B = 3 Bits fuer die Hintergrund-Mischfarbe einer Zelle
	       3 = Intensity, 2 = Rot, 1 = Gruen, 0 = Blau
           X = Blinken,   6 = Rot, 5 = Gruen, 4 = Blau
    Standard = 00000111 d.h. Hintergrund Schwarz, Zeichen Hellgrau

    Die folgenden globale Variablen koennen in allen Unterprogrammen
    gelesen und ueberschrieben werden.
    static bedeutet, dass sie falls sie in MinGW oder VC++ schon existieren
    nicht mehr neu angelegt werden.
*/
static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

/**
 *  Setzt die Farbe fuer cprintf(), clrscr(), etc.
 */
void textcolor (int color)
{
    if ( 0<=color && color<=15 )
    {
       __FOREGROUND = color;
       color = __FOREGROUND + (__BACKGROUND << 4);
       SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
    }
}

/**
 *  Setzt die Hintergrundfarbe
 */
void textbackground (int color)
{
    if ( 0<=color && color<=7 )
    {
       __BACKGROUND = color;
       color = __FOREGROUND + (__BACKGROUND << 4);
       SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), color);
    }
}

/**
 *  Veraendert das Erscheinungsbild des Cursors
 */
void _setcursortype (DWORD type)
{
	CONSOLE_CURSOR_INFO Info;   /* Erzeugt Info-Objekt */
    GetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
    if (type == 0)
    {
        Info.bVisible = FALSE;
    }
    else
    {
        Info.dwSize = type;
        Info.bVisible = TRUE;
    }
    SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}

/**
 * Loesche Eventpuffer
 */
void flush(void)
{
    FlushConsoleInputBuffer( GetStdHandle (STD_INPUT_HANDLE) );
}

/**
 *  Setzt die Konsole mit Titel
 */
void setconsole( char * text)
{
	SetConsoleTitle(text);

    // Definierung der maximalen Fenstergröße
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSize = GetLargestConsoleWindowSize(hOut);
    SetConsoleScreenBufferSize(hOut, NewSize);

    // Neu-Platzierung des Konsolenfensters
	SMALL_RECT DisplayArea = {0, 0, 0, 0};
	DisplayArea.Right = NewSize.X - 70;
    DisplayArea.Bottom = NewSize.Y - 30;
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);

	// Setze Cursor unsichtbar und loesche Tastaturpuffer
	_setcursortype(_NOCURSOR);
	flush();
}

/**
 *  Setzt die Konsole auf den Standard zuruek
 */
void resetconsole(void)
{
  	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	_setcursortype(_NORMALCURSOR);
	flush();
}

/**
 *  Ermittelt aktuelle und max Anzahl der Zeilen und Spalten des Bildschirms
 *  Standard: 25 x 80
 */

int cols(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwSize.X ;
}

int maxcols(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwMaximumWindowSize.X ;
}

int rows(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwSize.Y ;
}

int maxrows(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwMaximumWindowSize.Y ;
}


/**
 *  Positioniert den Cursor
 *  (nur wenn im erlaubten Bereich)
 */
void gotoxy(int xpos, int ypos)
{
    if ( 0 < xpos && xpos < cols() &&
         0 < ypos && ypos < rows()     )
    {
       COORD Screenpos;
       Screenpos.X = xpos - 1;
       Screenpos.Y = ypos - 1;
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Screenpos);
    }
}


/**
 *  Ermitteln den aktuellen Ort des Cursors
 */
int wherex(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwCursorPosition.X + 1;
}

int wherey(void)
{
   CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
   GetConsoleScreenBufferInfo( GetStdHandle (STD_OUTPUT_HANDLE), &BufferInfo );
   return BufferInfo.dwCursorPosition.Y + 1;
}

/**
 *  Loescht den Bildschirm und verwendet dazu die zuvor gesetzten Farbwerte
 *  z.B. wenn textbackground() oder textcolor() verwendet wurde.
 */
void clrscr(void)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char color =  __FOREGROUND + (__BACKGROUND << 4);
    int anzahl = maxcols() * maxrows();
    COORD Startpos = {0,0};
    DWORD ergebnis;  /* Anzahl des geschriebenen Zellen */

    FillConsoleOutputAttribute( h, color, anzahl, Startpos, &ergebnis);
    FillConsoleOutputCharacter( h,  ' ' , anzahl, Startpos, &ergebnis);
    gotoxy (1, 1);
}

/*
   Alternativ kann man DOS-Befehle mit der system()-Funktion ausfuehren.
   Beispiele: system("cls") oder system("pause")
   Nachteil: langsam, weniger sicher und nutzt die Farbwerte nicht
*/


 /**
  *   Wartet die angegebenen Millisekunden
  *   Besser: Sleep(millisekunden)
  */
void delay(int msec)
{
    long start = clock();  /* clock() liefert Zeit seit Start des Rechners  */
    long dauer = msec * (CLOCKS_PER_SEC / 1000);  /* Anpassen an PC speed */
    long ende = start + dauer;

    while( clock() < ende );  // haut die Zeit aufwendig tot
}


/**
 *  Initialisiert den Zufallsgenerator
 */
void randomize(void)
{
     srand( (unsigned) time(NULL));
}
/*
   Anmerkung:
   srand() setzt den Zufallsgenerator auf neuen Startwert
   Ohne srand()-Aufruf wuerde rand() immer den gleichen Wert ausgeben
   time(NULL) liefert die Anzahl der vergangenen Sekunden seit dem 1.1.1970
   Es genuegt, randomize() einmal am Anfang des Programms aufzurufen.
*/


/**
 *  Gibt einen Zufallswert als Ganzzahl zwischen 0 und max-1 aus
 */
int random(int max)
{
    return rand() % max;
}
/* Anmerkung:
   rand() liefert einen Zufallswert zwischen 0 und RAND_MAX (= 32767)
   Wir wollen aber einen Wert zwischen 0 und max-1 ...

   Der Modulo-Operator (%) errechnet den *Rest* einer Integerdivision
   Beispiel fuer verschiedene rand()-Ausgaben und max = 4:
   Zahl von rand()    rand() % 4
        0                0
        1                1
        2                2
        3                3
        4                0
        5                1
        6                2
        7                3
        8                0
        9                1
       10                2
       ...              ...

   d.h random(4) erzeugt einen Returnwert zwischen 0 und 3

*/




/* ========================================================================== */
/*                          SELBSTGESCHRIEBENE                                */
/*           UND IN VC++ GETESTETE FUNKTIONEN FUER INTERESSIERTE              */
/*                  (zum Auskommentieren, ohne Garantie)                      */
/* ========================================================================== */
/*                     Matthias.Ebert@BS-Erlangen.de                          */


/**
 *  Schreibe ein ASCII-Zeichen in den Bildschirmpuffer
 *  an die aktuelle Cursorposition und gehe eine Position weiter
 */
/*
void putch(int in)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    GetConsoleScreenBufferInfo( h, &BufferInfo );
	COORD Startpos = { wherex()-1, wherey()-1 };
    DWORD ergebnis;

    FillConsoleOutputAttribute( h, 0x07, 1, Startpos, &ergebnis);
    FillConsoleOutputCharacter( h,  in , 1, Startpos, &ergebnis);
	gotoxy(wherex()+1, wherey());
	return;
}
*/


/**
 *  Schreibe ein ASCII-Zeichen in den Bildschirmpuffer
 *  incl. der aktellen Farbeinstellung
 *  an die aktuelle Cursorposition und gehe eine Position weiter
 */
/*
void cputch(int in)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    char color =  __FOREGROUND + (__BACKGROUND << 4);
    CONSOLE_SCREEN_BUFFER_INFO BufferInfo;
    GetConsoleScreenBufferInfo( h, &BufferInfo );
	COORD Startpos = { wherex()-1, wherey()-1 };
    DWORD ergebnis;

    FillConsoleOutputAttribute( h, color, 1, Startpos, &ergebnis);
    FillConsoleOutputCharacter( h,  in , 1, Startpos, &ergebnis);
	gotoxy(wherex()+1, wherey());
	return;
}
*/


/**
 *  Schreibe einen ASCII-String in den Bildschirmpuffer
 *  incl. der aktellen Farbeinstellung
 *  an die aktuelle Cursorposition und gehe eine Position weiter
 */
/*
void cputs(const char * in)
{
	int i;
	for(i=0; in[i]!=0; i++) cputch(in[i]);
}
*/


/**
 *  Lese 1 ASCII-Zeichen aus dem Eventpuffer
 */
/*
int getch()
{
	INPUT_RECORD input;
	DWORD erg;
	do
	{
		ReadConsoleInput( GetStdHandle(STD_INPUT_HANDLE), &input, 1, &erg);
	}
	while(input.Event.KeyEvent.uChar.AsciiChar == 0);
	return input.Event.KeyEvent.uChar.AsciiChar;
}
*/


/**
 *  Lese 1 ASCII-Zeichen aus dem Eventpuffer
 *  und gib es aus
 */
/*
int getche()
{
	int tmp = getch();
	if ( tmp >= 32 && tmp <= 255 )
		cputch (tmp);
	return tmp;
}
*/


/**
 *  Prüfe ob sich ein ASCII-Zeichen im Eventpuffer befindet
 */
/*
int kbhit()
{
	INPUT_RECORD input[255];
	DWORD erg;
	int i;
	bool found = 0;

    PeekConsoleInput( GetStdHandle(STD_INPUT_HANDLE), input, 255, &erg);
  	for(i=0;i<255;i++)
	{
		if(input[i].EventType == 1)
		{
			found = 1;
			break;
		}
	}
	return found;
}
*/


/**
 *  Lese den aktuellen Eventtyp
 *  1 = Tastatur
 *  2 = Maus
 *  4 = Window change
 *  8 = Menu change
 * 16 = Focus change
 */
/*
int geteventtype(void)
{
    INPUT_RECORD input;
	DWORD erg;
    ReadConsoleInput( GetStdHandle(STD_INPUT_HANDLE), &input, 1, &erg);
	return input.EventType;
}
*/


/**
 *  Lese Anzahl von Events im Eventpuffer
 *  Tastatur: Key_down / Key_up ?
 *  Maus: ?
 */
/*
int getnumberofevents(void)
{
	DWORD erg;
    GetNumberOfConsoleInputEvents( GetStdHandle(STD_INPUT_HANDLE), &erg);
	return erg;
}
*/

#endif /* _BSE_CONSOLE_H */
