#ifndef GRAFIK_H
#define GRAFIK_H

#include <QWidget>


class grafik : public QWidget
{
protected:
    static const int N=500;
    float samples[N];

public:
    grafik(QWidget *w);
    virtual void paintEvent( QPaintEvent * );
    int getN()
    {  return N;
    }
    float* getsamples()
    {  return samples;
    }



};

#endif // GRAFIK_H
