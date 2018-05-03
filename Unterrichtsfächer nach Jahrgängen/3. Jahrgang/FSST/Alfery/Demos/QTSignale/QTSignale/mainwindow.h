///////////////////////////////////////////////////////////////////////////////
//   mainwindow.h
//
//   progr. by di w.alfery
//   2009-10-02
//   version 1.0
//
///////////////////////////////////////////////////////////////////////////////


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    static const float AM_MIN=-100,AM_MAX=100;
    static const int FR_MIN=1,FR_MAX=100;
    static const int PHI_MIN=-180,PHI_MAX=180;

    void getAm();
    void getFre();
    void getPhi();
    void getSu();

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    float am,fr,phi,su;
    float *samples;

private slots:
    void on_exitButton_clicked();
    void on_resetButton_clicked();
    void on_noiseButton_clicked();
    void on_rampButton_clicked();
    void on_rectButton_clicked();
    void on_sinusButton_clicked();
    void on_dcButton_clicked();

};

#endif // MAINWINDOW_H
