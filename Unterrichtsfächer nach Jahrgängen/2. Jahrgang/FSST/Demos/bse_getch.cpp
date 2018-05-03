
#include <windows.h>  /* fuer GetStdHandle(), Sleep(), etc                    */


/**
 *  Lese 1 ASCII-Zeichen aus dem Eventpuffer
 */

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


