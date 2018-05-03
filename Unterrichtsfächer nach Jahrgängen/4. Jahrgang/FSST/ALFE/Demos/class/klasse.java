 /*  Klasse.java
     w.alfery
        
     eigene Klassen,Objekte, 
     Vererbung und Polymorphie   
           
 */

 import java.io.*;
 
 class Person                                    // eigene Klassendefinition 
 {
    public String name;                          // Datenelemente der Klasse 
    protected int alter;                         // Zugriffsattribute "public,protected,private" 
                                                 // sind vor jeder Variable u. Methode anzugeben 
                                                                                                
    public void ausgabe()                        // Methodendefinition 
    {  System.out.println("Name  ="+name); 
       System.out.println("Alter ="+alter);  
    }
  
    Person(String name,int alter)                // Konstuktordefinition 
    {
       this.name  = name;                        // bei Namensüberdeckung mit lokalen Variablen od. Parameternamen
       this.alter = alter;                       // kann mit "this" auf das Datenelement der Klasse referenziert werden 
    }
    Person(String name)                          // überladener 2.Konstuktor 
    {
       this.name  = name;                        // bei Namensüberdeckung mit lokalen Variablen od. Parameternamen
    }
    
 }

 class Schueler extends Person                   // abgeleitete Klasse  
 {
    public int katnr;
    static private int anzahl=0;                 // static Element = Klassenvariable    
    
    public void ausgabe()                        // virtuelle (polymorphe) Methode
    {  System.out.println("Name  ="+name); 
       System.out.println("Alter ="+alter);  
       System.out.println("Katnr.="+katnr);  
       System.out.println("Anzahl="+anzahl);  
    }
  
    Schueler(String name,int alter,int katnr)    // Konstuktordefinition 
    {
       super(name,alter);                        // Aufruf des Basisklassen-Konstruktors
       this.katnr = katnr;            
       anzahl++;
    }
 }

  
 public class klasse  		                     // Hauptklasse 
 {   

    public static void main(String args[])       
    { 
       
	   Person p=new Person("James Gosling",50);  // Objekte sind dynamisch    
	   Schueler ti1=new Schueler("Listig",15,20);  
       Schueler ti2=new Schueler("Klug",16,21);  
       
       System.out.println("\n Klasse ");
       System.out.println(" ________ \n");
	   System.out.println("\n Person p : ");
	   p.ausgabe();                              // Methodenaufruf 
	   
	   System.out.println("\n Schueler ti1 : ");
	   ti1.ausgabe();
	   System.out.println("\n Schueler ti2 : ");
	   ti2.ausgabe();
       
    }
 }