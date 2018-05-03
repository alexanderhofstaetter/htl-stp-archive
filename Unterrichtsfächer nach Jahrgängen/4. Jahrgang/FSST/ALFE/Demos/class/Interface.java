
 /*  Interface.java
     w.alfery
        
     finale Klassen, abstrakte Klassen und Interfaces 
     
     Von finalen Klassen und Methoden kann nicht mehr abgeleitet werden,  
     der Methodenaufruf erfolgt dadurch mit besserer Performance.
          
     Abstrakte Klassen müssen abgeleitet werden und 
     können nicht direkt instanziert werden.  
     Abstrakte Basisklassen dienen als Vorlage für abgeleitete Klassen 
     und enthalten mindestens eine abstrakte Methode,
     die in den abgeleiteten Klassen dann überschrieben werden muss.
     
     Interfaces sind Klassen, die ausschließlich abstrakte Methoden 
     und Konstanten enthalten, jedoch keine Konstruktoren.  
     Es kann aber von mehreren Interfaces geerbt werden. 
     
    
           
 */

 import java.io.*;
 
 //////////////////////////////////////////////////////////////////////////////
 final class Farbe                               // finale Klasse hat keine Erben  
 {  
    private static int color=0; 
      
    public void setcolor(int color)
    {  this.color = color;
    } 
    public int getcolor()
    {  return color;
    } 

 }     

 
 //////////////////////////////////////////////////////////////////////////////
 abstract class Objekt                           // abstrakte Klasse als Vorlage 
 {                                              
    protected String name;                 
                       
    Objekt ( String name )                       // Konstruktor
    { this.name = name; 
    } 
                                                                                                
    public abstract void ausgabe();              // abstrakte Methoden 
    
 }

 class Kreis extends Objekt                      // abgeleitete Klasse  
 {
    int x,y,r;
    
    Kreis ( int x, int y, int r )             
    { super("   Kreis");                 
      this.x=x; this.y=y;this.r=r;
    }
                 
    public void ausgabe()                        // abstrakte Methode implementieren (konkretisieren)
    {  System.out.println(name); 
       System.out.println("   x="+x+",y="+y+",r="+r); 
    }
  
 }


 //////////////////////////////////////////////////////////////////////////////
 interface Material                              // Interface - Definition   
 {  
    int METALL=1,                                // Konstante 
        ALU=2,
        GLAS=3;
 
    int nummer();                                // abstrakte Methode
 }

 class Metall implements Material                // Interface wird implementiert 
 {
    public int nummer() { return METALL; }
 }


 //////////////////////////////////////////////////////////////////////////////
 public class Interface		                     // Hauptklasse 
 {   
    public static void main(String args[])       
    { 
       
       Farbe c1,c2;
       c1=new Farbe();c2=new Farbe();            // Instanzen der finalen Klasse 
       c1.setcolor(10);
       System.out.println("\n Farbe als finale Klasse :");
       System.out.println("   c1="+c1.getcolor());
       System.out.println("   c2="+c2.getcolor());                       
       
	   // Objekt o=new Objekt("nicht möglich!"); // Instanz einer abstr. Klasse nicht möglich !

	   Kreis k=new Kreis (50,50,20);             // Instanz der konkreten Klasse  
	   System.out.println("\n Kreis als konkrete Klasse : ");
	   k.ausgabe();                               
   
       
       Metall m=new Metall();                    // Instanz einer Implentierung    
       System.out.println("\n Metall implementiert das Interface Material : ");
	   System.out.println("   Materialnummer zu Metall="+m.nummer());                               
       
    }
 }