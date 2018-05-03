 /*  Stringbufferr.java
     w.alfery
        
     Klasse StringBuffer 
     für Strings mit veränderbaren Zeichen
      
 */

 import java.io.*;
 
 public class Stringbuffer 		            
 {  

    public static void main(String args[])       // Methode main() 
           throws IOException
    { 
       int i; 
	   String s=new String("Hallo Java String"); // String  

	   StringBuffer s1=new StringBuffer();       // leerer Stringbuffer  
	   StringBuffer s2=new StringBuffer("Buffer");// mit Konstantstring       
	   StringBuffer s3=new StringBuffer(s);      // mit String s     


       BufferedReader ein = new BufferedReader(
                            new InputStreamReader(System.in));

       System.out.println("\n Stringbuffer ");
       System.out.println(" _____________ \n");

       System.out.println(" s1 = " + s1);
       System.out.println(" s2 = " + s2);
	   System.out.println(" s3 = " + s3);

       s1.append("mehr").append("fach ").append("anhängen");
       System.out.println("\n s1 mit append = " + s1);
       
       System.out.print(" s2.setCharAt = ");
       s2.setCharAt(0,'b');                      // 'b' an Pos. 0 schreiben
       for (i=0;i<s2.length();i++)               // bis Stringende 
       {  System.out.print("-" + s2.charAt(i));  // zeichenweise ausgeben
       }
       
       s2.reverse();                             // String umkehren 
       System.out.println("\n s2.reverse = " + s2);
       
       s3.replace(11,17,"Buffer");               // Teilstring ersetzen
	   System.out.println(" s3.replace = " + s3);
	   
       s3.insert(11," (einfügbaren Zeichen) ");  // Teilstring einfügen 
       System.out.println(" s3.insert  = " + s3);
	   
    }
 }