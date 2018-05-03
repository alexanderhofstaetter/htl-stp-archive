 /*  ScanExc.java
     
     Einlesen über Scanner-Klasse  
     mit Exception Handling
      
 */
 
 import java.io.*;
 import java.util.Scanner;            

public class ScanExc 
{

   public static void main(String []args)  
   {
       Scanner ein = new Scanner(System.in);  // Instanz zu Scanner

        int i;
        float x; 
        double d;  

        try                                   // Exception abfangen  
        {  System.out.print(" Integer Eingabe : ");    
           i = ein.nextInt(); 
        } 
        catch (Exception e)                   // Exception behandeln   
        {  i=0; 
        }                  

        System.out.format(" -> %d \n",i);

   }
}