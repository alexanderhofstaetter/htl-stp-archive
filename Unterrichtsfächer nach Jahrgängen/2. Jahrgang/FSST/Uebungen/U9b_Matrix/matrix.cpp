/////////////////////////////////////////////////////////////////////////////
//   Name: A. Hofstätter
//   Programmname : memory.cpp
//   Aufgabe :  Memory
//
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <math.h>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   Globale Definition von Feldern
/////////////////////////////////////////////////////////////////////////////

const int NMAX = 10;                    // Feldgröße NMAX
const int MMAX = 10;                     // Feldgröße MMAX
typedef int matrix[NMAX][MMAX];

/////////////////////////////////////////////////////////////////////////////
//   Funktionsprototypen
/////////////////////////////////////////////////////////////////////////////

void matrix_init( matrix m, int value);
void matrix_serie( matrix m, int start, int step );
void matrix_out( matrix m );
int matrix_max( matrix m );
int  matrix_rowsum ( matrix m, int row );
int  matrix_colsum ( matrix m, int col );
void matrix_add ( matrix m1, matrix m2, matrix m );
void matrix_sub ( matrix m1, matrix m2, matrix m );
void matrix_mul ( matrix m1, matrix m2, matrix m );
void matrix_div ( matrix m1, matrix m2, matrix m );

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{
    srand(time(NULL));

    matrix matrix0;
    matrix matrix1;
    matrix matrix2;
    int abc=3;
    cout << "1" << "2" << abc;

    int value,row,col,start,step;
    printf(" Matrix initilaisieren mit Wert: "); cin >> value;
    matrix_init(matrix0,value);
    matrix_out(matrix0);

    printf("\n Matrix mit Erhoehung\n");
    printf(" Start Wert:"); cin >> start;
    printf(" Erhoehung:"); cin >> step;
    matrix_serie(matrix0,start,step);
    matrix_out(matrix0);
    printf("\n Maxmimum: %d\n",matrix_max(matrix0));

    printf(" Summe der Reihe: "); cin >> row;
    printf(" %d\n",matrix_rowsum(matrix0,row));

    printf(" Summe der Spalte: "); cin >> col;
    printf(" %d\n",matrix_colsum(matrix0,col));

    printf("\n Matrix m1\n");
    printf(" Start Wert:"); cin >> start;
    printf(" Erhoehung:"); cin >> step;
    matrix_serie(matrix1,start,step);
    matrix_out(matrix1);
    printf("\n Maxmimum: %d\n",matrix_max(matrix1));

    printf("\n Matrix m2 mit Erhoehung\n");
    printf(" Start Wert:"); cin >> start;
    printf(" Erhoehung:"); cin >> step;
    matrix_serie(matrix2,start,step);
    matrix_out(matrix2);
    printf("\n Maxmimum: %d\n",matrix_max(matrix2));

    printf("\n m1 + m2\n");
    matrix_add(matrix1,matrix2,matrix0);
    matrix_out(matrix0);
    printf("\n Maxmimum: %d\n",matrix_max(matrix0));

    printf("\n m1 - m2\n");
    matrix_sub(matrix1,matrix2,matrix0);
    matrix_out(matrix0);
    printf("\n Maxmimum: %d\n",matrix_max(matrix0));

    printf("\n m1 * m2\n");
    matrix_mul(matrix1,matrix2,matrix0);
    matrix_out(matrix0);
    printf("\n Maxmimum: %d\n",matrix_max(matrix0));

    printf("\n m1 / m2\n");
    matrix_div(matrix1,matrix2,matrix0);
    matrix_out(matrix0);
    printf("\n Maxmimum: %d\n",matrix_max(matrix0));

    printf("\n\n");
    system("PAUSE");
    return 0;

}

/////////////////////////////////////////////////////////////////////////////
//   Funktionsdefinitionen
/////////////////////////////////////////////////////////////////////////////

void matrix_init( matrix m, int value)
////////////////////////////////////////////////////////////////////////////
//   alle Feldelemente mit dem Wert "value" initialisieren
{
    for(int i=0;i<NMAX;i++)
        for(int j=0;j<MMAX;j++)
            m[i][j] = value;
}
void matrix_serie( matrix m, int start, int step )
////////////////////////////////////////////////////////////////////////////
//   alle Feldelemente mit ansteigenden Zahlen
//   beginnend mit dem Wert "start" und der Erhöhung "step" initialsieren
{
    int wert=start;
    for(int i=0; i<NMAX;i++)
    {   for(int j=0; j<MMAX;j++)
        {   m[i][j]=wert;
            wert+=step;
        }
    }
}

void matrix_out( matrix m )
////////////////////////////////////////////////////////////////////////////
//   Matrix als Tabelle am Bildschrim ausgeben
{
    for(int i=0; i<NMAX;i++)
    {  printf(" [ ");
       for(int j=0; j<MMAX;j++)
            printf("%3d ",m[i][j]);
        printf(" ]\n");
    }
}

int  matrix_rowsum ( matrix m, int row )
////////////////////////////////////////////////////////////////////////////
//   Summe aller Feldelemente einer Zeile (Reihensumme) berechnen
//   und als Rückgabewert ausgeben
{
   int summe=0;
   for(int j=0; j<MMAX;j++)
      summe+=m[row-1][j];
   return summe;
}

int  matrix_colsum ( matrix m, int col )
////////////////////////////////////////////////////////////////////////////
//   Summe aller Feldelemente einer Spalte (Spaltensumme) berechnen
//   und als Rückgabewert ausgeben
{
   int summe=0;
   for(int j=0; j<MMAX;j++)
      summe+=m[col-1][j];
   return summe;
}

int  matrix_max ( matrix m )
////////////////////////////////////////////////////////////////////////////
//   Maximum aller Feldelemente berechnen
//   und als Rückgabewert ausgeben
{
   int maximum=m[0][0];
   for(int i=0; i<NMAX;i++)
   {  for(int j=0; j<MMAX;j++)
         if(m[i][j] > maximum) maximum=m[i][j];
      printf("\n");
   }
   return maximum;
}

void  matrix_add ( matrix m1, matrix m2, matrix m )
////////////////////////////////////////////////////////////////////////////
//   die Addition von Matrix m1 und m2 berechnen
//   und der Matrix m zuweisen
{
   for(int i=0; i<NMAX;i++)
   {  for(int j=0; j<MMAX;j++)
         m[i][j]=m1[i][j]+m2[i][j];
   }
}

void  matrix_sub ( matrix m1, matrix m2, matrix m )
////////////////////////////////////////////////////////////////////////////
//   die Addition von Matrix m1 und m2 berechnen
//   und der Matrix m zuweisen
{
   for(int i=0; i<NMAX;i++)
   {  for(int j=0; j<MMAX;j++)
         m[i][j]=m1[i][j]-m2[i][j];
   }
}

void  matrix_mul ( matrix m1, matrix m2, matrix m )
////////////////////////////////////////////////////////////////////////////
//   die Addition von Matrix m1 und m2 berechnen
//   und der Matrix m zuweisen
{
   for(int i=0; i<NMAX;i++)
   {  for(int j=0; j<MMAX;j++)
         m[i][j]=m1[i][j]*m2[i][j];
   }
}

void  matrix_div ( matrix m1, matrix m2, matrix m )
////////////////////////////////////////////////////////////////////////////
//   die Addition von Matrix m1 und m2 berechnen
//   und der Matrix m zuweisen
{
   for(int i=0; i<NMAX;i++)
   {  for(int j=0; j<MMAX;j++)
         m[i][j]=m1[i][j]/m2[i][j];
   }
}
