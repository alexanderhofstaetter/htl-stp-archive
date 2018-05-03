#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bse_console.h"

#include "labyrinth.h"

#define ESC 27
#define SYMBOL_WAY '0'

int main()
{
   srand(time(NULL));
   char menue;
   do
   {  int xmax = 100 , ymax = 60;
      system("CLS");

      system("mode con: cols=82 lines=24");
      printf(" Labyrinth erzeugen\n");
      //printf(" Breite (x)= "); scanf("%d",&xmax);
      //printf(" Hoehe (y)= "); scanf("%d",&ymax);
      system("CLS");


      Labyrinth lab(xmax,ymax);                     // Instanz erzeugen mit Zuweisung der Maximalwerte

      char SYS_string[50];
      sprintf(SYS_string,"mode con: cols=%d lines=%d",lab.GetWindowWidthX(),lab.GetWindowWidthY());
      system(SYS_string);

      lab.SetShowDigProcess(true,5);
      system("CLS");
      lab.GenerateStart(DFS);
      //lab.Display(true);
      menue = getch();

      system("CLS");
      lab.SetShowSolveProcess(true,5);
      lab.SolveStart();
      lab.Display(2);
      menue = getch();
      lab.~Labyrinth();                             // Manueller Destruktor-Aufruf
   }while(menue!=ESC);

	return 0;
}

Labyrinth::Labyrinth(int xmax, int ymax)
{
   if(xmax <= 10) xmax = 11;
   if(ymax <= 10) ymax = 11;

   if(xmax%2 == 0) xmax++;
   if(ymax%2 == 0) ymax++;

   DisplayOffsetX = 10;
   DisplayOffsetY = 4;
   ShowDigProcess = false;
   ShowSolveProcess = false;
   DigProcessTime = 10;
   SolveProcessTime = 10;

   data = new unsigned char*[xmax];                   // Neues dynamisches Char Array (0-256)
   solve = new unsigned char*[xmax];
   for(int x = 0; x < xmax; x++)
   {  data[x] = new unsigned char[ymax];              // Neues dynamisches Char Array für jedes Feldelement (0-256)
      solve[x] = new unsigned char[ymax];
      for(int y = 0; y < ymax; y++)
         data[x][y] = solve[x][y] = WAND;                           // Initialisierung mit WAND
   }

   this->xmax = xmax;
   this->ymax = ymax;
   symetric_enable = true;

   Start_End_Points();
}

Labyrinth::~Labyrinth()
{
   if(data != NULL)
   {  for(int i = 0; i < xmax; i++)    // Alle Array Elemente löschen
      {	delete [] data[i];
         data[i] = NULL;
      }
      delete [] data;
      data = NULL;
   }

   if(solve != NULL)
   {  for(int i = 0; i < xmax; i++)    // Alle Array Elemente löschen
      {	delete [] solve[i];
         solve[i] = NULL;
      }
      delete [] solve;
      solve = NULL;
   }

	xmax = ymax = NULL;
	xstart = ystart = dirstart = NULL;
	xend = yend = dirend = NULL;
}

int Labyrinth::GenerateStart(int algorithm)
{
   if(algorithm == DFS)
   {  for(int x = 0; x < xmax; x++)
         for(int y = 0; y < ymax; y++)
            data[x][y] = WAND;                           // Initialisierung mit WAND

      if(ShowDigProcess == true)
         Display(1);

      return GenerateDFS(xstart,ystart,dirstart);
   }

   else if(algorithm == RDM)
   {  for(int x = 0; x < xmax; x++)
         for(int y = 0; y < ymax; y++)
            data[x][y] = WAND;                           // Initialisierung mit WAND

      for(int x = 1; x < xmax-1; x++)
         for(int y = 1; y < ymax-1; y++)
            data[x][y] = GANG;                           // Initialisierung mit WAND

      if(ShowDigProcess == true)
         Display(1);

      return GenerateRDM(0,0,xmax,ymax);
   }
}

int Labyrinth::GenerateDFS(int x, int y, int dir)
{
   int nextdir, dx = 0, dy = 0;
	unsigned char movex = 3, movey = 2;

	bool AlreadyDigged[4] = {false};
	bool dig = false;
	bool symetric[4] = {false};

	if(symetric_enable)
   {  symetric[oben]   = symetric[unten] = x%2;
      symetric[rechts] = symetric[links] = y%2;
   }
   else
      symetric[oben] = symetric[rechts] = symetric[unten] = symetric[links] = 1;


	data[x][y] = GANG;
	AlreadyDigged[dir] = true;

   if(ShowDigProcess == true)
   {  gotoxy(x+2,y+2);
      if(x == xstart && y == ystart)
      {  textcolor(LIGHTGREEN);
         printf("%c",219);
         textcolor(LIGHTGRAY);
      }
      else if(x == xend && y == yend)
      {  textcolor(LIGHTRED);
         printf("%c",219);
         textcolor(LIGHTGRAY);
      }
      else
         printf("%c",GANG);
      Sleep(DigProcessTime);
   }

	do
	{	do
         nextdir = rand()%4;
		while(AlreadyDigged[nextdir] == true);

      AlreadyDigged[nextdir] = true;

      if(nextdir == oben   && symetric[oben])
		{
		   dy = y-1;
			dig = true;
			for(int i = 0; i < movey; i++)
			{	dx = x-1;
				if(dx < 0 || dy < 0) dig = false;
				for(int j = 0; j < movex && dig == true; j++)
				{	if(data[dx][dy] == GANG || dx >= xmax)
						dig = false;
					dx += 1;
				}
				dy -= 1;
			}
			if(dig == true)
				GenerateDFS(x, y-1, unten);
		}
		if(nextdir == rechts && symetric[rechts])
		{
		   dx = x+1;
			dig = true;
			for(int i = 0; i < movey; i++)
			{	dy = y-1;
				if(dx >= xmax || dy < 0) dig = false;
				for(int j = 0; j < movex && dig; j++)
				{	if(data[dx][dy] == GANG || dy >= ymax)
						dig = false;
					dy += 1;
				}
				dx += 1;
			}
			if(dig == true)
				GenerateDFS(x+1, y, links);
		}
		if(nextdir == unten  && symetric[unten])
		{
		   dy = y+1;
			dig = true;
			for(int i = 0; i < movey; i++)
			{	dx = x -1;
				if(dx < 0 || dy >= ymax) dig = false;
				for(int j = 0; j < movex && dig == true; j++)
				{	if(data[dx][dy] == GANG || dx >= xmax)
						dig = false;
					dx += 1;
				}
				dy += 1;
			}
			if(dig == true)
				GenerateDFS(x, y+1, oben);
		}
		if(nextdir == links  && symetric[links])
		{
		   dx = x-1;
			dig = true;
			for(int i = 0; i < movey; i++)
			{	dy = y-1;
				if(dx < 0 || dy < 0) dig = false;
				for(int j = 0; j < movex && dig == true; j++)
				{	if(data[dx][dy] == GANG || dy >= ymax)
						dig = false;
					dy += 1;
				}
				dx -= 1;
			}
			if(dig == true)
				GenerateDFS(x-1, y, rechts);
		}

	}while(AlreadyDigged[0] == false || AlreadyDigged[1] == false || AlreadyDigged[2] == false || AlreadyDigged[3] == false);
	return 0;
}

int Labyrinth::GeneratePrim(int x, int y, int dir)
{
	return 0;
}

int Labyrinth::GenerateRDM(int xstart, int ystart, int xend, int yend)
{
   system("CLS");
   Display(1);
   Sleep(10);

   int x,y,sector;
   int HoleX,HoleY;
   bool RandNew;

   RandNew = false;
   do
   {  do
         x = rand()%((xend-1)-(xstart+1)+1)+xstart+1;
      while(x%2);
      for(int i = ystart+1; i < yend-1 && !RandNew; i++)
      {  if(data[x][i] == WAND)
            RandNew = true;
         if(data[x-1][i] == WAND || data[x+1][i])
            RandNew = true;
      }
   }
   while(RandNew);

   RandNew = false;
   do
   {  do
         y = rand()%((yend-1)-(ystart+1)+1)+ystart+1;
      while(y%2);
      for(int i = ystart+1; i < xend-1 && !RandNew; i++)
      {  if(data[i][y] == WAND)
            RandNew = true;
         if(data[i][y-1] == WAND || data[i][y+1])
            RandNew = true;
      }
   }
   while(RandNew);

   for(int i = 0; i < ymax; i++)
      data[x][i] = WAND;

   for(int i = 0; i < xmax; i++)
      data[i][y] = WAND;

   //do
      HoleX = rand()%((xend-1)-(xstart+1)+1)+xstart+1;
   //while(data[HoleX+1][y] == WAND || data[HoleX-1][y] == WAND || data[HoleX][y+1] == WAND || data[HoleX][y-1] == WAND);

   //do
      HoleY = rand()%((yend-1)-(ystart+1)+1)+ystart+1;
   //while(data[x+1][HoleY] == WAND || data[x-1][HoleY] == WAND || data[x][HoleY+1] == WAND || data[x][HoleY-1] == WAND);

   data[HoleX][y] = GANG;
   data[x][HoleY] = GANG;

   if(xend-xstart < 2 || yend-ystart < 2)
      return 0;

   bool AlreadyDivided[4] = {false};

   do
   {  do
         sector = rand()%4;
      while(AlreadyDivided[sector] == true);
      AlreadyDivided[sector] = true;

      if(sector == 0)
      {  GenerateRDM(0,0,x,y);
      }
      if(sector == 1)
      {  GenerateRDM(x,0,xend,yend);
      }
      if(sector == 2)
      {  GenerateRDM(x,0,xend,y);
      }
      if(sector == 3)
      {  GenerateRDM(0,y,x,yend);
      }
   }while(AlreadyDivided[0] == false || AlreadyDivided[1] == false || AlreadyDivided[2] == false || AlreadyDivided[3] == false);
   return 0;
}

int Labyrinth::SolveStart()
{
   for(int x = 0; x < xmax; x++)
         for(int y = 0; y < ymax; y++)
            solve[x][y] = WAND;                           // Initialisierung mit WAND

   if(ShowSolveProcess == true)
         Display(1);

   return Solve(xstart,ystart,dirstart);
}

int Labyrinth::Solve(int x, int y, int dir)
{
	int nextdir, dx, dy;
	bool AlreadyTried[4] = {false};
	int gefunden = 0;

	if(xend == x && y == yend)
      return 1;

	solve[x][y] = SOLVE;
	if(ShowSolveProcess == true && (x != xstart || y != ystart))
   {  gotoxy(x+2,y+2);
      textcolor(YELLOW);
      printf("%c",SYMBOL_WAY);
      Sleep(SolveProcessTime);
      textcolor(LIGHTGRAY);
   }
	AlreadyTried[dir] = true;

	do
	{	do
         dir = rand()%4;
		while(AlreadyTried[dir] == true);
      AlreadyTried[dir] = true;

      if(dir == oben)
		{  dx = x;
         dy = y-1;
         nextdir = unten;
		}
		if(dir == rechts)
		{  dx = x+1;
         dy = y;
         nextdir = links;
		}
		if(dir == unten)
		{  dx = x;
         dy = y+1;
         nextdir = oben;
		}
		if(dir == links)
		{  dx = x-1;
         dy = y;
         nextdir = rechts;
		}

      if(data[dx][dy] == GANG && dx >= 0 && dy >= 0 && dx < xmax)
      {  gefunden = Solve(dx, dy, nextdir);
         if(gefunden == 0)
            solve[dx][dy] = TRIED;
         else
            return 1;
      }

	}while(AlreadyTried[0] == false || AlreadyTried[1] == false || AlreadyTried[2] == false || AlreadyTried[3] == false);
   if(ShowSolveProcess == true)
   {  gotoxy(x+2,y+2);
      textcolor(LIGHTRED);
      printf("%c",'0');
      Sleep(SolveProcessTime);
      textcolor(LIGHTGRAY);
   }
   return gefunden;
}

int Labyrinth::Display(int DisplayWithSolve)
{
   printf("\n");
   for(int y = 0; y < ymax; y++)
	{  printf(" ");
	   for(int x = 0; x < xmax; x++)
      {  if(x == xstart && y == ystart)
         {  textcolor(LIGHTGREEN);
            printf("%c",219);
            textcolor(LIGHTGRAY);
         }
         else if(x == xend && y == yend)
         {  textcolor(LIGHTRED);
            printf("%c",219);
            textcolor(LIGHTGRAY);
         }
         else if(DisplayWithSolve >= 2 && DisplayWithSolve <= 3 && solve[x][y] == SOLVE)
         {  textcolor(YELLOW);
            printf("%c",SYMBOL_WAY);
            textcolor(LIGHTGRAY);
         }
         else if(DisplayWithSolve == 2 && DisplayWithSolve != 3 && solve[x][y] == TRIED)
         {  textcolor(LIGHTRED);
            printf("%c",SYMBOL_WAY);
            textcolor(LIGHTGRAY);
         }
         else if(data[x][y] == WAND) printf("%c",219);
         else if(data[x][y] == GANG) printf("%c",' ');
         else return -1;
      }
		printf("\n");
	}
	return 0;
}

void Labyrinth::Start_End_Points()
{
   switch(rand()%4)
   {  case 0:                                           // Startpunkt links oben
         xstart = 1;
         ystart = 1;
         if(rand()%2 == 0)
            dirstart = unten;
         else
            dirstart = rechts;

         xend = xmax - 2;
         yend = ymax - 2;
         break;
      case 1:                                           // Startpunkt rechts oben
         xstart = xmax - 2;
         ystart = 1;
         if(rand()%2 == 0)
            dirstart = links;
         else
            dirstart = unten;

         xend = 1;
         yend = ymax - 2;
         break;
      case 2:                                           // Startpunkt rechts unten
         xstart = xmax - 2;
         ystart = ymax - 2;
         if(rand()%2 == 0)
            dirstart = oben;
         else
            dirstart = links;

         xend = 1;
         yend = 1;
         break;
      case 3:                                           // Startpunkt links unten
         xstart = 1;
         ystart = ymax - 2;
         if(rand()%2 == 0)
            dirstart = rechts;
         else
            dirstart = oben;

         xend = xmax - 2;
         yend = 1;
         break;
   }
   /*
   switch(rand()%4)
   {  case oben:                                            // Startpunkt oben
         do
            xstart = rand()%(xmax-2)+1;
         while ((xstart)%2 == 0);
         ystart = 0;
         dirstart = oben;

         xend = xmax - 1 - xstart;
         yend = ymax - 1;
         dirend = unten;
         break;
      case rechts:                                          // Startpunkt rechts
         xstart = (xmax-1);
         do
            ystart = rand()%(ymax-2)+1;
         while ((ystart)%2 == 0);
         dirstart = rechts;

         xend = 0;
         yend = ymax - 1 - ystart;
         dirend = links;
         break;
      case unten:                                           // Startpunkt unten
         do
            xstart = rand()%(xmax-2)+1;
         while((xstart)%2==0);
         ystart = ymax-1;
         dirstart = unten;

         xend = xmax - 1 - xstart;
         yend = 0;
         dirend = oben;
         break;
      case links:                                           // Startpunkt links
         xstart = 0;
         do
            ystart = rand()%(ymax-2)+1;
         while((ystart%2) == 0);
         dirstart = links;

         xend = xmax - 1;
         yend = ymax - 1 - ystart;
         dirend = rechts;
         break;
   }*/
}
