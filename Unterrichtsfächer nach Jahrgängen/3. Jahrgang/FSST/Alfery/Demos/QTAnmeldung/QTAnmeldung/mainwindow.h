#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void sleep(int ms);

private:
    Ui::MainWindow *ui;

private slots:
    void on_quitButton_clicked();
    void on_resetButton_clicked();
    void on_anmeldeButton_clicked();
};

#endif // MAINWINDOW_H
