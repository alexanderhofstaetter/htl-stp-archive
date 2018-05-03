/* GuiFrame.java
   w.alfery 
   
   GUI Fenster (Frame) 
   erstellen und konfigurieren 
 
*/ 

import java.awt.*;                               // AWT Packages importieren


public class GuiFrame extends Frame              // Hauptfensterklasse von Frame ableiten  
{                                                
  
  public GuiFrame()                              // Konstruktor definieren 
  {  
     super("Fenster");                           // Basisklasenkonstruktor(von Frame) aufrufen 
                                                 // zur Fensterbeschriftung 
  }	

  public static void main(String[] args)        
  { 

     GuiFrame f = new GuiFrame();                // eigene Fensterklasse instanzieren
  	 
  	                                             // Fenster Einstellungen:  
     f.setSize(400,300);                         // Fenstergröße 
     f.setResizable(false);                      // Größe nicht veränderbar 
     f.setLocation(200,200);                     // Fensterposition 
     f.setBackground(Color.lightGray);           // Hintergrundfarbe    
     
     f.setVisible(true);                         // Fenster sichtbar darstellen   
  }


}
