///////////////////////////////////////////////////////////////////////////////
//   grafik.h
//
//   Widget Klassendefinition
//
//   Zeichenbereich :
//   im Designer als leeres Widget einfügen
//   und als Platzhalter für benutzerdefinierte Klasse festlegen
//
///////////////////////////////////////////////////////////////////////////////

#ifndef GRAFIK_H
#define GRAFIK_H

#include <QWidget>


class grafik : public QWidget
{
public:
    grafik(QWidget *w);

    virtual void paintEvent( QPaintEvent * );

    int N;
};

#endif // GRAFIK_H
