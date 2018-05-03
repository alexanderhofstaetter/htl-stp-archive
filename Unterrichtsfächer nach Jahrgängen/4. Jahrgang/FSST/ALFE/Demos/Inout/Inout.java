  /*  Inout.java
     
     Einlesen von Tastatur und Ausgeben auf Konsole 
     - ohne Ausnahmebehandlung 
      
 */

 import java.io.*;                
 
 public class Inout
 {
    public static void main(String args[])throws IOException
    {  char auswahl;
       int i;
       float x,y;
       double d;
       String text; 
      
       // Instanz zu BufferedReader 
       // für gepuffertes Einlesen mit der Methode readline()	
       BufferedReader eingabe = new BufferedReader(
                            new InputStreamReader(System.in));
       
	 
       System.out.println("\n Eingaben mit  BuffererdReader ");
       System.out.println(" _______________________________ \n");

       do 
       { 
        
         // Stringeingabe 
         System.out.print(" Texteingabe = ");
         text=eingabe.readLine();
         System.out.println(" -> Text = " + text);
    
         // Eingabe und Umwandlung auf int-Variable  
         System.out.print(" Eingabe int-Zahl i= ");
         i = Integer.parseInt(eingabe.readLine());  
         System.out.println(" -> i = " + i);	
       
         // Eingabe und Umwandlung auf float-Variable  
         System.out.print(" Eingabe float-Zahl x= ");
         x = Float.parseFloat(eingabe.readLine());  
         System.out.println(" -> x = " + x);
     
         // Eingabe und Umwandlung auf double-Variable  
         System.out.print(" Eingabe double-Zahl d= ");
         d = Double.parseDouble(eingabe.readLine());  
         System.out.println(" -> d = " + d);
          
         // Eingabe von Einzelzeichen über Methode read()
         System.out.print("\n Quit mit [q] ");
         auswahl = (char) eingabe.read(); 
         
         eingabe.readLine();              // CR auslesen       	
 
       } while (auswahl != 'q');   

    }
 }