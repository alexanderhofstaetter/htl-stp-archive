///////////////////////////////////////////////////////////////////////////////
//  scopedemo_canvas.java
//  w.alfery 
//   
//  scope-Demoprogramm  
//      
/////////////////////////////////////////////////////////////////////////////// 


import java.awt.*;                           	// awt Package 
import java.awt.event.*;


///////////////////////////////////////////////////////////////////////////////
//   Hauptklasse scopedemo_canvas 
///////////////////////////////////////////////////////////////////////////////

public class scopedemo_canvas extends Frame      // Hauptklasse testscope
{ 
  
  public scopedemo_canvas()                    	// Konstruktor
  { 
     super(" Scope by w.alfery " );            	// Fensterfestlegungen  
     setLocation(50,50);
     setVisible(true);
     setLayout(new FlowLayout(10));

     addWindowListener( new WindowAdapter()    	// Listener für Fenster schließen  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
      
  }    
     
  
  public static void main(String[] args)       	// Hauptmethode zu testscope  
  {
  	 int i,n;
  	 
  	 n=200;
  	 float s[]=new float[n];
  	 
  	 for (i=0;i<n;i++)                         	//  Sinussignal erzeugen     
	 {  s[i]=1.0f*(float) Math.sin(2*Math.PI*i*2/n + 0);
	 }

     scope g = new scope(500,250);              // scope-Objekt 
    
     g.scale(0,200,-1f,1f);
     g.signal(s); 

     
     scopedemo_canvas t = new scopedemo_canvas();  	// scopedemo_canvas Objekt 
     t.add(g);                                 	// scope Objekt g aufnehmen 
     t.pack();                                  // Fenster(größe) einrichten   
  
  }

 
}



///////////////////////////////////////////////////////////////////////////////
//   Klasse scope 
///////////////////////////////////////////////////////////////////////////////
        
class scope extends Canvas                       // Klasse scope 
{
  
  private int xe,ye;                             // Bildgröße 
  private float sx1=0,sy1=-100,sx2=100,sy2=100;  // Skalenendwerte   
  
  private int n;                                 // Anzahl der Samples 
  private float s[];                             // Referenz zu Sample Array 
    
   
  scope(int w,int h)                             // Konstruktor  
  {  
     this.xe=w;
     this.ye=h;
    
     setBackground(Color.lightGray);             // Fensterfarbe,-größe,-position 
     setSize(xe+60,ye+60);                       
    
  }

  void scale( float x1,float x2,float y1,float y2) // Skalenendwerte zuweisen    
  {  
     this.sx1=x1;this.sx2=x2;
     this.sy1=y1;this.sy2=y2;
  }

  void signal( float y[] )                        // Signalwerte zuweisen
  {  
     this.s=y;
     this.n=y.length;
     
  }

    
  // Umrechnung von Funktionswerten auf Bildwerte für x - Richtung :
  int scalx(float x)            // aus (xg-x1)/(x2-x1)=(x-xs1)/(xs2-xs1)
  {  
	 return (int) ( (x-sx1)*xe/(sx2-sx1));
  }

  // Umrechnung von Funktionswerten auf Bildwerte für y - Richtung :
  int scaly(float y)           // aus (yg-y1)/(y2-y1)=-(y-ys1)/(ys2-ys1)
  { 
     return (int) ( ye - (y-sy1)*ye/(sy2-sy1));
  }



 
  public void paint( Graphics g)                 // Methode paint für Grafikausgabe
  {  
     int i,x,y,dx,dy,x0,y0;             
     int xm=scalx(0),ym=scaly(0);
              
     g.translate(30,30);                         // Nullpunkt verschieben  
     g.setColor(Color.lightGray); 
     g.drawRect(0,0,xe,ye);                      // Rechteck zeichnen 
     g.fillRect(0,0,xe,ye); 

     g.setColor(Color.darkGray); 
     g.drawLine(0,ym,xe,ym);                     // x-Achse 
     g.drawLine(xm,0,xm,ye);                     // y-Achse 
     
     g.setColor(Color.blue); 
     x0= scalx(0);                               // Anfangswerte x0,y0
     y0= scaly(s[0]); 
        
     for (i=0;i<n;i++)                           // Signal zeichnen 
     {  x=scalx(i);
        y=scaly(s[i]);
        g.drawLine(x0,y0,x,y);
        x0=x;y0=y;
     }
       

  } 
  
}
  

