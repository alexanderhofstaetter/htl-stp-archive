//Dimitri B. PONG
#include <stdio.h>
#include <stdlib.h>
#include "bse_console.h"
#include <time.h>

#define BLOCK 219
#define W_LEFT 10
#define W_RIGHT 65
#define W_TOP 4
#define W_BOTTOM 25
#define MAX_DIR 4
#define MAX_TIME_SNOW 1
#define MAX_TIME_MELT 1
#define SNOW 10000



int main(void)
{

    int i;

    for(i=W_LEFT;i<=W_RIGHT;i++)
    {
        gotoxy(i,W_TOP);
        printf("%c",BLOCK);
        gotoxy(i,W_BOTTOM);
        printf("%c",BLOCK);

    }

    for(i=W_TOP;i<=W_BOTTOM;i++)
    {
        gotoxy(W_RIGHT,i);
        printf("%c",BLOCK);
        gotoxy(W_LEFT,i);
        printf("%c",BLOCK);
    }                           // Bis hier Rand
/*



    int posX, posY, dir, old_PosX, old_PosY, t, letter, farbe;

    int a;
    a=1;

    while(a<SNOW)
    {


    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    letter=rand()%(255-33);

    t=rand()%(MAX_TIME_SNOW);

    gotoxy(posX,posY);
    printf("%c",letter);


    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    t=rand()%(MAX_TIME_SNOW);

    gotoxy(posX,posY);
    printf("*");

    a++;

    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    dir=rand()%(MAX_DIR);

    t=rand()%(MAX_TIME_MELT);

    gotoxy(posX,posY);
    printf(" ");

    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    dir=rand()%(MAX_DIR);

    t=rand()%(MAX_TIME_MELT);

    gotoxy(posX,posY);
    printf(" ");


    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    dir=rand()%(MAX_DIR);

    t=rand()%(MAX_TIME_MELT);

    gotoxy(posX,posY);
    printf(" ");

    posX=rand()%((W_RIGHT-1)-W_LEFT)+W_LEFT+1;

    posY=rand()%((W_BOTTOM-1)-W_TOP)+W_TOP+1;

    dir=rand()%(MAX_DIR);

    t=rand()%(MAX_TIME_MELT);


    farbe=rand()%(15);

    textcolor(farbe);



    gotoxy(posX,posY);
    printf(" ");





    delay(t);

    }

    gotoxy(1,25);*/


    return 0;
}
