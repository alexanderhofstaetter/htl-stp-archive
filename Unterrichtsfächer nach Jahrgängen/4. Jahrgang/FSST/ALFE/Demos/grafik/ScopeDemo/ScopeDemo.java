/* Scope.java
   w.alfery 
   
   Scope - Signal Darstellung 
   
   
*/ 

import java.awt.*;                               // awt Packages importieren
import java.awt.event.*;


public class ScopeDemo                           // Hauptklasse ScopeDemo  
{
  
  public static void main(String[] args)
  {
 	 int i,n=200;
 	 float fn=0.5f;
 	 float s[]=new float[n];
  	 
  	 for (i=0;i<n;i++)                          //  Sinussignal erzeugen     
	 {  s[i]=1.0f*(float) Math.sin(2*Math.PI*i*fn/n + 0);
	    fn=fn*1.01f;                            //  sweep
	 }

  	
     Scope f = new Scope(500,250);               // Scope instanzieren
  
     f.setScale(0,n,-1f,1f);                     // Skalenendwerte einstellen
     f.signal(s);                                // Signal zuweisen 
     f.show();                                   // und darstellen   

  }
  
}



