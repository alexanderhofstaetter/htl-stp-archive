#include "labyrinth.h"
#include "bse_console.h"

Labyrinth::Labyrinth(int xmax, int ymax)
{
   if(xmax <= 10) xmax = 11;
   if(ymax <= 10) ymax = 11;

   if(xmax%2 == 0) xmax++;
   if(ymax%2 == 0) ymax++;

   data = NULL;                                       // Doppelter Zeiger auf dynamisches Array
   this->xmax = xmax;
	this->ymax = ymax;
	symetric_enable = true;

	data = new unsigned char*[xmax];                   // Neues dynamisches Char Array (0-256)
	solve = new unsigned char*[xmax];
   for(int x = 0; x < xmax; x++)
   {  data[x] = new unsigned char[ymax];              // Neues dynamisches Char Array für jedes Feldelement (0-256)
      solve[x] = new unsigned char[ymax];
   }

   for(int x = 0; x < xmax; x++)
      for(int y = 0; y < ymax; y++)
      {  data[x][y] = WAND;                           // Initialisierung mit WAND
         solve[x][y] = WAND;
      }
   Start_End_Points();
}

Labyrinth::~Labyrinth()
{
   for(int i = 0; i < xmax; i++)    // Alle Array Elemente löschen
	{	delete [] data[i];
      delete [] solve[i];
		data[i] = NULL;
		solve[i] = NULL;
	}
	delete [] data;
	delete [] solve;
	data = NULL;
	solve = NULL;
	xmax = ymax = NULL;
	xstart = ystart = dirstart = NULL;
	xend = yend = dirend = NULL;
}

int Labyrinth::DigIt()
{
   return DigIt(xstart,ystart,dirstart);
}

int Labyrinth::DigIt(int x, int y, int dir)
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

   gotoxy(x+2,y+2);
   printf("%c",GANG);
	Sleep(10);

   if(dirend == oben && x == xend && (y-yend <=1 && y-yend > 0))
         DigIt(x,y-1,dirend);
   if(dirend == rechts && (xend-x <=1 && xend-x > 0) && y == yend)
         DigIt(x+1,y,dirend);
   if(dirend == unten && x == xend && (yend-y <=1 && yend-y > 0))
         DigIt(x,y+1,dirend);
   if(dirend == links && (x-xend <=1 && x-xend > 0) && y == yend)
         DigIt(x-1,y,dirend);

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
				DigIt(x, y-1, unten);
		}
		if(nextdir == rechts && symetric[rechts])
		{
		   dx = x+1;
			dig = true;
			for(int i = 0; i < movey; i++)
			{	dy = y-1;
				if(dx >= xmax || dy < 0) dig = false;
				for(int j = 0; j < movex && dig == true; j++)
				{	if(data[dx][dy] == GANG || dy >= ymax)
						dig = false;
					dy += 1;
				}
				dx += 1;
			}
			if(dig == true)
				DigIt(x+1, y, links);
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
				DigIt(x, y+1, oben);
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
				DigIt(x-1, y, rechts);
		}

	}while(AlreadyDigged[0] == false || AlreadyDigged[1] == false || AlreadyDigged[2] == false || AlreadyDigged[3] == false);
	return 0;
}

int Labyrinth::Solve(int x, int y, int dir)
{
	int nextdir, dx, dy;
   if(x == xend && y == yend)
      gefunden = true;
	bool AlreadyDigged[4] = {false};
	bool dig = false;
	bool symetric[4] = {false};

	solve[x][y] = GANG;
	AlreadyDigged[dir] = true;

   Sleep(10);
	gotoxy(x+2,y+2);
   if(solve[x][y] == GANG)
   {  textcolor(YELLOW);
      printf("0");
      textcolor(LIGHTGRAY);
   }

   //DisplaySolve();

	do
	{	do
         dir = rand()%4;
		while(AlreadyDigged[dir] == true);

      AlreadyDigged[dir] = true;

      if(dir == oben   && !gefunden)
		{  dx = x;   dy = y-1; nextdir = unten;
		}
		if(dir == rechts && !gefunden)
		{  dx = x+1; dy = y;   nextdir = links;
		}
		if(dir == unten  && !gefunden)
		{  dx = x;   dy = y+1; nextdir = oben;
		}
		if(dir == links  && !gefunden)
		{  dx = x-1; dy = y;   nextdir = rechts;
		}

      if(data[dx][dy] == GANG && dx >= 0 && dy >= 0 && dx < xmax && !gefunden)
      {  Solve(dx, dy, nextdir);
         solve[dx][dy] = TRIED;
         gotoxy(dx+2,dy+2);
         if(solve[dx][dy] == TRIED)
            printf(" ");

      }

	}while(AlreadyDigged[0] == false || AlreadyDigged[1] == false || AlreadyDigged[2] == false || AlreadyDigged[3] == false);
	gotoxy(dx+2,dy+2);
   if(solve[dx][dx] == TRIED && !gefunden)
      printf(" ");
	return 0;
}

int Labyrinth::Solve()
{
   printf("end: %d,%d",xend,yend);
   return Solve(xstart,ystart,dirstart);
}

int Labyrinth::Display()
{
   printf("\n");
   for(int y = 0; y < ymax; y++)
	{  printf(" ");
	   for(int x = 0; x < xmax; x++)
      {  if(data[x][y] == GANG) printf("%c",' ');
         if(data[x][y] == WAND) printf("%c",219);
      }
		printf("\n");
	}
	return 0;
}

int Labyrinth::DisplaySolve()
{
   for(int y = 0; y < ymax; y++)
	{  for(int x = 0; x < xmax; x++)
      {  gotoxy(x+2,y+2);
         if(solve[x][y] == GANG)
         {  textcolor(YELLOW);
            printf("0");
            textcolor(LIGHTGRAY);
         }
         if(solve[x][y] == TRIED)
         {  printf(" ");
         }
      }
	}
	return 0;
}

void Labyrinth::Start_End_Points()
{
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
   }
}
