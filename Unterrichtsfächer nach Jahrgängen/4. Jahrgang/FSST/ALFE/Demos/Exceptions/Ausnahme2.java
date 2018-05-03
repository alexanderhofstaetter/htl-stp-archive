 /*  Ausnahme2.java
   
     w.alfery 
     
     eigene Exception auslösen und weiterleiten   
     mit throw und throws  
          
 */

 import java.io.*;				
 
 public class Ausnahme2			
 {  
    public static void main(String args[]) 
       
    {  
       int i;
       String s; 

       System.out.println(" Fehler werfen ...  \n"); 
       
       

       do 
       { 
         
          try                                     	// hier ausprobieren   
          {  System.out.print(" Noten Eingabe = ");
             
             BufferedReader ein = new BufferedReader( new InputStreamReader(System.in));  
             s = ein.readLine();                    // von Tastatur    
             i = Integer.parseInt(s);               // Note einlesen 


             NotenAusnahmen t= new NotenAusnahmen(); 
             System.out.println(" Ergebnis =" + t.test(i));  // und prüfen 
             
             
          } 
          
 
          
          catch (NotenAusnahmen e)                 	// und hier abfangen   
          {     
             System.out.println(" -> Notenfehler  " + e.toString());
          }         

          catch (Exception e)                  	    // und alles andere, was so herumfliegt 
          {     
             System.out.println(" -> Fehler  " + e.toString());
          }         

          

 
       } while (true);                           	// immer wieder  

    }
 }
 
 

// damit lasssen sich Noten abfangen 

class  NotenAusnahmen extends Throwable
{   
    public String s=" keine gueltige Note ";
    
       
    public String test (int note) throws NotenAusnahmen  // Ausnahme weiterleiten 
    {   s ="positiv";  
    
        if (note <=0 )                    // wenn so was  
        {   s=" das ist zu gut";
            throw new NotenAusnahmen();   // dann Ausnahme auslösen (werfen) 
        }    
           
        else if (note > 5 )               // oder so was 
        {   s=" das ist zu schlecht";
            throw new NotenAusnahmen();   // dann werfen 
        }
        
        else if (note == 5 )   
           s= " auch damit fliegt man raus !";
        
        return s;    
      
    }
   
    public String getLocalizedMessage()   // Fehlermeldung erstellen
    {   return s;   
    } 

} 