///////////////////////////////////////////////////////////////////////////////
//   mainwindow.h
//
//   Hauptfenster
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

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_nincButton_clicked();
    void on_ndecButton_clicked();
    void on_quitButton_clicked();

};

#endif // MAINWINDOW_H
