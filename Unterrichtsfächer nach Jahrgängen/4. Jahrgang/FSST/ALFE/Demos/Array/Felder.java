 /*  Felder.java
     progr. w.alfery
     
     Arrays definieren und verwenden, 
     sowie Berechnungen über die eigene Klasse "Analyse" ausführen  
      
 */

 import java.io.*;
 import java.util.*;
 
 // Hauptklasse  
 
 public class Felder 		            
 {  
     
    public static void main(String args[])       // static Methode main() 
    { 
       int i,n=5; 
       float summe,mittel; 

       // Java Arrays werden als dynamische Objekte erzeugt 
       float[] x; 								 // Referenz  
       x = new float[n];                         // Array instanzieren  
       
       // oder Referenz und Objekt über eine Anweisung erstellen    
       float []y = new float[n];              
          
       
       
       System.out.println("\n Arrays  ");
       System.out.println(" __________________________ ");

       for (i=0;i<x.length;i++)                  // allen Feldelementen    
       {  x[i]=Math.round(10*Math.random());     // Zufallswerte zuweisen 
          System.out.format(" x[%2d] =    %5.2f  \n",i,x[i]); 
       }  

       System.out.println(" __________________________ ");

       y = x.clone();                            // Felder kopieren (klonen) x->y      
                                                 // y=x würde nur die Referenzen kopieren !  

       Analyse a = new Analyse();                // Instanz zur Klasse "Analyse" erstellen 
       summe  = a.summe(x);                      // um die Methode summe aufzurufen     
       mittel = a.mittel(x);                    

       System.out.format(" Summe  =  %6.2f \n",summe);
       System.out.format(" Mittel =  %6.2f \n",mittel);


       System.out.println(" __________________________ ");
 
       Arrays.sort(x);                           // Methode sort anwenden

       System.out.println("\n sortiertes Feld :");
       for (i=0;i<x.length;i++)
       {  System.out.println("       " + x[i]);
       }   

    }

 }
 
 
 
 // Hilfsklasse 
 
 class Analyse
 {
  
     public float summe(float[] x)                // Methode summe   
     {  int i;
        float s=0;
        for (i=0;i<x.length;i++)                   
        { s += x[i];
        }
        return s;
     }  

     public float mittel(float[] x)                // Methode mittel   
     { 
        return summe(x)/x.length;
     }  

 }