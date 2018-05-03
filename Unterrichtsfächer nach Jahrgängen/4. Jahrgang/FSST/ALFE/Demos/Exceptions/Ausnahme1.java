 /*  Ausnahme1.java
   
     w.alfery 
     
     Exception Handling  
     mit try and catch 
          
 */

 import java.io.*;				
 
 public class Ausnahme1				
 {  
    public static void main(String args[]) 
       
    {  
       int i,j,n=0;
       float x;
       double y;
       char c; 
       String s,datei;
       int[] a = new int[5]; 


       System.out.println(" try & catch  \n"); 

       

       do 
       { 
         
          try                                     	// hier ausprobieren   
          {  System.out.print(" Eingabe bitte ... ");
             
             BufferedReader ein = new BufferedReader( new InputStreamReader(System.in));
             
             s = ein.readLine();                    // von Tastatur in den String s   
             
             x = Float.parseFloat(s);               // umwandeln auf float x  

             i = Integer.parseInt(s);               // umwandeln auf int j

             j = 1/i;                               // 1/0  ?   
             
             a[i] = i;                              // Array Grenzen ?   
             
             
             if (n<3)  datei="Ausnahme1.java";      
             else      datei=""; 
             FileReader f = new FileReader(datei);  // Datei lesend öffnen 
             
             n++; 
          } 
          
 
          
          catch (NumberFormatException e)         	// und wenn's schief geht hier abfangen   
          {     
             System.out.println("   -> Fehler beim Umwandeln ! ");
          }         

         
          catch (ArithmeticException e)
          {         
             System.out.println("   -> Fehler mit der Mathematik !");
          }   
          
          catch (IndexOutOfBoundsException e)        
          { 
             System.out.println("   -> Fehler mit Feldgrenzen !");
          }
          
        
          catch (IOException e)                   
          {  
             System.out.println("   -> Fehler beim Datei oeffnen !");
          }
          
          catch (Exception e) 
          { 
             System.out.println("   -> oder irgend ein Fehler " + e.toString());
          }
          
              
          finally 
          {
              System.out.println(" ... hierher kommt man immer \n\n"); 
              
          }
 
       } while (true);                           	// immer wieder  

    }
 }