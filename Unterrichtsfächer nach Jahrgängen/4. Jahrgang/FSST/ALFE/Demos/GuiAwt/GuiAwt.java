/* GuiAwt.java
   w.alfery 
   
   Grafische Benutzeroberfläche 
   mit AWT-Komponenten und Event-Handling
 
*/ 

import java.awt.*;                               // AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse von Frame ableiten  
public class GuiAwt extends Frame                
{ 
  TextField a;                                   
  Button b,c; 
  
  GuiAwt(String titel)                           // Konstruktor definieren  
  {
     super(titel);                               // Zugriff auf Element titel der Basisklasse 

     // Frame festlegen 
     setBackground(Color.lightGray);             // Fensterfarbe,-größe,-position    
     setSize(200,100);
     setLocation(100,100);
     
     // Layout Manager zur Anordnung der Komponenten 
     setLayout(new FlowLayout());                // Layout Manager FlowLayout(reihenweise)                     

     // Komponenten in Container (Frame) aufnehmen 
     a = new TextField("Textfeld",20);           // Textfeld instanzieren 
     b = new Button(" Button ");                 // Button instanzieren 
     c = new Button(" Quit ");                   // Button instanzieren 
     add(a);                                     // Textfeld hinzufügen
     add(b);                                     // Button hinzufügen
     add(c);                                     // Button hinzufügen

     // Komponenten für Event-Handling bei Listener registrieren 
     addWindowListener(new Lauscher());          // Frame  bei WindowListener registrieren 
     b.addActionListener(new Aktion());          // Button b bei ActionListener registrieren
     c.addActionListener(new Aktion());          // Button c bei ActionListener registrieren
     b.addMouseListener(new Maus());             // Button b bei MouseListener registrieren
     a.addKeyListener(new Taste());              // Textfeld a bei KeyListener registrieren

  }


  public static void main(String[] args)         // Methode main  
  {
     GuiAwt Fenster = new GuiAwt("Event-Handling");// Fensterklasse instanzieren
     Fenster.show();                             // Fenster darstellen   
 
  }


  // Listenerklasse (als innere Klasse) für WindowEvent definieren   
  // abgeleitet von Adapterklasse 
  class Lauscher extends WindowAdapter
  {  public void windowClosing(WindowEvent e)
     {  System.exit(0);                         
     }
  }

  // Listenerklasse für ActionListener definieren   
  class Aktion implements ActionListener
  {  public void actionPerformed( ActionEvent event )
     {  if (event.getSource()== b )
          a.setText("Button gedrückt");       
        if (event.getSource()== c )
          System.exit(0);        
     }         
  }

  // Listenerklasse für MouseListener definieren   
  class Maus implements MouseListener
  {  public void mouseClicked(MouseEvent e)
     {  a.setText(" Mouse Event ");       
        System.out.println(" click ");
     }
     public void mouseEntered(MouseEvent e) 
     {  a.setText(" Mouse Event ");       
        System.out.println(" enter ");
     }
     public void mouseExited(MouseEvent e)
     {  a.setText(" Mouse Event ");       
        System.out.println(" excited ");
     }
     public void mousePressed(MouseEvent e)
     {  a.setText(" Mouse Event ");       
        System.out.println(" pressed ");
     }
     public void mouseReleased(MouseEvent e) 
     {  a.setText(" Mouse Event ");       
        System.out.println(" release ");
     }
  }

  // Listenerklasse für KeyListener definieren 
  // abgeleitet von Adapterklasse    
  class Taste extends KeyAdapter 
  {  public void keyPressed(KeyEvent e)
     {  a.setText(" Key pressed "); 
     }
  }
  
}

