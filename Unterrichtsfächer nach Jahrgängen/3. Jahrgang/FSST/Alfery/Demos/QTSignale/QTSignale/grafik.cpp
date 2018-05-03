///////////////////////////////////////////////////////////////////////////////
//   grafik.cpp
//
//   Widget-Methode für Grafikausgabe
//
///////////////////////////////////////////////////////////////////////////////

#include "grafik.h"
#include <math.h>
#include <qpainter.h>
#include <qcolor.h>


grafik::grafik(QWidget *w):QWidget(w)
{

}

void grafik::paintEvent( QPaintEvent * )
{
    QPainter g( this );                          // QPainter-Objekt zur Grafikdarstellung


    QPoint cp = rect().center();                 // aktuelle Mittelpunkt-Koordinaten abfragen
    int d = width();                             // aktuelle Fensterbreite abfragen
    int h = height();                            //          Fensterhöhe   abfragen

    QMatrix matrix;                              // Bild-Transformations-Matrix erzeugen
    matrix.translate( 0 , cp.y() );              // Nullpunkt festlegen
    matrix.scale( d/N, h/200.0F );               // Koordinaten-Endpunkte mit x=N und y=+-100 skalieren
    g.setWorldMatrix( matrix );                  // Koordinaten-Transformation durchführen

    g.setPen(QColor(100,100,100));               // Zeichenstift
    g.drawLine(0,0,500,0);                       // Mittellinie ziehen

    g.setPen(QColor(100,100,250));
    int x,y,x0,y0;
    x0=0; y0=0;
    for(x=0;x<N;x++)                            // Sample-Array als Linienzug darstellen
    {   y = - (int) samples[x];
        g.drawLine(x0,y0,x,y);
        x0=x;y0=y;
    }

}
