/* GuiJFrame.java
   w.alfery 
   
   GUI Swing Fenster (JFrame) 
   erstellen und konfigurieren 
 
*/ 

import java.awt.*;                               // AWT Packages u. 
import javax.swing.*;                            // Swing Packages importieren


public class GuiJFrame extends JFrame            // Hauptfensterklasse von JFrame ableiten  
{                                                
  
  public GuiJFrame()                             // Konstruktor definieren 
  {  
     setTitle("Swing Fenster");                	 // Fenster Beschriftung   
     setSize(400,300);                         	 // Fenstergröße 
     setResizable(false);                      	 // Größe nicht veränderbar 
     setLocation(200,200);                     	 // Fensterposition 
     setBackground(Color.lightGray);           	 // Hintergrundfarbe    
     setVisible(true);                         	 // Fenster sichtbar darstellen   

     setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );  // Close Button festlegen   
     
  }	

  public static void main(String[] args)        
  { 

     GuiJFrame f = new GuiJFrame();              // eigene Fensterklasse instanzieren
  	 
  
  }


}
