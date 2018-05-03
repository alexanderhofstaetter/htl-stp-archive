#ifndef LABYRINTH_H_INCLUDED
#define LABYRINTH_H_INCLUDED

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define oben 0
#define rechts 1
#define unten 2
#define links 3

#define GANG 0
#define WAND 1
#define SOLVE 2
#define TRIED 3

#define DFS 0
#define RDM 1
#define PRIM 2

class Labyrinth
{
private:
      int xmax, ymax;
      int DisplayOffsetX, DisplayOffsetY;
      int xstart, ystart, dirstart;
      int xend, yend, dirend;
      int DigProcessTime, SolveProcessTime;

      bool ShowDigProcess, ShowSolveProcess;
      bool symetric_enable;

      unsigned char **data;
      unsigned char **solve;

private:
      void Start_End_Points();

public:
      Labyrinth(int x, int y);
      ~Labyrinth();
      int GenerateStart(int algorithm);
      int GenerateDFS(int x, int y, int dir);
      int GeneratePrim(int x, int y, int dir);
      int GenerateRDM(int xstart, int ystart, int xend, int yend);
      int SolveStart();
      int Solve(int x, int y, int dir);
      int Display(int DisplayWithSolve);

      int GetWindowWidthX()
      {  return xmax + DisplayOffsetX;
      }
      int GetWindowWidthY()
      {  return ymax + DisplayOffsetY;
      }

      void SetXmax(int x)
      {  xmax = x;
      }
      void SetYmax(int y)
      {  ymax = y;
      }
      void SetDisplayOffsetX(int x)
      {  DisplayOffsetX = x;
      }
      void SetDisplayOffsetY(int y)
      {  DisplayOffsetY = y;
      }
      void SetShowSolveProcess(bool enable)
      {  ShowSolveProcess = enable;
      }
      void SetShowSolveProcess(bool enable, int time_ms)
      {  ShowSolveProcess = enable;
         SolveProcessTime = time_ms;
      }
      void SetShowDigProcess(bool enable)
      {  ShowDigProcess = enable;
      }
      void SetShowDigProcess(bool enable, int time_ms)
      {  ShowDigProcess = enable;
         DigProcessTime = time_ms;
      }



};

#endif // LABYRINTH_H_INCLUDED
