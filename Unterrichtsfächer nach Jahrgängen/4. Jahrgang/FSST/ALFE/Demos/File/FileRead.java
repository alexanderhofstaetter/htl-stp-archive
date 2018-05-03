/*  FileRead.java
    w.alfery
        
    Beispiel für Textdatei lesen    
 */


import java.io.*;

public class FileRead
{
   public static void main(String[] args)
               throws IOException
   {
       FileReader f = new FileReader("Test.txt");//  Inputstream instanzieren

       int c;
     
       while ((c = f.read()) != -1)              //  bis Dateiende
       {                                         //  zeichenweise lesen
           System.out.print((char)c);            //  auf Konsole ausgeben	 
       }


   }

}
