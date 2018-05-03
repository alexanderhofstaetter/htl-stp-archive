/////////////////////////////////////////////////////////////////////////////
//   Programmname : main.cpp
//
//   Autor   :  Alex Hofstätter
//   Datum   :  11. Okt. 2013
//   Version :  1.0
//
//   Aufgabe :  Stammbau
//
/////////////////////////////////////////////////////////////////////////////

/**----------- Header-Dateien ---------------------------------------------*/

using namespace std;                // Namensraum für Standardbibliothk
#include <iostream>
#include <stdio.h>
#include <math.h>

/**----------- Klassen ----------------------------------------------------*/

typedef struct liste LIST;
struct liste{
	LIST *left;
	LIST *right;
	int daten;
};

/**----------- Hauptprogramm ----------------------------------------------*/

int SwitchList (LIST *el, int n);

int main()
{
   #define N 20
   LIST a[N];
   for (int i=0;i<(N-1);i++)
      a[i].right = &a[i+1];

   for (int i=0;i<N;i++)
      a[i].left = &a[i-1];

   a[N-1].right = NULL;
   a[0].left = NULL;

   for(int i=0;i<N;i++)
   {  a[i].daten=i;
      printf("%d-",a[i].daten);

   }
   printf("\n\n");

   SwitchList(a,5);
   SwitchList(a,8);
   SwitchList(a,15);

   //for(int i=0;i<N;i++)
      //printf("%d-",a[i].daten

   LIST *first = a;
   while(first != NULL)
   {  printf("%d-",first->daten);
      first=first->right;
   }

}

int SwitchList (LIST *feld, int n)
{
   LIST *el = &feld[n];
   LIST *p1,*p2,*p3,*p4;

   if((el)->right != NULL)
   {
      p1=el->left;             // eins vorher
      p2=el;                   // selbst
      p3=el->right;            // nächstes
      p4=el->right->right;     // übernächstes

      p1->right=p3;
      p2->right=p4;
      p3->right=p2;

      p2->left=p3;
      p3->left=p1;
      p4->left=p2;
   }
}
