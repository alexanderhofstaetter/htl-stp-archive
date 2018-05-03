 /*  ClockDemo.java
     w.alfery
     
     Stoppuhr als Thread

 */
 
import java.awt.*;
import java.awt.event.*; 


///////////////////////////////////////////////////////////////////////////////
//  Clock Thread 
///////////////////////////////////////////////////////////////////////////////
class Clock extends Thread  
{
  private long t=0,                              // laufende Zeitdifferenz in ms   
               t0=0,                             // Startzeit  in ms 
               te=0,                             // Stoppzeit  in ms 
               tc=0;                             // Systemzeit in ms  
  private boolean running=false;                    
  private Label display=null; 	
  
  
  // Run Methode 
  public void run()  
  {   
  	  while (!isInterrupted())             	     // Thread laufend ausführen 
      {  
      	 if (running)                            // Stoppuhr läuft ?          
      	 {   tc=System.currentTimeMillis();      // Systemzeit abfragen
	         t=tc-t0;                            // Zeitdifferenz zu t0
     	 }
         try 
         {  Thread.sleep(1);                     // 1 ms warten (-> ms Takt Abfrage, sonst 
	     }                                       // würde der Thread zuviel Systemleistung benötigen!) 
	     catch (InterruptedException e)       
	     {
	     }

      }
  }
  
  public void startTime()                        // Uhr starten   
  {    running=true;
       t0=System.currentTimeMillis();            // Startzeit t0
  }
  
  public void stopTime()                         // Uhr stoppen                      
  {    running=false;
  	   te=tc;                                  
       t=te-t0;
  }

  public void resetTime()                        // Uhr rücksetzen                       
  {    running=false;   
       te=tc=t0=0;
       t=0;
  }

  public long getTime()                          // Zeit ausgeben  
  {    return t; 
  }
  
  public String toString()
  {    return String.format("  %04d : %03d  ",t/1000,t%1000); // Anzeigeformat "s : ms"  
  }	
	
}



///////////////////////////////////////////////////////////////////////////////
//  Hauptklasse  
///////////////////////////////////////////////////////////////////////////////
public class ClockDemo extends Frame 
{

   // GUI Komponenten 
  Label      time1, time2;  
  Button     start1,start2,stop1,stop2,reset1,reset2;
  
  //  Clock Referenzen 
  Clock  t1,t2; 
  
  //  View     
  private void view()	                    
  { 
      // Fenster Einstellungen 
     setTitle( " Stoppuhr " );
     setBackground(Color.lightGray);            	      
     setSize(400,120);
     setLocation(300,200);
     setResizable(false);         
   
     
 	 // Komponenten erzeugen
     time1      = new Label("");           	     // Label für Zeitanzeige 1 
     time1.setFont(new Font("arial", Font.BOLD, 16));
     time1.setAlignment(Label.RIGHT);

     time2      = new Label("");  	             // Label für Zeitanzeige 2 
     time2.setFont(new Font("arial", Font.BOLD, 16));
     time2.setAlignment(Label.RIGHT);

     start1 = new Button(" Start ");        	 // Buttons erstellen
     stop1  = new Button(" Stop  "); 
     start2 = new Button(" Start ");
     stop2  = new Button(" Stop  "); 
     reset1 = new Button(" Reset ");
     reset2 = new Button(" Reset "); 

     // Layout                 
     setLayout(new GridLayout(2,4));             // Grid Layout für Hauptfenster  
     
     add(start1);    							 // Komponenten anordnen 
     add(stop1); 
     add(reset1);      	
     add(time1);      
     add(start2); 
     add(stop2); 
     add(reset2);      	
     add(time2);      

  }
 
  // Konstruktor  
  public ClockDemo() 
  {
     view();                                     // GUI aufbauen    
          
     start1.addActionListener(new on_click());   // Listener registrieren  
     start2.addActionListener(new on_click()); 
     stop1.addActionListener(new on_click()); 
     stop2.addActionListener(new on_click()); 
     reset1.addActionListener(new on_click()); 
     reset2.addActionListener(new on_click()); 

     addWindowListener( new WindowAdapter()       
     {  public void windowClosing(WindowEvent event)
        { System.exit(0);}          
     } );
     
  }

  

  //  main Methode   
  public static void main(String[] args)
  {

      ClockDemo app=new ClockDemo();
      app.setVisible(true);                      // ClockDemo App ausführen 
      
      app.t1 = new Clock();                      // Clock Thread erzeugen 
      app.t2 = new Clock();              
      
      app.t1.start();                            // Clock t1 starten 
      app.t2.start();       	                 // Clock t2 starten  
      
      while(true)
      {
          try 
		  {  
		      app.time1.setText(app.t1.toString()); // Zeitanzeigen aktualisieren
		      app.time2.setText(app.t2.toString());
		      
		      Thread.sleep(100);                 // im 100 ms Takt anzeigen  
		  } 
		  catch (InterruptedException e) 
		  {
		  }
      } 

  }


  ///////////////////////////////////////////////////////////////////////////////
  // Event-Handling (Control)  - ActionListener Klasse    
  ///////////////////////////////////////////////////////////////////////////////
  class on_click implements ActionListener       
  {  
     public void actionPerformed( ActionEvent event )
     {   if (event.getSource()== start1)         
         {  t1.startTime();                      // Clock1 start 
         }   
         if (event.getSource()== start2)         
         {  t2.startTime();                      // Clock2 start 
         }   
         if (event.getSource()== stop1)         
         {  t1.stopTime();                       // Clock1 stop 
         }   
         if (event.getSource()== stop2)         
         {  t2.stopTime();                       // Clock2 stop
         }   
  	     if (event.getSource()== reset1)         
         {  t1.resetTime();                      // Clock1 reset
         }   
  	     if (event.getSource()== reset2)         
         {  t2.resetTime();                      // Clock2 reset 
         }   

     }     
  }


}

 
