 /*  ReadWriteTest.java
   
     Verwendung der Hilfsklasse "Read" 
     für das Einlesen und Ausgeben auf Konsole 
     mit Fehler Behandlung (Exception Handling)  
     
 */

 import java.io.*;				
 
 public class ReadWriteTest			
 {  
    public static void main(String args[]) throws IOException
    {  
       String text; 
       char c,auswahl;
       int i; 
       float x; 	
       	 
       Read in= new Read(); 
       	
       System.out.println(" Test der Hilfsklasse \"Read\" \n");

       do 
       {

          System.out.print(" String  Eingabe s= ");
          text=in.readString();
          if (in.getError()) System.out.println(" -> Eingabefehler ");  
          
          System.out.print(" Integer Eingabe i= ");
          i=in.readInt();
          if (in.getError()) System.out.println(" -> Eingabefehler ");  
        
          System.out.print(" Float   Eingabe x= ");
          x=in.readFloat();
          if (in.getError()) System.out.println(" -> Eingabefehler ");  
 
          do
          {
          	System.out.print("Zeichen = ");
          	c= in.readChar();
          	System.out.print(" -> "+ c);
          	
          }while (c!='x');
       
       
          System.out.print("\n Quit mit [q] ");
          auswahl = in.readChar(); 
       } while (auswahl != 'q');   

    }
 }


class Read 
{   
    public BufferedReader ein;
    private boolean error; 
 
    public Read() 
    {  ein = new BufferedReader(new InputStreamReader(System.in));
       error = false;
    } 
   
    public boolean getError()
    {  return error; 
    }	 	
  
    char readChar() 
    {  char c=0; 
    
       
       try                                       //  Exception abfangen  
       {   c=(char) ein.read();                  //  Zeichen einlesen 
           //ein.readLine();                       
           error=false; 
       } 
       catch (IOException e)  
       {   error=true; 
       }         	    
    
       return c;  
    }

      
    String readString() 
    {  String s=""; 
    
       try                                       //  Exception abfangen  
       {   s=ein.readLine();                     //  String einlesen 
           error=false; 
       } 
       catch (IOException e)  
       {   error=true; 
       }         	    
       return s;  
    }  
      
    int readInt()
    {  int i=0; 
       
       try                                       //  Exception abfangen  
       {  i = Integer.parseInt(ein.readLine());  //  auf int umwandeln
          error=false; 
       } 
       catch (NumberFormatException e)  
       {   error=true; 
       }     
       catch (IOException e)  
       {   error=true; 
       }         	    

       return i;
    }

    float readFloat()
    {  float x=0; 
       
       try                                       //  Exception abfangen  
       {  x = Float.parseFloat(ein.readLine());  //  auf float umwandeln
          error=false; 
       } 
       catch (NumberFormatException e)  
       {  error=true; 
       } 
       catch (IOException e)  
       {   error=true; 
       }         	    

       return x; 
    }

 
}
        
