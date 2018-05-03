#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>               // Für SetConsoleTitle
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main()
{
    srand(time(NULL));
    const int N = 100;
    char text[N];
    printf(" Text einlesen:\n");
    //cin >> text;
    long double schluessel = rand()%10000000;
    printf("%d",schluessel);
    //for (int i=0;i<N;i++)

    return 0;
}
