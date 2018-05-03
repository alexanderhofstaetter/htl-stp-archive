/*******************************************************
* Datei    : Signalanalyse.java
* 
* progr.   : w.alfery
* 
* date     : 2013-10-23
*
* version  : v1.0 
*   
* 
* Anwendung für Signalerzeugung und Signalanalyse
*
* 
*
*******************************************************/


public class Signalanalyse
{
   
   
   public static void main (String[] args)
   { 
   	  
      System.out.println("Signale");

      
      // Referenz für Signalsamples
      float[] samples;  
      
      float am=10.0f,fn=1.0f,phi=0.0f;    // Signalparameter

      // Generator erstellen 
      Signal g = new Signal(20);    
   
      samples=g.dc(am);
      	
    
      for(int i=0;i<samples.length;i++)
      {  System.out.printf(" %4d  :  %5.2f  \n",i,samples[i]); 
      }	



   }
}


////////////////////////////////////////////////////////
//  Klassendefinition "Signal"
////////////////////////////////////////////////////////
class Signal
{
   private int n; 	                    // SIgnalfeldgröße
   public float[] g; 	                // Referenz für Signalarray
	
   
   public Signal(int n)              // Konstruktor  
   {
   	  g=new float[n];                   // Array Instanz      
   	  this.n=n;  	
   }	   
   
   public float[] dc( float am )        // Gleichsignal 
   {  int i;
      
      for(i=0;i<g.length;i++)
      {  g[i]=am; 
      }	
   	  return g; 
   }  	
/*
   public float[] sinus( float am, float fn, float phi )  // Sinussignal 
   {  int i;
      // ..       
   
   }  	

   public float[] rectangle( float am, float fn, float phi ) 
   {  int i;
      float s;
      // ... 
   	
   }	
  */ 
  	
   public float[] rand( float am )
   {  int i;
      
      for(i=0;i<g.length;i++)
      {  g[i] =(float)( 2*am*Math.random() - am ); 
      }	

   	  return g; 
   }	
    
	
}


////////////////////////////////////////////////////////
//  Klassendefinition "Analyse"
////////////////////////////////////////////////////////
class Analyse
{ 
   
 
}

