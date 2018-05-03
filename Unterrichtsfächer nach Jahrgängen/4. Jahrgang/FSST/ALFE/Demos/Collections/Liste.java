 /*  
     Arraylist Demo 
       
     progr. w.alfery
     
     1) Arraylist Beispiel für eine Sammlung von Objekten 
        der selbstdefinierten Klasse "Artikel"
     
     2) Erstellung der Klasse "Artikelliste" zur einfacheren Verwendung 
        einer Artikelsammlung   
        
                     
 */

 import java.io.*;
 import java.util.*;


////////////////////////////////////////////////////////////////////////////
// Klasse Artikel 
////////////////////////////////////////////////////////////////////////////
 class Artikel
 {  
 	public String name;    // Artikeldaten
 	int    nummer;
 	float  wert;
 	
 	Artikel(String name,int nummer, float wert)
 	{  	this.name  =name;
 		this.nummer=nummer;
 		this.wert  =wert;
 	}	

    public String getName()	
    {   return name;
    }		
 
 	public void setWert(float wert)
 	{   this.wert=wert;
 	}	 
   
    public String toString()
 	{   
 		return name + ", " + nummer + ", " + wert + " \n"; 
 	} 	
 	 
 }


////////////////////////////////////////////////////////////////////////////
// Klasse Artikelliste  
////////////////////////////////////////////////////////////////////////////
 class Artikelliste 
 {
    private int anzahl=0; 
    List<Artikel> bl;  
      
    Artikelliste()	
    { 
       bl = new ArrayList<Artikel>();	  
       anzahl = bl.size(); 
    }	
      
    int anzahl()
    {  return anzahl;
    }	
      
    void add(Artikel b)
    {  bl.add(b);
       anzahl = bl.size();
    }	       	
   
    Artikel get(int i)
    {  return bl.get(i); 
    }	 
 	
 } 	 
 
 
 
////////////////////////////////////////////////////////////////////////////
// Hauptklasse (Anwendung)  
////////////////////////////////////////////////////////////////////////////
 public class Liste	            
 {  

   public static void main( String[] args ) 
   {  int i; 

      // Liste für Artikel erstellen 
      System.out.println(" Liste  : " ); 
      List<Artikel> l = new ArrayList<Artikel>();   
      
      Artikel a = new Artikel("Ball",1,20.00f);
      Artikel b = new Artikel("Korb",2,50.00f);
      Artikel c = new Artikel("Netz",3,10.00f);
      
      l.add(a);                                   // Artikel  in die Liste eintragen 
      l.add(b);                                   //  ... 
      l.add(c);                   

      // Liste ausgeben 
      System.out.println( l );                    // gesamte Liste ausgeben -> [A0,A1,...] 
      System.out.println( " Anzahl=" + l.size()); // Anzahl der Elemente bestimmen 
      
      System.out.println( " Elemente einzeln abfragen: ");
      for ( i = 0; i < l.size(); i++ )  
          System.out.print(l.get(i));             // Artikel Zugriff über Index     
  
      
      l.clear();                                  // Liste löschen 
      System.out.println( "\n Liste löschen :" + l );      
      System.out.println( "\n\n" );      
   

      
      // Artikelliste über die Klasse "Artikelliste" erstellen 
      Artikelliste al = new Artikelliste(); 
      
      System.out.println(" Artikelliste  : " ); 	
      Artikel a1 = new Artikel(" Cafe   ",1,5.00f);
      al.add(a1);
      al.add(new Artikel(" Java   ",2,20.00f));
      al.add(new Artikel(" Bohnen ",3,10.00f));
      	
      for ( i = 0; i < al.anzahl(); i++ )  
          System.out.print(al.get(i));          
      
      System.out.println( "\n\n" );
      
   } 
}