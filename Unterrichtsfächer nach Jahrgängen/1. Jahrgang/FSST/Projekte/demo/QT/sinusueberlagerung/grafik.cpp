///////////////////////////////////////////////////////////////////////////////
//   grafik.cpp
//
//   Widget-Methode für Grafikausgabe
//
///////////////////////////////////////////////////////////////////////////////

#include "grafik.h"
#include <math.h>
#include <QPainter>
#include <QMatrix>


grafik::grafik(QWidget *w):QWidget(w)            // Konstruktor
{   N=1;                                         // Anzahl der Oberwellen
}

void grafik::paintEvent( QPaintEvent * )         // Paint event Handler
{
    QPainter g(this);                            // QPainter-Objekt zur Grafikdarstellung

    QPoint cp = rect().center();                 // aktuelle Mittelpunkt-Koordinaten abfragen
    int d = width();                             // aktuelle Fensterbreite abfragen

    QMatrix matrix;                              // Bild-Transformations-Matrix erzeugen
    matrix.translate( cp.x(), cp.y() );          // Nullpunkt in den Fenster-Mittelpunkt legen
    matrix.scale( d/2000.0F, d/2000.0F );        // Koordinaten-Endpunkte mit x=+-1000 und y=+-1000 skalieren
    g.setWorldMatrix( matrix );                  // Koordinaten-Transformation durchführen

    g.setPen(QColor(250,0,0));                   // Zeichenstift mit Farbe wählen
    g.drawText (20,10,"Grafik Demo");            // Textausgabe an der Position x,y

    g.setPen(QColor(100,100,100));               // neuer Zeichenstift
    g.drawLine(-1000,0,1000,0);                  // Linien ziehen
    g.drawLine( 0,-1000,0,1000);

    g.setPen(QColor(100,100,250));
    int x,y,x0,y0;
    for(int f=1;f<=N;f+=2)                       // Sinus-Frequenzvielfache berechnen und darstellen
    {  x0=-1000;y0=0;
       for(x=-1000;x<1000;x++)
       {   y = (int)((500.0/f)*sin(2*M_PI*x*f/2000));
           g.drawLine(x0,y0,x,y);
           x0=x;y0=y;
       }
    }

    g.setPen(QColor(250,100,100));
    x0=-1000;y0=0;
    for(x=-1000;x<1000;x++)
    {  y=0;
       for(int f=1;f<=N;f+=2)                       // Sinus-Frequenzvielfache berechnen und darstellen
       {   y += (int)((500.0/f)*sin(2*M_PI*x*f/2000));
       }
       g.drawLine(x0,y0,x,y);
       x0=x;y0=y;

    }


}
