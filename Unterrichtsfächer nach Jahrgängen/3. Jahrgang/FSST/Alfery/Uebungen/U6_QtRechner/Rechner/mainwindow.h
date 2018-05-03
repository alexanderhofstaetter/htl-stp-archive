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

private slots:
    void on_plusButton_clicked();
    void on_minusButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();
    void on_equalsButton_clicked();
    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    double x;
    int operation;
};



#endif // MAINWINDOW_H
