/* ========================================================================== */
/*                                                                            */
/*   Dateiname: bse_console.h                                                 */
/*     Version: 1.2.2                                                         */
/*     Autoren: Jens Herbst, Tobias Ackermann, Matthias Ebert                 */
/*       Datum: 22.02.09                                                      */
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
/*                                                                            */
/*       Usage: Diese Datei bse_console.h in den Projektordner aufnehmen      */
/*              und in den eigenen Quellcode integrieren:                     */
/*              #include "bse_console.h"                                      */
/*              Bei MINGW muss beim Uebersetzen folgendes angegeben werden    */
/*              gcc test.c -o text.exe -lconio                                */
/*                                                                            */
/*        ToDo: Testing !!                                                    */
/*                                                                            */
/* Feedback an: Matthias.Ebert@BS-Erlangen.de                                 */
/*                                                                            */
/*     Tipps: - Die Funktion Sleep(int millisekunden) in der Windows-API      */
/*              ersetzt die sleep(int sekunden)-Funktion von dos.h            */
/*            - Die Funktion Beep( int frequenz_in Hz, int dauer_in ms)       */
/*              ersetzt die sound(), nosound()-Funktionen von conio.h         */
/*              z.B. C = 440Hz muesste funktionieren                          */
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
#include <windows.h>  /* fuer GetStdHandle(), Sleep(), etc                    */
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
 *  Cursor-Fuellung in Prozent der Zellhoehe 
 */
#define _NOCURSOR        0
#define _NORMALCURSOR   20
#define _SOLIDCURSOR   100


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
*/

/**
 *  Diese folgenden globale Variablen koennen in allen Unterprogrammen 
 *  gelesen und geschrieben werden. 
 *  static bedeutet, dass sie falls sie in MinGW oder VC++ schon existieren  
 *  nicht mehr neu angelegt werden.
 */
static int __BACKGROUND = 0;
static int __FOREGROUND = 0x7;

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
 * Loesche Eventpuffer
 */
void flush(void)
{
    FlushConsoleInputBuffer( GetStdHandle (STD_INPUT_HANDLE) );
}


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