/** second.java

    Hauptklasse und Hauptmethode, 
    static- und nicht-static-Elemente der Hauptklasse 

*/

// die Hauptklasse muss public  
// und namensgleich zum Dateinamen sein 
public class second 
{  
   // die Hauptmethode main 
   // muﬂ public und static sein 
   public static void main (String[] args)      
   {  
      String titel = "Quadrate :";          	// lokale Variable
      System.out.println("\n"+titel);        	// Ausgabe auf Konsole 

      String s;                    
      for ( int i = 1; i<=n; i=i+1 )           	// for-Schleife
      {  s = "sqr(" + i + ") = "+ sqr(i);     	// Aufruf der static-Methode
         System.out.println( s );
      }
      
      System.out.println();
      second inst=new second();                	// Instanz zur Hauptklasse      inst.stringout(inst.s);               	// stringout aufrufen 

   }


   // nur static-Elemente kˆnnen in der static-Methode main 
   // ohne Instanzieren direkt verwendet werden. 
   
   static int n=10;                              // static Datenelement
   
   static int sqr(int n)                         // static Methode
   {  return n*n;
   }


   // nicht static-Elemente m¸ssen in der static-Methode main 
   // ¸ber eine Instanz der eigenen Klasse verwendet werden.
   
   String s= "Java Stringobjekt";                // Datenelement  
   
   void stringout(String s)                      // Methode  
   {  System.out.println(s);
   }

}
