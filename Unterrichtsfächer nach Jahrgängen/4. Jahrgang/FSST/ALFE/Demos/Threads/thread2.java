 /*  thread2.java
     w.alfery
        
     Threads -  über das Interface "Runnable" implementieren 
           
 */

class faden1 extends thread2 implements Runnable // 1.Thread                      
{   
   public void run()
   {  int i = 0;
      while (true) 
      {  System.out.format("%3d    %3d %n",nr,i);
         i++;nr++;  
         
         if (Thread.interrupted()) break; 
         try 
         {  Thread.sleep(10); }                   // 1ms warten  
         catch (InterruptedException e) { }

      }
   }
}

class faden2 extends thread2 implements Runnable // 2.Thread                      
{  
   public void run()
   {  int i = 0;
      while (true) 
      {  System.out.format("%3d              %3d %n",nr,i);
         i++;nr++; 
         
         if (i>10) break;   
         try 
         {  Thread.sleep(20); }                   // 2ms warten  
         catch (InterruptedException e) { }

                
      }
   }
}
 
 
public class thread2                             // Hauptklasse  
{  
   static int nr = 0;                            // gemeinsame Variable
     
   public static void main(String[] args)
   {
   	  System.out.println("Threads ");
   	  System.out.println("nr     Faden 1    Faden2 ");
  	  
      faden1 f1 = new faden1();              
      Thread t1 = new Thread(f1);                  
      faden2 f2 = new faden2();              
      Thread t2 = new Thread(f2);                  

      t1.start();                                // und starten 
      t2.start();                                
      
      try 
      {  Thread.sleep(500);                      // für 0.5s lang 
      } 
      catch (InterruptedException e) 
      {  
      }
      t1.interrupt();                            // Thread abbrechen  
      t2.interrupt();                            // interrupt() bricht kontrolliert ab  
                                                   
   }
   
}
 
