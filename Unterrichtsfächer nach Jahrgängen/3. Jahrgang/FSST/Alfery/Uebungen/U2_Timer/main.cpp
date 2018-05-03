/////////////////////////////////////////////////////////////////////////////
//   Programmname : main.cpp
//
//   Autor   :  Alex Hofstätter
//   Datum   :  18. Okt. 2013
//   Version :  1.0
//
//   Aufgabe :  Erstellung eines Timers mit Klassen
//
/////////////////////////////////////////////////////////////////////////////

/**----------- Header-Dateien ---------------------------------------------*/

using namespace std;                // Namensraum für Standardbibliothk
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <windows.h>

/**----------- Klassen ----------------------------------------------------*/

class Timer
{
   public:
      int time;               // Zeitdauer in ms

   private:
      int old_time;           // Zeit vor dem Anhalten / Standard = 0
      int start_time;         // Startzeit
      int end_time;           // Endzeit
      int status;             // 0: Timer reset
                              // 1: Timer run
                              // 2: Timer over
                              // 3: Timer stop

   public:
      Timer ();
      Timer (int time);

      void start();
      void reset();
      void stop();
      bool IsTimerRunning();
      int getTime();
      void setTime(int t);
      string ReadableStatus();

};

/**----------- Hauptprogramm ----------------------------------------------*/
int main()
{  const int time_max = 10000;      // maximale Zeit in ms
   srand(time(NULL));

   Timer timer1(0);
   Timer timer2(0);
   Timer timer3(0);

   timer1.setTime(rand()%time_max+1);
   timer2.setTime(rand()%time_max+1);
   timer3.setTime(rand()%time_max+1);

   timer1.start();
   timer2.start();
   timer3.start();

   while(1)
   {  system("CLS");
      cout << " 3 Timer mit zuf\x84lliger Zeitdauer " << endl << endl;
      cout << "  Timer 1: " << setw(5) << timer1.time << " - Status: " << timer1.ReadableStatus() << endl;
      cout << "  Timer 2: " << setw(5) << timer2.time << " - Status: " << timer2.ReadableStatus() << endl;
      cout << "  Timer 3: " << setw(5) << timer3.time << " - Status: " << timer3.ReadableStatus() << endl << endl << endl;

         if (timer1.IsTimerRunning() == false && timer2.IsTimerRunning() == false && timer3.IsTimerRunning() == false)
            break;

      if (timer1.IsTimerRunning() == true)
         cout << " ++ Timer 1 ++ (" << timer1.getTime() << " ms)" << endl;

      if (timer2.IsTimerRunning() == true)
         cout << " ++ Timer 2 ++ (" << timer2.getTime() << " ms)" << endl;

      if (timer3.IsTimerRunning() == true)
         cout << " ++ Timer 3 ++ (" << timer3.getTime() << " ms)" << endl;

   Sleep(20);

   }

   timer1.reset();
   timer2.reset();
   timer3.reset();
}

/**----------- externe Methodendefintionen der Klasse ----------------------*/

Timer::Timer()
{  old_time = 0;
   start_time = 0;
   status = 0;
}

Timer::Timer(int time)
{  old_time = 0;
   Timer::time = time;
   start_time = 0;
   status = 0;
}

void Timer::start()
{  status = 1;
   start_time = old_time + clock();
   end_time = start_time + time;
}

void Timer::reset()
{  status = 0;
   end_time = 0;
   old_time = 0;
}

void Timer::stop()
{  status = 3;
   end_time = 0;
   old_time = clock();
}

bool Timer::IsTimerRunning()
{  if (clock() < end_time)
      return true;
   else
   {  status = 2;
      return false;
   }

}

void Timer::setTime(int t)
{  time = t;
}

int Timer::getTime()
{  if (IsTimerRunning() == true)
      return clock() - start_time;
   else
   {  status = 2;
      return end_time;
   }
}

string Timer::ReadableStatus()
{  if (status == 0)      return ("Stop / Reset");
   else if (status == 1) return ("L\x84uft");
   else if (status == 2) return ("Abgelaufen");
   else if (status == 3) return ("Angehalten");
}
