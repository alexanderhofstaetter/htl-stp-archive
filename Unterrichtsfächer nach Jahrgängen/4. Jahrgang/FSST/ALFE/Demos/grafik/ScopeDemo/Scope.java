/* Scope.java
   w.alfery 
   
   Scope - Signal Darstellung 
   
   
*/ 

import java.awt.*;                               // awt Packages importieren
import java.awt.event.*;


class Scope extends Frame                     	 // Klasse Scope   
{
  private int w,h;                               // Bildgröße 
  private float xs1=0,ys1=-100,xs2=100,ys2=100;  // Skalenendwerte   
 
  private int n;                                 // Anzahl der Samples 
  private float[] s;                             // Referenz zu Sample Array 
    

  Scope(int w,int h)                             // Konstruktor  
  {
     super(" Scope by w.alfery " );   
          
     addWindowListener( new WindowAdapter()      // für Grafikfenster schließen  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );

     this.w =w; this.h =h;  
     	
     setBackground(new Color(220,220,220));      // Hintergrundfarbe    
     setSize(w+60,h+60);                         // Fenstergröße  
     setResizable(false);    
     setVisible(true);

  }

  public void setScale(float xs1,float xs2,float ys1,float ys2)
  {  this.xs1=xs1;this.ys1=ys1;  
     this.xs2=xs2;this.ys2=ys2;
  }	


  public void signal( float[] s )                // Signalarray zuweisen
  {  
     this.s=s;
     this.n=s.length;
     
  }

    
  // Umrechnung von Funktionswerten auf Bildwerte für x - Richtung :
  int xp(float x)         
  {  
	 return (int) ( (x-xs1)*w/(xs2-xs1));
  }

  // Umrechnung von Funktionswerten auf Bildwerte für y - Richtung :
  int yp(float y)  
  { 
     return (int) ( h - (y-ys1)*h/(ys2-ys1));
  }


  public void paint( Graphics g)                 // Methode paint für Grafikausgabe
  {  
     int i,x,y,dx,dy,x0,y0;                       
     int xm=xp(0),ym=yp(0);                
              
     g.translate(30,40);                         // Nullpunkt verschieben  
     g.setColor(new Color(250,250,250)); 
     g.fillRect(0,0,w,h);                        // Rechteckfläche mit Farbe füllen 
     g.setColor(new Color(200,200,220)); 
     g.drawRect(0,0,w,h);                        // Rechteck zeichnen 

     g.setColor(new Color(100,100,120)); 
     g.drawLine(0,ym,w,ym);                      // x-Achse 
     g.drawLine(xm,0,xm,h);                      // y-Achse 
     
     g.setColor(new Color(100,100,250)); 
     x0= xp(0);                                  // Anfangswerte x0,y0
     y0= yp(s[0]); 
        
     for (i=0;i<n;i++)                           // Signal zeichnen 
     {  x=xp(i);          
        y=yp(s[i]);
        g.drawLine(x0,y0,x,y);
        x0=x;y0=y;
     }
     
  } 
  
}
