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
	LIST *prev;
	LIST *next;
	int daten;
};

/**----------- Hauptprogramm ----------------------------------------------*/

int Switch(LIST *first, int n1, int n2);

int main()
{
   #define N 20
   LIST a[N];
   for (int i=0;i<(N-1);i++)
      a[i].next = &a[i+1];

   for (int i=0;i<N;i++)
      a[i].prev = &a[i-1];

   a[N-1].next = NULL;
   a[0].prev = NULL;

   for(int i=0;i<N;i++)
   {  a[i].daten=i;
      printf("%d-",a[i].daten);

   }
   printf("\n\n");

   Switch(a,5,6);
   Switch(a,8,9);
   Switch(a,15,16);

   LIST *first = a;
   while(first != NULL)
   {  printf("%d-",first->daten);
      first=first->next;
   }

}

int Switch(LIST *first, int n1, int n2)
{
   LIST *element1 = first;
   LIST *element2 = first;

   int i=0;
   while(i<n2)
   {  i++;
      if (i<n1)
         element1=element1->next;
      element2=element2->next;
   }

  /* element2->next=element1;
   element1->next=element2;
*/


/*
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
   */
   return 0;
}
