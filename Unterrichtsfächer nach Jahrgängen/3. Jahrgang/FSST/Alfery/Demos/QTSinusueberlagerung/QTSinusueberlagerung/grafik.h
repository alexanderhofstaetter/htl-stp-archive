///////////////////////////////////////////////////////////////////////////////
//   grafik.h
//
//   Widget Klassendefinition
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
