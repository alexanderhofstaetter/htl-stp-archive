 /*  thread3.java
     w.alfery
     
     Synchronisation von Threads über Monitore -   
     mit dem Schlüsselwort "synchronized" kann ein Block geschützt 
     und ohne Unterbrechung ausgeführt werden.
     
     Synchronisation des Zugriffs auf gemeinsame Variable            

 */
 
 
 
public class thread3 extends Thread              
{  
   static int cnt1 = 0;                          // gemeinsame Variable
   static int cnt2 = 0;    
   static long n = 1000000;    
   
   public void run()
   {
      while (true) 
      {  synchronized (getClass())               // synchronisierter Block  
         {  
            for(long i=0;i<n;i++)                // wird geschützt (ohne Unterbrechung) ausgeführt
            {  cnt1++;
               Math.pow(Math.sin(Math.PI),Math.cos(Math.PI));
            }
            System.out.println("A="+cnt1);
          
         }
          
         for(long j=0;j<n;j++)                  // nicht synchronisierter Teil 
         {  cnt2++;
            Math.pow(Math.sin(Math.PI),Math.cos(Math.PI));
         }
         System.out.println("B="+cnt2);
         
         if (cnt1>=n) break;    
         
      }
   }


   
   public static void main(String[] args)
   {  
   	  System.out.println("Threads mit Synchronisation ");
  	  
      Thread t1 = new thread3();  
      Thread t2 = new thread3();                  
      Thread t3 = new thread3();    
      
      t1.start();                                // und starten 
      t2.start();                                
      t3.start();                                
     
      t1.interrupt();                            // Thread abbrechen  
                                                 // interrupt() bricht kontrolliert ab  
      
      System.out.println();  
      
   }
}

   
