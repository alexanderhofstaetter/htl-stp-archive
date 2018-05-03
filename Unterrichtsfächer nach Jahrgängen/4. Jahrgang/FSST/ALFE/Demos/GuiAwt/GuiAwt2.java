/* GuiAwt2.java
   w.alfery 
    
   GUI mit AWT  
   Layout Manager u. Controls 

*/ 

import java.awt.*;                               // AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse GuiAwt2 
public class GuiAwt2 extends Frame               // abgeleitet von Frame 
                     implements ActionListener   // implementiert ActionListener 
{ 
  
  // Steuerelemente (Controls) instanzieren 
  Label beschriftung = new Label("Kurs-Anmeldung");
  Label eingabe_text = new Label ("   Name   "); // Label
  TextField eingabe = new TextField("",20);      // Textfeld 
  
  CheckboxGroup group = new CheckboxGroup ();    // Gruppe für Radiobuttons 
  Checkbox o1 = new Checkbox ("männlich", group, true);
  Checkbox o2 = new Checkbox ("weiblich", group, false);
  
  Checkbox s1 = new Checkbox ("C/C++");          // Checkboxen
  Checkbox s2 = new Checkbox ("Java",true);
  
  Label wahl_text = new Label ("Semester");      // Label
  Choice wahl = new Choice();                    // Auswahlfeld 
  
  Label ausgabe_text = new Label ("  Ausgabe  ");   
  TextArea ausgabe = new TextArea(5,20);         // Textarea 
    
  Button ok = new Button(" OK ");                // Buttons
  Button cancel = new Button("Cancel"); 
  Button quit = new Button("Quit"); 
 
  
  // Konstruktor definieren  
  GuiAwt2(String titel)                          
  {
     super(titel);                               // Zugriff auf Basisklasse 
     Fenster();                                  // Fenster festlegen 
     Erst();                                     // Einstellungen 
     Anordnung();                                // Komponenten anordnen 
          
     addWindowListener(new Lauscher());          // Listener registrieren 
     ok.addActionListener(this); 
     cancel.addActionListener(this); 
     quit.addActionListener(this); 

  }

  
  // Methode main 
  public static void main(String[] args)
  {
     GuiAwt2 Fenster = new GuiAwt2("Layout mit Controls");// Fensterklasse instanzieren
     Fenster.pack();                             // Komponenten ausrichten 
     Fenster.show();                             // Fenster darstellen   
 
  }

  // Fenstereinstellungen  
  private void Fenster()	                      
  { 
     setBackground(Color.lightGray);            
     setSize(500,400);
     setLocation(0,0);
  }   

  // Einstellungen   
  private void Erst()	                      
  {   
     beschriftung.setFont(new Font("Arial", Font.BOLD,16)); // Schrift   
     beschriftung.setForeground(Color.red);      // Schriftfarbe  

     eingabe_text.setFont(new Font("Arial", Font.PLAIN,14));
     eingabe_text.setForeground(new Color(80,80,200));      
     eingabe_text.setAlignment(Label.CENTER);

     ausgabe_text.setFont(new Font("Arial", Font.PLAIN,14));
     ausgabe_text.setForeground(new Color(80,80,200));      
     ausgabe_text.setAlignment(Label.CENTER); 

     wahl_text.setAlignment(Label.CENTER); 
        
     wahl.addItem("1.Semester");                 // Einträge für Auswahlfeld
     wahl.addItem("2.Semester");      
     wahl.addItem("3.Semester");      
     wahl.addItem("4.Semester");      
     
  }   

  // Layout Festlegungen   
  private void Anordnung()	                    
  {  	
     Panel nord = new Panel();                   // Panel als Container  	
     nord.add(beschriftung );                    // Label einfügen
     this.add(nord,BorderLayout.NORTH);	         // Panel ins Hauptfenster einfügen 
       
     Panel zentral = new Panel();				 // Panel zentral 
     zentral.setLayout(new BorderLayout());      // Layout festlegen
     this.add(zentral,BorderLayout.CENTER);		 // Panel ins Hauptfenster einfügen 

     Panel zentral_nord = new Panel();			 // eingeschachteltes Panel 
     zentral_nord.setLayout(new GridLayout(5,2,8,10));// Gitter mit 5 Reihen u.2 Spalten 
     zentral_nord.add(eingabe_text);             // Label einfügen
     zentral_nord.add(eingabe);                  // Textfeld
     zentral_nord.add(o1); zentral_nord.add(s1); // Radios u. Checkboxes 
     zentral_nord.add(o2); zentral_nord.add(s2);           
     zentral_nord.add(wahl_text);                     
     zentral_nord.add(wahl);                     // Choice 
     zentral.add(zentral_nord,BorderLayout.NORTH);// Panel in Panel zentral einfügen 

     Panel zentral_sued = new Panel();		     // eingeschachteltes Panel
     zentral_sued.setLayout(new GridLayout(1,2,8,10));// Gitter mit 2 Spalten
     zentral_sued.add(ausgabe_text);                  
     zentral_sued.add(ausgabe);                  // Textarea
     zentral.add(zentral_sued,BorderLayout.SOUTH);// Panel in Panel zentral einfügen 

     Panel sued = new Panel();	  				 // Panel sued 
     sued.setLayout(new GridLayout(1,3,8,10));	 // Gitter mit 3 Spalten
     sued.add(ok);                               // Buttons einfügen 
     sued.add(cancel);
     sued.add(quit);
     this.add(sued,BorderLayout.SOUTH);	         // Panel ins Hauptfenster einfügen 
      
     pack();  	
  }
	
  
  // Event-Handling   
  class Lauscher extends WindowAdapter
  {  public void windowClosing(WindowEvent e)
     {  System.exit(0);                         
     }
  }
  
  public void actionPerformed( ActionEvent event )
  {  
     if (event.getSource()== ok)                 // wenn OK Button 
     {  ausgabe.append(" Anmeldung : ");  
        ausgabe.append(eingabe.getText());       // Eingaben ins Ausgabefeld ausgeben 
        if ( o1.getState() ) ausgabe.append ("\n männlich ");
        if ( o2.getState() ) ausgabe.append ("\n weiblich ");
        if ( s1.getState() ) ausgabe.append ("\n " + s1.getLabel());
        if ( s2.getState() ) ausgabe.append ("\n " + s2.getLabel());
        ausgabe.append("\n " + wahl.getSelectedItem() + "\n");  
     }     
     
     if (event.getSource()== cancel)             // wenn Cancel Button
     {  eingabe.setText("");                     // Eingaben zurücksetzen
        o1.setState(true);o2.setState(false);
        s1.setState(false);s2.setState(true);
        wahl.select(0);
        ausgabe.setText("");
     }
     
     if (event.getSource()== quit)               // wenn Quit Button 
        System.exit(0);                          // Programm beenden 
  }


}


