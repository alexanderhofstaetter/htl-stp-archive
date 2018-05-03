 /*  InoutExc.java
   
     Einlesen und Ausgeben auf Konsole 
     mit Exception Handling
     
 */

 import java.io.*;				
 
 public class InoutExc				
 {  
    public static void main(String args[]) throws IOException
    {  
       char auswahl;
       boolean error;
       int i,n,sum;

       BufferedReader ein = new BufferedReader(
                            new InputStreamReader(System.in));
 
       System.out.println("\n Berechnung der Summe von 1 bis n \n");

       do 
       { 
         
         do 
         { try                                   // Exception abfangen  
               { System.out.print(" Anzahl n = ");
                 n = Integer.parseInt(ein.readLine()); 
                 error=false; 
               } 
           catch (NumberFormatException e)       // Exception behandeln   
               { n=0; error=true; 
               }         

         } while (error || n<0);                 // Wiederholung bis korrekte Eingabe   
         

         sum = 0;                                // Summen Berechnung 
         for (i=1;i<=n;i++)
         { sum += i;         
         }

         System.out.println(" Summe von 1 bis " + n + " = " + sum + "\n");

         System.out.print("\n Quit mit [q] ");
         auswahl = (char) ein.read(); 
         ein.readLine();
 
       } while (auswahl != 'q');   

    }
 }