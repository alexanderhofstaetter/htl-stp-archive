/*  RandomAccess.java
    di w.alfery

    Beispiel zu Random Access
 */



import java.io.*;
import javax.swing.JOptionPane;


public class RandomAccess
{
  public static void main( String[] args )
  {
     String filename= new String("zahlen.dat");  // Dateiname

    ////////////////////     Binärdatei Zugriff  /////////////////////////////

    int a[]=new int[10];                         // int-Array

    System.out.print("\n  Binaerdatei und Random Access \n");
    System.out.print("\n  Array : ");
    for (int i=0;i<a.length;i++)
    {  a[i]=i+1;
       System.out.print(a[i]+", ");
    }

    try                                          // ein Versuch ...
    {
       FileOutputStream fos = new FileOutputStream( filename );
                                                 // Datei-Ausgabestrom erzeugen
       DataOutputStream buffer = new DataOutputStream(fos);
                                                 // Daten-Ausgabestrom anlegen
       for (int i=0;i<a.length;i++)
       {  buffer.writeInt(a[i]);                 // und Array ausgeben
       }

       buffer.flush();                           // Datenstrom ausleeren
       buffer.close();                           // und schließen
       fos.close();
       System.out.println("\n  -> Array auf Datei geschrieben !");

    }
    catch ( Exception e )                        // Dateizugriffs-Fehler abfangen
    {  System.out.println("\n  -> Datei-Fehler " + e );
    }

    ////////////////////     wahlfreier Zugriff  /////////////////////////////

    boolean error;
    long pos;
    int zahl;
    final int sizeInt=Integer.SIZE/Byte.SIZE;    // Integergröße in Bytes

    do
    {  try                                       // Eingabe der Zeichenposition
       {  String s;
          s=JOptionPane.showInputDialog("\n  Zugriff auf Position = ");
                                                 // swingender Eingabedialog
          pos = Integer.parseInt(s);
          error=false;
       }
       catch (NumberFormatException e)
       {  pos=0; error=true;
       }
    } while ( error || pos<0);

    RandomAccessFile rac = null;                 // Random Access Zugriff

    try                                          // try & catch
    {
       rac = new RandomAccessFile( filename,"rw" ); // Random Access Zugriff öffnen  

       if ( pos*sizeInt < rac.length())
       {  rac.seek(pos*sizeInt);                 // Dateizeiger setzen
          zahl=rac.readInt();                    // und eine Zahl lesen
          System.out.println("\n  Zahl an der Position " + pos + "=" + zahl);
       }

       System.out.println("\n  Dateigroesse = " + rac.length());
       rac.close();

    }
    catch ( IOException e )
    {  System.out.println("\n  -> Datei-Zugriffs-Fehler !");
    }

  }
}

