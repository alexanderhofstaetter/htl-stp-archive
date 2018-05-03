/* GuiAwt3.java
   w.alfery 
    
   GUI mit AWT  
   Menüs u. Dialoge 

*/ 

import java.awt.*;                               // AWT Packages importieren
import java.awt.event.*;                        

// Hauptfensterklasse GuiAwt3 
public class GuiAwt3 extends Frame               // abgeleitet von Frame 
                     implements ActionListener   // implementiert ActionListener 
{ 
  // Menupunkte   
  MenuItem m_oeffnen,m_speichern,m_ende,m_ndialog; 
   
  
  // Konstruktor definieren  
  GuiAwt3(String titel)                          
  {
     super(titel);                               // Zugriff auf Basisklasse 
     Fenster();                                  // Fenster festlegen 
     Menue();                                    // Menü anordnen 
          
     addWindowListener(new Lauscher());          // Listener registrieren 

  }

  
  // Methode main 
  public static void main(String[] args)
  {
     GuiAwt3 Fenster = new GuiAwt3("Menüs und Dialoge");// Fensterklasse instanzieren
     Fenster.setSize(300,200);  
     Fenster.show();                             // Fenster darstellen   
 
  }

  // Fenstereinstellungen  
  private void Fenster()	                      
  { 
     setBackground(Color.lightGray);            
     setSize(300,200); 
     setLocation(100,100);
  }   


  // Menü Festlegungen   
  private void Menue()	                    
  {  	
     MenuBar mb = new MenuBar();                 // Menüleiste     	
     setMenuBar(mb);                             // anbringen 
     
     Menu m = new Menu("Datei");                 // Eintrag in Menüleiste
     mb.add (m);                                   
     
     m_oeffnen   = new MenuItem("Öffnen");       // Menüpunkte  
     m_speichern = new MenuItem("Speichern");
     m_ende      = new MenuItem("Ende");
     
     m.add(m_oeffnen);                           // hinzufügen  
     m.add(m_speichern);   
     m.add(m_ende);   
     
     m_oeffnen.addActionListener(this);          // bei Listener registrieren
     m_speichern.addActionListener(this);        
     m_ende.addActionListener(this);        
     
     Menu m2 = new Menu("Dialog");               // Eintrag in Menüleiste
     mb.add (m2); 
     m_ndialog = new MenuItem("nichtmodaler Dialog");
     m2.add(m_ndialog);                          
     m_ndialog.addActionListener(this);
     

  }
	
    
  // Event-Handling   
  class Lauscher extends WindowAdapter
  {  public void windowClosing(WindowEvent e)
     {  System.exit(0);                         
     }
  }
  
  public void actionPerformed( ActionEvent event )
  {  
     if (event.getSource()== m_oeffnen)          // Menüauswahl Öffnen  
     {  FileDialog fd = new FileDialog(this,"Datei",FileDialog.LOAD); 
        fd.show();
        String pfadname = fd.getDirectory() + fd.getFile();
        System.out.println(pfadname);   
     }     

     if (event.getSource()== m_speichern)        // Menüauswahl Speichern   
     {  FileDialog fd = new FileDialog(this,"Datei",FileDialog.SAVE); 
        fd.show();
        String pfadname = fd.getDirectory() + fd.getFile();
        System.out.println(pfadname);   
     }     
     
     if (event.getSource()== m_ndialog)          // Menüauswahl nichtmodaler Dialog
     {  mdialog nmd = new mdialog(this,"nicht modal",false,250,150);
        System.out.println(nmd.data);   
     }     

     if (event.getSource()== m_ende)             // Menüauswahl Ende  
        System.exit(0);                         
  }

}


// eigene Dialogklasse mdialog abgeleitet von Dialog    
class mdialog extends Dialog 
              implements ActionListener 
{  public String data;  
       
   Label text = new Label("Dialog");
   TextField eingabe = new TextField("",20);  
   Button ok = new Button(" OK ");              
   Button cancel = new Button("Cancel"); 
     
   mdialog(Frame f,String titel,boolean modal,int x, int y )     
   {  super (f,titel,modal);       
      
      setSize(x,y); 
      setResizable(false);
      setLayout(new FlowLayout()); 
      add(text);add(eingabe); 
      add(ok);add(cancel);
      setVisible(true); 
      addWindowListener(new dLauscher());     
      ok.addActionListener(this);      
      cancel.addActionListener(this);      
      
   }

  class dLauscher extends WindowAdapter
  {  public void windowClosing(WindowEvent e)
     {  setVisible(false);
        dispose();
        System.exit(0);                         
     }
  }
  
  public void actionPerformed( ActionEvent event )
  {  
     if (event.getSource()== ok)  
     {   data=eingabe.getText();     
         System.out.println(data);   
         setVisible(false); 
         dispose();
     }     
     if (event.getSource()== cancel)  
     {   data="";     
         System.out.println(data);   
         setVisible(false); 
         dispose();  
     }   
   }

}
