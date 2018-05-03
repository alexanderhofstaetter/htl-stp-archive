 /*  thread1.java
     w.alfery
        
     Threads laufen parallel wie Prozesse,
     haben jedoch einen gemeinsamen Adressraum mit gemeinsamen Variablen.
     Threads können über die Klasse "Thread" oder das Interface "Runnable"
     implementiert werden.    

     Threads -  über die Klasse "Thread" ausführen
           
 */


class faden1 extends Thread                      // 1.Thread  
{  
   public void run()                             // Methode run überschreiben     
   {  int i = 0;
      while (true) 
      {  System.out.println(i++);
      }
   }
}
 
class faden2 extends Thread                      // 2.Thread                      
{  
   public void run()
   {  int i = 0;
      while (true) 
      {  System.out.println("           " + i++);
      }
   }
}
 
public class thread1                             // Hauptklasse  
{
   public static void main(String[] args)
   {
   	  System.out.println("Threads ");
   	  System.out.println("Faden 1    Faden2 ");
  	  
      faden1 f1 = new faden1();                  // Threads instanzieren  
      faden2 f2 = new faden2(); 
      f1.start();                                // und starten 
      f2.start();

   	  System.out.println(f1.getName() + "   " + f2.getName());
      
      try 
      {  Thread.sleep(10);                       // für 10ms lang 
      } 
      catch (InterruptedException e) 
      {  
      }
      f1.stop();                                 // Thread abbrechen  
      f2.stop();                                 // stop() führt unkontrollierten Abbruch aus!  
                                                   
   }
}
 
