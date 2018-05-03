/* GuiLayout.java
   w.alfery 
    
   Layout-Manager festlegen 
   und Komponenten einfügen

*/ 

import java.awt.*;                             	// AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse GuiLayout
public class GuiLayout extends Frame            // Hauptfenster  
                     
{  
  // Komponenten erzeugen
  Label title   = new Label(" Layout Manager ");// Beschriftung  
  TextField text = new TextField("Eingabe bitte",20); // Textfeld 
  Button enter   = new Button(" Enter ");       // Button
  Button quit    = new Button(" Quit  ");    
  
  // Konstruktor definieren   
  GuiLayout(String titel)                          
  {
     super(titel);                              // Fenstertitel übergeben
          
     addWindowListener( new WindowAdapter()    	// für Grafikfenster schließen  
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
     	
     
     // Fenster Einstellungen
     setBackground(Color.lightGray);                   
     setSize(400,100);
     setLocation(200,200);
  	 
     // Layout Manager definieren                  
     setLayout(new GridLayout(2,2));            // Grid Layout mit 2x2    

     add(title);                                // Komponenten anordnen 
     add(text);      
     add(quit);    
     add(enter);      
       
    
  }

  // Methode main 
  public static void main(String[] args)
  {
     GuiLayout view = new GuiLayout("Layout mit Controls");// Fensterklasse instanzieren
     view.setVisible(true);                    // Fenster darstellen   
 
  }
  
 
}
