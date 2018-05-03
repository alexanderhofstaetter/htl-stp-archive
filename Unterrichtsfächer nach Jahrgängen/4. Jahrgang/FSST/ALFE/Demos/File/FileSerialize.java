/*  FileSerialize.java
    w.alfery
        
    Beispiel zur Objekt Serialisierung 
    ( Datenspeicherung von Objekten ) 
    
      
 */


import java.io.*;
import java.io.Serializable; 


// Klasse zur Serialisierung  
class Person implements Serializable 
{ 
  String name; 
  String adress; 
  String telnr="0"; 	
  float  gewicht=50; 
  	
  Person(String name,String adress)
  {  this.name=name; 
  	 this.adress=adress; 
  }	 	
  	
  void setAdress(String adress)	
  {  this.adress = adress;  
  }	
  String getAdress()
  {  return adress; 
  }
  public String toString()
  {  return name+", "+adress+", "+telnr+", "+gewicht+";";
  }	 		
}


// Hauptklasse 
public class FileSerialize
{
   public static void main(String[] args)
               throws IOException
   {
       
        // Dateinamen festlegen    
        File f = new File("data.ser");  
        System.out.println(" Serialiserung auf Datei : " + f );
        System.out.println();
        	
        // Objekt erstellen 	
        Person  p = new Person("James Gosling","Calgary");
        System.out.print(" Person sichern : ");
        System.out.println(p);
        System.out.println();

   	    
        // Datei Ausgabestrom erzeugen  
		try 
		{
           ObjectOutputStream out = new ObjectOutputStream(
                                    new FileOutputStream(f));
           
           out.writeObject(p);      // Objekt p auf Datei schreiben 
           out.close(); 
           	
        } 
        catch (IOException e) 
        {  System.err.println(e.toString());
        }
		
        p.setAdress("*"); 	        // testweise die Adresse ändern  
		
		
   	    // Datei Eingabestrom erzeugen
	    try 
		{ 
		  ObjectInputStream in  = new ObjectInputStream(
		  	                      new FileInputStream(f)); 
		  
		  Person pin = (Person) in.readObject();  // Objekt von Datei lesen 
          
          System.out.println(" Person wiederherstellen : ");
          System.out.println(" Name=" + pin.name );
          System.out.println(" Adresse=" + pin.adress );
          System.out.println();
           
		} 
		catch ( IOException e )
		{ System.err.println( e ); 
		} 
		catch ( ClassNotFoundException e )
		{ System.err.println( e ); 
		} 

   }

}
