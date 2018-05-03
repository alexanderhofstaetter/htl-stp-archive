 /*  Scan.java
     
     Einlesen über Scanner-Klasse  
      
 */
 
 import java.io.*;
 import java.util.Scanner;            

public class Scan 
{

   public static void main(String []args) 
   {
       Scanner ein = new Scanner(System.in);     // Instanz zu Scanner

        int i;
        float x; 
        double d;  

        System.out.print(" Integer Eingabe : ");    
        i = ein.nextInt();                         // einlesen mit Methode nextInt
        System.out.format(" -> %d \n",i);
		
        System.out.print(" Float Eingabe : ");
        x = ein.nextFloat();
        System.out.format(" -> %f \n",x);

        System.out.print(" Double Eingabe : ");
        d = ein.nextDouble();
        System.out.format(" -> %f \n",d);
   }
}