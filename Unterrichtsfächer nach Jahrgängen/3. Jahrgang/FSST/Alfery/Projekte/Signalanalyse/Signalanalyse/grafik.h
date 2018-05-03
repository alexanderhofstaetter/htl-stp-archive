#ifndef GRAFIK_H
#define GRAFIK_H

#include <QWidget>


class grafik : public QWidget
{
protected:
    static const int N=1000;
    float samples[N];
    float samples2[N];

public:
    grafik(QWidget *w);
    virtual void paintEvent( QPaintEvent * );
    int getN()
    {  return N;
    }
    float* getsamples()
    {  return samples;
    }

    float* getsamples2()
    {  return samples2;
    }

};

#endif // GRAFIK_H
