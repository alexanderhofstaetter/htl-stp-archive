#ifndef GETCH_CONSOLE_H_INCLUDED
#define GETCH_CONSOLE_H_INCLUDED

/**
 *  Includieren der benoetigten Header, die in MinGW und VC++ bereits existieren
 */
#include <windows.h>  /* fuer GetStdHandle(), Sleep(), Beep(), etc            */

int getch_console()
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
#endif // GETCH_CONSOLE_H_INCLUDED
