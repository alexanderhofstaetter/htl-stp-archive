/* NullLayout.java
   w.alfery 
    
   Null Layout 
   für die Positionierung über absolute Koordinatenangaben 
   mit setBounds, setLocation u. setSize 
   
*/ 

import java.awt.*;                             				// AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse NullLayout
public class NullLayout extends Frame            			// Hauptfenster  
                     
{  
  // Komponenten 
  Label title;  
  Label textlabel; 
  TextField text; 
  Button enter; 
  Button clear;
  Button quit; 
      
  
  // Konstruktor definieren   
  NullLayout()                          
  {
     view();                                    			// View ausführen (Oberfläche)                    
       
     addWindowListener( new WindowAdapter()      			// Fenster Schließschalter    
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
    
  }


  // View     
  private void view()	                    
  {  
     
     // Fenster Einstellungen 
     setTitle( " Layout mit Panels " );
     setBackground(Color.lightGray);            	      
     setSize(400,140);
     setLocation(200,100);
     setResizable(false);                    
     
  	 // Komponenten erzeugen
     title     = new Label(" Container ");          		// Beschriftungen  
     textlabel = new Label(" Texteingabe ");    
     text      = new TextField(" Eingabe bitte ... ",20); 	// Textfeld 
     enter     = new Button(" Enter ");                   	// Buttons
     clear     = new Button(" Clear ");    
     quit      = new Button(" Quit  ");      
  	
  	 // Komponenten Formatierungen 
     title.setFont(new Font("Arial", Font.BOLD,14));     	// Formatierungen für title  
     title.setForeground(new Color(50,150,50));      
     title.setAlignment(Label.CENTER); 
     
     // Null Layout setzen        
     setLayout(null);                                    	// Null Layout für Hauptfenster   
  	 
  	 title.setBounds(100,20,200,40); 				   		// Größe u. Position für "title" zuweisen  
  	 add(title);                            				// Komponente "title" einfügen 
    
  	 textlabel.setBounds(10,60,190,20);  			   		// Größe u. Position für "textlabel" zuweisen  
     add(textlabel);										// Komponente "textlabel" einfügen 
     
 	 text.setBounds(200,60,190,20);   	 			   		// Größe u. Position für "text" zuweisen       
     add(text);												// Komponente "text" einfügen 
     
     enter.setSize(120,30);         	 			   		// Größe für "enter" u.                            
     enter.setLocation(10,100);  	 			   		    // Position zuweisen 
     add(enter); 											// Button "enter" einfügen 

     clear.setSize(120,30);         	 			   		// Größe für "clear" u.                            
     clear.setLocation(140,100);		   					// Position zuweisen 
     add(clear);  											// Button "clear" einfügen 
	
     quit.setSize(120,30);         	 			   			// Größe für "quit" u.                            
     quit.setLocation(270,100);  	 			   			// Position zuweisen
     add(quit);  											// Button "quit" einfügen 
  
  }
	

  // Methode main 
  public static void main(String[] args)
  {
     NullLayout view = new NullLayout();    				// Fensterklasse instanzieren
     view.setVisible(true);                     			// Fenster darstellen   
 
  }
  
 
}
