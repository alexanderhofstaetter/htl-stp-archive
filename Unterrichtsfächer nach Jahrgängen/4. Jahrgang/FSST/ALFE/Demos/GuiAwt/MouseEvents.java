/* Grafik.java
   w.alfery 
   
   Mouse Events  
   
   
*/ 

import java.awt.*;                        
import java.awt.event.*;

 
 
public class MouseEvents extends Frame            // Frame Hauptklasse
{
   
  public MouseEvents()                            // Konstruktor
  {
     super(" Mouse Events ");
     addWindowListener( new WindowAdapter()       // Listener für Grafikfenster schließen  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
     
     addMouseListener(new onMouse());
  }
 
  class onMouse extends MouseAdapter              // MouseAdapter verwenden
  {
     int cnt = 0;
 
     public void mousePressed(MouseEvent event)   // wenn Maustaste gedrückt    
     {
        Graphics g = getGraphics();
        int x = event.getX();                     // Maus Koordinaten abfragen
        int y = event.getY();
        if (event.getClickCount() == 1)           // bei erstem Klick    
        {   
            ++cnt;
    
            g.drawOval(x-10,y-10,20,20);          // Grafikdarstellung -> Gesicht
            g.fillRect(x-6,y-5,4,5);              // mit -> Augen
            g.fillRect(x+3,y-5,4,5);

            if (event.isMetaDown())               // bei rechter Maustaste 
           	{  g.drawLine(x-5,y+7,x+5,y+7);       // -> freundliche Mundwinkel  
            } 
            else 
           	{ 
               g.drawArc(x-7,y-7,14,14,225,100);  // 
            }

            g.drawString(""+cnt,x+10,y-10);
        } 
        else if (event.getClickCount() == 2)     // bei Doppelklick -> mit Brille 
       	{   
            g.drawLine(x-9,y-3,x+9,y-3);
        }
     }
  }
 
  public static void main(String[] args)
  {
     MouseEvents wnd = new MouseEvents();
     wnd.setSize(500,400);
     wnd.setLocation(200,100);
     wnd.setVisible(true);
  }
 

}
