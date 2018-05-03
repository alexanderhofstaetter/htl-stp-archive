/*******************************************************
* Datei    : Signale.java
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


public class Signale
{
   
   
   public static void main (String[] args)
   { 
   	  
      System.out.println("Signale");

      
      // Referenz für Signalsamples
      float[] samples;  
      
      float am=10.0f,fn=1.0f,phi=0.0f;    // Signalparameter

      // Generator erstellen 
      Generator g = new Generator(20);    
      samples=g.dc(am);	                  // Gleichsignal einstellen
      // samples=g.sinus(am,fn,phi);         // Sinussignal einstellen
      	



   }
}


////////////////////////////////////////////////////////
//  Klassendefinition "Generator"
////////////////////////////////////////////////////////
class Generator
{
   private int n; 	                    // SIgnalfeldgröße
   public float[] g; 	                // Referenz für Signalarray
	
   
   public Generator(int n)              // Konstruktor  
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

   public float[] sinus( float am, float fn, float phi )  // Sinussignal 
   {  int i;
      
      for(i=0;i<g.length;i++)
      {  g[i]=(float)(am*Math.sin(2*Math.PI*i*fn/n + Math.PI*phi/180 )); 
      }	
   	  return g; 
   }  	

   public float[] rectangle( float am, float fn, float phi ) 
   {
   	  int i;
      
      for(i=0;i<g.length;i++)
      {  g[i]=(float)(Math.sin(2*Math.PI*i*fn/n + Math.PI*phi/180 )); 
      }	
   	  return g; 
   }	
  
   public float[] rand( float am )
   {
   	
   	
   }	
    
	
	
}


////////////////////////////////////////////////////////
//  Klassendefinition "Analyse"
////////////////////////////////////////////////////////
class Analyse
{ 
   
   float mean(float[] s)          // Mittelwert
   {  
   	  float sum=0; 
   	  
   	  for(i=0;i<s.length;i++)	
   	  {
   	  	 sum += s[i]; 
   	  }	
   	  return sum/s.length; 
   	
   }	
   
   
   float vss(float[] s)           // Spitze-Spitze-Wert
   {
   	
   	
   } 	
	
   float rms(float[] s)           // Effektivwert  
   {
   	
   	
   }		
	
}

