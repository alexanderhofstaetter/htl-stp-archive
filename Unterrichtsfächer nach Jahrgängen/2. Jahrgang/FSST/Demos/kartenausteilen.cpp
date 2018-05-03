/////////////////////////////////////////////////////////////////////////////
//   Programmname : Kartenausteilen.cpp
//
//   Aufgabe :  Kartenfeld erstellen, mischen und auf Spielfeld auslegen    
//            
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//   Header-Dateien
/////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <iostream>
#include <iomanip>  
#include <time.h> 

using namespace std;

/////////////////////////////////////////////////////////////////////////////
//   globale Definitionen   
/////////////////////////////////////////////////////////////////////////////
 const int N=16;                  // Kartenanzahl  
 const int M=4;                   // Spielfeldgröße 4x4

 int a[N];                        // Kartenstapel  
 int m[M][M];                     // Spielfeld  

/////////////////////////////////////////////////////////////////////////////
//   Hauptprogramm
/////////////////////////////////////////////////////////////////////////////
int main()
{  int i,j,k,hilf;
    
   system("CLS");                 // Bildschirm löschen
   cout << " Kartenpaare " << endl << endl; 
   cout << endl << " Karten :  " << endl; 
   srand(time(NULL));     
   
   // Kartenfeld erstellen 
   for (i=0;i<N;i++)
   {  a[i] = i + 1;             
      cout << setw(4) << a[i];  
   }

   // Karten mischen  
   for (i=0;i<N;i++)
   {  j=rand()%N;                // zufällige Position  
      hilf=a[i];                 // Karten tauschen  
      a[i]=a[j];             
      a[j]=hilf;
   }

   // Kartenfeld zeigen   
   cout << endl << " gemischte Karten : " << endl; 
   for (i=0;i<N;i++)
   {  cout << setw(4) << a[i];  
   }
     
   // auf Spielfeld auslegen  
   cout << endl << " auf Spielfeld auslegen : " ; 
   for (k=0,i=0;i<M;i++)
   {  cout << endl;  
      for (j=0;j<M;j++)
      {  m[i][j] = a[k++];       
         cout << setw(4) << m[i][j];  
      }
   }   
   
   cout << endl << endl; 
   system("PAUSE"); 
   return 0;
 }
