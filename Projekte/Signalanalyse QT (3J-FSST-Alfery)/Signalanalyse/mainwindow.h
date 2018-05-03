#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QObject>
#include <QMargins>
#include <qmath.h>
#include <limits>
#if QT_VERSION < QT_VERSION_CHECK(5, 0, 0)
#  include <qnumeric.h>
#  include <QPrinter>
#  include <QPrintEngine>
#else
#  include <QtNumeric>
#  include <QtPrintSupport>
#endif
#include "grafik.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;

    int NMAX;

    void getAm();
    void getFre();
    void getPhi();
    void getSu();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString filename;

    float am,fr,phi,su;
    float *samples;
    float *samples2;

    float array_max ( float a[], int n1 , int n2 );
    float array_min ( float a[], int n1 , int n2 );
    float array_mittel(float a[], int n1, int n2);
    float array_ss ( float a[], int n1 , int n2 );
    float array_rms ( float a[], int n1, int n2 );

private slots:
    void on_actionDatei_laden_triggered();

};

#endif // MAINWINDOW_H
