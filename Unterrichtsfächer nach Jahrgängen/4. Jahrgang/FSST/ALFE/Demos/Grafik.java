/* Grafik.java
   w.alfery 
   
   Grafik Ausgaben mit AWT ( Abstract-Window-Toolkit ) 
   
   
*/ 

import java.awt.*;                               // awt Packages importieren
import java.awt.event.*;

public class Grafik extends Frame                // Hauptklasse von Frame ableiten  
{
 
  Grafik()                                       // Konstruktor  
  {
     super("  Diagramm " );                      // Zugriff auf Element titel der Basisklasse 
     
     addWindowListener( new WindowAdapter()      // für Grafikfenster schließen  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );

     setBackground(Color.lightGray);             // Fensterfarbe,-größe,-position    
     setSize(500,300);
     setLocation(100,100);
     setVisible(true);

  }


  public void paint( Graphics g)                 // Methode paint für Grafikausgabe
  {  
     int n=400,am=100,x,y,x0,y0;   
	 final double pi = Math.PI; 
    
     g.setColor(Color.white);                    // Farbe einstellen
     g.fillRect(50,50,400,200); 
     g.setColor(Color.darkGray);                   
     g.drawRect(50,50,400,200);                  // Rechteck zeichnen 
          
     g.drawLine(50,150,450,150);                 // Linie zeichnen
	 g.drawString(" Sinus-Frequenzvielfache ",50,280);
	 g.setColor(Color.blue); 
	 
	 for(int f=1;f<25;f+=2)                      // Sinus-Frequenzvielfache darstellen 
     {  x0=50;y0=150;
        for(int i=0;i<n;i++)
	    {  x = 50 + i;
    	   y = 150 - (int)((am*1.0/f)*Math.sin(2*pi*i*f/n));
           g.drawLine(x0,y0,x,y);
           x0=x;y0=y;
	    }
	 }   
     
  } 
  

  public static void main(String[] args)
  {
     Grafik f = new Grafik();                    // Fensterklasse instanzieren
     f.show();                                   // Fenster darstellen   

  }
  
}

