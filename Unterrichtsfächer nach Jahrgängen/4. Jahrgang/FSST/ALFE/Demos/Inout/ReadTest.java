 /*  ReadTest.java
   
     Verwendung der Hilfsklasse "Read" 
     für das Einlesen von Konsole 
   
     w.alfery 
       
 */

 import java.io.*;	
 	
 public class ReadTest			
 {  
    public static void main(String args[]) throws IOException
    {  
      
       char auswahl;
       String s=""; 
       int i; 
       float x; 
       double d; 		
       	 
       Read in= new Read(); 
       	
       System.out.println(" Test der Hilfsklasse \"Read\" \n");

       do 
       {
       	
          System.out.print(" String Eingabe  s= ");
          s=in.readString(); 
          System.out.println(" -> s= " + s);  
         
          System.out.print(" Integer Eingabe i= ");
          i=in.readInt();
          System.out.println(" -> i= " + i);  
          if (in.getError()) System.out.println(" -> Eingabefehler ");  
        
      
          System.out.print("\n Quit mit [q] ");
          auswahl = in.readChar(); 
       } while (auswahl != 'q');   

    }
 }





/*   -------------------------------------------------------------------------- 
     Klassendefinition "Read" 
     für das Einlesen von Zeichen, Strings und numerischen Datentypen 
     über die Konsole mit Fehler Behandlung (Exception Handling)  
   
     w.alfery 
     --------------------------------------------------------------------------
 */ 

class Read 
{   
    public InputStreamReader is;
    public BufferedReader ein;
   
    private boolean error; 
 
    public Read() 
    {  is  = new InputStreamReader(System.in);
       ein = new BufferedReader(is);
       error = false;
    } 
   
    public boolean getError()
    {  return error; 
    }	 	
    	
 
    char readChar() 
    {  char c=0; 
    
       try                                       //  Exception abfangen  
       {   c=(char) ein.read();                  //  Zeichen einlesen mit Enter 
           ein.readLine();
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
       {  
           s=ein.readLine();                     //  String einlesen   
           error=false; 
       } 
       catch (IOException e)  
       {   error=true; 
       }         	    
    
       return s;  
    }

      
    int readShort()
    { 
	  return 0; 
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

    long readLong()
    {  
     	return 0;	
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
 
    double readDouble()
    {   return 0; 
    }


}
        
