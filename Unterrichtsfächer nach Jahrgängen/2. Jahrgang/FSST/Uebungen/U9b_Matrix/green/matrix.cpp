#include <iostream>
#include "bse_console.h"

const int N=80;
char caRow[80];

using namespace std;

int Modulus(int iN, int iMod)
{
    int iQ = (iN/iMod);
    return iN - (iQ*iMod);
}

char GetChar(int iGenerator, char cBase, int iRange)
{
    return (cBase + Modulus(iGenerator, iRange));
}

int main()
{
   textbackground(GREEN);
   system("CLS");
   textcolor(BLACK);
   int j = 7, k = 2, l = 5, m = 1;
   while (1)
   {  for(int i=0;i<N;i++)
      {  if (caRow[i] != ' ')
         {
            switch(rand()%15+1)
            {
               case 1: caRow[i] = '1'; break;
               case 2: caRow[i] = '2'; break;
               case 3: caRow[i] = '3'; break;
               case 4: caRow[i] = '4'; break;
               case 5: caRow[i] = '5'; break;
               case 6: caRow[i] = '6'; break;
               case 7: caRow[i] = '7'; break;
               case 8: caRow[i] = '8'; break;
               case 9: caRow[i] = '9'; break;
               case 10: caRow[i] = 'A'; break;
               case 11: caRow[i] = 'B'; break;
               case 12: caRow[i] = 'C'; break;
               case 13: caRow[i] = 'D'; break;
               case 14: caRow[i] = 'E'; break;
               case 15: caRow[i] = 'F'; break;
            }

         }
         cout << caRow[i];
      }
      j+=31; k+=17; l+=47; m+=67;
      caRow[Modulus(j, N)] = '-';
      caRow[Modulus(k, N)] = ' ';
      caRow[Modulus(l, N)] = '-';
      caRow[Modulus(m, N)] = ' ';
      for (int i=0; i<700000; i++) // Warten
      GetChar(1, 1, 1);
   }
   return 0;
}
