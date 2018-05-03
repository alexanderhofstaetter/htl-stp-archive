 /*  Strings.java
     progr. w.alfery
     
     String Objekte verwenden 

     Klasse String für unveränderliche Strings 
     Klasse StringBuffer für dynamisch veränderliche Strings 
     
      
 */

 import java.io.*;
 
 public class Strings 		            
 {  
     
    public static void main(String args[])        
           throws IOException 
    { 
       String s;                                 // String (Referenz)  
       String s1="Java";                         // Referenz auf Konstantstring    
       String s2= new String();                  // leeres String Objekt 
       String s3= new String("Text");            // String Objekt 
   
       System.out.println("\n Strings  ");
       System.out.println(" _________ \n");

       s=s1;                                     // Stringzuweisung
       s=s1 + " String ";                        // Stringverkettung
       
       System.out.println(" s = " + s);
       System.out.println(" Laenge = " + s.length());  // Stringlänge 
       System.out.println(" Uppercase = " + s.toUpperCase()); // Großschreibung
       System.out.println(" ersetzen = " + s.replace('a','i'));    // Zeichen ersetzen 
       System.out.println(" String Pos. = " + s.indexOf("String"));  // Teilstring suchen  
       s1=s.substring(6,10);                     // Teilstring bilden
       System.out.println(" Teilstring  = " + s1);                   
       
       System.out.print(" zeichenweise = ");   
       for (int i=0;i<s.length();i++)            // bis Stringende 
       {  System.out.print(s.charAt(i)+"-");     // zeichenweise ausgeben 
       }  
       System.out.print("\n"); 
	    
	   StringBuffer sb1=new StringBuffer();      // leerer Stringbuffer  
	   StringBuffer sb2=new StringBuffer("Buffer");// mit Konstantstring       
	   StringBuffer sb3=new StringBuffer(s);     // mit String s     

       System.out.println("\n Stringbuffer ");
       System.out.println(" _____________ \n");

       System.out.println(" sb1 = " + sb1);
       System.out.println(" sb2 = " + sb2);
	   System.out.println(" sb3 = " + sb3);

       sb1.append("mehr").append("fach ").append("anhaengen");
       System.out.println("\n sb1 mit append = " + sb1);
       
       sb2.setCharAt(0,'b');                     // 'b' an Pos. 0 schreiben
       System.out.println(" sb2.setCharAt = " + sb2);
       
       sb2.reverse();                            // String umkehren 
       System.out.println("\n sb2.reverse = " + sb2);
       
       sb3.replace(5,12,"StringBuffer");         // Teilstring ersetzen
	   System.out.println(" sb3.replace = " + sb3);
	   
       sb3.insert(5," (mit einfuegbaren Zeichen) ");// Teilstring einfügen 
       System.out.println(" s3.insert  = " + sb3);
	   
   
    }

 }