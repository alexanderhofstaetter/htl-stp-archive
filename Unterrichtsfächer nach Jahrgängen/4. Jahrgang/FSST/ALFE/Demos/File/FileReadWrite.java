/*  FileReadWrite.java
    w.alfery
        
    Beispiel für Textdatei schreiben u.lesen      
 */

import java.io.*;                               


public class FileReadWrite
{
   public static void main(String[] args)  throws IOException
   {
      // Datei Ein- und Ausgabe erfordert IOException handling 

      int x = 10;
      String s = " Java File Test \n";

      /////////////////////////////////////////////////////////////////////////
      // Daten auf Datei schreiben 
      // über PrintWriter >> FileWriter >> File 
      //  
      try                                         
      {  
         File datei = new File("test.txt");      // File Objekt erzeugen (öffnen)
         FileWriter f = new FileWriter(datei);   // Outputstream instanzieren
         PrintWriter aus = new PrintWriter(f);   // Ausgabe über PrintWriter

         f.write(s);                             // String s über FileWriter ausgeben 
         aus.println("Hallo");                   // Ausgabe über PrintWriter 
         aus.print("Zahl =" + x );               // ... Integerwert ausgeben 
         aus.println();                          // ... neue Zeile 
         
         aus.close();                            // FileWriter schließen
         f.close();                              // Datei schließen

      } 
      catch (IOException e)                      // IOExceptions auffangen  
      {
         System.out.println("\n -> Datei-Schreib-Fehler !");
      }

      /////////////////////////////////////////////////////////////////////////
      // Daten von Datei zeichenweise lesen  
      // über FileReader << File 
      //  
      String line;   
      try 
      {      
         FileReader fi = new FileReader("test.txt");// Inputstream instanzieren
         int i;
         line="";
         while((i=fi.read())!=-1)                //  zeichenweise lesen bis Dateiende
         {                                       
            line = line + (char)i;               //  Text zusammenfügen
         }
         fi.close();                             //  Datei schließen
         System.out.println(line);               //  Text auf Konsole ausgeben 

      }
      catch (IOException e) 
      {  
         System.out.println("\n -> Datei-Lese-Fehler ! ");
      }
   
    

      /////////////////////////////////////////////////////////////////////////
      // Daten von Datei zeilenweise lesen  
      // über BufferedReader << FileReader << File 
      //  
      try 
      {  FileReader fi = new FileReader("test.txt");// Inputstream instanzieren
         BufferedReader f = new BufferedReader(fi); // einlesen über BufferedReader  
         
         while ((line = f.readLine()) != null)   // zeilenweise lesen bis Dateiende   
         {
            System.out.println(line);            // und auf Konsole ausgeben 
         }
       
         fi.close();
      } 
      catch (IOException e) 
      {
         System.out.println("\n -> Datei-Lese-Fehler ! ");
      }

   }
}  
