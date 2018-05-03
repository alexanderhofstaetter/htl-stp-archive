 /*  Collection2.java
     progr. w.alfery
     
     Collections (Sammlungen) verwenden :  
     
     Map - 
          für einen assoziativen Speicher (Dictionary), der Schlüssel auf Werte abbildet,
          Schlüssel und Werte sind Objekte eines beliebigen Typs,
          HashMap ist eine schnelle Implementierung durch Verwendung einer Hash-Tabelle - 
          über eine Transformationsfunktion werden Schlüssel auf Indexpositionen abgebildet,
          TreeMap ist langsamer im Aufbau und rascher im Zugriff, da ein sortierter Binärbaum gebildet wird
                
 */

 import java.io.*;
 import java.util.*;
 
 public class Collection2		            
 {  

   public static void main( String[] args ) 
   { 

      System.out.println(" Map des Collection-Frameworks verwenden \n" ); 

      // Map erstellen
      System.out.println(" HashMap : " ); 
      HashMap<String,String> maillist = new HashMap<String,String>(); // HashMap erstellen

      maillist.put("georg","georg@benson.at");        // Schlüssel-Wert-Paar einfügen 
      maillist.put("laura","laura@ashley.de");
      maillist.put("paul","paul@cartney.uk");
 
      // Map ausgeben 
      System.out.println( maillist );                 // gesamte Map ausgeben -> {...} 
      System.out.println( " Anzahl="+maillist.size());// Anzahl der Elemente bestimmen 
   
      // Elemente über Iterator ausgeben 
      System.out.println( "\n Elemente einzeln über Iterator ausgeben : "); 
      Iterator iter = maillist.entrySet().iterator(); // Iterator erstellen   
      while (iter.hasNext())                          //  HashMap durchlaufen   
      {
          Map.Entry entry = (Map.Entry)iter.next();
          System.out.println( (String)entry.getKey()  // Schlüssel 
                               + " = " + 
                              (String)entry.getValue()// Wert 
                            );
      } 
      
      // Elemente abfragen                           
      String s=maillist.get("laura");                  // über Schlüssel abfragen   
      System.out.println( "\n Abfrage nach \"laura\" = " + s); 
   
      // Elemente löschen    
      maillist.keySet().remove("laura");              // über Schlüssel löschen
      maillist.values().remove( "georg@benson.at" );  // über Wert löschen
      System.out.println("\n Elemente löschen :"+ maillist );      

      // gesamte HashMap löschen 
      if (maillist.isEmpty()==false) maillist.clear(); 
      System.out.println( "\n Liste löschen :" + maillist );     

   } 
}