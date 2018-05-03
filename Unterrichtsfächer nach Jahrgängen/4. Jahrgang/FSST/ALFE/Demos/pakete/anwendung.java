 /*  anwendung.java
     w.alfery
        
     Pakete schnüren und verwenden 
           
 */

 import paket1.*;
 import paket1.paket1a.*;
 
 
  
 public class anwendung		                     // Anwendungsklasse 
 {   

    public static void main(String args[])       
    { 
       System.out.println(" Anwendung mit Verwendung von Paketen \n");
       
       klasse1  a = new klasse1();              // klasse1 von paket1 verwenden 
       a.message(); 

       klasse2  b = new klasse2();              // klasse2 von paket1 verwenden 
       b.message(); 
       	       	
       klasse1a c = new klasse1a();             // klasse1a von paket1a verwenden 
       c.message(); 
 
       
    }
 }