////////////////////////////////////////////////////////////////////////////
//   Programmname : controlboard.h
//   DI W.Alfery
//
//   Control Board -  Steuerungsanzeige
//
/////////////////////////////////////////////////////////////////////////////


#ifndef CONTROLBOARD_H
#define CONTROLBOARD_H


typedef unsigned char byte;       // Typdefinition für Byte (8 Bit)

void drawBoard();
void updateBoard(byte *portin, byte *portout);
void clearBoard();


#endif  // CONTROLBOARD_H
